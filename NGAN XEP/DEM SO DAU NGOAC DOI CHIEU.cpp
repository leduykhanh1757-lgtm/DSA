#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		cin>>s;
		stack<char>st;
		int dem = 0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='('){
				st.push(s[i]);
			}
			else{
				if(!st.empty()&&st.top()=='('){
					st.pop();
				}
				else{
					st.push(s[i]);
				}
			}
		}
		int open = 0,close = 0;
		while(!st.empty()){
			if(st.top()=='('){
				open++;
			}
			else{
				close++;
			}
			st.pop();
		}
		int ans = (open+1)/2+(close+1)/2;
		cout<<ans<<endl;
	}
}