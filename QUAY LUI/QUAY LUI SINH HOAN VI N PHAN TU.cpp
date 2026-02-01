#include<iostream>
#include<iomanip>
#include<algorithm>

using namespace std;

int n,x[100],used[100];

void inkq(){
	for(int i=1;i<=n;i++){
		cout<<x[i];
	}
	cout<<endl;
}

void Try(int i){
	// Duyệt các khả năng mà x[i] có thể nhận được
	for(int j=1;j<=n;j++){
		// xét xem liệu rằng có thể gán x[i]=j hay không 
		if(used[j]==0){
			x[i]=j;
			used[j]=1;// đánh dấu
			if(i==n){
				inkq();
			}
			else{
				Try(i+1);
			}
			//backtrack
			used[j]=0;
		}
	}
}
int main(){
	cin>>n;
	Try(1);
}
/*
Xây dựng dãy x từng phần tử, tại mỗi bước i, chọn giá trị j chưa được sử dụng từ tập {1,2,…,n}
Đánh dấu giá trị j là đã sử dụng bằng mảng used.
Khi i==n dãy x hoàn chỉnh, in ra kết quả.
Sau khi thử giá trị j ở bước i, quay lui bằng cách bỏ đánh dấu used[j]=0, để tiếp tục thử giá trị khác.
Hàm Try(i):
	i: vị trí hiện tại đang gán giá trị trong dãy hoán vị x
	Duyệt qua tất cả các giá trị j từ 1 đến n:
	Nếu j chưa được sử dụng (used[j]=0):
	Gán x[i]=j, đánh dấu used[j]=1
	Nếu i==n nghĩa là đã hoàn tất dãy hoán vị, in kết quả.
	Nếu chưa, gọi đệ quy Try(i+1) để tiếp tục gán giá trị cho vị trí tiếp theo.
	Backtrack: Bỏ đánh dấu used[j]=0 để thử giá trị khác.
*/
