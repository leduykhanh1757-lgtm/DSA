#include<iostream>
#include<iomanip>

using namespace std;

int n,x[100],k,check=0,a[100][100];
string s;

void Try(int i,int j){
	if(i==n&&j==n){
		cout<<s<<endl;
		check=1;
	}
	if(i+1<=n&&a[i+1][j]==1){
		s+="D";
		Try(i+1,j);
		s.pop_back();
	}
	if(j+1<=n&&a[i][j+1]==1){
		s+="R";
		Try(i,j+1);
		s.pop_back();
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	Try(1,1);
}
/*
Cho một mê cung được mô tả dưới dạng một ma trận nhị phân có N hàng và N cột. 
Một con chuột bắt đầu tử ô (1, 1) và muốn di chuyển tới ô (N, N). 
Con chuột chỉ được di chuyển xuống dưới hoặc sang phải và chỉ được di chuyển tới ô nào đó nếu ô đó có giá trị là 1.
Bạn hãy in ra các cách đi hợp lệ của con chuột, trong đó nếu con chuột đi sang phải
thì nước đi được mô tả là chữ R, và nếu con chuột đi xuống dưới thì nước đi được mô tả là chữ D.
Nếu con chuột không thể đi xuống ô (N, N) thì in ra -1. Chú ý trên mỗi đường đi con chuột chỉ có thể đi qua 1 ô nào đó đúng 1 lần.
*/