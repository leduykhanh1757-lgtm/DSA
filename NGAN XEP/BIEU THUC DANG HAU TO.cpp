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
		stack<long long>st;
		for(char x:s){
			if(x=='+'||x=='-'||x=='*'||x=='/'){
				long long num2 = st.top();st.pop();
				long long num1 = st.top();st.pop();
				
				if(x=='+'){
					st.push(num1+num2);
				}
				else if (x=='-'){
					st.push(num1-num2);
				}
				else if (x=='*'){
					st.push(num1*num2);
				}
				else if (x=='/'){
					st.push(num1/num2);
				}
				
			}
			else{
				st.push(x-'0');
			}
		}
		cout<<st.top()<<endl;
	}
}