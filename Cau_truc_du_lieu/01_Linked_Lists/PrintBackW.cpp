/*Hãy viết một chương trình nhập vào n số nguyên sau đó in ra không quá 10 phần tử được nhập vào đầu tiên có giá
trị lớn hơn hoặc bằng 90. 
Các phần tử này được in ngược với thứ tự nhập. 
Biết rằng, trong bài này, không được sử dụng mảng và không được include thêm thư viện.
Đầu vào của bài toán gồm:
- Dòng đầu tiên là số n.
- n số kế tiếp là các số nguyên từ 0 đến 99.
Đầu ra của bài toán là các số nguyên đầu tiên có giá trị lớn hơn hoặc bằng 90. 
Số lượng số nguyên được in ra không vượt quá 10 và liền sau kết quả là một khoảng trắng và chuỗi "END".*/


#include <iostream>

using namespace std;

struct NODE {
    int iData;
    NODE* pNext;
};

struct LIST {
    NODE* pHead;
    NODE* pTail;
};

NODE* createNode (int x) {
    NODE*p = new NODE;
    p->iData=x;
    p->pNext=NULL;
    return p;
}

void CreateEmptyList (LIST &L) {
    L.pHead=NULL;
    L.pTail=NULL;
}

void AddHead (LIST &L, NODE *x) {
    if (L.pHead == NULL) {
        L.pHead = x;
        L.pTail = L.pHead;
    }
    else {
        x->pNext = L.pHead;
        L.pHead = x;
    }
}

void PrintListCond(const LIST L){
    NODE *p = L.pHead;
    int n = 10;
    while (n!=0&&p!=NULL){
        if (p->iData >= 90){
            cout << p->iData << " ";
            n=n-1;
        }
        p = p->pNext;
    }
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    LIST L; CreateEmptyList(L);
    for (int i=0; i<n; i++) {
        int x; 
        cin>>x;
        NODE *p=createNode(x);
        AddHead(L,p);
     }
     PrintListCond(L);
     cout << "END";
    return 0;
}