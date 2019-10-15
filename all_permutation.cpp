/*
All Unique Permutations
Given a collection of numbers that might contain duplicates, return all possible unique permutations. Example : [1,1,2] have the following unique permutations:
[1,1,2]
[1,2,1]
[2,1,1]
 NOTE : No 2 entries in the permutation sequence should be the same. Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS. Example : next_permutations in C++ / itertools.permutations in python. If you do, we will disqualify your submission retroactively and give you penalty points.
*/


void find_permute(vector<int> &A, vector<vector<int>> &result, map<vector<int>,int> &hash, int idx){
    if(idx==A.size()){
        if(hash.find(A)==hash.end())
        {
            hash[A]=1;
            result.push_back(A);
        }
        return;
    }
    for(int i=idx;i<A.size();i++){
        swap(A[i],A[idx]);
        find_permute(A, result, hash, idx+1);
        swap(A[i],A[idx]);
    }

}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> result;
    map<vector<int>,int> hash;
    int idx=0;
    find_permute(A,result,hash,idx);
    //sort(result.begin(),result.end());
    return result;
}