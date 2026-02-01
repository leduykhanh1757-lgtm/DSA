#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int n,a[100],ok;

void ktao(){// n bít 0
	for(int i=1;i<=n;i++){
		a[i]=0;
	}	
}

void sinh(){
	// bắt dầu từ bit cuối cùng và đi tìm bít 0 đầu tiên
	int i=n;
	while(a[i]>=1&&a[i]==1){
		a[i]=0;
		i--;
	}
	if(i==0){
		ok=0;// day chính là cấu hình cuối cùng
	}
	else{
		a[i]=1;
	}
}
int main(){
	cin>>n;
	ok=1;
	ktao();
	while(ok){
		for(int i =1; i<=n;i++){
			cout<<a[i];
		}
		cout<<endl;
		sinh();
	}
}
/*
Ban đầu, tất cả các bit của mảng a được đặt bằng 0. Đây là cấu hình nhị phân đầu tiên: 000..0 (tất cả các bit đều là 0).
Thuật toán tìm bit 0 đầu tiên từ cuối dãy và đổi nó thành 1. Đồng thời, tất cả các bit bên phải bit này sẽ được đặt lại thành 0
Nếu không còn bit 0 nào (tất cả bit đã là 1), dãy hiện tại là cấu hình cuối cùng, và biến ok được đặt bằng 0 để dừng vòng lặp.
*/