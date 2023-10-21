#include "ThaiTinKhang.h"

int main() {
    int key;
    Nodeptr dsmh;
    khoiTao(dsmh);
    while (true) {
        cout << "CHUONG TRINH DANH SACH HANG HOA C/C++\n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Them n mat hang.                              **\n";
        cout << "**  2. Sap xep hang hoa tang dan.                    **\n";
        cout << "**  3. Xoa 1 mat hang khoi danh sach.                **\n";
        cout << "**  4. Them 1 mat hang vao cuoi danh sach.           **\n";
        cout << "**  5. Xuat ra thong tin mat hang la boi cua 7.      **\n";
        cout << "**  6. Tim mat hang co so luong lon nhat.            **\n";
        cout << "**  7. Kiem tra mat hang ton kho.                    **\n";
        cout << "**  8. Tim va xoa nhung mat hang het hsd.            **\n";
        cout << "**  9. Thong ke nhung mat hang con hsd.              **\n";
        cout << "**  10. Xuat danh sach mat hang ra file text         **\n";
        cout << "**  0. Thoat                                         **\n";
        cout << "*******************************************************\n";
        cout << "Chon chuc nang: ";
        if (cin >> key) {
        }
        else {
            cout << "Oops có lỗi! Bạn phải nhập kí tự số. Mời bạn khởi động lại chương trình" << endl;
        }
        switch (key) {
        case 1:
            nhap_DanhSachMatHang(dsmh);
            xuat_DanhSachMatHang(dsmh);
            pressAnyKey();
            break;
        case 2:
            if (dsmh != NULL) {
                sapXep_DSTangDan(dsmh);
            }
            else {
                cout << "\nDanh sach mat hang trong!";
            }
            pressAnyKey();
            break;
        case 3:
            if (dsmh != NULL) {
                char ten[20];
                cin.ignore();
                cout << "Nhap ten mat hang can xoa: ";
                cin.getline(ten, 20);
                xoa_MatHang(dsmh, ten);
            }
            else {
                cout << "\nDanh sach mat hang trong!";
            }
            pressAnyKey();
            break;
        case 4:
            them_MatHangCuoi(dsmh);
            pressAnyKey();
            break;
        case 5:
            if (dsmh != NULL) {
                xuat_MatHangBoi7(dsmh);
            }
            else {
                cout << "\nDanh sach mat hang trong!";
            }
            pressAnyKey();
            break;
        case 6:
            if (dsmh != NULL) {
                xuat_ThongTinMotMatHangCoSoLuongLonNhat(dsmh);
            }
            else {
                cout << "\nDanh sach mat hang trong!";
            }
            pressAnyKey();
            break;
        case 7:
            if (dsmh != NULL) {
                char tenMatHang[20];
                cin.ignore();
                cout << "Nhap ten mat hang can kiem tra: ";
                cin.getline(tenMatHang, 20);
                kiemtra_TinhTrangMatHang(dsmh, tenMatHang);
            }
            else {
                cout << "\nDanh sach mat hang trong!";
            }
            pressAnyKey();
            break;
        case 8:
            if (dsmh != NULL) {
                thongKeHetHanSuDung(dsmh);
            }
            else {
                cout << "\nDanh sach mat hang trong!";
            }
            pressAnyKey();
            break;
        case 9:
            if (dsmh != NULL) {
                thongKeHanSuDung(dsmh);
            }
            else {
                cout << "\nDanh sach mat hang trong!";
            }
            pressAnyKey();
            break;
        case 10:
            if (dsmh != NULL) {
                xuat_ThongTinRaFile(dsmh, "danhsachmathang.txt");
            }
            else {
                cout << "\nDanh sach mat hang trong!";
            }
            pressAnyKey();
            break;
        case 11:
            if (dsmh != NULL) {
                xuat_DanhSachMatHang(dsmh);
            }
            else {
                cout << "\nDanh sach mat hang trong!";
            }
            pressAnyKey();
            break;
        case 0:
            cout << "\nBan da chon thoat khoi chuong trinh";
            giaiPhong(dsmh);
            return 0;
        default:
            cout << "\nKhong co chuc nang nay!";
            cout << "\nHay chon chuc nang trong hop menu.";
            pressAnyKey();
            break;
        }
    }
    giaiPhong(dsmh);
    return 0;
}