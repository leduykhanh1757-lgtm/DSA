#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream> 

using namespace std;

struct SinhVien {
    string mssv;
    string ten;
    string nganh;
    float diemTB;
};
int binarySearch(const vector<SinhVien>& ds, string targetMSSV) {
    int left = 0;
    int right = ds.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (ds[mid].mssv == targetMSSV) return mid;
        if (ds[mid].mssv < targetMSSV) left = mid + 1;
        else right = mid - 1;
    }
    return -1; 
}

void inSinhVien(const SinhVien& sv) {
    cout << "\n--- KET QUA ---" << endl;
    cout << "MSSV: " << sv.mssv << endl;
    cout << "Ho ten: " << sv.ten << endl;
    cout << "Nganh: " << sv.nganh << endl;
    cout << "Diem TB: " << sv.diemTB << endl;
    cout << "---------------" << endl;
}

bool soSanhMSSV(const SinhVien& a, const SinhVien& b) {
    return a.mssv < b.mssv;
}
void docFile(vector<SinhVien>& ds) {
    ifstream fileInput("sinhvien.txt"); 

    if (!fileInput.is_open()) {
        cout << "Loi: Khong tim thay file sinhvien.txt!" << endl;
        return;
    }

    while (true) {
        SinhVien sv;
        fileInput >> sv.mssv; 
        if (fileInput.eof()) break;
        fileInput.ignore(); 
        getline(fileInput, sv.ten);
        getline(fileInput, sv.nganh);

        fileInput >> sv.diemTB;

        ds.push_back(sv);
    }
    
    fileInput.close();
    cout << ">> Da doc xong du lieu tu file (" << ds.size() << " sinh vien)." << endl;
}

int main() {
    vector<SinhVien> danhSachLop;
    int luaChon;

    cout << "CHON CACH NHAP DU LIEU:" << endl;
    cout << "1. Nhap tu ban phim" << endl;
    cout << "2. Doc tu file sinhvien.txt" << endl;
    cout << "Nhap lua chon (1 hoac 2): ";
    cin >> luaChon;

    if (luaChon == 1) {
        int n;
        cout << "Nhap so luong sinh vien: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            SinhVien sv;
            cout << "\nNhap thong tin sinh vien thu " << i + 1 << ":" << endl;
            cout << " - MSSV: "; cin >> sv.mssv;
            cin.ignore(); 
            cout << " - Ho ten: "; getline(cin, sv.ten);
            cout << " - Nganh: "; getline(cin, sv.nganh);
            cout << " - Diem TB: "; cin >> sv.diemTB;
            danhSachLop.push_back(sv);
        }
    } else if (luaChon == 2) {
        docFile(danhSachLop);
    } else {
        cout << "Lua chon khong hop le!" << endl;
        return 0;
    }
    if (!danhSachLop.empty()) {
        sort(danhSachLop.begin(), danhSachLop.end(), soSanhMSSV);
        cout << "\n(Danh sach da duoc sap xep tang dan theo MSSV)\n";

        string mssvCanTim;
        cout << "\nNhap MSSV can tim: ";
        cin >> mssvCanTim;
        
        int ketQua = binarySearch(danhSachLop, mssvCanTim);

        if (ketQua != -1) {
            cout << "TIM THAY SINH VIEN:";
            inSinhVien(danhSachLop[ketQua]);
        } else {
            cout << "\n=> Khong tim thay sinh vien co MSSV: " << mssvCanTim << endl;
        }
    } else {
        cout << "Danh sach trong!" << endl;
    }

    return 0;
}