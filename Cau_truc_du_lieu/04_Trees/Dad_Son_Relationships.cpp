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
bool isFather(Tree, int, int);
void run(int, Tree);


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

bool isFather(Tree T, int father, int son) {
     TNode* current = T.root;
     while (current != nullptr) {
          if (current->key == father) {
               if (current->pLeft != nullptr && current->pLeft->key == son) {
                    return true;
               }
               if (current->pRight != nullptr && current->pRight->key == son) {
                    return true;
               }
               return false;
          }
          else if (father < current->key) {
               current = current->pLeft;
          }
          else {
               current = current->pRight;
          }
     }
     return false;
}

void run(int q, Tree T) {
     while (q != 0) {
          int father, son;
          cin >> father >> son;
          if (isFather(T, father, son)) {
               cout << father << " la cha cua "<< son << endl;
          }
          else {
               if (isFather(T, son, father)) {
                    cout << son << " la cha cua "<< father << endl;
               }
               else {
                    cout << father << " va " << son << " khong co quan he cha con" << endl;
               }
          }
          q--;
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
