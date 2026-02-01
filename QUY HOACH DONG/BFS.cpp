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

/*void BFS(int u){
	queue<int> q;
	q.push(u);
	visited[u]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		cout<<x<<" ";
		for(int y:ke[x]){
			if(!visited[y]){
				q.push(y);
				visited[y]=1;
			}
		}
	}
}*/


int main(){
	nhap();
	for(int i=1;i<=n;i++){
		cout<< i <<" : ";
		for(int x:ke[i]){
			cout<<x<<" ";
		}
		cout<<endl;
	}
}