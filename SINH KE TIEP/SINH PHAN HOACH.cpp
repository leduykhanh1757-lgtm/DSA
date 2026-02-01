#include<iostream>

using namespace std;

int n,a[100],dem,final=0;

void ktao(){
	dem=1;
	a[1]=n;
}

void sinh(){
	int i=dem;
	while(i>=1&&a[i]==1){
		--i;
	}
	if(i==0){
		final=1;
	}
	else{
		--a[i];
		int d=dem-i+1;
		dem=i;
		int q = d / a[i],r = d % a[i];
		for(int j=1;j<=q;j++){
			++dem;
			a[dem]=a[i];
		}
		if(r){
			++dem;
			a[dem]=r;
		}
	}
}

int main(){
	cin>>n;
	ktao();
	while(!final){
		for(int i=1;i<=dem;i++){
			cout<<a[i]<<" ";
		}
	cout<<endl;
	sinh();
	}
	
}