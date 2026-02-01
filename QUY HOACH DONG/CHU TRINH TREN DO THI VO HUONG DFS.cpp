#include<bits/stdc++.h>

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
}

bool dfs(int u){
	visited[u]=1;
	for(int v:ke[u]){
		if(visited[v] && v!= parent[u] ){
			return true;
		}
		if(!visited[v]){
			parent[v]=u;
			if(dfs(v)) return true;
		}
	}
	return false;
}

bool BFS(int u){
	queue<int> q;
	q.push(u);
	visited[u]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int y:ke[x]){
			if(visited[y] && y!= parent[x] ){
				return true;
			}
			if(!visited[y]){
				q.push(y);
				visited[y]=1;
				parent[y]=x;
			}
		}
	}
	return false;
}

int main(){
	nhap();
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			if(dfs(i)){
				cout<<1<<endl;
				return 0;
			}
		}
	}
	cout<<0<<endl;
}