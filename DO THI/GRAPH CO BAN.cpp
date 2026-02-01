#include<iostream>
#include<iomanip>

using namespace std;

int a[1005][1005];
int n,m;


int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		a[x][y]=a[y][x]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<endl;
	}
}