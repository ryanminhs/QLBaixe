#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <unordered_map>
#include <fstream>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;

struct Xe {
    string maXe;
    string soXe;
    string loaiXe;
    string hoTenChuXe;
    int donGiaGui;
	Xe* next;
};

void displayVehicleInfo(Xe xe) {
    cout << "Ma xe: " << xe.maXe << ", So xe: " << xe.soXe << ", Loai xe: " << xe.loaiXe << ", Ho ten chu xe: " << xe.hoTenChuXe << ", Don gia goi: " << xe.donGiaGui << endl;
}

Xe nhapThongTinXe() {
    Xe xe;
    cout << "Nhap ma xe: ";
    cin >> xe.maXe;
    cout << "Nhap so xe: ";
    cin >> xe.soXe;
    cout << "Nhap loai xe: ";
    cin >> xe.loaiXe;
    cout << "Nhap ho ten chu xe: ";
    cin >> xe.hoTenChuXe;
    cout << "Nhap don gia goi: ";
    cin >> xe.donGiaGui;
    return xe;
}

void themXeVaoStack(stack<Xe>& baiXe) {
    Xe xe = nhapThongTinXe();
    baiXe.push(xe);
    cout << "Xe da duoc them vao bai xe." << endl;
}
//string timLoaiXeNhieuNhat(stack<Xe> baiXe) {
//    unordered_map<string, int> demLoaiXe;
//    int maxSoXe = 0;
//    string loaiXeNhieuNhat;
//    
//    // Đếm số lượng xe của từng loại và tìm loại xe có số lượng nhiều nhất
//    while (!baiXe.empty()) {
//        Xe xe = baiXe.top();
//        baiXe.pop();
//        demLoaiXe[xe.loaiXe]++;
//        if (demLoaiXe[xe.loaiXe] > maxSoXe) {
//            maxSoXe = demLoaiXe[xe.loaiXe];
//            loaiXeNhieuNhat = xe.loaiXe;
//        }
//    }
//    
//    return loaiXeNhieuNhat;
//}
string timLoaiXeNhieuNhat(stack<Xe> baiXe) {
    unordered_map<string, int> demLoaiXe;
    int maxSoLuong = 0;
    string loaiXeNhieuNhat;
    while (!baiXe.empty()) {
        Xe xe = baiXe.top();
        baiXe.pop();
        demLoaiXe[xe.loaiXe]++;
        if (demLoaiXe[xe.loaiXe] > maxSoLuong) {
            maxSoLuong = demLoaiXe[xe.loaiXe];
            loaiXeNhieuNhat = xe.loaiXe;
        }
    }
    return loaiXeNhieuNhat;
}

bool kiemTraLoaiXeTrongBaiXe(stack<Xe> baiXe, string loaiXe) {
    while (!baiXe.empty()) {
        Xe xe = baiXe.top();
        baiXe.pop();
        if (xe.loaiXe == loaiXe) {
            return true;
        }
    }
    return false;
}

void thongKeTheoDonGiaGui(stack<Xe> baiXe) {
    unordered_map<double, int> demTheoDonGia;
    while (!baiXe.empty()) {
        Xe xe = baiXe.top();
        baiXe.pop();
        demTheoDonGia[xe.donGiaGui]++;
    }
    cout << "Thong ke so luong xe theo don gia goi:" << endl;
    for (auto it : demTheoDonGia) {
        cout << "Don gia goi: " << it.first << ", So luong xe: " << it.second << endl;
    }
}

//void demSoLuongXeTheoLoai(stack<Xe> baiXe) {
//    unordered_map<string, int> demTheoLoaiXe;
//    while (!baiXe.empty()) {
//        Xe xe = baiXe.top();
//        baiXe.pop();
//        demTheoLoaiXe[xe.loaiXe]++;
//    }
//    cout << "So luong xe theo tung loai xe:" << endl;
//    for (auto it : demTheoLoaiXe) {
//        cout << "Loai xe: " << it.first << ", So luong xe: " << it.second << endl;
//    }
//}
void demSoLuongXeTheoLoai(stack<Xe> baiXe) {
    unordered_map<string, int> demTheoLoaiXe;
    stack<Xe> tempStack = baiXe; 
    while (!tempStack.empty()) {
        Xe xe = tempStack.top();
        tempStack.pop();
        demTheoLoaiXe[xe.loaiXe]++;
    }
    cout << "So luong xe theo tung loai xe:" << endl;
    for (auto it : demTheoLoaiXe) {
        cout << "Loai xe: " << it.first << ", So luong xe: " << it.second << endl;
    }
}

