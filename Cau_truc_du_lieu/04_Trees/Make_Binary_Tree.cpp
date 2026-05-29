#include <iostream>
#include <vector>

using namespace std;

struct TNode {
     int key;
     TNode* pLeft;
     TNode* pRight;
};

typedef TNode* Tree;

//Tạo node mới 
TNode* MakeNode (int x) {
     TNode* newNode = new TNode;
     newNode->key = x;
     newNode->pLeft = nullptr;
     newNode->pRight = nullptr;
     return newNode;
}

//Thêm 1 phần tử vào cây nhị phân
void InsertNode (Tree &root, int x) {
     if (root == nullptr) {
          root = MakeNode (x);
          return;
     }
     if (x<root->key) {
          InsertNode (root->pLeft, x);
     }
     else {
          InsertNode (root->pRight, x);
     }
}

//Duyệt NLR
void NRL (Tree root) {
     if (root != nullptr) {
          cout << root->key << " ";
          NRL (root->pLeft);
          NRL (root->pRight);
     }
     return;
}

// Duyệt LNR
void LNR (Tree root) {
     if (root != nullptr){
          LNR(root->pLeft);
          cout << root->key << " ";
          LNR(root->pRight);
     }
     return;
}

// Duyệt LRN
void LRN (Tree root) {
     if (root != nullptr){
          LRN(root->pLeft);
          LRN(root->pRight);
          cout << root->key << " ";
     }
     return;
}

// Duyệt RLN
void RLN (Tree root) {
     if (root != nullptr){
          RLN(root->pRight);
          RLN(root->pLeft);
          cout << root->key << " ";
     }
     return;
}

// Duyệt RNL
void RNL (Tree root) {
     if (root != nullptr){
          RNL(root->pRight);
          cout << root->key << " ";
          RNL(root->pLeft);
     }
     return;
}


int main(){
     int N;
     cin >> N;

     vector<int> arr(N);
     for (int i = 0; i < N; i++) {
          cin >> arr[i];
     }

     Tree root = nullptr;
     for (int x : arr) {
          InsertNode(root, x);
     }

     NRL(root);
     cout << endl;
     LNR(root);
     cout << endl;
     LRN(root);
     cout << endl;
     RLN(root);
     cout << endl;
     RNL(root);
     return 0;
}