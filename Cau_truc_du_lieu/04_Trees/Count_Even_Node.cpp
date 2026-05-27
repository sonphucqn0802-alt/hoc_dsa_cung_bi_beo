/*Nhận vào một dãy gồm N số nguyên, hãy hình thành cây NPTK bằng cách thêm
các số này một cách tuyến tính và viết hàm đếm tổng số lượng nút có giá trị chẵn
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
int DemNutChan(TNode *);

void Insert(TNode* &root, int x) {
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

int DemNutChan(TNode* root) {
     if (root == nullptr) {
          return 0;
     }
     int dem = 0;
     if (root->key % 2 == 0) {
          dem = 1;
     }
     return dem + DemNutChan(root->pLeft) + DemNutChan(root->pRight);
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
    
    cout << "#EvenNodes: " << DemNutChan(T.root);
    
    return 0;
}