void xoaLoaiXe(stack<Xe>& baiXe, string loaiXeCanXoa) {
    stack<Xe> tempStack;
    while (!baiXe.empty()) {
        Xe xe = baiXe.top();
        baiXe.pop();
        if (xe.loaiXe != loaiXeCanXoa) {
            tempStack.push(xe);
        }
    }
    while (!tempStack.empty()) {
        Xe xe = tempStack.top();
        tempStack.pop();
        baiXe.push(xe);
    }
}
int demTongSoXe(stack<Xe> baiXe) {
    return baiXe.size();
}
//int demTongSoXe(stack<Xe> baiXe) {
//    int tongSoXe = 0;
//    while (!baiXe.empty()) {
//        baiXe.pop();
//        tongSoXe++;
//    }
//    return tongSoXe;
//}

void thongKeDoanhThuTheoNgay(stack<Xe> baiXe, time_t ngayBatDau, time_t ngayKetThuc) 
{
	cout << "Thong ke doanh thu tu ngay " << ngayBatDau << " den ngay " << ngayKetThuc << ":" << endl;
}

Xe* taoNodeXe(string maXe, string soXe, const string& loaiXe, const string& hoTenChuXe, int donGiaGui) {
    Xe* newNode = new Xe;
    newNode->maXe = maXe;
    newNode->soXe = soXe;
    newNode->loaiXe = loaiXe;
    newNode->hoTenChuXe = hoTenChuXe;
    newNode->donGiaGui = donGiaGui;
    newNode->next = nullptr;
    return newNode;
}

