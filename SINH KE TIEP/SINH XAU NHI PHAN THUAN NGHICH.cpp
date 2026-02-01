#include<iostream>

using namespace std;

int a[1000],n,k, isfinal;

void khoitao(){
	for(int i=1;i<=k;i++){
		a[i]=0;
	}
}

void sinh(){
	int i = k;
	while(i>=1 && a[i]==1){
		a[i]=0;
		--i;
	}
	if(i == 0){
		isfinal = 0;
	}
	else{
		a[i] = 1;
	}
}
int main(){
	cin>>n;
	k = n/2 + n%2;
	khoitao();
	isfinal = 1;
	while(isfinal){
		for(int i=1;i<=k;i++){
			cout<<a[i]<<" ";
		}
		int x;// diem neo
		if(n%2 ==0){
			x = k;
		}
		else{
			x = k-1;
		}
		for(int i = x;i>=1;i--){
			cout<<a[i]<<" ";
		}
		cout<<endl;
		sinh();
	}
}