#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,m;
vector<int> ke[10005];
int visited[10005];
vector<pair<int,int>> dscanh;

void nhap(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		ke[x].push_back(y);
		ke[y].push_back(x);
		dscanh.push_back({x,y});
	}
}

void dfs(int u,int x,int y){
	visited[u]=1;
	for(int v:ke[u]){
		if((u==x&&v==y)||(u==y&&v==x)){
			continue;
		}
		if(!visited[v]){
			dfs(v,x,y);
		}
	}
}

int main(){
	int cnt=0;
	nhap();
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			++cnt;
			dfs(i,0,0);
		}
	}
	int cau = 0;
	for(auto e:dscanh){
		int x=e.first,y=e.second;
		memset(visited,0,sizeof(visited));
		int cnt2=0;
		for(int j=1;j<=n;j++){
			if(!visited[j]){
				++cnt2;
				dfs(j,x,y);
			}
		}
		if(cnt2 > cnt) ++cau;	
	}
	cout<<cau<<endl;
}