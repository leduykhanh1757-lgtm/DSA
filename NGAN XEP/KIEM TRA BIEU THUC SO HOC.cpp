#include<iostream>
#include<stack>

using namespace std;

int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin,s);
		stack<char>st;
		bool found = false;
		for(int i=0;i<s.size();i++){
			if(s[i]!=')'){
				st.push(s[i]);
			}
			else{
				bool ok = false;
				while(!st.empty()){
					char c  = st.top();st.pop();
					if(c=='('){
						break;
					}
					if(c=='+'||c=='-'||c=='*'||c=='/'){
						ok = true;
					}
				}
				if(!ok){
					found = true;
					break;
				}
			}
		}
		if(found) cout<<"Yes\n";
		else cout<<"No\n";
	}
}