#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findFirst(const vector<int>& a, int n, int x) {
    int left = 0, right = n - 1;
    int res = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) {
            res = mid;   
            right = mid - 1; 
        } else if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return res;
}

int findLast(const vector<int>& a, int n, int x) {
    int left = 0, right = n - 1;
    int res = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) {
            res = mid;      
            left = mid + 1; 
        } else if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return res;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int first = findFirst(a, n, x);
    int last = findLast(a, n, x);

    if (first != -1) {
        cout << last - first + 1 << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    int t;
    cin >> t; 
    while (t--) {
        solve(); 
    }
    return 0;
}