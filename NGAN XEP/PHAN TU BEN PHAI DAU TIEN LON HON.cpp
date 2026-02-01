#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		stack<int>st;
		vector<int>res(n,-1);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			while(!st.empty()&&a[i]>a[st.top()]){
				int pos = st.top();
				st.pop();
				res[pos]=a[i];
			}
			st.push(i);
		}
		for(int x:res){
			cout<<x<<" ";
		}
		cout<<endl;
	}
}