#include<iostream>

using namespace std;

int n,dem,a[105],ok;

void ktao(){
	dem = 1;
	a[1] = n;
}
void sinh(){
	int i = dem;
	while(i>=1 && a[i] == 1){
		i--;
	}
	if(i==0){
		ok = 0;
	}
	else{
		a[i]--;
		int d = dem-i+1;
		dem=i;
		int q = d / a[i];
		int r = d % a[i];
		if(q){
			for(int j = 1;j<=q;j++){
				dem++;
				a[dem] = a[i];
			}
		}
		if(r){
			dem++;
			a[dem] = r;
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ktao();
		ok = 1;
		while(ok){
			cout<<"(";
			for(int i =1;i<=dem;i++){
				cout<<a[i];
				if(i==dem) cout<<") ";
				else cout<<" ";
			}
			sinh();
		}
		cout<<endl;
	}
}