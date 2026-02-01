#include<iostream>
#include<cmath>
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
		for(int i = s.size()-1;i>=0;i--){
			string a = string(1,s[i]);
			if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
				string x = st.top();st.pop();
				string y = st.top();st.pop();
				string z = x + y + a;
				st.push(z);
			}
			else{
				st.push(a);
			}
		}
		cout<<st.top()<<endl;
	}
}