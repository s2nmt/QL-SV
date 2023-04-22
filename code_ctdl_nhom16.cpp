#include<conio.h>
#include<stdio.h>
#include <iostream>
#include <string.h>
#define MAX 100
using namespace std;

struct Monhoc{
    char malop[11];
    int mamon;
    float diemthuong = 0;
    float diemgk = 0;
    float diemck = 0;
    float diemtk ; 
   
};
// Nhap du lieu cho mon hoc
void Nhapmonhoc(Monhoc &mh){
    cout <<"Nhap ma lop: ";
    fflush(stdin);
    gets(mh.malop);
    cout <<"Nhap ma mon: ";
    cin>>mh.mamon;
    cout <<"Nhap diem thuong: ";
    cin >>mh.diemthuong;
    cout <<"Nhap diem giua ki: ";
    cin >>mh.diemgk;
    cout <<"Nhap diem cuoi ki: ";
    cin >>mh.diemck;
    mh.diemtk = ((mh.diemthuong + mh.diemgk) + mh.diemck)/2;
    if(mh.diemtk > 10){
    	mh.diemtk = 10;
    }
}
// Xuat du lieu mon hoc
void Xuatmonhoc(Monhoc &mh){
    cout <<"Ma lop: " <<mh.malop;
    cout <<"Ma mon: " <<mh.mamon;
    cout <<"Diem thuong: " <<mh.diemthuong;
    cout <<"Diem giua ki: " <<mh.diemgk;
    cout <<"Diem cuoi ki: " <<mh.diemck;
    cout <<"Diem tong ket: " <<mh.diemtk;
}
struct Bangdiem
{   
	int mssv;
    Monhoc Monhoc;
    char tenmon[30];
    int stc;  
  

};
//Nhap du lieu bang diem
void Nhapbangdiem(Bangdiem &bd){
    cout <<"Nhap mssv: ";
    cin >>bd.mssv;
    cout <<"Nhap ten mon: ";
    fflush(stdin);
    gets(bd.tenmon);
    cout <<"So tin chi: ";
    cin >> bd.stc;  
    Nhapmonhoc(bd.Monhoc);

}

//Xuat bang diem
void Xuatbangdiem(Bangdiem &bd){
    cout <<"Mon: "<<bd.tenmon;
    cout <<"So tin chi: "<<bd.stc;
    cout <<"Diem tong ket: "<<bd.Monhoc.diemtk;
    
}
//Xuat danh sach bang diem
void XuatDSBD(Bangdiem b[], int n, int mssv){
    for(int i = 0;i < n;i++){
        if(b[i].mssv == mssv){
            Xuatbangdiem(b[i]);
            cout<<endl;
        }
            
    }
}

struct Sinhvien{
 
    int mssv;
    char hoten[30];
    char ngaysinh[30];
    char gioitinh[6];
    char email[51];
    char sdt[51];
    char quequan[30];
    float dtl = 0;
    int stctl =0;
        
};
typedef Sinhvien SV;
//Nhap thong tin sinh vien
void Nhapsinhvien(SV &sv){
    cout <<"Nhap ma so sinh vien: ";
    cin >>sv.mssv;
    fflush(stdin);
    cout <<"Nhap ho ten: ";
    fflush(stdin);
    gets(sv.hoten);
    cout <<"Nhap ngay sinh: ";
    fflush(stdin);
    gets(sv.ngaysinh);
    cout <<"Nhap gioi tinh: ";
    fflush(stdin);
    gets(sv.gioitinh);
    cout<<"Nhap email: ";
    fflush(stdin);
    gets(sv.email);
    cout<<"Nhap so dien thoai: ";
    fflush(stdin);
    gets(sv.sdt);
    cout<<"Nhap que quan: ";
    fflush(stdin);
    gets(sv.quequan);
}

//Xuat thong tin sinh vien
void Xuatsinhvien(SV &sv){
    cout <<"\nMa so sinh vien: "<<sv.mssv;
    cout <<"\tHo ten: "<<sv.hoten;
    cout <<"\tNgay sinh: "<<sv.ngaysinh;
    cout <<"\tGioi tinh: "<<sv.gioitinh;
    cout <<"\tEmail: "<<sv.email;
    cout <<"\tSo dien thoai: "<<sv.sdt;
    cout <<"\tQue quan: "<<sv.quequan;
}

