#include<bits/stdc++.h>

using namespace std;

bool check(int a[],int n,int k, long long m){
	int dem=0;
	long long tong=0;
	for(int i=0;i<n;i++){
		tong+=a[i];
		if(tong>m){
			++dem;
			tong=a[i];
		}
	}
	++dem;
	return dem<=k;
}

int main(){
	int n,k;
	cin>>n>>k;
	int a[n];
	long long left = LLONG_MIN,right=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		left=max(left,0ll+a[i]);
		right+=a[i];
	}
	long long res=-1;
	while(left<=right){
		long long mid=(left+right)/2;
		if(check(a,n,k,mid)){
			res=mid;
			right=mid-1;
		}
		else{
			left=mid+1;
		}
	}
	cout<<res<<endl;
}