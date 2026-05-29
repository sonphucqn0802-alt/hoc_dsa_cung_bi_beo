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
void AddTail(LIST &, STUDENT);
void DeleteList(LIST &);

struct HashTable {
    int M; // HashTable Size
    int n; // The number of keys in the current table
    LIST* Table;
};

void CreateHashTable(HashTable &, int);
int HashFunction(HashTable, int); // Hash Function
void PrintHashTable(HashTable);
void DeleteHashTable(HashTable &);
void Insert(HashTable &, STUDENT);
NODE* Search(HashTable , int);

void Input(STUDENT &x) {
    cin >> x.MSSV;
    getline(cin >> ws, x.HoTen);
    cin >> x.NamSinh;
    cin >> x.GioiTinh;
    cin >> x.TBK;
}

void Output(STUDENT sv){
    cout << "[" << sv.MSSV << ", " << sv.HoTen << ", " << sv.GioiTinh << ", " << sv.NamSinh << ", " << sv.TBK << "] ";
}

int main()
{
    HashTable HT;

    int M, n, k, mssv;
    STUDENT sv;

    cin >> M;
    CreateHashTable(HT, M);
    cin >> n;
    for (int i = 0; i < n; i++) {
        Input(sv);
        Insert(HT, sv); // Code cái này
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> mssv;
        NODE *p = Search(HT, mssv);   // Code cái này

        if (p == NULL)
            cout << "KHONG TIM THAY\n";
        else {
            sv = p->data;
            Output(sv);
            cout << "\n";
        }
    }
    DeleteHashTable(HT);
    return 0;
}

void CreateEmptyList(LIST &L) {
    L.pHead = L.pTail = NULL;
}

NODE* CreateNode(STUDENT x) {
    NODE *p = new NODE;
    p->pNext = NULL;
    p->data = x;
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
            Output(sv);
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

void Insert(HashTable &HT, STUDENT x) {
     if ((float) (HT.n+1)/HT.M >=0.7) {
          return;
     }
     int index = HashFunction(HT,x.MSSV);
     AddTail(HT.Table[index], x);
     HT.n++;
}
NODE* Search(HashTable HT, int x){
     int dem = 0;
     int index = HashFunction(HT, x);
     NODE* p = HT.Table[index].pHead;
     while (p != NULL) {
          if (p->data.MSSV == x) {
               return p;
          }
          p = p->pNext;
     }
     return NULL;
}