// Xuat danh sach sinh vien
void XuatDSSV(SV a[], int n){
    for(int i=0;i<n;i++){
            Xuatsinhvien(a[i]);
    }
}
//Tinh diem tich luy
void Diemtichluy(SV a[],Bangdiem b[],int mssv,int n,int m){
    int sum = 0;
    float tong = 0;
    for(int i = 0;i < m;i ++){
        if(b[i].mssv == mssv){
         //   Tinhdtb(b[i]);
            sum = sum+b[i].stc;
            tong = tong +b[i].Monhoc.diemtk*b[i].stc;
        }
    }
    for(int i = 0;i < n;i++){
        if(a[i].mssv = mssv){
            a[i].stctl =sum;
            a[i].dtl = tong/sum;
        }
    }
    for(int i = 0;i < n;i++){
        if(a[i].mssv = mssv){
            cout <<"\nSo tin chi tich luy: "<<a[i].stctl;
            cout <<"\nDiem tich luy: "<<a[i].dtl;
            break;
        }
    }

}
// Xuat thong tin cua mot sinh vien
void Show1sinhvien(SV a[], int i){
    cout <<"\nMssv \t\tHo ten\t\t     Ngay Sinh    \tGioitinh \tEmail \t\t Sdt \t\tQuequan \n";
    cout <<a[i].mssv;
    cout <<"" <<a[i].hoten;
    cout <<"" <<a[i].ngaysinh;
    cout <<"\t\t" <<a[i].gioitinh;
    cout <<"\t\t" <<a[i].email;
    cout <<"\t" <<a[i].sdt;
    cout <<"" <<a[i].quequan;

}
//Tim kiem theo ten
void timKiemTheoTen(SV a[], char ten[], int n) {
    SV arrayFound[MAX];
    char tenSV[30];
    int found = 0;
    for(int i = 0; i < n; i++) {
        strcpy(tenSV, a[i].hoten);
        if(strstr(strupr(tenSV), strupr(ten))) {
            arrayFound[found] = a[i];
            found++;
        }
    }
    XuatDSSV(arrayFound, found);
}
//Tim kiem theo mssv
void Timkiemmssv(SV a[], int mssv,int n){
    SV arrayFound[MAX];
    int found = 0;
    int tk = 0;
    for(int i = 0;i < n;i++){
        if(a[i].mssv == mssv){
            arrayFound[found] = a[i];
            tk = 1;
        }
	}
    if (tk == 1){
        Show1sinhvien(arrayFound, found);
    }
    else {
        cout <<"Khong tim thay sinh vien";
    }
    
}
//Xuat bang diem cua mot sinh vien
void Showbd1sv(Bangdiem b[], int i){
    cout <<"\nMssv \tMon hoc\t So tin chi \n";
    cout <<b[i].mssv;
    cout <<b[i].tenmon;
    cout <<b[i].stc;
}
//Tim bang diem sinh vien
void Timbangdiemsv(Bangdiem b[], int mssv,int n){
    Bangdiem array1[MAX];
    int found = 0;
    int tk = 0;
    for(int i = 0;i < n;i++){
        if(b[i].mssv == mssv){
            array1[found] = b[i];
            tk = 1;
        }
    }
    if(tk == 1){
    	Showbd1sv(array1, found);
	}
     
    else{
        	cout<<"Khong tim thay sinh vien ";
		}
	}
    
