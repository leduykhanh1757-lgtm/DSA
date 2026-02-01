#include<iostream>

using namespace std;

int n,a[100],b[100],ok;


void ktao(){
	for(int i = 1;i<=n;i++){
		a[i] = i;
	}
}

void sinh(){
	int i = n-1;
	while(i>=1 && a[i]>a[i+1]){
		i--;
	}
	if(i==0){
		ok = 0;
	}
	else{
		int j = n;
		while(a[i]>a[j]) j--;
		swap(a[i],a[j]);
		int l = i+1,r = n;
		while(l<r){
			swap(a[l],a[r]);
			l++;r--;
		}
		
	}
}

bool check(){
	for(int i=1;i<=n;i++){
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
		int dem =1;
		cin>> n;
		for(int i =1;i<=n;i++){
			cin>>b[i];
		}
		ktao();
		ok = 1;
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