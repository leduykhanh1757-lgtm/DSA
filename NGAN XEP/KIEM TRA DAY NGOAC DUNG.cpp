#include<iostream>
#include<iomanip>
#include<cmath>
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
		stack<char> st;
		bool check = true;
		for(char x:s){
			if(x=='(' || x=='{' || x=='['){
				st.push(x);
			}
			else{
				if(st.empty()){
					check = false;
					break;
				}
				char top = st.top();
				if(top == '(' && x != ')'||
					top == '{' && x != '}'||
					top == '[' && x != ']'){
						check = false;
						break;
				}
				else{
					st.pop();
				}
			}
		}
		if(st.empty()&&check == true){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}