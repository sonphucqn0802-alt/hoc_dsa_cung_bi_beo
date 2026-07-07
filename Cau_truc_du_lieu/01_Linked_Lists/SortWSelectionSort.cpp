
/*Hãy viết chương trình thực hiện các tác vụ sau:

Tạo một danh sách liên kết đơn để lưu trữ N số nguyên. 
Sắp xếp danh sách liên kết đơn theo thứ tự tăng dần*/ 

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

void SelectionSort(LIST &);

void SelectionSort(LIST &L) {
    NODE* current = L.pHead;
    while (current != NULL) {
        NODE* min = current;
        NODE* next = current->pNext;
        while (next != NULL) {
            if (next->info < min->info) {
                min = next;
            }
            next = next->pNext;
        }
        int temp = current->info;
        current->info = min->info;
        min->info = temp;
        current = current->pNext;
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
