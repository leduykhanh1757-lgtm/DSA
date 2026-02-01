#include<iostream>
#include<cmath>
#include<algorithm>
#include<stack>
#include<climits>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		long long a[n];
		stack<long long>st;
		long long res = -1e9;
		for(long long i=0;i<n;i++){
			cin>>a[i];
		}
		long long i=0;
		while(i<n){
			if(st.empty()||a[i]>a[st.top()]){
				st.push(i);
				i++;
			}
			else{
				long long idx = st.top();// chỉ số của cột ở đỉnh stack
				st.pop();
				// tính toán hình chữ nhật tạo bởi cột hiện tại, trong đó cột hiện tại được coi là cột ngắn nhất của hình chữ nhật đó
				if(st.empty()){
					res = max (res, i*a[idx]);
				}
				else{
					res = max (res, a[idx]*(i-st.top()-1));
				}
			}
		}
		while(!st.empty()){
			long long idx = st.top();
				st.pop();
			if(st.empty()){
				res = max (res, i*a[idx]);
			}
			else{
				res = max (res, a[idx]*(i-st.top()-1));
			}
		}
		cout<<res<<endl;
	}
}