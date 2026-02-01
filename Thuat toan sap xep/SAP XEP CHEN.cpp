#include<bits/stdc++.h>

using namespace std;

void InsertSort(int a[],int n){
	vector<string> result;
	string x = "Buoc 0: "+to_string(a[0]);
	for(int i=1;i<n;i++){
		// Lấy ra phần tử ở chỉ số i
		int x = a[i],pos = i - 1;
		while(pos >= 0 && x < a[pos]){
			a[pos+1] = a[pos];
			--pos;
		}
		a[pos + 1] = x;
		string s = "Buoc "+to_string(i)+": ";
		for(int j = 0; j<=i;j++){
			s+=to_string(a[j])+" ";
		}
		result.push_back(s);
	}
	for(int i = result.size()-1;i>=0;i--){
		cout<<result[i]<<endl;
	}
	cout<<x<<endl;
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	InsertSort(a,n);
}