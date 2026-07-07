/*Viết chương trình nhập vào một dãy A có n số nguyên x và một danh sách P gồm k ví trí trong dãy A.
Hãy tính tổng Sum các số ở từng vị trí P[i] trong dãy A và in ra giá trị Sum này. 
Biết mỗi vị trí P[i] được xét một lần duy nhất. 
Yêu cầu không được sử dụng cấu trúc mảng và các thư viện khác iostream.
Định dạng dữ liệu nhập:
- Số đầu tiên là n, n∈[0, 105].
- n số tiếp theo là các số nguyên x trong dãy A, x∈[-14.103, 14.103]
- Kế đến là số k cho biết số chỉ số trong dãy P, k∈[13, 104]
- k số tiếp theo là các chỉ số cần tính tổng trong dãy A, k∈[1, n]*/

/*Ex:
Đầu vào
5
1 4 5 -2 -7
3
2 1 4   
Đầu ra
2
*/

#include <iostream>

using namespace std;
	
struct NODE {
     int info;
     NODE *pNext;
};

struct  lisst{
     NODE *pHead;
     NODE *pTail;
};


void CreateEmptylisst (lisst &L) {
     L.pHead = NULL;
     L.pTail = NULL;
}

void AddTail (lisst &L, NODE *p) {
     if (L.pHead == NULL) {
          L.pHead = p;
          L.pTail = L.pHead;
     }
     else {
          L.pTail->pNext = p;
          L.pTail = p;
     }
}

NODE* CreateNode(int x) {
     NODE*p = new NODE;
     p->info = x;
     p->pNext = NULL;
     return p; 
}


void Printlisst(lisst L)
{
    NODE *p = L.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    lisst lisst;
    lisst.pHead = NULL;
    lisst.pTail = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        NODE* p = CreateNode(x);
        AddTail(lisst, p);
    }
        int k;
        cin >> k;
        int sum = 0;
        for (int i = 0; i < k; i++) {
            int pos;
            cin >> pos;
            // Duyệt đến vị trí pos và cộng vào tổng
            NODE *p = lisst.pHead;
            for (int j = 0; j < pos; j++) {
                p = p->pNext;
            }
            // Cộng vào tổng
            sum += p->info;
        }
    
    cout << sum;
    
    return 0;

}
