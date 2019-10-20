/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other. N Queens: Example 1 Given an integer n, return all distinct solutions to the n-queens puzzle. Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively. For example, There exist two distinct solutions to the 4-queens puzzle:
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

bool IsSafe(vector<string> &r, int curr_row, int col, int A){
    int row=curr_row, c=col;
    while(row-1>=0 && c-1>=0){
        if(r[row-1][c-1]=='Q'){
            return false;
        }
        else{
         row--;
         c--;
        }
    }
    row=curr_row, c=col;
    while(row-1>=0){
        if(r[row-1][c]=='Q'){
            return false;
        }
        else{
         row--; 
        }
    }
    row=curr_row, c=col;
    while(row-1>=0 && c+1<=A){
        if(r[row-1][c+1]=='Q'){
            return false;
        }
        else{
            row--;
            c++;
        }
    }
    return true;
}

/*Recurssive Funstion*/

void count_nqueen(int curr_row, vector<string> &r, int &A,  vector<vector<string>> &result){
    if(curr_row>=A)
    {
        result.push_back(r);
        return;
    }
    for(int i=0;i<A;i++){
        if(IsSafe(r,curr_row,i, A)){
            r[curr_row][i]='Q';
            count_nqueen(curr_row+1, r, A, result);
            r[curr_row][i]='.';
        }
    }
}

/* Main Function */
vector<vector<string> > Solution::solveNQueens(int A) {
    int curr_row=0;
    vector<string> m(A,string(A,'.'));
    vector<vector<string>> result;
    count_nqueen(curr_row, m, A, result);
    return result;
}