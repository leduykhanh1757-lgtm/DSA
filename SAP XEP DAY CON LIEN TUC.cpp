#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n],b[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
			b[i] = a[i];
		}
		sort(b,b+n);
		
		int l=0;
		while(l<n && a[l]==b[l]){
			l++;
		}
		
		int r = n-1;
		while(r>=0 && a[r]==b[r]){
			r--;
		}
		
		if(l<r){
			cout<<l+1<<" "<<r+1<<endl;
		}
		else{
			cout<<"1 1"<<endl;
		}
	}
}