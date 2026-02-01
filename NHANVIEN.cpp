#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cmath> 

using namespace std;

struct NhanVien {
    string maNV;
    string ten;
    string phongBan;
    int luong;
};

void docFile(vector<NhanVien>& ds) {
    ifstream f("nhanvien.txt");
    if (!f.is_open()) {
        cout << "Loi: Khong mo duoc file nhanvien.txt" << endl;
        return;
    }
    while (true) {
        NhanVien nv;
        getline(f, nv.maNV);
        if (f.eof()) break; 
        getline(f, nv.ten);
        getline(f, nv.phongBan);
        f >> nv.luong;
        f.ignore(); 
        ds.push_back(nv);
    }
    f.close();
    cout << ">> Da doc xong " << ds.size() << " nhan vien." << endl;
}

void inDanhSach(const vector<NhanVien>& ds) {
    for (const auto& nv : ds) {
        cout << nv.maNV << " - " << nv.ten << " - " << nv.phongBan << " - " << nv.luong << endl;
    }
}

bool soSanhTen(const NhanVien& a, const NhanVien& b) {
    return a.ten < b.ten;
}

void timCacPhanTuTrung(const vector<NhanVien>& ds, int index, string tenCanTim) {
    if (index == -1) {
        cout << "=> Khong tim thay nhan vien: " << tenCanTim << endl;
        return;
    }

    cout << "\nKET QUA TIM KIEM:" << endl;

    int left = index;
    while (left >= 0 && ds[left].ten == tenCanTim) {
        left--;
    }

    int right = index;
    while (right < ds.size() && ds[right].ten == tenCanTim) {
        right++;
    }

    for (int i = left + 1; i < right; i++) {
        cout << "  Found: " << ds[i].maNV << " | " << ds[i].ten 
             << " | " << ds[i].phongBan << " | " << ds[i].luong << "$" << endl;
    }
}

int jumpSearch(const vector<NhanVien>& ds, string x) {
    int n = ds.size();
    int step = sqrt(n);
    int prev = 0;

    while (ds[min(step, n) - 1].ten < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }

    while (ds[prev].ten < x) {
        prev++;
        if (prev == min(step, n)) return -1;
    }

    if (ds[prev].ten == x) return prev;
    return -1;
}

int fibonacciSearch(const vector<NhanVien>& ds, string x) {
    int n = ds.size();

    int fibMM2 = 0; 
    int fibMM1 = 1; 
    int fibM = fibMM2 + fibMM1; 

    while (fibM < n) {
        fibMM2 = fibMM1;
        fibMM1 = fibM;
        fibM = fibMM2 + fibMM1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fibMM2, n - 1);

        if (ds[i].ten < x) {
            fibM = fibMM1;
            fibMM1 = fibMM2;
            fibMM2 = fibM - fibMM1;
            offset = i;
        } 
        else if (ds[i].ten > x) {
            fibM = fibMM2;
            fibMM1 = fibMM1 - fibMM2;
            fibMM2 = fibM - fibMM1;
        } 
        else {
            return i;
        }
    }

    if (fibMM1 && offset + 1 < n && ds[offset + 1].ten == x) {
        return offset + 1;
    }

    return -1;
}

int main() {
    vector<NhanVien> dsNhanVien;

    docFile(dsNhanVien);

    if (dsNhanVien.empty()) return 0;

    sort(dsNhanVien.begin(), dsNhanVien.end(), soSanhTen);
    cout << "(Danh sach da duoc tu dong sap xep theo Ten de thuc hien thuat toan)\n";

    string tenCanTim;
    cout << "\nNhap ten nhan vien can tim (VD: Nguyen Van A): ";
    getline(cin, tenCanTim);

    cout << "\n--- CHON THUAT TOAN ---\n";
    cout << "1. Jumping Search\n";
    cout << "2. Fibonacci Search\n";
    cout << "Chon: ";
    int chon; cin >> chon;

    int ketQua = -1;
    if (chon == 1) {
        ketQua = jumpSearch(dsNhanVien, tenCanTim);
    } else {
        ketQua = fibonacciSearch(dsNhanVien, tenCanTim);
    }

    timCacPhanTuTrung(dsNhanVien, ketQua, tenCanTim);

    return 0;
}