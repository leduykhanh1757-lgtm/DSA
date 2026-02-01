#include<bits/stdc++.h>

using namespace std;

void BubbleSort(int a[],int n){
	vector<string> result;
	for(int i=0;i<n-1;i++){
		bool ok = false;
		for(int j = 0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
				ok = true;
			}
		}
		if(ok==true){
			string s = "Buoc "+to_string(i+1)+": ";
			for(int x = 0; x<n;x++){
				s+= to_string(a[x]) + " ";
			}
			result.push_back(s);
		} else{
			break;
		}
	}
	for(int i = result.size()-1;i>=0;i--){
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
		BubbleSort(a,n);
	}	
}