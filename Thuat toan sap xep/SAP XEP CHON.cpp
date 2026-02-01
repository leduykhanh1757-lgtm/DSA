#include<bits/stdc++.h>

using namespace std;

void selectionSort(int a[],int n){
	vector<string> results;
	for(int i=0;i<n-1;i++){
		// dùng 1 biến để chỉ số của phần tử nhỏ nhất
		int min_pos = i;
		// duyệt tất cả các phần tử đứng sau phần tử hiện tại và cập nhật chỉ số của phần tử nhỏ nhất
		for(int j = i+1;j<n;j++){
			if(a[j]<a[min_pos]){
				min_pos = j;
			}
		}
		swap(a[i],a[min_pos]);
		
		string s = "Buoc "+ to_string(i+1)+": ";
		for(int x = 0; x<n;x++){
			s+=to_string(a[x]) + " ";
		}
		results.push_back(s);
	}
	for(int i = results.size()-1;i>=0;i--){
		cout<<results[i]<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	selectionSort(a,n);
}