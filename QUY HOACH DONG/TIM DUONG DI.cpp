#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,m;
vector<int> ke[10005];
int visited[10005];
int TPLT[10005];
int cnt=0;

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

void dfs(int u){
	visited[u]=1;
	TPLT[u]=cnt;
	for(int v:ke[u]){
		if(!visited[v]){
			dfs(v);
		}
	}
}

int main(){
	nhap();
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			++cnt;
			dfs(i);
		}
	}
	int q;
	cin>>q;
	while(q--){
		int u,v;
		cin>>u>>v;
		if(TPLT[u]==TPLT[v]){
			cout<<1<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
}