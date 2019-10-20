/*Combination Sum II
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T. Each number in C may only be used once in the combination.
 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
Example : Given candidate set 10,1,2,7,6,1,5 and target 8, A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]*/


void combination_sum(vector<int> &A, int B, vector<int> &aux, vector<vector<int>> &result, int idx, map<vector<int>,int> &hash){
    if(idx==A.size()){
        int p = accumulate(aux.begin(), aux.end(), 0);
        if(p==B && hash.find(aux)==hash.end()){
         result.push_back(aux);
         hash[aux]=1;
        }
        return;
    }
        combination_sum(A,B,aux,result,idx+1, hash);
        aux.push_back(A[idx]);
        combination_sum(A,B,aux,result,idx+1, hash);
        aux.pop_back();   
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<int> aux;
    vector<vector<int>> result;
    map<vector<int>,int> hash;
    int idx=0;
    sort(A.begin(),A.end());
    combination_sum(A, B, aux, result, idx, hash);
    return result;
}
