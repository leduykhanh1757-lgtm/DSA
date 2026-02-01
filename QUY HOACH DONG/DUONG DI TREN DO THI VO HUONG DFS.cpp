#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,m,s,t;
vector<int> ke[10005];
int visited[10005];
int parent[10005];

void nhap(){
	cin>>n>>m>>s>>t;
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

void dfs(int u){
	visited[u]=1;
	for(int v:ke[u]){
		if(!visited[v]){
			dfs(v);
			parent[v]=u;
		}
	}
}

int main(){
	nhap();
	dfs(s);
	if(visited[t]){
		vector<int> res;
		while(t!=s){
			res.push_back(t);
			t=parent[t];	
		}
		res.push_back(s);
		reverse(res.begin(),res.end());
		for(int x:res){
			cout<<x<<" ";
		}
	}
	else{
		cout<<-1<<endl;
	}
}