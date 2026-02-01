#include<iostream>
#include<iomanip>

using namespace std;

int n,x[100];

void inkq(){
	for(int i=1;i<=n;i++){
		cout<<x[i];
	}
	cout<<endl;
}

void Try(int i){
	for(int j=0;j<=1;j++){
		x[i]=j;
		if(i==n){
			inkq();
		}
		else{
			Try(i+1);
		}
	}
}
int main(){
	cin>>n;
	Try(1);
}
/*
Sử dụng kỹ thuật quay lui (backtracking), xây dựng dãy nhị phân từng phần tử một.
Với mỗi vị trí i trong dãy, thử hai khả năng x[i]=0 và x[i]=1, sau đó tiếp tục xử lý các vị trí tiếp theo.
Hàm Try(int i):
Với mỗi vị trí i, lần lượt gán x[i]=0 và x[i]=1
Nếu đã đến vị trí cuối cùng (i=n), in kết quả.
Nếu chưa, tiếp tục thử với vị trí tiếp theo (i+1). In kq
Bắt đầu từ Try(1), chương trình sẽ duyệt qua toàn bộ không gian các dãy nhị phân độ dài nnn.
*/
