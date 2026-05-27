
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
int GetHeight(TNode *);

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

int GetHeight(TNode* root) {
    if (root == nullptr) return -1;
    else {
        return 1 + max(GetHeight(root->pLeft), GetHeight(root->pRight));
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
    
    cout << "Height: " << GetHeight(T.root);
    
    return 0;
}
