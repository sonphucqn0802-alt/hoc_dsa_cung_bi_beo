#include <iostream>
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
    TNode* p;
    p = new TNode;
    if (p == NULL)
        exit(1);
    p->key = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

void Insert(TNode* &, int);
void NLR(TNode *);
void NRL(TNode *);
void LNR(TNode *);
void LRN(TNode *);
void RNL(TNode *);
void RLN(TNode *);

     void Insert (TNode* &root, int x) {
     if (root == NULL) {
          root = CreateTNode(x);
          return;
     }
     if (x < root->key) {
          Insert(T.root->pLeft, x);
     }
     else {
          Insert(T.root->pRight, x);
     }
     }

void NLR(TNode *root){
    if (root != NULL) {
        cout << root->key << " ";
        NLR(root->pLeft);
        NLR(root->pRight);
    }
}
void NRL(TNode *root){
    if (root != NULL) {
        cout << root->key << " ";
        NRL(root->pRight);
        NRL(root->pLeft);
    }
}
void LNR(TNode *root){
    if (root != NULL) {
        LNR(root->pLeft);
        cout << root->key << " ";
        LNR(root->pRight);
    }
}
void LRN(TNode *root){
    if (root != NULL) {
        LRN(root->pLeft);
        LRN(root->pRight);
        cout << root->key << " ";
    }
}
void RNL(TNode *root){
    if (root != NULL) {
        RNL(root->pRight);
        cout << root->key << " ";
        RNL(root->pLeft);
    }
}
void RLN(TNode *root){
    if (root != NULL) {
        RLN(root->pRight);
        RLN(root->pLeft);
        cout << root->key << " ";
    }
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
    
    cout << "NRL: ";
    NRL(T.root);
    cout << "\n";

    cout << "LNR: ";
    LNR(T.root);
    cout << "\n";

    cout << "LRN: ";
    LRN(T.root);
    cout << "\n";

    cout << "RLN: ";
    RLN(T.root);
    cout << "\n";

    cout << "RNL: ";
    RNL(T.root);
    
    return 0;
}
