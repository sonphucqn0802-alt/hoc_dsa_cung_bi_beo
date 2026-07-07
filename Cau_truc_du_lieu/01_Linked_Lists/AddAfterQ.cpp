/*Hãy viết chương trình thực hiện các tác vụ sau:

Tạo một danh sách liên kết đơn để lưu trữ N số nguyên. 
Tìm và thêm một phần tử có giá trị X sau phần tử có giá trị K trong danh sách liên kết*/ 

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

void PrintList(LIST L)
{
    NODE *p = L.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
}


NODE* InsertTail(LIST &L, NODE* p) {
    if (L.pHead == NULL) {
        L.pHead = p;
        L.pTail = p;
    }
    else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
    return p;
}

NODE*TimKiem(LIST L, int x) {
    NODE* p = L.pHead;
    while (p != NULL) {
        if (p->info == x) {
            return p;
        }
        p = p->pNext;
    }
    return NULL;
}

void InsertNode(LIST &L, NODE* p) {
    if (L.pHead == NULL) {
        L.pHead = p;
        L.pTail = p;
    }
    else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void TimKiemVaThem(LIST &L, int k) {
    NODE* p = TimKiem(L, k);
    NODE* l = CreateNode(1999);

    if (p == NULL) {
        InsertTail(L, l);
    }
    else {
        l->pNext = p->pNext;
        p->pNext = l;

        if (p == L.pTail) {
            L.pTail = l;
        }
    }

    PrintList(L);
}



NODE* TimKiem(LIST, int);
void InsertNode(LIST &, NODE*);
void TimKiemVaThem(LIST &, int);

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
    TimKiemVaThem(L, k);
    return 0;
}
