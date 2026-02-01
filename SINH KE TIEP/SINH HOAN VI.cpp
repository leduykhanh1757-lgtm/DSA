#include<iostream>
#include<iomanip>
#include<algorithm>

using namespace std;

int n,a[100],ok;

void ktao(){
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
}
void sinh(){
	int i = n-1;
	while(i>=1 && a[i]>a[i+1]){
		i--;
	}
	if(i==0){
		ok=0;
	}
	else{
		// đi tìm thằng lớn hơn a[i] trong [i+1,n]
		int j = n;
		while(a[i]>a[j]) j--;
		swap(a[i],a[j]);
		int l = i+1, r= n;
		while(l<r){
			swap(a[l],a[r]);
			l++;r--;
		}
	}
}
int main(){
	int dem =1;
	cin>>n;
	ktao();
	ok = 1;
	while(ok){
		cout<<dem<<": ";
		for(int i = 1;i<=n;i++){
			cout<<a[i]<<" ";
		}
		sinh();
		dem++;
		cout<<endl;
	}
}
/*
Mảng a được khởi tạo thành {1,2,3,…,n}tức là cấu hình ban đầu là hoán vị tăng dần nhỏ nhất.
Duyệt từ phải sang trái (từ n−1đến 1) để tìm phần tử đầu tiên a[i] mà a[i]<a[i+1] .Nếu không tìm thấy (tức là i=0), nghĩa là cấu hình hiện tại là cấu hình cuối cùng, đặt ok=0 để dừng vòng lặp.
Duyệt từ phải sang trái (từ n) để tìm phần tử a[j] nhỏ nhất mà a[i]<a[j]
Hoán đổi giá trị của a[i] và a[j]
Đảo ngược thứ tự các phần tử trong đoạn từ a[i+1] đến a[n] để đảm bảo tạo ra hoán vị tiếp theo nhỏ nhất.
*/
