#include<bits/stdc++.h>

using namespace std;

int Partition(int a[],int l, int r){
	int pivot = a[r]; //phần tử bên phải cùng
	int i = l-1;
	for(int j=l;j<r;j++){
		if(a[j] <= pivot){
			++i;
			swap(a[i],a[j]);
		}	
	}
	// đưa chốt về giữa
	++i;
	swap(a[i],a[r]);
	return i;// vị trí
}

void quick_sort(int a[],int l, int r){
	if(l>=r) return;
	int  p = Partition(a,l,r);
	quick_sort(a,l,p-1);
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