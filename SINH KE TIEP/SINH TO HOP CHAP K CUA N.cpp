#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;


int n,k,a[100],ok;

void ktao(){
	for(int i=1;i<=k;i++){
		a[i] = i;
	}
}

void sinh(){
	int i = k;
	while(i>=1 && a[i]==n-k+i){
		i--;
	}
	if(i==0){
		ok = 0;
	}
	else{
		a[i]++;
		for(int j = i+1;j<=n;j++){
			a[j] = a[j-1] + 1; 
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		ktao();
		ok =1;
		while(ok){
			for(int i=1;i<=k;i++){
				cout<<a[i];
			}
			sinh();
			cout<<" ";
		}
		cout<<endl;
	}
}
/*
Ban đầu, mảng a được khởi tạo thành {1,2,…,k} tức là tổ hợp nhỏ nhất, chọn k phần tử đầu tiên của tập.
Duyệt từ cuối về đầu, tìm phần tử a[i] sao cho a[i]<n−k+i. Nếu không tìm thấy, nghĩa là tất cả các phần tử đã đạt giá trị lớn nhất có thể, và cấu hình hiện tại là cấu hình cuối cùng.
Tăng giá trị của a[i] lên a[i]+1
Đặt a[j]=a[j−1]+1 cho tất cả j>i để đảm bảo dãy tăng dần.
*/