#include <iostream>

using namespace std;

struct TNode {
     int key;
     TNode* pLeft;
     TNode* pRight;
};

typedef TNode* Tree;

// search Node không dùng đệ quy
TNode* searchNode(Tree Root, int x) {
     TNode *p = Root;
     while (p!=NULL) {
          if (x==p->key) {
               return p;
          }
          else if (x<p->key) {
               p = p->pLeft;
          }
          else {
               p = p->pRight;
          }
     }
     return NULL;
}

// search Node có dùng đệ quy
TNode * searchNodeRecursive(Tree T, int x) {
     if (T != NULL) {
          if (T->key == x){
               return T;
          }
          else if (T->key > x){
               return searchNodeRecursive(T->pLeft, x);
          }
          
          return searchNodeRecursive(T->pRight, x);
     }
     return NULL;
}

int main(){
     Tree root = NULL;
     root = searchNode(root, 5);
     root = searchNodeRecursive(root, 5);
     return 0;
}
