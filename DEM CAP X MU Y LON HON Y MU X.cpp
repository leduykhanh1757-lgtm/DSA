#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
    	int n,m;
    	cin>>n>>m;
    	long long a[n],b[m];
    	for(int i=0;i<n;i++){
    		cin>>a[i];
		}
		for(int j=0;j<m;j++){
			cin>>b[j];
		}
		int dem = 0;
		for(int i=0;i<n;i++){
			for(int j = 0;j<m;j++){
				if(pow(a[i],b[j])>pow(b[j],a[i])){
					dem++;
				}
			}
		}
		cout<<dem<<endl;
	}
}