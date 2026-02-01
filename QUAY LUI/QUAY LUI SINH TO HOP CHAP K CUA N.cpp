#include<iostream>
#include<iomanip>

using namespace std;

int n,x[100],k;

void inkq(){
	for(int i=1;i<=k;i++){
		cout<<x[i];
	}
	cout<<endl;
}

void Try(int i){
	for(int j=x[i-1]+1;j<=n-k+i;j++){
		x[i]=j;
		if(i==k){
			inkq();
		}
		else{
			Try(i+1);
		}
	}
}
int main(){
	cin>>n>>k;
	Try(1);
}
/*
Hàm Try(int i):
Tại vị trí i, duyệt các giá trị j từ x[i−1]+1 đến n−k+i
Gán x[i]=j, sau đó:
Nếu i==k, tức là đã chọn đủ k phần tử, thì in kết quả.
Nếu chưa, gọi đệ quy cho vị trí tiếp theo (i+1).
In dãy x[1],x[2],…,x[k]  đại diện cho một tổ hợp.
Điều kiện biên:
Mảng x được khởi tạo với x[0]=0 (giá trị giả) để đảm bảo tính hợp lệ khi kiểm tra x[i−1]+1
*/
