#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

struct SanPham {
    int maVach; 
    string tenSP;
    float gia;
    int soLuong;
};
int binarySearch(const vector<SanPham>& arr, int x, int& soBuoc) {
    int left = 0;
    int right = arr.size() - 1;
    soBuoc = 0; 

    while (left <= right) {
        soBuoc++;
        int mid = left + (right - left) / 2;

        if (arr[mid].maVach == x) return mid;
        if (arr[mid].maVach < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
int interpolationSearch(const vector<SanPham>& arr, int x, int& soBuoc) {
    int low = 0;
    int high = arr.size() - 1;
    soBuoc = 0;

    while (low <= high && x >= arr[low].maVach && x <= arr[high].maVach) {
        soBuoc++;

        if (low == high) {
            if (arr[low].maVach == x) return low;
            return -1;
        }

        int pos = low + (((double)(high - low) / 
                  (arr[high].maVach - arr[low].maVach)) * (x - arr[low].maVach));

        if (arr[pos].maVach == x) return pos;
        
        if (arr[pos].maVach < x) low = pos + 1;

        else high = pos - 1;
    }
    return -1;
}

void docFile(vector<SanPham>& ds) {
    ifstream fileInput("sanpham.txt");
    if (!fileInput.is_open()) {
        cout << "Loi: Khong tim thay file sanpham.txt!" << endl;
        return;
    }
    while (true) {
        SanPham sp;
        fileInput >> sp.maVach;
        if (fileInput.eof()) break;
        fileInput.ignore(); 
        getline(fileInput, sp.tenSP);
        fileInput >> sp.gia;
        fileInput >> sp.soLuong;
        ds.push_back(sp);
    }
    fileInput.close();
    cout << ">> Da doc xong " << ds.size() << " san pham tu file." << endl;
}
bool soSanhMaVach(const SanPham& a, const SanPham& b) {
    return a.maVach < b.maVach;
}

int main() {
    vector<SanPham> dsSanPham;

    cout << "1. Nhap tu ban phim\n2. Doc tu file sanpham.txt\nChon: ";
    int chon; cin >> chon;

    if (chon == 1) {
        int n;
        cout << "Nhap so luong san pham: "; cin >> n;
        for (int i = 0; i < n; i++) {
            SanPham sp;
            cout << "SP thu " << i+1 << " (Ma vach, Ten, Gia, SL): \n";
            cout << " - Ma vach: "; cin >> sp.maVach;
            cin.ignore();
            cout << " - Ten SP: "; getline(cin, sp.tenSP);
            cout << " - Gia: "; cin >> sp.gia;
            cout << " - So luong: "; cin >> sp.soLuong;
            dsSanPham.push_back(sp);
        }
    } else {
        docFile(dsSanPham);
    }
    sort(dsSanPham.begin(), dsSanPham.end(), soSanhMaVach);
    int maCanTim;
    cout << "\nNhap Ma vach can tim: ";
    cin >> maCanTim;

    cout << "\n--- KET QUA SO SANH ---" << endl;

    //Binary Search
    int buocBinary = 0;
    int kqBinary = binarySearch(dsSanPham, maCanTim, buocBinary);
    cout << "Binary Search: ";
    if (kqBinary != -1) cout << "Tim thay tai index " << kqBinary;
    else cout << "Khong tim thay";
    cout << " | So buoc thuc hien: " << buocBinary << endl;

    //Interpolation Search
    int buocInter = 0;
    int kqInter = interpolationSearch(dsSanPham, maCanTim, buocInter);
    cout << "Interpolation Search: ";
    if (kqInter != -1) cout << "Tim thay tai index " << kqInter;
    else cout << "Khong tim thay";
    cout << " | So buoc thuc hien: " << buocInter << endl;

    if (kqInter != -1) {
        cout << "\n>> Thong tin san pham: " << dsSanPham[kqInter].tenSP 
             << " - Gia: " << dsSanPham[kqInter].gia << endl;
    }

    return 0;
}