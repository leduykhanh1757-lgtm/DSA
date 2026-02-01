#include<iostream>

using namespace std;

int n,k,a[100],b[100],ok;

void ktao(){
	for(int i =1;i<=k;i++){
		a[i] = i;
	}
}

void sinh(){
	int i = k;
	while(i>=1 && a[i]==n-k+i){
		i--;
	}
	if(i==0){
		ok=0;
	}
	else{
		a[i]++;
		for(int j = i+1;j<=n;j++){
			a[j] = a[j-1] +1;
		}
	}
}

bool check(){
	for(int i = 1; i<=k;i++){
		if(a[i]!=b[i]){
			return false;
		}
	}
	return true;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		int dem =1;
		for(int i =1;i<=k;i++){
			cin>>b[i];
		}
		ktao();
		ok = 1 ;
		while(ok){
			if(check()){
				cout<<dem<<endl;
				break;
			}
			dem++;
			sinh();
		}
		cout<<endl;
	}
}