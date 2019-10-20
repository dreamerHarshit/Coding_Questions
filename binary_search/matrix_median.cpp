/*Matrix Median
Given a N cross M matrix in which each row is sorted, find the overall median of the matrix. Assume N*M is odd. For example,
Matrix=
[1, 3, 5]
[2, 6, 9]
[3, 6, 9]

A = [1, 2, 3, 3, 5, 6, 6, 9, 9]

Median is 5. So, we return 5.*/

int Solution::findMedian(vector<vector<int> > &A) {
    int l=0, r=INT_MAX, cont=0, req=(int)A.size()*(int)A[0].size();
    int mid;
    //cout<<"req = "<<req/2 + 1<<endl;
    while(r-l){
        cont = 0;
        mid = l+(r-l)/2;
        for(auto &i:A){
            int p = upper_bound(i.begin(),i.end(),mid)-i.begin();
            cont+=p;
            //cout<<"count = "<<cont<<endl;
        }
        if(cont>=(req/2)+ 1)
            r=mid;
        else
            l=mid;
    }
    return r;
}