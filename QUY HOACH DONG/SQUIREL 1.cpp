#include<iostream>
#include<iomanip>

using namespace std;

int a[1000005];
long long F[1000005];

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	F[0]=0;
	F[1]=abs(a[1]-a[0]);
	for(int i=2;i<n;i++){
		F[i]=min(F[i-1]+abs(a[i]-a[i-1]),F[i-2]+abs(a[i]-a[i-2]));
	}
	cout<<F[n-1]<<endl;
}
/*
Có N nhóm hạt ngũ cốc được đánh số từ 1 tới N mỗi nhóm sẽ có lượng hạt ngũ cốc là A[i] với 1<=i<=N, một con sóc đang ở vị trí nhóm hạt số 1.
 Nhiệm vụ của nó là tới được nhóm hạt thứ N, chi phí mỗi lần di chuyển từ nhóm hạt x sang nhóm hạt y là abs(A[x] - A[y]),
  mỗi lần di chuyển con sóc chỉ có thể di chuyển từ nhóm hạt i sang nhóm hạt i + 1 hoặc i + 2.

Nhiệm vụ của bạn là tính số lượng ngũ cốc tối thiểu mà con sóc này phải tiêu tốn để có thể đi đến nhóm hạt thứ N
*/