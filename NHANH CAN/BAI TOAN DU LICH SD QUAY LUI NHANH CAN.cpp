#include<iostream>
#include<iomanip>
#include<algorithm>
#include <climits>

using namespace std;

int n,c[105][105],X[1000];
int visited[1000];
int d=0, res = INT_MAX,d_min=INT_MAX;
 
void nhap(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
			if(c[i][j]!=0){
				d_min=min(d_min, c[i][j]);
			}
		}
	}
}

void Try(int i){
	for(int j=1;j<=n;j++){
		if(visited[j]==0){
			X[i]=j;
			visited[j]=1;
			int u = X[i-1];
			int v = X[i]; 
			d+=c[u][v];
			if(i==n){
				res = min(res,d+c[X[n]][1]);
			}
			else if(d+(n-i+1)*d_min<res){
				Try(i+1);
			}
			visited[j]=0;
			d-=c[u][v];
		}
	}
}

int main(){
	nhap();
	X[1]=1;
	visited[1]=1;
	Try(2);
	cout<<res<<endl;
}