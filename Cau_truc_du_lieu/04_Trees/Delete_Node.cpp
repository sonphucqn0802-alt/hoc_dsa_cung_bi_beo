/*Lưu ý: khi xóa node thì lấy nhánh bên trái (nhánh nhỏ)*/

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
bool DeleteNode(TNode* &, int);
void NLR(TNode*);
void process(Tree &, int);

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

bool DeleteNode (TNode* &root, int x) {
     if (root == nullptr) {
          return false;
     }
     if (root->key == x) {
          return true;
     }
     if (x < root->key) {
          return DeleteNode(root->pLeft, x);
     }
     else if (x > root->key) {
          return DeleteNode(root->pRight, x);
     }
     else {
          // Found the node to delete
          if (root->pLeft->key == x) {
               return true;
          }
          else if (root->pRight->key == x) {
               return true;
          }
     }
}

void NLR (TNode* root) {
     if (root != nullptr) {
          cout << root->key << " ";
          NLR(root->pLeft);
          NLR(root->pRight);
     }
}

void process(Tree & T, int x){
     if 
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree T;
    CreateTree(T);
    int n, k; cin >> n;
    while(n--) {
        cin >> k;
        Insert(T.root, k);
    }
    int q, x; cin >> q;
    while(q--){
        cin >> x;
        process(T, x);
    }
    cout << "NLR: ";
    NLR(T.root);
    return 0;
}
