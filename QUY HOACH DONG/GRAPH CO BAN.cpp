#include<iostream>
#include<vector>

using namespace std;

int a[1005][1005];
int n,m;
int visited[1005];
vector<int> ke[1005];
vector<pair<int,int>>dscanh;

void DFS(int u){
	cout<<u<<' ';
	visited[u]=1;
	for(int v:ke[u]){
		if(!visited[v]){
			DFS(v);
		}
	}
}

/*void DFS(int u){
	cout<<u<<' ';
	visited[u]=1;
	for(int v = 1;v<=n;v++){
		if(a[u][v]==1 && !visited[v]){
			DFS(v);
		}
	}
}

void DFS(int u){
	cout<<u<<' ';
	visited[u]=1;
	for(pair<int,int> e:dscanh){
		if(x.first==u&&!visited[x.second]){
			DFS(x.second);
		}
		if(x.second==u&&!visited[x.first]){
			DFS(x.first);
		}
	}
}

/*
9 7
1 2
2 7
2 6
5 2
1 3
3 4
8 9
*/

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		ke[x].push_back(y);
		ke[y].push_back(x);
		dscanh.push_back({x,y});
	}
	for(int i=1;i<=n;i++){
		cout<<i<< ":";
		for(int x:ke[i]){
			cout<<x<<" ";
		}
		cout<<endl;
	}
}