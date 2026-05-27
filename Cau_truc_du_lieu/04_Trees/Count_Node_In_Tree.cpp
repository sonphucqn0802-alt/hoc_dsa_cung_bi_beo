/*Nhận vào một dãy gồm N số nguyên, hãy hình thành cây NPTK bằng cách thêm
các số này một cách tuyến tính và viết hàm đếm tổng số lượng nút trong cây
INPUT
- Dòng đầu tiên là số nguyên dương N
- Dòng thứ hai gồm N số nguyên.
OUTPUT
- In ra số lượng nút trong cây 
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TNode{
    int key;
    TNode* pLeft;
    TNode* pRight;
};

struct Tree{
    TNode* root;
};

void CreateTree(Tree &T)
{
    T.root = NULL;
}

TNode* CreateTNode(int x) {
    TNode* p = new TNode;
    p->key = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

void Insert(TNode* &, int);
int DemNut(TNode*);

void Insert(TNode* &root,int x) {
     if (root == nullptr) {
          root = CreateTNode(x);
          return;
     }
     if (x < root->key) {
          Insert(root->pLeft, x);
     }
     else {
          Insert(root->pRight, x);
     }
}

int DemNut(TNode* root) {
     if (root == nullptr) {
          return 0;
     }
     return 1 + DemNut(root->pLeft) + DemNut(root->pRight);
}




int main()
{
    Tree T;
    CreateTree(T);
    int n; cin >> n;
    int data;
    while(n != 0) {
        cin >> data;
        Insert(T.root, data);
        n--;
    }
    
    cout << "#Nodes: " << DemNut(T.root);
    
    return 0;
}

