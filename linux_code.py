#!/usr/bin/env python

import json
import subprocess

data = None

def parseJsonFile():
   with open('dependency.json') as inputFile:
      global data
      data = json.load(inputFile)
      print "Dependencies to be downloaded: \n", data

def downloadPackages():
   success = True
   failedPackages = []
   for package in data['Dependencies']:
      print "Downloading package: %s, Version: %s" % (package, data['Dependencies'][package])
      try:
         proc = subprocess.Popen(["pip", "install", package + "==" + data['Dependencies'][package]], stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
         output = proc.stdout.read()

         if "Could not find a version that satisfies the requirement" in output:
            success = False
            failedPackages.append(package)

      except OSError:
         success = False
         failedPackages.append(package)

   if success:
      print "Successfully installed all the dependencies"
   else:
      print "Download failed for following packages:"
      for package in failedPackages:
         print package

if __name__ == '__main__':
   parseJsonFile()
   downloadPackages()
