/*Dùng danh sách liên kết thay cho mảng, vector, hãy viết chương trình in ra các số chẵn từ các số đã nhập vào sao cho thứ tự in ra ngược với thứ tự nhập.
Đầu vào:
- Số nguyên dương n, cho biết có n số nguyên dương.
- n nguyên dương kế tiếp là các số được nhập vào.
Đầu ra: Một dòng duy nhất chứa các số nguyên dương chẵn theo thứ tự ngược với thứ tự nhập. Mỗi số cách nhau một khoảng trắng.
Lưu ý:
1) Cấu trúc List và một số hàm CreateList, CreateNode, AddHead, AddTail đã được cài đặt sẵn. Sinh viên có thể tham khảo để sử dụng.
2) Cần cài đặt hàm main để thực hiện chương trình.*/
#include <iostream>

using namespace std;

// Cấu trúc một Node
struct Node {
    int data;
    Node* next;
};

// Cấu trúc danh sách liên kết
struct List {
    Node* head;
    Node* tail;
};

// Khởi tạo danh sách
void CreateList(List &l) {
    l.head = NULL;
    l.tail = NULL;
}

// Tạo node mới
Node* CreateNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

// Thêm vào đầu danh sách (giúp đảo ngược thứ tự nhập)
void AddHead(List &l, int x) {
    Node* p = CreateNode(x);
    if (l.head == NULL) {
        l.head = l.tail = p;
    } else {
        p->next = l.head;
        l.head = p;
    }
}

int main() {
    int n, value;
    List l;
    CreateList(l);

    // Nhập số lượng phần tử
    if (!(cin >> n)) return 0;

    // Nhập n số và thêm vào đầu danh sách
    // Vì dùng AddHead, các số nhập sau sẽ nằm ở phía trước
    for (int i = 0; i < n; i++) {
        cin >> value;
        AddHead(l, value);
    }

    // Duyệt danh sách và in ra số chẵn
    // Vì danh sách đã được AddHead, nên duyệt từ head đến tail 
    // chính là in theo thứ tự ngược lại so với lúc nhập
    Node* p = l.head;
    while (p != NULL) {
        if (p->data % 2 == 0) {
            cout << p->data << " ";
        }
        p = p->next;
    }

    // Giải phóng bộ nhớ (tốt nhất là nên làm)
    while (l.head != NULL) {
        Node* temp = l.head;
        l.head = l.head->next;
        delete temp;
    }

    return 0;
}