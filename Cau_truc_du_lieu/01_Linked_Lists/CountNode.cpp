#include <iostream>
using namespace std;

struct NODE{
     int data;
     NODE* next;
};
struct LIST{
     NODE *head;
     NODE *tail;
};

void CreateEmptyList(LIST &L) {
     L.head = NULL;
     L.tail = NULL;
}

NODE* CreateNode(int x) {
     NODE* p = new NODE;
     if (p == NULL) exit(1);
     p->data = x;
     p->next = NULL;
     return p;
}

void InsertTail(LIST &L, NODE *p){
     if (L.head==NULL) {
          L.head = p;
          L.tail=p;
     }
     else {
          L.tail->next=p;
          L.tail=p;
     }
}

int DemSoLuongPhanTuTrongL(LIST L) {
     int count = 0;
     NODE *p=L.head;
     while (p!=NULL) {
          count++;
          p=p->next;
     }
     return count;
}

void InsertTail(LIST &, NODE *);
int DemSoLuongPhanTuTrongL(LIST);

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
    int k = DemSoLuongPhanTuTrongL(L);
    cout << k;
    return 0;
}
