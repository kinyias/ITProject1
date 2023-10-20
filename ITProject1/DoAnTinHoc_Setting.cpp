#include "DoAnTinHoc.h"
void khoiTao(Nodeptr& list) {
	list = NULL;
}

int isEmpty(Nodeptr list) {
	return list == NULL ? 1 : 0;
}
void giaiPhong(Nodeptr& list) {
	Nodeptr p = list;
	while (p != NULL) {
		list = list->link;
		delete p;
		p = list;
	}
}

//1. Nhập danh sách n mặt hàng với đầy đủ các thông tin trên.
Nodeptr tao_Node_MatHang(MatHang mh) {
	Nodeptr p = new Node;
	p->data = mh;
	p->link = NULL;
	return p;
}
Nodeptr them_MatHang(Nodeptr& list, MatHang mh) {
	Nodeptr p = tao_Node_MatHang(mh);
	p->link = list;
	list = p;
	return p;
}

bool kiemTra_TrungTen(Nodeptr list, char* ten) {
	Nodeptr p = list;
	while (p != NULL) {
		if (strcmp(p->data.ten, ten) == 0) return true;
		p = p->link;
	}
	return false;
}
void nhap_DanhSachMatHang(Nodeptr& list) {
	MatHang mh;
	int n; // n mặt hàng cần nhập
	khoiTao(list);
	cout << "\nSo luong mat hang can nhap: ";
	cin >> n;
	cin.ignore();
	for (int i = 1; i <= n; i++) {
		cout << "\nNhap thong tin mat hang thu " << i<<": ";
		cout << "\nTen mat hang: ";
		cin.getline(mh.ten, 20);
		while (kiemTra_TrungTen(list, mh.ten)) {
			cout << "Ten mat hang bi trung";
			cout << "\nNhap lai ten mat hang: ";
			cin.getline(mh.ten, 20);
		}
		cout << "Nhap gia: ";
		cin >> mh.gia;
		cout << "Nhap so luong con lai: ";
		cin >> mh.soLuong;
		cout << "Nhap han su dung: ";
		cin >> mh.hanSuDung;
		cin.ignore();
		them_MatHang(list, mh);
	}
}

void xuat_DanhSachMatHang(Nodeptr list){
	cout << "--------------------------------------------------------------" << endl;
	cout << left << setw(20) << "Ten" << setw(20) << "Gia" << setw(10) << "SL" << setw(20) << "HSD"<<setw(25)<< endl;
	cout << "--------------------------------------------------------------" << endl;
	while (list != NULL) {
		cout << left << setw(20) << list->data.ten << setw(20) << list->data.gia << setw(10) << list->data.soLuong << setw(20) << list->data.hanSuDung << endl;
		list = list->link;
	}
	cout << "--------------------------------------------------------------" << endl;
}
//2. Sắp xếp danh sách các mặt hàng theo giá mặt hàng tăng dần, nếu cùng giá thì sắp xếp theo tên mặt
//hàng và xuất ra màn hình
void sapXep_DSTangDan(Nodeptr& list) {
	for (Nodeptr i = list; i != NULL; i = i->link) {
		for (Nodeptr j = i->link; j != NULL; j = j->link) {
			if (i->data.gia > j->data.gia || (i->data.gia == j ->data.gia && strcmp(i->data.ten, j->data.ten) > 0)){
				swap(i->data.ten, j->data.ten);
				swap(i->data.gia, j->data.gia);
				swap(i->data.soLuong, j->data.soLuong);
				swap(i->data.hanSuDung, j->data.hanSuDung);
			}
		}
	}
	xuat_DanhSachMatHang(list);
}

