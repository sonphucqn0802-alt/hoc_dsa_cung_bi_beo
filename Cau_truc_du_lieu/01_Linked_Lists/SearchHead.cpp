/*
Hãy viết chương trình thực hiện các tác vụ sau theo từng bước:

Tạo một danh sách liên kết đơn để lưu trữ N số nguyên. Phần tử mới được THÊM vào CUỐI danh sách liên kết
In ra vị trí xuất hiện đầu tiên của phần tử K trong danh sách liên kết. Nếu K không có trong danh sách thì
in ra -1.
*/


#include <iostream>
using namespace std;

struct NODE {
     int data;
     NODE * pNext;
};

struct LIST {
     NODE * pHead;
     NODE * pTail;
};

void CreateEmptyList(LIST &L) {
     L.pHead = NULL;
     L.pTail = NULL;
}

NODE* CreateNode(int x) {
     NODE *p = new NODE;
     if (p == NULL) exit(1);
     p->data = x;
     p->pNext = NULL;
     return p;
}

void InsertTail (LIST &L, NODE *p) {
     if (L.pHead == NULL) {
          L.pHead = p;
          L.pTail = L.pHead; 
     }
     else {
          L.pTail->pNext = p;
          L.pTail = p;
     }
}

int TimKiem(LIST L, int x) {
     int pos = 0;
     NODE*p = L.pHead;
     while (p != NULL && p->data != x) {
          pos += 1;
          p = p->pNext;
     }
     if (p==NULL) return -1;
     return pos;
}

int TimKiem(LIST, int);


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
    cout << TimKiem(L, k);
    return 0;
}
