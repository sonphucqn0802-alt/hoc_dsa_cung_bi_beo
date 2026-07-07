/*Hãy viết chương trình thực hiện các tác vụ sau:

Tạo một danh sách liên kết đơn để lưu trữ N số nguyên. Phần tử mới được THÊM vào ĐẦU danh sách liên kết
In ra toàn bộ danh sách liên kết*/ 

#include <iostream>
using namespace std;

struct NODE {
     int info;
     NODE *pNext;
};

struct LIST {
     NODE *pHead;
     NODE *pTail;
};


void CreateEmptyList (LIST &L) {
     L.pHead = NULL;
     L.pTail = NULL;
}

void InsertHead (LIST &L, NODE *p) {
     if (L.pHead == NULL) {
          L.pHead = p;
          L.pTail = L.pHead;
     }
     else {
          p->pNext = L.pHead;
          L.pHead = p;
     }
}

NODE* CreateNode(int x) {
     NODE*p = new NODE;
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

int main()
{
    LIST L;
    CreateEmptyList(L);
    int n; cin >> n;
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        InsertHead(L, CreateNode(x));
    }
    PrintList(L);
    return 0;
}
