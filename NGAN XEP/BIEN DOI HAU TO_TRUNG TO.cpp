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
		stack<string>st;
		for(int i= 0;i<s.size();i++){
			string a = string(1,s[i]);
			if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
				string y = st.top();st.pop();
				string x = st.top();st.pop();
				string z = "(" + x + a + y + ")";
				st.push(z);
			}
			else{
				st.push(a);
			}
		}
		cout<<st.top()<<endl;
	}
}