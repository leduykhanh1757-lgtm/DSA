#include<iostream>
#include<iomanip>

using namespace std;

int n,x[100],cot[100],xuoi[100],nguoc[100],dem;

void inkq(){
	for(int i=1;i<=n;i++){
		cout<<"CON HAU O HANG"<<" "<<i<<" "<<"NAM O COT "<<x[i]<<endl;
	}
	cout<<endl;
}

void Try(int i){
	for(int j=1;j<=n;j++){
		if(cot[j]==0&&xuoi[i-j+n]==0&&nguoc[i+j-1]==0){
			x[i]=j;
			cot[j]=xuoi[i-j+n]=nguoc[i+j-1]=1;
			if(i==n){
				dem++;
			}
			else Try(i+1);
			cot[j]=xuoi[i-j+n]=nguoc[i+j-1]=0;
		}
	}
}
int main(){
	cin>>n;
	Try(1);
	cout<<dem;
}