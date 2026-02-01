#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<int> ke[10005];
int visited[10005];

void nhap(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		sort(ke[i].begin(),ke[i].end());
	}
}

int main(){
	cin>>n;
	cin.ignore();
	vector<pair<int,int>> dscanh;
	for(int i=1;i<=n;i++){
		string s;
		getline(cin,s);
		stringstream ss(s);
		string w;
		while(ss>>w){
			if(stoi(w)>i){
				dscanh.push_back({i,stoi(w)});
			}
		}
		sort(dscanh.begin(),dscanh.end());
		for(auto x:dscanh){
			cout<<x.first<<' '<<x.second<<endl;
		}		
	}
}