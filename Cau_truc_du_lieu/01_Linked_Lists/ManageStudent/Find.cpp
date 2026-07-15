/*Kiểu dữ liệu cấu trúc để quản lý sinh viên gồm các thành phần là Mã số Sinh viên (MASV) (kiểu chuỗi), Họ và Tên (HoTen) (kiểu chuỗi), Năm sinh (kiểu struct gồm Ngày, Tháng và Năm kiểm int), Giới tính (kiểu ký tự), Điểm toán (kiểu số thực), Điểm lý (kiểu số thực), Điểm hóa (kiểu số thực), Điểm Trung bình (kiểu số thực).

Dựa vào template, hãy hoàn thành chương trình giúp tìm kiếm và xuất ra thông tin của tất cả sinh viên sinh năm Y.

Lưu ý: Trong template đã có sẵn các hàm nhập, xuất thông tin của một sinh viên.

INPUT
Dãy các ký tự và số trong đó: (Giả sử luôn thỏa điều kiện nhập)

Dòng đầu tiên: số nguyên dương Y có 4 chữ số đại diện cho năm sinh cần tìm kiếm theo yêu cầu
Dòng thứ hai: Số lượng n phần tử trong danh sách.
(n*5) dòng có thông tin tiếp theo: Trong đó cứ mỗi 5 dòng thể hiện 7 thông tin của một sinh viên trong mảng:
Dòng thứ 1: Chuỗi Mã số sinh viên
Dòng thứ 2: Chuỗi Họ tên sinh viên
Dòng thứ 3: 3 giá trị Ngày Tháng Năm sinh cách nhau 1 khoảng trắng
Dòng thứ 4: Ký tự thể hiện giới tính: M (Nam) hoặc F (Nữ)
Dòng thứ 5: 3 Số thực lưu Điểm toán lý hóa cách nhau 1 khoảng trắng
OUTPUT
Hiển thị Danh sách sinh viên có năm sinh thứ Y trên các dòng liên tiếp. Mỗi dòng hiển thị 8 thông tin theo thứ tự sau:

Mã số Sinh viên, Họ và Tên, Năm sinh, Giới tính, Điểm toán, Điểm lý, Điểm hóa, Điểm Trung bình.
Mỗi thông tin cách nhau một dấu tab (\t)
Điểm trung bình hiển thị hai số lẻ sau dấu thập phân (nếu có).
Trong trường hợp không tìm thấy sinh viên nằm có năm sinh Y thì in ra màn hình "Not found in list."*/
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct NGAY {
    int Ngay, Thang, Nam;
};
struct SINHVIEN {
    string MASV;
    string HoTen;
    NGAY NgaySinh;
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};
struct NODE{
    SINHVIEN key;
    NODE* pNext;
};
struct LIST{
    NODE*pHead, *pTail;
};

void NhapNgay(NGAY &);
void XuatNgay(NGAY);
void NhapSinhVien(SINHVIEN &);
void XuatSinhVien(SINHVIEN );
NODE* CreateNode(SINHVIEN );
void CreateEmptyList(LIST &);
void AddTail(LIST&, NODE* );
void XuatDS(LIST L);
void NhapDS(LIST &, int );
void Tim_SinhVien_TheoNamSinh(LIST, int);

int main() {
    LIST L;
    int n, namsinh;

    cin >> namsinh;
    cin >> n ;
    NhapDS(L, n);

    Tim_SinhVien_TheoNamSinh(L, namsinh);

    return 0;
}
void NhapNgay(NGAY &a){
    cin >> a.Ngay >> a.Thang >> a.Nam;
}
void XuatNgay(NGAY a){
    cout << a.Ngay << "/" << a.Thang << "/" << a.Nam;
}
void NhapSinhVien(SINHVIEN &a){
    cin >> ws;
    getline(cin, a.MASV);
    getline(cin, a.HoTen);
    NhapNgay(a.NgaySinh);
    cin >> a.GioiTinh;
    cin >> a.DiemToan >> a.DiemLy >> a.DiemHoa;
    a.DTB = (a.DiemToan + a.DiemLy + a.DiemHoa) / 3;
}
void XuatSinhVien(SINHVIEN a){
    cout << a.MASV;         cout << "\t";
    cout << a.HoTen;        cout << "\t";
    XuatNgay(a.NgaySinh);   cout << "\t";
    cout << a.GioiTinh;     cout << "\t";
    cout << a.DiemToan;     cout << "\t";
    cout << a.DiemLy;       cout << "\t";
    cout << a.DiemHoa;      cout << "\t";
    cout << setprecision(3);
    cout << a.DTB;
}

NODE* CreateNode(SINHVIEN x){
    NODE* p = new NODE;
    p->key = x;
    p->pNext = NULL;
    return p;
}
void CreateEmptyList(LIST &l){
    l.pHead = l.pTail = NULL;
}
void AddTail(LIST&l, NODE*p ){
    if (l.pHead==NULL){
        l.pHead = l.pTail = p;
    }
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void XuatDS(LIST L) {
    if (L.pHead != NULL) {
        for (NODE*p = L.pHead; p!=NULL; p=p->pNext) {
            XuatSinhVien(p->key);
            cout << endl;
        }
    }
    else cout << "Empty List." << endl;
}

void NhapDS(LIST &L, int n) {
    CreateEmptyList(L);
    for (int i = 0; i < n; i++) {
        SINHVIEN x;
        NhapSinhVien(x);
        NODE* p = CreateNode(x);
        AddTail(L, p);
    }
}
void Tim_SinhVien_TheoNamSinh(LIST l, int n){
    bool check =0;
    NODE* p = l.pHead; 
    while(p!=NULL){
        if(p->key.NgaySinh.Nam == n) {
            XuatSinhVien(p->key);
            check = 1;
            cout<<endl;
        }
        p=p->pNext;
    }
    if (!check) {
        cout<<"Not found in list.";
    }
}