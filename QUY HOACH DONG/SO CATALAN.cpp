#include<iostream>
#include<iomanip>
#include<algorithm>

using namespace std;

long long C[10005];
int mod = 1e9+7;

int main(){
	C[0]=1;
	C[1]=1;
	for(int i=2;i<=1000;i++){
		for(int j=0;j<i;j++){
			C[i]+=C[j]*C[i-j-1];
			C[i]%=mod;
		}
	}
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<C[n]<<endl;
	}
}