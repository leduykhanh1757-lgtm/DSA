#include<bits/stdc++.h>

using namespace std;

int main(){
	int t=1;
	while(t--){
		int n,x;
		cin>>n;
		string s;
		stack<int>v;
		while(n--){
			cin>>s;
			if(s=="PUSH"){
				cin>>x;
				v.push(x);
			}
			else if(s=="PRINT"){
				if(v.empty()){
					cout<< "NONE";
				}
				else{
					cout<<v.top();
				}
				cout<<endl;	
			}
			else if(s=="POP"){
				if(!v.empty())
					v.pop();
			}
		}
		cout<<endl;
	}	
}