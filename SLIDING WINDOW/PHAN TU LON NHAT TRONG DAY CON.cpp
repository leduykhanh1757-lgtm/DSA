#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long n,k;
		cin>>n>>k;
		long long a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		deque<int>dq;
		vector<int>res;
		for(int i=0;i<n;i++){
			while(!dq.empty()&&a[dq.back()]<a[i]){
				dq.pop_back();
			}
			dq.push_back(i);
			if(dq.front()==i-k){
				dq.pop_front();
			}
			if(i>=k-1){
				res.push_back(a[dq.front()]);
			}
		}
		for(int x:res){
			cout<<x<<" ";
		}
		cout<<endl;
	}
}