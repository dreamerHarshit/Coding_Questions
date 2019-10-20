/*Combination Sum
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T. The same repeated number may be chosen from C unlimited number of times.
 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The combinations themselves must be sorted in ascending order.
CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR ... (a1 = b1 AND a2 = b2 AND ... ai = bi AND ai+1 > bi+1)
The solution set must not contain duplicate combinations.*/

void combination_sum(vector<int> &s, int B, vector<int> &aux, vector<vector<int>> &result, int idx, int curr_sum){
    if(curr_sum==B){
        result.push_back(aux);
        return;
    }
    if(curr_sum>B)
        return;
        
    for(int i=idx;i<s.size();i++){
        aux.push_back(s[i]);
        curr_sum+=s[i];
        combination_sum(s,B,aux,result,i,curr_sum);
        aux.pop_back(); 
        curr_sum-=s[i];
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<int> aux;
    vector<vector<int>> result;
    int idx=0, curr_sum=0;
    sort(A.begin(),A.end());
    vector<int> uniqueA;
    uniqueA.push_back(A[0]);
    for(int i=1;i<A.size();i++){
        if(A[i]!=A[i-1])
            uniqueA.push_back(A[i]);
    }

    combination_sum(uniqueA, B, aux, result, idx, curr_sum);
    return result;
}