//3. Xóa 1 mặt hàng khỏi danh sách
void xoa_MatHang(Nodeptr& list, char* ten) {
	if(strcmp(list->data.ten, ten) ==0){
		Nodeptr p = list;
		list = list->link;
		delete p;
		cout << "Xoa thanh cong\n";
	}
	else {
		Nodeptr p, before;
		p = list;
		before = list;
		while (p != NULL && strcmp(p->data.ten, ten) != 0) {
			before = p;
			p = p->link;
		}
		if (p != NULL) {
			before->link = p->link;
			delete p;
			cout << "Xoa thanh cong\n";
		}
		else {
			cout << "Khong tim thay mat hang de xoa\n";
		}
	}

	xuat_DanhSachMatHang(list);
}
//4. Thêm 1 mặt hàng vào cuối danh sách
Nodeptr them_MatHangCuoi(Nodeptr& list) {
	MatHang mh;
	cin.ignore();
	cout << "\nTen mat hang: ";
	cin.getline(mh.ten, 20);
	while (kiemTra_TrungTen(list, mh.ten)) {
		cout << "Ten mat hang bi trung";
		cout << "\nNhap lai ten mat hang: ";
		cin.getline(mh.ten, 20);
	}
	cout << "Nhap gia: ";
	cin >> mh.gia;
	cout << "Nhap so luong con lai: ";
	cin >> mh.soLuong;
	cout << "Nhap han su dung: ";
	cin >> mh.hanSuDung;
	cin.ignore();

	//Thêm node mặt hàng vào cuối danh sách 
	Nodeptr p = tao_Node_MatHang(mh);
	if (list == NULL) list = p;
	else {
		Nodeptr q = list;
		while (q->link != NULL) {
			q = q->link;
		}
		q->link = p;
	}
	return p;
}
//5. Xuất ra màn hình thông tin mặt hàng là bội của 7
void xuat_MatHangBoi7(Nodeptr list) {
	Nodeptr p = list;
	while (p != NULL) {
		if (p->data.gia % 7 == 0) {
			cout << "Ten: " << p->data.ten << ", Gia: " << p->data.gia
				<< ", So luong: " << p->data.soLuong << ", Han su dung: " << p->data.hanSuDung << endl;
		}
		p = p->link;
	}
}
//6. Tìm mặt hàng có số lượng lớn nhất
//Hàm này để tìm mặt hàng có số lượng tồn kho lớn nhất 
Nodeptr timMatHangCoSoLuongLonNhat(Nodeptr list) {
	Nodeptr maxMatHang = NULL;
	int max = -1;
	while (list != NULL) {
		if (list->data.soLuong > max) {
			max = list->data.soLuong;
			maxMatHang = list;
		}
		list = list->link;
	}
	return maxMatHang;

}
// Xuất thông mặt hàng có số lượng tồn kho lớn nhất
void xuat_ThongTinMotMatHangCoSoLuongLonNhat(Nodeptr list) {
	Nodeptr maxMatHang = timMatHangCoSoLuongLonNhat(list);
	cout << "--------------------------------------------------------------" << endl;
	cout << left << setw(20) << "Ten" << setw(20) << "Gia" << setw(10) << "SL" << setw(20) << "HSD" << setw(25) << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << left << setw(20) << maxMatHang->data.ten << setw(20) << maxMatHang->data.gia << setw(10) << maxMatHang->data.soLuong << setw(20) << maxMatHang->data.hanSuDung << endl;
	cout << "--------------------------------------------------------------" << endl;
}
//7. Nhập vào một mặt hàng và kiểm tra trong kho xem mặt hàng này còn hay hết.
void kiemtra_TinhTrangMatHang(Nodeptr list, const char* ten) {
	Nodeptr p = list;
	while (p != NULL) {
		if (strcmp(p->data.ten, ten) == 0) {
			if (p->data.soLuong > 0) {
				cout << "Con hang" << endl;
			}
			else {
				cout << "Da het hang" << endl;
			}
			return;
		}
		p = p->link;
	}
	cout << "Khong tim thay mat hang ten " << ten << endl;
}
//8. Tìm trong danh sách những mặt hàng hết hạn sử dụng.Nếu có thì xóa mặt hàng này khỏi danh
//sách.
// Hàm để kiểm tra xem mặt hàng còn hạn sử dụng hay không
bool conHanSuDung(Nodeptr matHang) {
	// Lấy ngày hiện tại
	time_t t = time(0);
	struct tm* now = localtime(&t);
	int currentDay = now->tm_mday;
	int currentMonth = now->tm_mon + 1; // Tháng bắt đầu từ 0
	int currentYear = now->tm_year + 1900; // Năm hiện tại
	// Lấy ngày và tháng hết hạn sử dụng từ mặt hàng
	int expirationDay, expirationMonth, expirationYear;
	sscanf(matHang->data.hanSuDung, "%d/%d/%d", &expirationDay, &expirationMonth, &expirationYear);

	// So sánh hạn sử dụng với ngày hiện tại
	return (expirationYear > currentYear) ||
		(expirationYear == currentYear && expirationMonth > now->tm_mon + 1) ||
		(expirationYear == currentYear && expirationMonth == now->tm_mon + 1 && expirationDay >= now->tm_mday);
}
// Hàm để thống kê những mặt hàng hết hạn sử dụng
void thongKeHetHanSuDung(Nodeptr list) {
	Nodeptr p = list;
	bool coMatHangHetHanSuDung = false;

	cout << "Danh sach mat hang con han su dung:" << endl;
	while (p != NULL) {
		if (!conHanSuDung(p)) {
			cout << "Ten: " << p->data.ten << ", Gia: " << p->data.gia
				<< ", So luong: " << p->data.soLuong << ", Han su dung: " << p->data.hanSuDung << endl;
			coMatHangHetHanSuDung = true;
		}
		p = p->link;
	}

	if (!coMatHangHetHanSuDung) {
		cout << "Khong co mat hang het han su dung." << endl;
	}
	else {
		xoa_MatHangHetHan(list);
	}
}
void xoa_MatHangHetHan(Nodeptr &list) {
	Nodeptr p = list;
	Nodeptr previous = NULL;
	while (p != NULL) {
		if (!conHanSuDung(p)) {
			Nodeptr toDelete = p;
			if (previous != NULL) {
				previous->link = p->link;
			}
			else {
				list = p->link;
			}

			p = p->link;
			delete toDelete;
		}
		else {
			previous = p;
			p = p->link;
		}
	}
}
//9. Thống kê những mặt hàng còn hạn sử dụng trong danh sách.
// Hàm để thống kê những mặt hàng còn hạn sử dụng
void thongKeHanSuDung(Nodeptr list) {
	Nodeptr p = list;
	bool coMatHangConHanSuDung = false;

	cout << "Danh sach mat hang con han su dung:" << endl;

	while (p != NULL) {
		if (conHanSuDung(p)) {
			cout << "Ten: " << p->data.ten << ", Gia: " << p->data.gia
				<< ", So luong: " << p->data.soLuong << ", Han su dung: " << p->data.hanSuDung << endl;
			coMatHangConHanSuDung = true;
		}
		p = p->link;
	}

	if (!coMatHangConHanSuDung) {
		cout << "Khong co mat hang con han su dung." << endl;
	}
}
//10. Xuất thông tin các mặt hàng trong danh sách vào file text
void xuat_ThongTinRaFile(Nodeptr list, const char* tenFile) {
	ofstream outFile(tenFile);

	if (!outFile.is_open()) {
		cout << "Khong mo duoc file " << tenFile << endl;
		return;
	}

	Nodeptr p = list;

	outFile << "--------------------------------------------------------------" << endl;
	outFile << left << setw(20) << "Ten" << setw(20) << "Gia" << setw(10) << "SL" << setw(20) << "HSD" << setw(25) << endl;
	outFile << "--------------------------------------------------------------" << endl;
	while (p != NULL) {
		outFile << left << setw(20) << p->data.ten << setw(20) << p->data.gia << setw(10) << p->data.soLuong << setw(20) << p->data.hanSuDung << endl;
		p = p->link;
	}
	outFile << "--------------------------------------------------------------" << endl;
	outFile.close();
	cout << "Xuat file thanh cong." << endl;
}

void pressAnyKey() {
	cout << "\n\nBam phim bat ky de tiep tuc...";
	_getch();
	system("cls");
}