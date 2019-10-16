#include <iostream>
#define parr(arr,s) for(int i=0;i<s;cout<<arr[i++]<<" ");cout<<endl;
#define sarr(arr,s) for(int i=0;i<s;cin>>arr[i++]);

using namespace std;

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int a[],int l,int h){
	int i=l,j=h,pivot=a[l];

	do{
		do{i++;}while(a[i]<=pivot);
		do{j--;}while(a[j]>pivot);
		if(i<j){
			swap(&a[i],&a[j]);
		}
	}while(i<j);

	swap(&a[j],&a[l]);
	return j;
}

void quiksrt(int a[],int l,int h){
	if(l<h){
		int j = partition(a,l,h);
		quiksrt(a,l,j);
		quiksrt(a,j+1,h);
	}
}

int main(){
	int arr[6];
	arr[6] = INT_MAX;
	sarr(arr,5);

	quiksrt(arr,0,5);

	parr(arr,5);
}