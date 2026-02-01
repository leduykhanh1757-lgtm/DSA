#include<iostream>
#include<cmath>
#include<vector>
#include<stack>

using namespace std;

int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		cin>>s;
		stack<long long> st;
		for(int i= s.length()-1;i>=0;i--){
			if(s[i] == '+'|| s[i]=='-'||s[i]=='*'||s[i]=='/'){
				long long num1 = st.top();st.pop();
				long long num2 = st.top();st.pop();
				if(s[i]=='+'){
					st.push(num1+num2);
				}
				else if(s[i]=='-'){
					st.push(num1-num2);
				}
				else if(s[i]=='*'){
					st.push(num1*num2);
				}
				else if(s[i]=='/'){
					st.push(num1/num2);
				}	
			}
			else{
				st.push(s[i]-'0');
			}
		}
		cout<<st.top()<<endl;
	}
}