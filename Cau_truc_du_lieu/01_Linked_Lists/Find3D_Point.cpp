/*Hãy viết chương trình cài đặt danh sách liên kết đơn và nhập vào một danh sách A gồm tọa độ n điểm trong không gian 3 chiều. Sau đó, nhập m điểm pi và kiểm tra xem các điểm pi này có xuất hiện trong danh sách A hay không.
Yêu cầu:
- Không sử dụng thêm thư viện nào khác ngoài iostream và cmath đã được include sẵn.
- Không sử dụng mảng.
- Cài đặt hàm void run() để hoàn thành các yêu cầu của đề bài. Hàm run() này được hàm main gọi để thực hiện yêu cầu. Nếu không cài đặt hàm run(), chương trình sẽ không chạy được.

Đầu vào:
- Dòng đầu là số n (1 ≤ n ≤ 10000)
- n dòng kế tiếp, mỗi dòng 3 số có phần thập phân lần lượt là giá trị x, y và z của điểm trong danh sách.
- Dòng tiếp theo là số m (1 ≤ m ≤ 3500).
- m dòng tiếp theo, mỗi dòng có 3 số có phần thập phân lần lượt là giá trị x, y và z của điểm pi.
Đầu ra: Gồm m dòng, dòng thứ i là kết quả tìm điểm pi trong A. Kết quả tìm là
- "KHONG" nếu không tìm thấy,
- Chỉ số của điểm đầu tiên được tìm thấy trong A theo hướng tìm từ đầu danh sách đến cuối danh sách.*/

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

void initList (List& list) {
    list.head = nullptr;
    list.tail = nullptr;
}

Node* createNode(const Point& point) {
    Node* newNode = new Node;
    newNode->data = point;
    newNode->next = nullptr;
    return newNode;
}

void insertTail(List& list, const Point& point) {
    Node* newNode = createNode(point);
    if (list.tail == nullptr) {
        list.head = newNode;
        list.tail = newNode;
    } else {
        list.tail->next = newNode;
        list.tail = newNode;
    }
}

bool isEqual(Point a, Point b) {
    return (a.x == b.x && a.y == b.y && a.z == b.z);
}

int FindPoint(List& list, Point& point) {
    Node* current = list.head;
    int index = 0;
    while (current != nullptr) {
        if (isEqual(current->data, point)) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

void FreeList (List& list) {
    Node* current = list.head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    list.head = nullptr;
    list.tail = nullptr;
}


void run(){
    List A;
    initList(A);
    
    int n;
    if (!(cin >> n)) return;
    
    // Nhập danh sách A gồm n điểm
    for (int i = 0; i < n; i++) {
        Point p;
        cin >> p.x >> p.y >> p.z;
        insertTail(A, p);
    }
    
    int m;
    if (!(cin >> m)) {
        FreeList(A);
        return;
    }
    
    // Nhập m điểm pi và kiểm tra trực tiếp
    for (int i = 0; i < m; i++) {
        Point pi;
        cin >> pi.x >> pi.y >> pi.z;
        
        int result = FindPoint(A, pi);
        if (result == -1) {
            cout << "KHONG" << endl;
        } else {
            cout << result << endl;
        }
    }
    
    // Giải phóng bộ nhớ trước khi kết thúc
    FreeList(A);
}






int main() {

	int * a = new int[256];
	int * b = new int[256];
	delete [] a;
	run();
	delete [] b;
	return 0;
}