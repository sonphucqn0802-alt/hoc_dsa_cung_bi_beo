/*Kiểu dữ liệu cấu trúc để quản lý sinh viên gồm các thành phần là Mã số Sinh viên (MASV) (kiểu chuỗi), Họ và Tên (HoTen) (kiểu chuỗi), Năm sinh (kiểu struct gồm Ngày, Tháng và Năm kiểm int), Giới tính (kiểu ký tự), Điểm toán (kiểu số thực), Điểm lý (kiểu số thực), Điểm hóa (kiểu số thực), Điểm Trung bình (kiểu số thực).

Được biết, danh sách hiện tại đã được sắp xếp theo thứ tự giảm dần MASV, dựa vào template, hãy hoàn thành chương trình giúp chèn một sinh viên mới vào danh sách hiện tại nhưng vẫn giữ được trật tự ban đầu.

INPUT
Dãy các ký tự và số trong đó: (Giả sử luôn thỏa điều kiện nhập)

5 Dòng đầu tiên: thông tin của sinh viên mới cần chèn vào.
Dòng tiếp theo: Số lượng n phần tử trong danh sách.
Các dòng tiếp theo: Thông tin của n sinh viên.
Trong đó cứ mỗi 5 dòng thể hiện 7 thông tin của một sinh viên trong mảng:
Dòng thứ 1: Chuỗi Mã số sinh viên
Dòng thứ 2: Chuỗi Họ tên sinh viên
Dòng thứ 3: 3 giá trị Ngày Tháng Năm sinh cách nhau 1 khoảng trắng
Dòng thứ 4: Ký tự thể hiện giới tính: M (Nam) hoặc F (Nữ)
Dòng thứ 5: 3 Số thực lưu Điểm toán lý hóa cách nhau 1 khoảng trắng
OUTPUT
Hiển thị Danh sách n+1 sinh viên (giảm dần theo yêu cầu) trên n+1 dòng liên tiếp. Mỗi dòng hiển thị 8 thông tin theo thứ tự sau:

Mã số Sinh viên, Họ và Tên, Năm sinh, Giới tính, Điểm toán, Điểm lý, Điểm hóa, Điểm Trung bình.
Mỗi thông tin cách nhau một dấu tab (\t)
Điểm trung bình hiển thị hai số lẻ sau dấu thập phân (nếu có).*/

NODE* CreateNode(SINHVIEN x){
    NODE* p = new NODE;
    p->key = x;
    p->pNext = NULL;
    return p;
}
void CreateEmptyList(LIST &L){
    L.pHead = L.pTail = NULL;
}
void AddTail(LIST& l, NODE* p){
    if (l.pHead == NULL){
        l.pHead = l.pTail = p;
    }else{
        l.pTail ->pNext = p;
        l.pTail = p;
    }
}
void XuatDS(LIST L){
    NODE * p = L.pHead;
    while(p!=NULL){
        SINHVIEN sv = p->key;
        XuatSinhVien(sv);
        cout<<endl;
        p = p->pNext;
    }
}
void NhapDS(LIST &L, int n){
    CreateEmptyList(L);
    for (int i=0;i<n;i++){
        SINHVIEN x;
        NhapSinhVien(x);
        NODE*p = CreateNode(x);
        AddTail(L,p);
    }
}
void ChenGiam(LIST &l , SINHVIEN x){
    NODE*sv = CreateNode(x);
    if (l.pHead == NULL){
        AddTail(l,sv);
        return;
    }
    NODE*p = l.pHead;
    NODE*prev;
    //AddHead;

    if (l.pHead->key.MASV < sv->key.MASV){
        sv->pNext = p;
        l.pHead = sv;
        return;
    }
    while(p!=NULL){
        if(p->key.MASV < sv->key.MASV){
            break;
        }
        prev = p;
        p=p->pNext;
    }
    if(p==NULL){
        AddTail(l,sv);
    }else{
        sv->pNext = p;
        prev->pNext = sv;
    }
}