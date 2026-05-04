/*Nhận vào một dãy gồm N số nguyên, hãy hình thành cây NPTK bằng cách thêm
các số này một cách tuyến tính và tìm giá trị min, max của cây đó. 
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
void InMinMax(TNode*);

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

void InMinMax(TNode* root) {
     if (root == nullptr) {
          return;
     }
     TNode* current = root;
     while (current->pLeft != nullptr) {
          current = current->pLeft;
     }
     cout << "Min: " << current->key << endl;
     current = root;
     while (current->pRight != nullptr) {
          current = current->pRight;
     }
     cout << "Max: " << current->key << endl;
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
    
    InMinMax(T.root);
    
    return 0;
}
