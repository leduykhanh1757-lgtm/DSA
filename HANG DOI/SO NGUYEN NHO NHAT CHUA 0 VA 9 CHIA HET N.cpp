#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;

vector<string>res;
long long ans[101];

void init(){
	queue<string>q;
	q.push("9");
	res.push_back("9");
	while(true){
		string top = q.front();
		q.pop();
		if(top.length()==12) break;
		res.push_back(top+"0");
		res.push_back(top+"9");
		q.push(top+"0");
		q.push(top+"9");
	}
	for(int i=1;i<=100;i++){
		for(string x:res){
			if(stoll(x)%i==0){
				ans[i]=stoll(x);
				break;
			}
		}
	}
}

int main(){
	init();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<ans[n]<<endl;
	}
}