//Xoa thong tin sinh vien
int Xoathongtinsinhvien(SV a[] ,int mssv, int n){
    int found = 0;

    for(int i = 0;i < n;i++){
       if(a[i].mssv == mssv){
            found = 1;
            for(int j=i;j<n-1;j++){
		        a[j]=a[j+1];
	           }
            cout << "\n Da xoa SV co MSSV:" << mssv;
            break;
        }
    }
    if (found == 0) {
        cout <<"\n Sinh vien khong ton tai.";
        return 0;
    } else {
        return 1;
    }
    
}
//Xoa thong tin mon hoc
int Xoathongtinmonhoc(Bangdiem b[] ,int mssv, int n){
    int found = 0;

    for(int i = 0;i < n;i++){
       if(b[i].mssv == mssv){
            found = 1;
            for(int j=i;j<n-1;j++){
		        b[j]=b[j+1];
	           }
            cout << "\n Da xoa mon hoc  MSSV:" << mssv;
            break;
        }
    }
    if (found == 0) {
        cout <<"\n Sinh vien khong ton tai.";
        return 0;
    } else {
        return 1;
    }
    
}
//Cap nhat thong tin sinh vien
void CapnhatSV(SV a[], int mssv, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (a[i].mssv == mssv) {
            found = 1;
            cout << "\n Cap nhat thong tin sinh vien co MSSV = " << mssv<<endl;
            Nhapsinhvien(a[i]);
            break;
        }
    }
    if (found == 0) {
        cout<<"\n Sinh vien co MSSV khong ton tai.";
    }
}
//Xuat danh sach diem theo mon
void Xuatdsdiemtheomon(Bangdiem b[], int n, int mamon){

    for(int i = 0;i < n;i++){
        if(b[i].Monhoc.mamon == mamon){
            cout<<b[i].mssv;
            cout<<b[i].Monhoc.diemtk;
        }
    }
}
// Xuat danh sach sinh vien theo nganh
void Xuatdssinhvientheonganh(SV a[], int n,int manganh){
    int kt = 0;
    for(int i = 0; i < n;i++){
        if(a[i].mssv/1000 == manganh)
        {
            kt = 1;
            Show1sinhvien(a,i);
        }
    }
    if(kt == 0){
        cout<<"\nKhong tim thay ma nganh nay\n vui long nhap lai";
    }
}
// Xuat danh sach sinh vien theo nam nhap hoc
void Xuatdssinhvientheokhoa(SV a[], int n,int namhoc){
    int nh = 0;
    for(int i = 0; i < n;i++){
        if(a[i].mssv/1000000 == namhoc)
        {
            nh = 1;
            Show1sinhvien(a,i);
        }
    }
    if(nh == 0){
        cout<<"\nKhong tim thay ma nganh nay\n vui long nhap lai";
    }
}
// sap xep diem theo mon hoc
void insertionSort(Bangdiem b[], int n, int mamon)
{
    float c[MAX];
    int a = 0;
    int count = 0;
    for(int k = 0; k < n; k ++ ){
        if(b[k].Monhoc.mamon == mamon){
            c[count] = b[k].Monhoc.diemtk;
            count++;
            a = 1;
        }
            
    }
    for(int k = 0; k < n; k ++ ){
        if(b[k].Monhoc.mamon == mamon){
            cout<<"ten mon: "<<b[k].tenmon;
            break;
        }
            
    }
    if(a == 1){
        int i, j;
        float key;
        for (i = 0; i < count; i++)
        {
        key = c[i];
        j = i - 1;
        while (j >= 0 && c[j] > key){
            c[j + 1] = c[j];
            j=j- 1;
            }
        c[j+ 1]= key;
        }
        cout <<"Thu tu diem tang dan: ";
        for (i = 0; i < count; i++) {
            cout <<"  "<<c[i];
        }
    }
    else{
    	cout <<"Khong tim thay ma mon";
	}
}
// doc file sinh vien
int docFile(SV a[], char fileName[]) {
    FILE * fp;
    int i = 0;
    fp = fopen (fileName, "r");
    cout << "Chuan bi doc file: "; puts(fileName);
    // doc thong tin sinh vien
    while (fscanf(fp, "%10d%29[^\n]%29s%5s%50s%50s%29[^\n]\n", &a[i].mssv, &a[i].hoten, &a[i].ngaysinh,
            &a[i].gioitinh, &a[i].email, &a[i].sdt, &a[i].quequan) != EOF) {
       i++;
       cout << " Doc ban ghi thu: " << i << endl;
    }
    cout << " So luong sinh vien co san trong file la: " << i << endl;
    cout << endl;
    fclose (fp);
    // tra ve so luong sinh vien duoc doc tu file
    return i;
}
//ghi file sinh vien
void ghiFile(SV a[], int n, char fileName[]) {
    FILE * fp;
    fp = fopen (fileName,"w");
    for(int i = 0;i < n;i++){
        fprintf(fp, "%10d%20s%20s%5s%20s%20s%20s\n", a[i].mssv, &a[i].hoten, &a[i].ngaysinh,
            &a[i].gioitinh, &a[i].email, &a[i].sdt, &a[i].quequan);
    }
    fclose (fp);
}
// doc file bang diem
int docfileBangdiem(Bangdiem b[], char fileBangdiem[]) {
    FILE * ff;
    int i = 0;
    ff = fopen (fileBangdiem, "r");
    cout << "Chuan bi doc file: "; puts(fileBangdiem);
    // doc thong tin sinh vien
    while (fscanf(ff, "%10d%29[^\n]%10s%10d%10d%10f%10f%10f%10f\n", &b[i].mssv, &b[i].tenmon,&b[i].Monhoc.malop, &b[i].stc
           , &b[i].Monhoc.mamon, &b[i].Monhoc.diemthuong, &b[i].Monhoc.diemgk, &b[i].Monhoc.diemck, &b[i].Monhoc.diemtk) != EOF) {
       i++;
       cout << " Doc ban ghi thu: " << i << endl;
    }
    cout << " So luong sinh vien co san trong file la: " << i << endl;
    cout << endl;
    fclose (ff);
    // tra ve so luong sinh vien duoc doc tu file
    return i;
}
// ghi file bang diem
void ghifileBangdiem(Bangdiem b[], int m, char fileBangdiem[]) {
    FILE * ff;
    ff = fopen (fileBangdiem,"w");
    for(int i = 0;i < m;i++){
        fprintf(ff, "%10d%20s%20s%5d%5d%5.2f%5.2f%5.2f%8.2f\n", b[i].mssv, &b[i].tenmon,&b[i].Monhoc.malop, b[i].stc,
            b[i].Monhoc.mamon, b[i].Monhoc.diemthuong, b[i].Monhoc.diemgk, b[i].Monhoc.diemck, b[i].Monhoc.diemtk);
    }
    fclose (ff);
}
void printLine(int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "_";
    }
    cout << endl;
}
 

