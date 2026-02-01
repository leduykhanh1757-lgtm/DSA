#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

// Hàm tìm kiếm Fibonacci
int fibonacciSearch(vector<int>& arr, int x) {
    int n = arr.size();

    /* BƯỚC 1: Khởi tạo các số Fibonacci */
    // fibMMm2 là (m-2), fibMMm1 là (m-1), fibM là m
    int fibMMm2 = 0; 
    int fibMMm1 = 1; 
    int fibM = fibMMm2 + fibMMm1; 

    /* BƯỚC 2: Tìm số Fibonacci nhỏ nhất lớn hơn hoặc bằng kích thước mảng n */
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    // offset đánh dấu phạm vi đã bị loại bỏ ở phía trước mảng
    int offset = -1;

    /* BƯỚC 3: Vòng lặp kiểm tra các phần tử */
    while (fibM > 1) {
        // Kiểm tra xem vị trí (offset + fibMMm2) có hợp lệ không
        // Dùng min để đảm bảo không vượt quá biên mảng
        int i = min(offset + fibMMm2, n - 1);

        // Nếu x lớn hơn giá trị tại i -> Cắt bỏ phần từ offset đến i
        // Dời vùng tìm kiếm sang phải (xuống 1 bậc Fibonacci)
        if (arr[i] < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        // Nếu x nhỏ hơn giá trị tại i -> Cắt bỏ phần sau i
        // Dời vùng tìm kiếm sang trái (xuống 2 bậc Fibonacci)
        else if (arr[i] > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        // Nếu tìm thấy
        else {
            return i;
        }
    }

    /* BƯỚC 4: So sánh phần tử cuối cùng (trường hợp sót lại) */
    // Kiểm tra nếu fibMMm1 = 1 và phần tử tại offset+1 là x
    if (fibMMm1 == 1 && arr[offset + 1] == x) {
        return offset + 1;
    }

    // Không tìm thấy
    return -1;
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
    int x;
    cout << "Nhap gia tri can tim (x): ";
    cin >> x;
    int index = fibonacciSearch(arr, x);
    if (index != -1) {
        cout << "Tim thay gia tri " << x << " tai vi tri (index): " << index << endl;
    } else {
        cout << "Khong tim thay gia tri " << x << " trong mang." << endl;
    }

    return 0;
}