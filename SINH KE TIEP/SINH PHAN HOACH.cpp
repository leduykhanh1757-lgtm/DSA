#include<iostream>

using namespace std;

int n,a[100],dem,ok; // dem là số số hạng trong cái dãy tổng

void ktao(){
	dem=1;// khởi tạo đếm ban đầu bằng chính n
	a[1]=n;
}

void sinh(){
	int i=dem;
	while(i>=1&&a[i]==1){// nếu a[i] bằng 1 thì duyệt tiếp
		--i;
	}
	if(i==0){
		ok = 0;
	}
	else{
		--a[i];// giảm giá trị a[i] đi 1
		int d=dem-i+1;// phần bù còn thiếu để ra đc tổng là n
		dem=i;// cập nhật dem là i hiện tại 
		int q = d / a[i],r = d % a[i];// kiểm tra phần bù so với a[i] gấp mấy lần
		if(q){
			for(int j = 1;j<=q;j++){
				++dem;
				a[dem]=a[i];// viết q lần thằng a[i] vào đằng sau
			}
		}
		if(r){// nếu vẫn còn dư
			++dem;
			a[dem]=r;// viết thêm thằng dư ở cuối
		}
	}
}

int main(){
	cin>>n;
	ktao();
	ok =1;
	while(ok){
		for(int i=1;i<=dem;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
		sinh();
	}
}