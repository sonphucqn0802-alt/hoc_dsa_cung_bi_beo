#include <iostream>
using namespace std;

// cấu trúc node
struct Node{
     int key;
     Node* next;
};

// cấu trúc bảng băm
struct HashTable{
     int M;
     Node** table;
};

// hàm khởi tạo bảng băm có kích thước là size
void initHashTable(HashTable &ht, int size) {
     ht.M=size;
     ht.table = new Node*[size];
     for (int i = 0; i<size; i++) {
          ht.table[i]=nullptr;
     }
}

// hàm băm cơ sở (phương pháp Division)
int hashFunc(int key, int M) {
     int hash = key % M;
     if (hash < 0) hash += M;
     return hash;
}

//Thao tac TIM KIEM (Search)
Node* searchKey(HashTable ht, int key) {
     int index = hashFunc(key,ht.M);
     Node*current = ht.table[index];
     
     while (current != nullptr) {
          if (current->key == key) {
               return current;
          }
          current = current->next;
     }
     return nullptr;
}

//Thao tác CHÈN (Insert) - Thêm vào đầu danh sách liên kết tại vị trí băm
void insertKey(HashTable &ht, int key){
     int index = hashFunc(key, ht.M);
     
     // Kiem tra trung lap (tuy chon)
     if (searchKey(ht, key) != nullptr) 
          return;
     
     //tao node moi
     Node* newNode = new Node;
     newNode->key = key;
     
     //chen vao dau danh sach
     newNode->next = ht.table[index];
     ht.table[index] = newNode;
}



void printHashTable (HashTable ht) {
     for (int i = 0; i<ht.M; i++) {
          cout << "Bucket " << i << ": ";
          Node* current = ht.table[i];
          while (current != nullptr) {
               cout << current->key << " -> ";
               current = current->next;
          }
          cout << "NULL\n";
     }
}

// Ham giai phong bo nho
void deleteHashTable(HashTable &ht) {
     for (int i = 0; i < ht.M; i++) {
          Node* current = ht.table[i];
          while (current != nullptr) {
               Node* temp = current;
               current = current->next;
               delete temp;
          }
     }
     delete[] ht.table;
     ht.table = nullptr;
}


int main() {
     HashTable ht;
     initHashTable (ht, 7);
     
     insertKey(ht, 10);
     insertKey(ht, 20);
     insertKey(ht, 15);
     insertKey(ht, 22);
     cout << "--- TRẠNG THÁI BẢNG BĂM SEPARATE CHAINING ---\n";
     printHashTable(ht);

     int target=15;
     if (searchKey(ht,target) != nullptr) {
          cout << "Tim thay " << target << " trong bang bam\n";
     }
     else {
          cout << "Khong tim thay " << target << " trong bang bam\n";
     }

     deleteHashTable(ht);
     return 0;
}
