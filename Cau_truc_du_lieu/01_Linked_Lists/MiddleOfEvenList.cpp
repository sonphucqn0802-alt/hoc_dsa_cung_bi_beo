/*Hãy viết một chương trình nhập vào n số nguyên sau đó in ra số ở vị trí chính giữa của dãy số chẵn theo đúng thứ tự nhập vào. Nếu không vị trí chính giữa, thì lấy số ở vị trí lệch bên trái gần vị trí chính giữa nhất. Biết rằng, trong bài này, không được sử dụng mảng và không được include thêm thư viện.
Đầu vào của bài toán gồm:
- Dòng đầu tiên là số n.
- n số kế tiếp là các số nguyên dương.
Đầu ra của bài toán là một số duy nhất, chính là số ở vị trí chính giữa*/

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* head;
    Node* tail;
};

Node* CreateNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

void CreateList(List &l) {
    l.head = NULL;
    l.tail = NULL;
}

void AddTail(List &l, Node* node) {
    if (l.head == NULL) {
        l.head = node;
        l.tail = node;
    }
    else {
        l.tail->next = node;
        l.tail = node;
    }
}

void PrintList(List l) {
    Node* p = l.head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

List CheckEven (List l) {
    Node* p = l.head;
    List evenList;
    CreateList(evenList);
    while (p != NULL) {
        if (p->data % 2 == 0) {
            AddTail(evenList, p);
        }
        p = p->next;
    }
    return evenList;
}

Node* FindMiddle(List l) {
    Node*p =l.head;
    int count = 0;
    while (p!=NULL){
        if (p->data % 2 == 0) {
            count++;
        }
        p = p->next;
    }
    if (count % 2 == 0) count-=1;
    int mid = count / 2;
    Node *x = l.head;
    while (mid != 0){
        x = x->next;
        mid--;
    }
    return x;
}

int main(){
    int n;
    cin >> n;
    List l;
    CreateList(l);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node* node = CreateNode(x);
        AddTail(l, node);
    }

    List evenList = CheckEven(l);
    Node* middle = FindMiddle(evenList);
    cout << middle->data;

    return 0;
}