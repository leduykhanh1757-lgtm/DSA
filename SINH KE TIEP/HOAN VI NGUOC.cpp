#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,a[100],ok;

void ktao(){
	for(int i =1;i<=n;i++){
		a[i] = i;
	}
}

void sinh(){
	int  i = n-1;
	while(i>=1 && a[i] > a[i+1]){
		i--;
	}
	if(i==0){
		ok = 0;
	}
	else{
		int  j = n;
		while(a[i]>a[j]) j--;
		swap(a[i],a[j]);
		int l = i+1,r = n;
		while(l<r){
			swap(a[l],a[r]);
			l++;r--;
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		vector<string> res;
		cin>>n;
		ktao();
		ok = 1;
		while(ok){
			string s = "";
			for(int i =1;i<=n;i++){
				s+=to_string(a[i]);
			}
			res.push_back(s);
			sinh();
		}
		reverse(res.begin(),res.end());
		for(string x:res) cout<<x<<" ";
		cout<<endl;
	}
}