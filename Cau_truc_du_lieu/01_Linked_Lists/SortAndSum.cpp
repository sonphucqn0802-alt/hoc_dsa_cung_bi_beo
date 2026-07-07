/*Viết chương trình nhập vào một dãy A có n số nguyên x. Hãy sắp xếp dãy A theo thứ tự giảm dần. 
Sau đó, tính tổng Sum các số ở vị trí chẵn (vị trí 0, 2, 4, ...) và in ra giá trị Sum này. 
Yêu cầu không được sử dụng cấu trúc mảng và các thư viện khác iostream.
Định dạng dữ liệu nhập:
- Số đầu tiên là n, n∈[0, 105].
- n số tiếp theo là các số nguyên x trong dãy A, x∈[-14.103, 14.103]*/


#include <iostream>

using namespace std;
	
struct Node {
    int info;
    Node* pNext; 
};

struct lisst {
    Node* pHead;
    Node* pTail;
};

Node* CreateNode(int info) {
    Node* p = new Node;
    p->info = info;
    p->pNext = NULL;
    return p;
}

void createEmptylisst(lisst& lisst) {
    lisst.pHead = NULL;
    lisst.pTail = NULL;
}

void addTail(lisst& lisst, Node* node) {
    if (lisst.pHead == NULL) {
        lisst.pHead = node;
        lisst.pTail = node;
    } else {
        lisst.pTail->pNext = node;
        lisst.pTail = node;
    }
}

void MySelectionSort(lisst &lisst){
    if (lisst.pHead == NULL) {
        return;
    }
    Node*p=lisst.pHead;
    for (Node*i=p; i->pNext!=NULL; i=i->pNext) {
        for(Node*j=i->pNext; j!=NULL; j=j->pNext) {
            if(i->info<j->info) {
                int temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }        
    }    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lisst lisst;
    createEmptylisst(lisst);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node* node = CreateNode(x);
        addTail(lisst, node);
    }

    MySelectionSort(lisst);
    int sum = 0;
    for (int i = 0; i < n; i += 2) {
        sum += lisst.pHead->info;
        if (lisst.pHead->pNext == NULL) {
            break;
        }
        lisst.pHead = lisst.pHead->pNext->pNext;
    }
    cout << sum;
    return 0;
}