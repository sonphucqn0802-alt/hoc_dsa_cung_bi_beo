/*Hãy hoàn thành hàm Insert(HashTable &, STUDENT) để thêm một phần tử có kiểu dữ liệu STUDENT vào một bảng băm kiểu HashTable. Cho biết:

HashTable là loại bảng băm nối kết trực tiếp sử dụng danh sách liên kết đơn LIST để giải quyết đụng độ.
Hàm băm HashFunction sẽ biến đổi dữ liệu mã số sinh viên (MSSV) của học sinh thành chỉ số trong bảng băm bằng cách chia lấy dư MSSV cho kích thước tối đa của bảng băm.
Hệ số tải của bảng băm được cố định là 0.7, nghĩa là bảng băm luôn đảm bảo số phần tử được lưu trong bảng băm không chạm ngưỡng hoặc vượt quá 70% kích thước của bảng băm.
Số lượng phần tử cần thêm vào bảng băm không quá 1000 và bảng băm có kích thước không quá 1000 phần tử.
Input:
Dòng đầu tiên là kích thước tối đa M của bảng băm
Dòng thứ hai là số lượng sinh viên N được nhập thông tin để thêm vào bảng băm
5 * N dòng tiếp theo, mỗi 5 dòng thể hiện MSSV, Họ tên, Năm sinh, Giới tính, Điểm của sinh viên.
Output:
Bảng băm lưu trữ thông tin của các sinh viên
Lưu ý:
1) Chỉ cài đặt hàm Insert.
2) Các kiểu dữ liệu và các hàm cần thiết của các kiểu dữ liệu đã được cài đặt sẵn. Sinh viên có thể đọc để sử dụng.
3) Đầu vào và đầu ra đã được xử lý sẵn và phù hợp với định dạng nhập/xuất.*/


#include <iostream>
#include <string>

#define LOAD 0.7
using namespace std;

struct STUDENT {
    int MSSV;
    string HoTen;
    int NamSinh;
    bool GioiTinh;
    double TBK;
};

struct NODE {
    STUDENT data;
    NODE* pNext;
};

struct LIST {
    NODE* pHead;
    NODE* pTail;
};

NODE* CreateNode(STUDENT);
void CreateList(LIST &);
void AddTail(LIST&, STUDENT);
void DeleteList(LIST &);

struct HashTable {
    int M; // HashTable Size
    int n; // The number of keys in the current table
    LIST* Table;
};

void CreateHashTable(HashTable &, int);
int HashFunction(HashTable, int); // Hash Function
void Insert(HashTable &, STUDENT);
void PrintHashTable(HashTable);
void DeleteHashTable(HashTable &);

void Input(STUDENT &x) {
    cin >> x.MSSV;
    getline(cin >> ws, x.HoTen);
    cin >> x.NamSinh;
    cin >> x.GioiTinh;
    cin >> x.TBK;
}
int main()
{
    HashTable HT;

    int M, n;
    STUDENT sv;

    cin >> M;
    CreateHashTable(HT, M);
    cin >> n;
    for (int i = 0; i < n; i++) {
        Input(sv);
        Insert(HT, sv);
    }
    PrintHashTable(HT);
    DeleteHashTable(HT);
    return 0;
}

void CreateEmptyList(LIST &L) {
    L.pHead = L.pTail = NULL;
}

NODE* CreateNode(STUDENT x) {
    NODE *p = new NODE;
    p->data = x;
    p->pNext = NULL;
    return p;
}

void AddTail(LIST &L, STUDENT x) {
    NODE *p = CreateNode(x);
    if (L.pHead == NULL) {
        L.pHead = L.pTail = p;
    }
    else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void DeleteList(LIST &L) {
    while (L.pHead != NULL) {
        NODE *p = L.pHead;
        L.pHead = p->pNext;
        delete p;
    }
    L.pHead = L.pTail = NULL;
}

void CreateHashTable(HashTable &HT, int M) {
    HT.M = M;
    HT.n = 0;
    HT.Table = new LIST[M];
    for (int i = 0; i < M; i++)
        CreateEmptyList(HT.Table[i]);
}

int HashFunction(HashTable HT, int MSSV) {
    return MSSV % HT.M;
}

void PrintHashTable(HashTable HT) {
    for (int i = 0; i < HT.M; i++) {
        NODE* p = HT.Table[i].pHead;
        if (p == NULL) continue;
        while (p != NULL) {
            STUDENT sv = p->data;
            cout << "[" << sv.MSSV << ",  " << sv.HoTen << "  , " << sv.GioiTinh << ", " << sv.NamSinh << ", " << sv.TBK << "] ";
            p = p->pNext;
        }
        cout << "\n";
    }
}

void DeleteHashTable(HashTable &HT) {
    for (int i = 0; i < HT.M; i++) {
        DeleteList(HT.Table[i]);
    }
    delete [] HT.Table;
    HT.Table = NULL;
    HT.M = 0;
}

//hàm thực hiện thao tác
void Insert(HashTable &HT, STUDENT x) {
     if ((float) (HT.n + 1)/HT.M >=0.7){
          return;
     }
     int index = HashFunction(HT, x.MSSV);
     AddTail(HT.Table[index], x);
     HT.n++;
}
