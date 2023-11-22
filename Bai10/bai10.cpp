#include <bits/stdc++.h>
#include "SingleLinkList.cpp"

using namespace std;

struct CanBo {
	int ma;
	string hoTen;
	string phongBan;
	string chucVu;
	float heSoLuong;
};


class QLNS {
private:
	int soCanBo;
	SingleLinkList<CanBo> dsCanBo;
public:
	// Constrctor - Getter/Setter
	QLNS(){
		this->soCanBo = 0;
	}
	QLNS(int soCanBo, SingleLinkList<CanBo> dsCanBo) {
		this->soCanBo = soCanBo;
		this->dsCanBo.assign(dsCanBo);
	}
	int getSoNhanVien() {
		return soCanBo;
	}
	SingleLinkList<CanBo> getDsNhanVien() {
		return dsCanBo;
	}
	// Input/Output
	int nhapCanBo(int viTri = -1) {
		CanBo canBo;
		cout << "\nNhap ma can bo: "; cin >> canBo.ma; cin.ignore();
		if(canBo.ma <= 0)  {
			return 0;
		}
		cout << "Nhap ho ten: "; getline(cin, canBo.hoTen);
		cout << "Nhap phong ban: "; getline(cin, canBo.phongBan);
		cout << "Nhap chuc vu: "; getline(cin, canBo.chucVu);
		cout << "Nhap he so luong: "; cin >> canBo.heSoLuong; cin.ignore();

		if (viTri < 0) {
			dsCanBo.push_back(canBo);
			soCanBo++;
		}
		else {
    		dsCanBo.insert(viTri, canBo);
    		soCanBo++;
		}
		return 1;
	}
	void xuatCanBo(CanBo canBo) {
		cout << setw(8) << canBo.ma << setw(20) << canBo.hoTen << setw(18) << canBo.phongBan << setw(20) <<  canBo.chucVu << setw(15) << tinhLuong(canBo) << endl;
	}
	void nhapDsCanBo() {
		int result;
		CanBo canBo;
		while (true) {
			result = nhapCanBo();
			if (result == 0) break;
		}
	}
	void xuatDsCanBo() {
		cout << "\n------------------------------- DANH SACH CAN BO --------------------------------\n";
		cout << setw(8) << "Ma NV" << setw(20) << "Ho ten" << setw(18) << "Phong ban" << setw(20) <<  "Chuc vu" << setw(15) << "Luong" << endl;
		cout << "---------------------------------------------------------------------------------\n";
		for (const CanBo &canBo: dsCanBo) {
			xuatCanBo(canBo);
		}
		cout << "---------------------------------------------------------------------------------\n";
		cout << "(!) Danh sach co " << soCanBo << " can bo.\n";
	}

	long tinhLuong(CanBo nv) {
		return 1350000* nv.heSoLuong;
	}
	void sapXepNhanVienTheoTen() {
		for (SingleLinkList<CanBo>::iterator it = dsCanBo.begin(); it != dsCanBo.end(); it++) {
			for (SingleLinkList<CanBo>::iterator it2 = it; it2 != dsCanBo.end(); it2++) {
				int pos = (*it).hoTen.find_last_of(" ");
				string ten1 = (*it).hoTen.substr(pos + 1);
				pos = (*it2).hoTen.find_last_of(" ");
				string ten2 = (*it2).hoTen.substr(pos + 1);
				if (ten2 < ten1) {
					iter_swap(it, it2);
				}
			}
		}
	}
};

int main () {
	QLNS qlns;

	// Tao ds can bo
	cout << "(?) Nhap sanh sach can bo:";
	qlns.nhapDsCanBo();
	qlns.xuatDsCanBo();


	// Them 1 can bo bao danh sach
	int viTri;
	int ketQua;
	cout << "\n(?) Nhap vi tri muon them can bo (-1 de them vao cuoi ds): "; cin >> viTri;
	ketQua = qlns.nhapCanBo(viTri);
	cout << (ketQua ? "(!) Them can bo moi thanh cong!\n" : "(x) Them can bo moi that bai, ma can bo khong hop le!\n");


	// In cac can bo co hsl >= 4.4
	SingleLinkList<CanBo> dsCanBo = qlns.getDsNhanVien();
	cout << "\n\n----- Danh sach can bo co he so luong > 4,4:\n";
	cout << setw(8) << "Ma NV" << setw(20) << "Ho ten" << setw(18) << "Phong ban" << setw(20) <<  "Chuc vu" << setw(15) << "Luong" << endl;
	for (SingleLinkList<CanBo>::iterator it =  dsCanBo.begin(); it != dsCanBo.end(); it++) {
		CanBo canbo = *it;
		if (canbo.heSoLuong > 4.4)
			qlns.xuatCanBo(canbo);
	}

	// Tim va in danh sach theo chuc vu
	string timChucVu;
	cout << "\n\n(?) Nhap chuc vu muon tim kiem: "; getline(cin, timChucVu);
	cout << "----- Danh sach can bo co chuc vu " << timChucVu << ":\n";
	cout << setw(8) << "Ma NV" << setw(20) << "Ho ten" << setw(18) << "Phong ban" << setw(20) <<  "Chuc vu" << setw(15) << "Luong" << endl;
	for (SingleLinkList<CanBo>::iterator it =  dsCanBo.begin(); it != dsCanBo.end(); it++) {
		CanBo canbo = *it;
		if (canbo.chucVu == timChucVu)
			qlns.xuatCanBo(canbo);
	}

	// Tim va in ds theo hsl va phong ban
	float timHsl;
	string timPhongBan;
	cout << "\n\n(?) Nhap he so luong can tim: "; cin >> timHsl; cin.ignore();
	cout << "(?) Nhap phong ban can tim: "; getline(cin, timPhongBan);
	cout << "\n----- Danh sach can bo co he so luong > " << timHsl << " && phong ban " << timPhongBan << ":\n";
	cout << setw(8) << "Ma NV" << setw(20) << "Ho ten" << setw(18) << "Phong ban" << setw(20) <<  "Chuc vu" << setw(15) << "Luong" << endl;
	for (SingleLinkList<CanBo>::iterator it =  dsCanBo.begin(); it != dsCanBo.end(); it++) {
		CanBo canbo = *it;
		if (canbo.heSoLuong >= timHsl && canbo.phongBan == timPhongBan)
			qlns.xuatCanBo(canbo);
	}

	// Xap sep nhan vien theo ten
	qlns.sapXepNhanVienTheoTen();
	cout << "\n(!) Da xap sep danh sach theo ten:";
	qlns.xuatDsCanBo();


	return 0;
}


//1
//Nguyen Van Anh
//Maketing
//Quan ly
//5.6
//2
//Nguyen Van Hoang
//IT
//Quan ly du an
//5.4
//3
//Nguyen Van Chien
//IT
//Lap trinh vien
//3.5
//4
//Nguyen Van Dung
//IT
//Lap trinh vien
//4.6
//5
//Nguyen Van Linh
//IT
//Designer
//4.2
//6
//Nguyen Van Hoang
//Tai chinh
//Ke toan
//4.1
//7
//Nguyen Van Huy
//Tai chinh
//Kiem toan
//4.23
//-1
//3
//8
//Nguyen Van Sau
//IT
//CTO
//4.9
