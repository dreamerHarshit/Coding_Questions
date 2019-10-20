/*
Subset
Given a set of distinct integers, S, return all possible subsets.
 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
Example : If S = [1,2,3], a solution is:
[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]
*/

void find_subset(vector<int> &A, vector<vector<int>> &result, vector<int> &aux, int i){
    if(i==A.size()){
        result.push_back(aux);
        return;
    }
    find_subset(A,result,aux,i+1);   
    aux.push_back(A[i]);
    find_subset(A,result,aux,i+1);
    aux.pop_back();
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<int> aux;
    vector<vector<int> > result;
    int i = 0;
    sort(A.begin(),A.end());
    find_subset(A, result, aux, i);
    sort(result.begin(),result.end());
    return result;
}