#include<iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		cin>>s;
		int n = s.size();
		int i = n-1;
		while(i>=0 && s[i] == '1'){
			s[i] = '0';
			--i;	
		}
		if(i!= -1){
			s[i] = '1';
		}	
	}
}