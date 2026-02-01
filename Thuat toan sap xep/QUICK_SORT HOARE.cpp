#include<bits/stdc++.h>

using namespace std;

int Partition(int a[],int l, int r){
	int pivot = a[l]; 
	int i = l-1,j = r+1;
	while(true){
		do{
			++i;
		}while(a[i]<pivot);
		do{
			--j;
		}while(a[j]>pivot);
		if(i<j){
			swap(a[i],a[j]);
		}
		else return j;
	}
}

void quick_sort(int a[],int l, int r){
	if(l>=r) return;
	int  p = Partition(a,l,r);
	quick_sort(a,l,p);
	quick_sort(a,p+1,r);
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	quick_sort(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}