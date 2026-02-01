#include<iostream>
#include<iomanip>

using namespace std;

int a[1000005];
long long F[1000005];

int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	F[0]=0;
	for(int i=1;i<n;i++){
		F[i]=1e18;
		for(int j=1;j<=k;j++){
			if(i-j>=0){
				F[i]=min(F[i],F[i-j]+abs(a[i]-a[i-j]));
			}
		}
	
	}
	cout<<F[n-1]<<endl;
}