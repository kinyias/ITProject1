#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <conio.h>
#include<iomanip>
#include<fstream>
using namespace std;

// Cấu trúc lưu thông tin mặt hàng
struct MatHang {
    char ten[20]; // Tên mặt hàng
    int gia; // Giá mặt hàng
    int soLuong; // Số lượng còn lại trong kho
    char hanSuDung[11]; // dd/mm/yyyy
};

// Cấu trúc danh sách mặt hàng
struct Node {
    MatHang data;
    Node* link;
};
typedef Node* Nodeptr;

void khoiTao(Nodeptr& list);
int isEmpty(Nodeptr list);
void giaiPhong(Nodeptr& list);
//1. Nhập danh sách n mặt hàng với đầy đủ các thông tin trên.
Nodeptr tao_Node_MatHang(MatHang mathang);
Nodeptr them_MatHang(Nodeptr& list, MatHang mathang);
void nhap_DanhSachMatHang(Nodeptr& list);
void xuat_DanhSachMatHang(Nodeptr list);

//2. Sắp xếp danh sách các mặt hàng theo giá mặt hàng tăng dần, nếu cùng giá thì sắp xếp theo tên mặt
//hàng và xuất ra màn hình
void sapXep_DSTangDan(Nodeptr& list);

//3. Xóa 1 mặt hàng khỏi danh sách
void xoa_MatHang(Nodeptr& list,char* ten);
//4. Thêm 1 mặt hàng vào cuối danh sách
Nodeptr them_MatHangCuoi(Nodeptr& list);
//5. Xuất ra màn hình thông tin mặt hàng là bội của 7
void xuat_MatHangBoi7(Nodeptr list);
//6. Tìm mặt hàng có số lượng lớn nhất
Nodeptr timMatHangCoSoLuongLonNhat(Nodeptr list);
void xuat_ThongTinMotMatHangCoSoLuongLonNhat(Nodeptr list);
//7. Nhập vào một mặt hàng và kiểm tra trong kho xem mặt hàng này còn hay hết.
void kiemtra_TinhTrangMatHang(Nodeptr list, const char* ten);
//8. Tìm trong danh sách những mặt hàng hết hạn sử dụng.Nếu có thì xóa mặt hàng này khỏi danh
//sách.
void xoa_MatHangHetHan(Nodeptr& list);
void thongKeHetHanSuDung(Nodeptr list);

//9. Thống kê những mặt hàng còn hạn sử dụng trong danh sách.
bool conHanSuDung(Nodeptr matHang);
void thongKeHanSuDung(Nodeptr list);
//10. Xuất thông tin các mặt hàng trong danh sách vào file text
void xuat_ThongTinRaFile(Nodeptr danhSach, const char* tenFile);

void pressAnyKey();