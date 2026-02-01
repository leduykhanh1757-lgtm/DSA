#include<iostream>
#include<vector>
#include<algorithm>

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

void dfs(int u){
	visited[u]=1;
	for(int v:ke[u]){
		if(!visited[v]){
			dfs(v);
		}
	}
}

int main(){
	int cnt=0;
	nhap();
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			++cnt;
			dfs(i);
		}
	}
	int tru = 0;
	for(int i=1;i<=n;i++){
		memset(visited,0,sizeof(visited));
		int cnt2=0;
		visited[i]=1;
		for(int j=1;j<=n;j++){
			if(!visited[j]){
				++cnt2;
				dfs(j);
			}
		}
		if(cnt2 > cnt) ++tru;	
	}
	cout<<tru<<endl;
}