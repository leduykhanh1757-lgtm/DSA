#include<bits/stdc++.h>
using namespace std;

long n,M;
struct data{
	long w, val;
};

data a[200];
bool cmp(data a, data b){
	return(float)a.val/a.w > (float)b.val/b.w;
}

long nhanhcan(int i, long  w , long val)
{
    if(w > M)
        return 0;
    if(i == n)
    {
        if(w <= M)
        return val;
        else return 0;
    }
        int l = nhanhcan(i + 1 ,w + a[i].w, val + a[i].val);
        int r = nhanhcan(i + 1, w , val);
        return max(l ,r);
}
    
int main(){
	cin>>n>>M;
	for(int i=0;i<n;i++){
		cin>>a[i].w>>a[i].val;
	}
	sort(a,a+n,cmp);
	
	cout<<nhanhcan(0,0,0);
	return 0;
}