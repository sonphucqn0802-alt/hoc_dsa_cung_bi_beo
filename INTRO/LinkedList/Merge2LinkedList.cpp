/*
Hãy viết chương trình thực hiện các tác vụ sau theo từng bước:

Tạo một danh sách liên kết đơn L1 để lưu trữ N số nguyên. Phần tử mới được THÊM vào CUỐI danh sách liên kết
Tạo một danh sách liên kết đơn L2 để lưu trữ M số nguyên. Phần tử mới được THÊM vào CUỐI danh sách liên kết
Nối danh sách L2 vào sau danh sách L1
In ra 2 danh sách L1 và L2
*/


#include <iostream>
using namespace std;

struct NODE {
    int info;
    NODE* pNext;
};


struct LIST {
    NODE* pHead;
    NODE* pTail;
};

void CreateEmptyList(LIST &L) {
    L.pHead = NULL;
    L.pTail = NULL;
}

NODE* CreateNode(int x) {
    NODE* p = new NODE;
    if (p == NULL)
        exit(1);
    p->info = x;
    p->pNext = NULL;
    return p;
}

void InsertTail(LIST &L, NODE* p) {
    if (L.pHead == NULL) {
        L.pTail = p;
        L.pHead = L.pTail;
    }
    else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void PrintList(LIST L)
{
    NODE *p = L.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
}

void Noi(LIST &, LIST);

void Noi(LIST &L1, LIST L2) {
    L1.pTail->pNext = L2.pHead;
    L1.pTail = L2.pTail;
}




int main()
{
    LIST L1, L2;
    CreateEmptyList(L1);
    CreateEmptyList(L2);
    int n; cin >> n;
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        InsertTail(L1, CreateNode(x));
    }
    int m; cin >> m;
    for (int i = 0; i < m; i++){
        cin >> x;
        InsertTail(L2, CreateNode(x));
    }
    Noi(L1, L2);
    PrintList(L1);
    cout << "\n";
    PrintList(L2);
    return 0;
}