void pressAnyKey() {
    cout << "\n\nBam phim bat ky de tiep tuc...";
    getch();
    system("cls");
}
int main(){
    SV a[MAX];
    Bangdiem b[MAX];
    char fileName[] = "sinhvien.txt";
    char fileBangdiem[] = "bangdiem.txt";
    int slmh = 0;
    int slsv = 0;
    int luachon;

    slsv = docFile(a, fileName);
    slmh = docfileBangdiem(b, fileBangdiem);
    

    while(true){
        cout <<"==================-------NHOM-16-------===================>>\n";
        cout <<"==================--Quan li sinh vien--===================>>\n";
        cout <<"========Nguyen Minh Tuan--------------Phan Tan Quoc=======>>\n\n";
        cout <<"==================--------MENU---------===================>>\n";
        cout <<"<<===== 1. Nhap thong tin sinh vien ======================>>\n";
        cout <<"<<===== 2. Nhap danh sach mon hoc ========================>>\n";
        cout <<"<<===== 3. Xuat thong tin toan bo sinh vien===============>>\n";
        cout <<"<<===== 4. Xuat bang diem sinh vien ======================>>\n";
        cout <<"<<===== 5. Xuat danh sach sinh vien theo nganh============>>\n";
        cout <<"<<===== 6. Xuat danh sach sinh vien theo khoa hoc=========>>\n";
        cout <<"<<===== 7. Tim kiem sinh vien theo mssv ==================>>\n";
        cout <<"<<===== 8. Tim kiem theo ten==============================>>\n";        
        cout <<"<<===== 9. Xoa sinh vien theo mssv =======================>>\n";
        cout <<"<<==== 10. So tin chi va diem tich luy sinh vien can tim =>>\n";
        cout <<"<<==== 11. Cap nhat thong tin sinh vien ==================>>\n";
        cout <<"<<==== 12. Sap xep diem theo mon tang dan=================>>\n";
        cout <<"<<==== 13. Ghi danh sach sinh vien duoc nhap vao file txt >>\n";
        cout <<"<<==== 14. Ghi bang diem vao file ========================>>\n";
        cout <<"<<==== 15. Chon 0 de thoat================================>>\n";
        cout <<"<<=====================Nhap lua chon: ====================>>\n";
        cin >>luachon;
        switch(luachon){
            case 1:
            	printLine(50);
                cout <<"1. Nhap thong tin sinh vien\n";
                Nhapsinhvien(a[slsv]);
                slsv ++;
                pressAnyKey();
                break;
            case 2:
            	printLine(50);
                cout <<"2. Nhap danh sach mon hoc\n";
                Nhapbangdiem(b[slmh]);
                slmh++;
                pressAnyKey();
                break;
            case 3:
            	cout <<"3. Xuat thong tin sinh vien\n";
            	printLine(200);
                XuatDSSV(a,slsv);
                printLine(200);
                pressAnyKey();
                break;
            case 4:
                int id3;
                cout <<"4. Xuat bang diem sinh vien\n";
                cout <<"Nhap mssv can xuat: ";
                cin >>id3;
                printLine(65);
                XuatDSBD(b,slmh,id3);
                printLine(65);
                pressAnyKey();
                break;    
            case 5:
                int manganh;
                cout <<"5. Xuat danh sach sinh vien theo nganh\n";
                cout <<"Nhap ma nganh can xuat: ";
                cin >>manganh;
                printLine(130);
                Xuatdssinhvientheonganh(a, slsv,manganh);      
				printLine(130);          
                pressAnyKey();
                break;
            case 6:
                int namhoc;
                cout <<"6. Xuat danh sach sinh vien theo khoa\n";
                cout <<"Khoa hoc can xuat: ";
                cin >>namhoc;
                printLine(130);
                Xuatdssinhvientheokhoa(a, slsv, namhoc);
                printLine(130);
                pressAnyKey();
                break;
            case 7:
                int mssv;
                if(slsv > 0) {
	                cout <<"7. Tim kiem sinh vien theo mssv\n";
	                cout <<"Nhap mssv can tim kiem: ";
	                cin >>mssv;
	                printLine(130);
                	Timkiemmssv(a,mssv,slsv);
                	printLine(130);
                	}
                else{
                	cout << "\nSanh sach sinh vien trong!";
				}
                
                pressAnyKey();
                break; 
            case 8:
                if(slsv > 0) {
                    cout << "8. Tim kiem sinh vien theo ten.\n";
                    char strTen[30];
                    cout << "\nNhap ten de tim kiem: "; fflush(stdin); gets(strTen);
                    timKiemTheoTen(a, strTen, slsv);
                }else{
                    cout << "\nSanh sach sinh vien trong!";
                }
                pressAnyKey();
                break;
            case 9:
                int id;
                cout <<"9. Xoa sinh vien theo mssv\n";
                cout <<"Nhap mssv can xoa:  ";
                cin >>id;
                if (Xoathongtinsinhvien(a,id,slsv) == 1){
                    cout <<"\nXoa sinh vien thanh cong";
                    slsv -- ;
                }
                else{
                    cout << "\nDanh sach sinh vien trong!";
                }
                while(true){
	                if (Xoathongtinmonhoc(b,id,slmh) == 1){
	                    cout <<"\nXoa mon hoc thanh cong";
	                    slmh --;
	                }
	                else{
	                    cout << "\nDanh sach bang diem trong!";
	                    break;
	                }
	            }
                pressAnyKey();
                break; 
            case 10:
                int id1;
                cout <<"10. So tin chi va diem tich luy sinh vien can tim\n";
                cout <<"Nhap mssv can xem: ";
                cin >>id1;

                Diemtichluy(a,b,id1,slsv,slmh);
                pressAnyKey();
                break;
            case 11:
                cout <<"11. Cap nhat thong tin sinh vien \n";
                int id2;
                cout <<"Nhap mssv can cap nhat:";
                cin >>id2;
                CapnhatSV(a,id2,slsv);
                pressAnyKey();
                break;
            case 12:
                cout <<"12. Sap xep diem theo mon\n";
                cout <<"Nhap ma mon: ";
            	int mamon;
            	cin>>mamon;
                insertionSort(b, slmh, mamon);
                pressAnyKey();
                break;   
            case 13:
                if(slsv > 0){
                    cout << "\n13. Ghi danh sach sinh vien vao file.";
                    ghiFile(a, slsv, fileName);
                }else{
                    cout << "\nSanh sach sinh vien trong!";
                }
                cout <<"\nGhi danh sach sinh vien vao file thanh cong";
                pressAnyKey();
                break;
             case 14:
                 if(slmh > 0){
                    cout <<"14. Ghi Bang diem vao file txt\n";
                     ghifileBangdiem(b, slmh, fileBangdiem);
                 }else{
                     cout << "\nDanh sach Bang diem trong!";
                 }
                 cout <<"\nGhi danh sach Bangdiem vao file thanh cong";
                 pressAnyKey();
                 break;
            case 0:
                cout << "\nBan da chon thoat chuong trinh!";
                getch();
                return 0;
            default:
                cout << "\nKhong co chuc nang nay!";
                cout << "\nHay chon chuc nang trong hop menu.";
                pressAnyKey();
                break;

        }

    }
    return 0;
    
}

