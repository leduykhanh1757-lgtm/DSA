#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		bool check = false;
		for(int i=0;i<n;i++){
			cin>>a[i];	
		}
		stack<int>st;
		for(int i=0;i<n;i++){
			if(st.empty()||a[i]<a[st.top()]){
				st.push(i);
			}
		}
		int Max = -1e9;
		for(int j=n-1;j>=0;j--){
			while(!st.empty()&&a[j]>a[st.top()]){
				Max = max(Max, j-st.top());
				check = true;
				st.pop();
			}
		}
		if(check == false){
			cout<<-1<<endl;
		}
		else{
			cout<<Max<<endl;
		}
	}
}