void themNodeVaoCuoi(Xe*& head, Xe* newNode) {
    if (head == nullptr) {
        head = newNode;
    } else {
        Xe* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void hienThiDanhSachXe(Xe* head) {
    if (head == nullptr) {
        cout << "Danh sach xe trong." << endl;
        return;
    }
    Xe* cur = head;
    while (cur != nullptr) {
        displayVehicleInfo(*cur);
        cur = cur->next;
    }
}

void hienThiDanhSachXeTrongStack(stack<Xe> baiXe) {
    if (baiXe.empty()) {
        cout << "Bai xe trong." << endl;
        return;
    }

    stack<Xe> tempStack = baiXe; // Sao chép stack ban đầu sang một stack tạm thời
    cout << "Danh sach cac xe trong bai xe:" << endl;
    while (!tempStack.empty()) {
        Xe xe = tempStack.top();
        tempStack.pop();
        displayVehicleInfo(xe); // Hiển thị thông tin của xe
    }
}
void giaiPhongDanhSachXe(Xe*& head) {
    while (head != nullptr) {
        Xe* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    stack<Xe> baiXe;
	FILE *f;
	Xe xe;
	Xe* head = nullptr;
	string loaiXe;
	string loaiXeCanXoa;
	time_t ngayBatDau, ngayKetThuc;
	string maXe;
	string soXe;
	string hoTenChuXe;
	string donGiaGui;
    int choice;
    do {
        cout << "\n================ MENU ================" << endl;
		cout << "1. Nhap tu ban phim thong tin xe" << endl;
		cout << "2. Doc du lieu xe tu file txt." << endl;
		cout << "3. Ghi du lieu xe tu file txt." << endl;
		cout << "4. Hien thi tat ca thong tin xe" << endl;
		cout << "5. Hien thi tat ca thong tin xe bang Stack" << endl;
        cout << "6. Them mot xe X vao (Stack)." << endl;
        cout << "7. Tim loai xe co nhieu so xe nhat(Stack)." << endl;
        cout << "8. Tim loai xe X trong bai xe(Stack)." << endl;
        cout << "9. Thong ke xe theo don gia goi(Stack)." << endl;
        cout << "10. Dem so luong xe theo tung loai xe(Stack)." << endl;
        cout << "11. Xoa xe ra khoi bai xe(Stack)." << endl;
        cout << "12. Dem tong so xe goi trong bai xe(Stack)." << endl;
        cout << "13. Thong ke doanh thu theo ngay/tuan/thang/quy,tu ngay den ngay(Stack)." << endl;
        cout << "0. Thoat." << endl;
        cout << "======================================" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            
            case 1: 
				{
				Xe xe = nhapThongTinXe();
				Xe* newNode = taoNodeXe(xe.maXe, xe.soXe, xe.loaiXe, xe.hoTenChuXe, xe.donGiaGui);
				themNodeVaoCuoi(head, newNode);
				cout << "Xe da duoc them vao danh sach." << endl;
				break;
				}
			case 2:
				//Doc File
				f =fopen("filedoc.txt","r");
				if(f==NULL)
				{
					printf("Loi tao hoac mo file\n");
					exit(1);
				}
				
				printf("Doc file quan ly bai xe: \n");
				fscanf(f,"%s",&maXe);
				printf("Ma xe: %s\n",&maXe);
				fscanf(f,"%s",&soXe);
				printf("So xe: %s\n",&soXe);
				fscanf(f,"%s",&loaiXe);
				printf("Ma xe: %s\n",&loaiXe);
				fscanf(f,"%s",&hoTenChuXe);
				printf("Ho ten chu xe: %s\n",&hoTenChuXe);
				fscanf(f,"%s",&donGiaGui);
				printf("Don gia gui: %s\n",&donGiaGui);
				fclose(f);
				break;
			case 3:
				//Ghi File
				f = fopen("fileghi.txt", "w");
				if (f == NULL) 
				{
					printf("Khong the tao hoac mo file\n");
					exit(1);
				}
				printf("Nhap thong tin quan ly bai xe can ghi vao file:\n");

				printf("Nhap ma xe: ");
				scanf("%s", maXe);
				fprintf(f, "Ma xe: %s\n", maXe);
			
				printf("Nhap so xe: ");
				scanf("%s", soXe);
				fprintf(f, "So xe: %s\n", soXe);
				printf("Nhap loai xe: ");
				scanf("%s", loaiXe);
				fprintf(f, "Loai xe: %s\n", loaiXe);

				printf("Nhap ho ten chu xe: ");
				scanf("%s", hoTenChuXe);
				fprintf(f, "Ho ten chu xe: %s\n", hoTenChuXe);

				printf("Nhap don gia gui: ");
				scanf("%s", donGiaGui);
				fprintf(f, "Don gia gui: %s\n", donGiaGui);

				fclose(f);
				printf("Ghi file thanh cong.\n");
				break;
			case 4:
				hienThiDanhSachXe(head);
				break;
			case 5:
				hienThiDanhSachXeTrongStack(baiXe);
				break;
			case 6:
                themXeVaoStack(baiXe);
                break;
            
			case 7:
				{
					cout << "Loai xe co nhieu xe nhat la: " << timLoaiXeNhieuNhat(baiXe)<< endl;
					break;
				}
            case 8:
                cout << "Nhap loai xe can tim: ";
                cin >> loaiXe;
                if (kiemTraLoaiXeTrongBaiXe(baiXe, loaiXe)) {
                    cout << "Loai xe " << loaiXe << " ton tai trong bai xe." << endl;
                } else {
                    cout << "Loai xe " << loaiXe << " khong ton tai trong bai xe." << endl;
                }
                break;
            case 9:
                thongKeTheoDonGiaGui(baiXe);
                break;
            case 10:
                demSoLuongXeTheoLoai(baiXe);
                break;
            case 11: 
                cout << "Nhap loai xe can xoa: ";
                cin >> loaiXeCanXoa;
                xoaLoaiXe(baiXe, loaiXeCanXoa);
                cout << "Loai xe " << loaiXeCanXoa << " da duoc xoa khoi bai xe." << endl;
                break;
            case 12:
                cout << "Tong so xe goi trong bai xe la: " << demTongSoXe(baiXe) << endl;
                break;
            case 13:
                cout << "Nhap ngay bat dau (dd/mm/yyyy): ";
                cin >> ngayBatDau;
                cout << "Nhap ngay ket thuc (dd/mm/yyyy): ";
                cin >> ngayKetThuc;
                thongKeDoanhThuTheoNgay(baiXe, ngayBatDau, ngayKetThuc);
                break;
            case 0:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
