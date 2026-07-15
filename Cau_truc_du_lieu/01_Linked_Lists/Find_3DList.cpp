/*Hãy viết chương trình cài đặt danh sách liên kết đơn để nhập vào một danh sách A 
gồm tọa độ n điểm trong không gian 3 chiều. Sau đó, nhập hai giá trị b và e, với 
b ≤ e, để chọn tập R chứa các điểm A[i] sao cho khoảng cách từ gốc tọa độ O(0,0,0) 
đến điểm A[i] là d(O, A[i]) ∈ [b, e]. Thứ tự dò tìm từ đầu danh sách A đến cuối danh 
sách A.
Đầu vào:
- Dòng đầu là số n (1 ≤ n ≤ 10000).
- n dòng kế tiếp, mỗi dòng 3 số có phần thập phân x, y và z là giá trị các chiều 
của một điểm trong danh sách A.

- 2 số b,e
Đầu ra: Nếu tập R rỗng thì xuất ra "KHONG". Nếu R không rỗng thì liệt kê các giá trị 
x, y và z của tọa độ các điểm trong R theo từng dòng, mỗi dòng là một điểm.*/

#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x, y, z;
};

struct Node {
    Point data;
    Node* next;
};

struct List {
    Node* head;
    Node* tail;
};

void initList(List& list) {
    list.head = nullptr;
    list.tail = nullptr;
}

Node* createNode(const Point& point) {
    Node* newNode = new Node;
    newNode->data = point;
    newNode->next = nullptr;
    return newNode;
}

void addTail(List& list, const Point& point) {
    Node* newNode = createNode(point);
    if (list.tail == nullptr) {
        list.head = list.tail = newNode;
    } else {
        list.tail->next = newNode;
        list.tail = newNode;
    }
}

double distanceFromOrigin(const Point& point) {
    return sqrt(point.x * point.x + point.y * point.y + point.z * point.z);
}

void findPointsInRange(List& list, double b, double e) {
    bool found = false;
    
    Node* current = list.head;
    while (current != nullptr) {
        double dist = distanceFromOrigin(current->data);
        if (dist >= b && dist <= e) {
            cout << current->data.x << " " << current->data.y << " " << current->data.z << endl;
            found = true;
        }
        current = current->next;
    }
    
    if (!found) {
        cout << "KHONG" << endl;
    }
}

int main() {
    List list;
    initList(list);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        Point point;
        cin >> point.x >> point.y >> point.z;
        addTail(list, point);
    }
    
    double b, e;
    cin >> b >> e;
    
    findPointsInRange(list, b, e);
    
    return 0;
}
