/*Hãy hoàn thành hàm Sort(List &) để sắp xếp danh sách học sinh theo thứ tự tăng dần của tên, nếu tên trùng nhau thì xét thứ tự Họ đệm tăng dần. Nếu tên và họ đệm trùng nhau, thì xét tuổi tăng dần. Một người có tuổi nhỏ hơn nếu có ngày sinh (bao gồm ngày, tháng, năm) lớn hơn. Thứ tự của tên, họ đệm cũng chính là thứ tự chuỗi theo bảng mã ASCII.
Lưu ý:
1) Chỉ cài đặt hàm Sort và những hàm liên quan (nếu cần) để sắp xếp sao cho thời gian sắp xếp nhỏ.
2) Kiểu dữ liệu và một số hàm liên quan đã được cài đặt sẵn. Sinh viên có thể đọc để sử dụng.
3) Đầu vào và đầu ra đã được xử lý sẵn và phù hợp với định dạng nhập/xuất.*/


#include <iostream>

using namespace std;

struct Hocsinh{
    string Hodem, Ten;
    bool Gioitinh;
    int Ngay, Thang, Nam;
    double Toan, Van, Ly, Hoa, Anh, Sinh;
};

void InputElement(Hocsinh &x) {
    getline(cin>>ws, x.Hodem);
    getline(cin>>ws, x.Ten);
    cin >> x.Gioitinh;
    cin >> x.Ngay >> x.Thang >> x.Nam;
    cin >> x.Toan >> x.Van >> x.Ly >> x.Hoa >> x.Anh >> x.Sinh;
}

void OutputElement(Hocsinh hs) {
    cout << hs.Hodem
            << ' ' << hs.Ten
            << '\t' << hs.Gioitinh
            << '\t' << hs.Ngay
            << '/' << hs.Thang
            << '/' << hs.Nam
            << '\t' << hs.Toan
            << '\t' << hs.Van
            << '\t' << hs.Ly
            << '\t' << hs.Hoa
            << '\t' << hs.Anh
            << '\t' << hs.Sinh << endl;;
}

struct Node {
    Hocsinh data;
    Node * next;
};

struct List {
    Node * head, * tail;
};

Node * CreateNode(Hocsinh x) {
    Node * p = new Node;
    if (p == NULL) exit(1);
    p->data = x;
    p->next = NULL;
    return p;
}

void CreateList(List &l) {
    l.head = l.tail = NULL;
}

void AddHead(List &l, Hocsinh x) {
    Node * p = CreateNode(x);
    if (l.head == NULL)
        l.tail = p;
    else
        p->next = l.head;
    l.head = p;
}

void AddTail(List &l, Hocsinh x) {
    Node * p = CreateNode(x);
    if (l.head == NULL)
        l.head = p;
    else
        l.tail->next = p;
    l.tail = p;
}

Node * RemoveHead(List &l) {
    if (l.head == NULL)
        return NULL;
    Node *p = l.head;
    l.head = p->next;
    p->next = NULL;
    return p;
}

void PrintList(List l) {
    Node * p = l.head;
    while (p != NULL) {
        OutputElement(p->data);
        p = p->next;
    }
}

void Sort(List &);

int main()
{
    List l;
    int n;
    Hocsinh hs;

    CreateList(l);
    cin >> n;
    for (int i = 0; i < n; i++) {
        InputElement(hs);
        AddTail(l, hs);
    }

    Sort(l);
    PrintList(l);
    return 0;
}

// Hàm so sánh: trả về true nếu a < b (đúng thứ tự sắp xếp)
bool LessThan(Hocsinh a, Hocsinh b) {
    if (a.Ten != b.Ten) {
        return a.Ten < b.Ten;
    }
    if (a.Hodem != b.Hodem) {
        return a.Hodem < b.Hodem;
    }
    // Tuổi nhỏ hơn = ngày sinh lớn hơn
    if (a.Nam != b.Nam) {
        return a.Nam > b.Nam;
    }
    if (a.Thang != b.Thang) {
        return a.Thang > b.Thang;
    }
    return a.Ngay > b.Ngay;
}

// Tìm node giữa linked list (dùng slow-fast pointer)
Node* GetMiddle(Node* head) {
    if (head == NULL) return NULL;
    
    Node* slow = head;
    Node* fast = head->next;
    
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    return slow;
}

// Merge hai linked list đã sắp xếp
Node* Merge(Node* left, Node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;
    
    Node* result;
    
    if (LessThan(left->data, right->data)) {
        result = left;
        result->next = Merge(left->next, right);
    } else {
        result = right;
        result->next = Merge(left, right->next);
    }
    
    return result;
}

// MergeSort đệ quy
Node* MergeSort(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // Tìm node giữa
    Node* mid = GetMiddle(head);
    Node* midNext = mid->next;
    mid->next = NULL;
    
    // Sắp xếp đệ quy hai nửa
    Node* left = MergeSort(head);
    Node* right = MergeSort(midNext);
    
    // Merge hai nửa đã sắp xếp
    return Merge(left, right);
}

void Sort(List &L){
    if (L.head == NULL || L.head->next == NULL){
        return;
    }
    
    // Thực hiện MergeSort
    L.head = MergeSort(L.head);
    
    // Cập nhật tail sau khi sắp xếp
    Node* p = L.head;
    while (p != NULL && p->next != NULL) {
        p = p->next;
    }
    L.tail = p;
}