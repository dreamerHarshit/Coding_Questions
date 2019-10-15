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

void count_nqueen(int curr_row, vector<string> &r, int &A,  vector<vector<string>> &result){
    if(curr_row>=A)
    {//cout<<"curr_row-"<<curr_row<<endl;
        result.push_back(r);
        return;
    }
    for(int i=0;i<A;i++){
        //cout<<IsSafe(r,curr_row,i, A)<<endl;
        if(IsSafe(r,curr_row,i, A)){
            r[curr_row][i]='Q';
            count_nqueen(curr_row+1, r, A, result);
            r[curr_row][i]='.';
        }
    }
}
vector<vector<string> > Solution::solveNQueens(int A) {
    int curr_row=0;
    vector<string> m(A,string(A,'.'));
    vector<vector<string>> result;
    count_nqueen(curr_row, m, A, result);
    return result;
}