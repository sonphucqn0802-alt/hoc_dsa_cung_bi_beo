/*
Hãy viết chương trình thực hiện các tác vụ sau theo từng bước:

Tạo một danh sách liên kết đơn L1 để lưu trữ N số nguyên. Phần tử mới được THÊM vào CUỐI danh sách liên kết.
Tạo một danh sách liên kết đơn L2 để lưu trữ M số nguyên. Phần tử mới được THÊM vào CUỐI danh sách liên kết
Biết rằng các phần tử ở L1 và L2 đều được sắp xếp theo trật tự tăng dần. Thực hiện tác vụ gộp các phần tử L1 và L2 vào danh sách L3 để L3 cũng có trận tự tăng dần
In ra các phần tử trong L3
*/
#include <bits/stdc++.h>
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

void TronDSLK(LIST &, LIST &, LIST &);

void TronDSLK(LIST &L1, LIST &L2, LIST &L3) {
    CreateEmptyList(L3);

    NODE* p1 = L1.pHead;
    NODE* p2 = L2.pHead;

    while (p1 != NULL && p2 != NULL) {
        if (p1->info <= p2->info) {
            InsertTail(L3, CreateNode(p1->info));
            p1 = p1->pNext;
        }
        else {
            InsertTail(L3, CreateNode(p2->info));
            p2 = p2->pNext;
        }
    }

    while (p1 != NULL) {
        InsertTail(L3, CreateNode(p1->info));
        p1 = p1->pNext;
    }

    while (p2 != NULL) {
        InsertTail(L3, CreateNode(p2->info));
        p2 = p2->pNext;
    }
}





int main()
{
    int t; cin >> t;
    LIST L1;
    LIST L2;
    LIST L3;
    for (int pid = 0; pid < t; pid++){
        CreateEmptyList(L1);
        int n, m; cin >> n >> m;
        int x;
        for (int i = 0; i < n; i++){
            cin >> x;
            InsertTail(L1, CreateNode(x));
        }
        CreateEmptyList(L2);
        for (int i = 0; i < m; i++){
            cin >> x;
            InsertTail(L2, CreateNode(x));
        }
        TronDSLK(L1, L2, L3);
        PrintList(L3);
        cout << "\n";
    }
    return 0;
}
