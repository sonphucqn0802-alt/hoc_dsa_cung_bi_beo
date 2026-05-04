/*Nhận vào một dãy gồm N số nguyên, hãy hình thành cây NPTK bằng cách thêm
các số này một cách tuyến tính và viết hàm kiểm tra xem 2 nút bất kỳ có quan hệ anh em
không.*/

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
bool isBrother(Tree, int, int);
void run(int, Tree);


void Insert(TNode* &root, int x) {
     if (root == nullptr) {
          root = CreateTNode (x);
          return;
     }
     if (x < root->key) {
          Insert(root->pLeft, x);
     }
     else {
          Insert(root->pRight, x);
     }
}


bool isBrother(Tree T, int x, int y) {
    if (T.root == nullptr) return false;

    // nếu node có 2 con
    if (T.root->pLeft != nullptr && T.root->pRight != nullptr) {
        int l = T.root->pLeft->key;
        int r = T.root->pRight->key;

        if ((l == x && r == y) || (l == y && r == x)) {
            return true;
        }
    }

    // kiểm tra bên trái
    Tree leftTree;
    leftTree.root = T.root->pLeft;

    // kiểm tra bên phải
    Tree rightTree;
    rightTree.root = T.root->pRight;

    return isBrother(leftTree, x, y) || isBrother(rightTree, x, y);
}

void run(int q, Tree T) {
     while (q--) {
          int x,y;
          cin >> x >> y;
          if (isBrother(T,x,y)){
               cout << x << " va " << y << " la anh em" << endl;
          }
          else cout << x << " va " << y << " khong phai la anh em" << endl;
     }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree T;
    CreateTree(T);
    int n; cin >> n;
    int data;
    while(n != 0) {
        cin >> data;
        Insert(T.root, data);
        n--;
    }
    int q; cin >> q;
    run(q, T);
    
    return 0;
}
