#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;

vector<string>res;

void init(){
	queue<string>q;
	q.push("6");
	q.push("8");
	res.push_back("6");
	res.push_back("8");
	while(true){
		string top = q.front();
		q.pop();
		if(top.length()==15) break;
		res.push_back(top+"6");
		res.push_back(top+"8");
		q.push(top+"6");
		q.push(top+"8");
	}
}

int main(){
	init();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<string> ans;
		vector<long long> result;
		for(string x:res){
			if(x.length()>=n+1) break;
			ans.push_back(x);
		}
		cout<<ans.size()<<endl;
		for(string x:ans){
			long long a = stoll(x);
			result.push_back(a);
		}
		reverse(result.begin(),result.end());
		for(long long x:result){
			cout<<x<<" ";
		}
		cout<<endl;
	}
}