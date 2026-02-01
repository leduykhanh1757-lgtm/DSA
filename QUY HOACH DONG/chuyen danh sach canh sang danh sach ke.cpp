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