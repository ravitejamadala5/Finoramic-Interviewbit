bool isValid(const vector<string>& A, int row, int col)
{
    char box = A[row][col]; 
    
    if (box -'0' < 1 || box - '0'  > 9)
        return false;
    
    for (int  p = 0; p<9; ++p)
    {
        if (A[p][col] == box && p != row)  return false;
        if (A[row][p] == box && p != col)  return false;
    }
    
    int sr = (row/3)*3;
    int sc = (col/3)*3;
    
    for (int i = sr; i<sr+3; ++i)
    {
        for (int j = sc; j<sc+3; ++j)
            if (A[i][j] == box && (i != row || j != col))
                return false;
    }
    
    return 1;
}

int sudoku(const vector<string>& A, int row, int col)
{
    if (row == 9)
        return 1;
    
    int nextRow, nextCol;
    if (col == 8)
    {
        nextRow = row + 1;
        nextCol = 0;
    }
    else
    {
        nextRow = row;
        nextCol = col + 1;
    }
    
    if (A[row][col] != '.')
    {
        if (!isValid(A, row, col))
            return 0;
    }
    
    return sudoku(A, nextRow, nextCol);
}

int Solution::isValidSudoku(const vector<string> &A) {
    if (A.size() != 9 || A[0].size() != 9)
        return 0;
    return sudoku(A, 0, 0);
}