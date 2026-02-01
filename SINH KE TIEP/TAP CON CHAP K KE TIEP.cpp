#include<iostream>
#include<vector>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<int>v(k+1);
		for(int i = 1;i<=k;i++){
			cin>>v[i];
		}
		int  i = k;
		while(i>=1 && v[i] == n-k+i){
			i--;
		}
		if(i==0){
			for(int i =1;i<=k;i++){
				cout<<i<<" ";
			}
			cout<<endl;
		}
		else{
			v[i]++;
			for(int j = i+1;j<=k;j++){
				v[j] = v[j-1] + 1;
			}
			for(int i = 1;i<=k;i++){
				cout<<v[i]<<" ";
			}
			cout<<endl;
		}
	}
}