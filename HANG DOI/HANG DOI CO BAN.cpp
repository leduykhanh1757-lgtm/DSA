#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;

int main(){
	int t;
	cin>>t;
	cin.ignore();
	deque<int>dq;
	while(t--){
		string s;
		cin>>s;
		if(s=="PUSHBACK"){
			int x;
			cin>>x;
			dq.push_back(x);
		}
		else if(s=="PRINTBACK"){
			if(!dq.empty()){
				cout<<dq.back();
			}
			else{
				cout<<"NONE";
			}
		}
		else if(s=="POPBACK"){
			if(!dq.empty()){
				dq.pop_back();
			}
		}
		else if(s=="PUSHFRONT"){
			int x;
			cin>>x;
			dq.push_front(x);
		}
		else if(s=="PRINTFRONT"){
			if(!dq.empty()){
				cout<<dq.front();
			}
			else{
				cout<<"NONE";
			}
		}
		else if(s=="POPFRONT"){
			if(!dq.empty()){
				dq.pop_front();
			}
		}
		cout<<endl;
	}
}