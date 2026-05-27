/*Hãy viết chương trình thực hiện các tác vụ sau theo từng bước:

Tạo một danh sách liên kết đơn để lưu trữ N số nguyên. Phần tử mới được THÊM vào CUỐI danh sách liên kết.
Sắp xếp các phần tử trong danh sách theo trật tự tăng dần sử dụng Selection Sort và SWAP CON TRỎ thay vì SWAP GIÁ TRỊ 
In ra các phần tử trong danh sách đã được sắp xếp*/


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


void SwapPointers(LIST &L, NODE *p, NODE *node_min) {
    if (p == node_min || p == NULL || node_min == NULL)
        return;

    NODE *prev_p = NULL;
    NODE *prev_min = NULL;
    NODE *cur = L.pHead;

    while (cur != NULL && (prev_p == NULL || prev_min == NULL)) {
        if (cur->pNext == p)
            prev_p = cur;
        if (cur->pNext == node_min)
            prev_min = cur;
        cur = cur->pNext;
    }

    if (p->pNext == node_min) {
        if (prev_p != NULL)
            prev_p->pNext = node_min;
        else
            L.pHead = node_min;

        p->pNext = node_min->pNext;
        node_min->pNext = p;
    }
    else if (node_min->pNext == p) {
        if (prev_min != NULL)
            prev_min->pNext = p;
        else
            L.pHead = p;

        node_min->pNext = p->pNext;
        p->pNext = node_min;
    }
    else {
        if (prev_p != NULL)
            prev_p->pNext = node_min;
        else
            L.pHead = node_min;

        if (prev_min != NULL)
            prev_min->pNext = p;
        else
            L.pHead = p;

        NODE *tmp = p->pNext;
        p->pNext = node_min->pNext;
        node_min->pNext = tmp;
    }

    if (L.pTail == p)
        L.pTail = node_min;
    else if (L.pTail == node_min)
        L.pTail = p;
}

void SelectionSort(LIST &L){
    NODE* tmp;
    NODE* p = L.pHead;
    NODE* q;
    NODE* node_min;
    while (p != NULL){
        node_min = p;
        for (q = p->pNext; q != NULL; q = q->pNext){
            if (q->info < node_min->info)
                node_min = q;
        }
        SwapPointers(L, p, node_min);
        p = node_min->pNext;
    }
}

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
    SelectionSort(L);
    PrintList(L);
    return 0;
}
