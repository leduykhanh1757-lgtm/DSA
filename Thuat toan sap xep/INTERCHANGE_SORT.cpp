#include<bits/stdc++.h>

using namespace std;

void InterchangeSort(int a[],int n){
	vector<string>result;
	for(int i=0;i<n-1;i++){
		for(int j = i+1;j<n;j++){
			if(a[j]<a[i]){
				swap(a[i],a[j]);
			}
		}
		string s = "Buoc " + to_string(i+1)+": ";
		for(int x=0;x<n;x++){
			s += to_string(a[x]) + " ";
		}
		result.push_back(s);
	}
	for(int i=result.size()-1;i>=0;i--){
		cout<<result[i]<<endl;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		InterchangeSort(a,n);
	}	
}