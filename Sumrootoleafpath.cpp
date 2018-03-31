/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int check(TreeNode* root, int sum, vector<vector<int> > &v, vector<int> p){
    if(root == NULL)
        return 0 ;
    else if(root->left==NULL && root->right==NULL && sum-root->val==0){
        p.push_back(root->val);
        v.push_back(p);
    }
    else{
        p.push_back(root->val);
        sum = sum - root->val;
        check(root->left,sum,v,p);
        check(root->right,sum,v,p);
    }
}

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {

    vector< vector<int> >v;
    vector<int>p;
    check(A,B ,v,p);
    return v;
}
