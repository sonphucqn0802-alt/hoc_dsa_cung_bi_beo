/*Hãy viết chương trình thực hiện các tác vụ sau:

Tạo một danh sách liên kết đơn để lưu trữ N số nguyên. 
Tìm và xóa phần tử có giá trị X trong danh sách liên kết*/ 

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
        L.pHead = p;
        L.pTail = p;
    }
    else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void PrintList(LIST L) {
    NODE* p = L.pHead;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->pNext;
    }
    cout << endl;
}

NODE* TimKiem(LIST L, int x) {
    NODE* p = L.pHead;
    while (p != NULL) {
        if (p->info == x) {
            return p;
        }
        p = p->pNext;
    }
    return NULL;
}

void DeleteNode(LIST &L, NODE* p) {
    if (L.pHead == NULL) {
        return;
    }
    if (L.pHead == p) {
        L.pHead = L.pHead->pNext;
        delete p;
        return;
    }
    NODE* q = L.pHead;
    while (q != NULL && q->pNext != p) {
        q = q->pNext;
    }
    if (q != NULL) {
        q->pNext = p->pNext;
        if (p == L.pTail) {
            L.pTail = q;
        }
        delete p;
    }
}

void TimKiemVaXoa(LIST &L, int x) {
    NODE* p = TimKiem(L, x);
    if (p == NULL) {
        cout << -1 << endl;
    }
    else {
        DeleteNode(L, p);
        PrintList(L);
    }
}




NODE* TimKiem(LIST, int);
void DeleteNode(LIST &, NODE*);
void TimKiemVaXoa(LIST &, int);


int main()
{
    LIST L;
    CreateEmptyList(L);
    int n; cin >> n;
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        InsertTail(L, CreateNode(x));
    }
    int k; cin >> k;
    TimKiemVaXoa(L, k);
    return 0;
}
