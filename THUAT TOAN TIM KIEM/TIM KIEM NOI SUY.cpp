#include <iostream>
#include <vector>

using namespace std;

// Hàm tìm kiếm nội suy
int interpolationSearch(vector<int>& arr, int value) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right && value >= arr[left] && value <= arr[right]) {
        // 1. Tính tử số (có ép kiểu long long để tránh tràn số)
        long long numerator = (long long)(value - arr[left]) * (right - left);
        // 2. Tính mẫu số
        int denominator = (arr[right] - arr[left]);
        // 3. Tránh lỗi chia cho 0 (khi tất cả phần tử bằng nhau hoặc còn 1 phần tử)
        if (denominator == 0) {
            if (arr[left] == value) {
                return left;
            } else {
                return -1;
            }
        }
        // 4. Tính vị trí mid
        int mid = left + (numerator / denominator);
        // Kiểm tra giá trị tại mid
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] < value) {
            left = mid + 1; // Tìm nửa phải
        } else {
            right = mid - 1; // Tìm nửa trái
        }
    }
    return -1; // Không tìm thấy
}

int main() {
    int n;
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Nhap cac phan tu (bat buoc phai sap xep tang dan): " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int value;
    cout << "Nhap gia tri can tim (value): ";
    cin >> value;
    int index = interpolationSearch(arr, value);
    if (index != -1) {
        cout << "Tim thay gia tri " << value << " tai vi tri (index): " << index << endl;
    } else {
        cout << "Khong tim thay gia tri " << value << " trong mang." << endl;
    }

    return 0;
}