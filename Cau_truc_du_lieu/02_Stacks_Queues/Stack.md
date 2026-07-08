# Tổng hợp kiến thức về Cấu trúc dữ liệu Stack (Ngăn xếp)

## 1. Khái niệm cơ bản
**Stack (Ngăn xếp)** là một cấu trúc dữ liệu tuyến tính hoạt động theo nguyên tắc **LIFO** (Last In - First Out), tức là "vào sau ra trước". 

Có thể hình dung Stack như một chồng sách được đặt trong một cái hộp. Việc đặt một quyển sách lên trên cùng chính là thao tác thêm phần tử, và lấy ra quyển sách ở trên đầu là thao tác loại bỏ phần tử. Như vậy, quyển sách được đặt vào sau cùng sẽ luôn được lấy ra trước tiên.

Vị trí cuối cùng của Stack (nơi thực hiện các thao tác thêm và xóa) được gọi là **đỉnh (Top)**.

## 2. Các thao tác cơ bản trên Stack
Một Stack thường hỗ trợ các thao tác cơ bản sau:
* **`Push(x)`**: Thêm đối tượng `x` vào đỉnh của Stack. Nếu Stack đã đầy, có thể xảy ra hiện tượng tràn (Overflow).
* **`Pop()`**: Lấy và loại bỏ phần tử ở đỉnh của Stack. Nếu Stack rỗng, có thể xảy ra hiện tượng thiếu (Underflow).
* **`Top()` (hoặc `Peek()`)**: Trả về giá trị của phần tử nằm ở đỉnh Stack mà không hủy (xóa) nó khỏi Stack.
* **`isEmpty()`**: Kiểm tra xem Stack có rỗng hay không. Trả về `true` nếu rỗng, ngược lại là `false`.
* **`isFull()`**: Kiểm tra xem Stack đã đầy hay chưa (thường dùng khi cài đặt Stack bằng mảng với kích thước cố định).
* **`Size()`**: Trả về số lượng phần tử hiện đang có trong Stack.

## 3. Độ phức tạp
* **Độ phức tạp thời gian**: Các thao tác `Push`, `Pop`, `Top`, `isEmpty`, `Size` đều thực hiện ở đỉnh của Stack nên hoạt động trong thời gian **O(1)**.
* **Độ phức tạp bộ nhớ**: Không gian bộ nhớ cần thiết là **O(N)** với N là số lượng phần tử đang được lưu trữ trong Stack.

---

## 4. Cách cài đặt Stack (trong C/C++)
Chúng ta có thể tự cài đặt Stack thủ công bằng **Mảng 1 chiều**, **Danh sách liên kết đơn** hoặc dùng thư viện chuẩn **STL**.

### 4.1. Cài đặt bằng Mảng 1 chiều (Array)
Sử dụng một mảng có kích thước cố định `MAX` và một biến `t` (hoặc `top`) lưu chỉ số của phần tử ở đỉnh.

```cpp
#define MAX 100

struct Stack {
    int a[MAX];
    int t;
};

// Khởi tạo Stack rỗng
void CreateStack(Stack &s) {
    s.t = -1;
}

// Kiểm tra Stack rỗng
bool isEmpty(Stack s) {
    return (s.t == -1);
}

// Kiểm tra Stack đầy
bool isFull(Stack s) {
    return (s.t >= MAX - 1);
}

// Thêm phần tử vào Stack
bool Push(Stack &s, int x) {
    if (!isFull(s)) {
        s.a[++s.t] = x;
        return true;
    }
    return false; // Stack đầy
}

// Lấy phần tử ra khỏi Stack
bool Pop(Stack &s, int &x) {
    if (!isEmpty(s)) {
        x = s.a[s.t--];
        return true;
    }
    return false; // Stack rỗng
}

// Lấy giá trị phần tử ở đỉnh Stack (Top)
int Top(Stack s) {
    if (!isEmpty(s)) {
        return s.a[s.t];
    }
    return 0; // Trả về giá trị mặc định nếu rỗng
}

```

### 4.2. Cài đặt bằng Danh sách liên kết đơn (Singly Linked List)
Khác với mảng, cài đặt Stack bằng danh sách liên kết giúp bộ nhớ được cấp phát động, do đó không lo gặp lỗi tràn ngăn xếp (Overflow) do giới hạn kích thước (trừ khi hết bộ nhớ RAM). 

Để đảm bảo các thao tác `Push` và `Pop` đạt độ phức tạp $O(1)$, mọi quá trình thêm và xóa phần tử đều phải được thực hiện ở **đầu danh sách (Head)**.

```cpp
#include <iostream>
using namespace std;

// Khai báo cấu trúc một Node
struct Node {
    int data;
    Node* next;
};

// Khai báo cấu trúc Stack
struct Stack {
    Node* top;
};

// Khởi tạo Stack rỗng
void init(Stack &s) {
    s.top = NULL;
}

// Kiểm tra Stack rỗng
bool isEmpty(Stack s) {
    return s.top == NULL;
}

// Thêm phần tử vào đỉnh Stack (Push)
void push(Stack &s, int value) {
    Node* p = new Node;
    p->data = value;
    p->next = s.top; // Trỏ Node mới vào Node đỉnh hiện tại
    s.top = p;       // Cập nhật đỉnh Stack mới
}

// Lấy và xóa phần tử ở đỉnh Stack (Pop)
bool pop(Stack &s, int &value) {
    if (isEmpty(s)) return false;
    
    Node* p = s.top;
    value = p->data;
    s.top = s.top->next; // Dời đỉnh Stack xuống phần tử tiếp theo
    delete p;            // Giải phóng bộ nhớ
    return true;
}

// Xem giá trị ở đỉnh Stack (Top/Peek)
int top(Stack s) {
    if (!isEmpty(s)) {
        return s.top->data;
    }
    return -1; // Trả về -1 nếu Stack rỗng
}
```

### 4.3. Sử dụng thư viện chuẩn (STL Stack trong C++)
Trong thực tế và đặc biệt là lập trình thi đấu, thay vì tự cài đặt thủ công, lập trình viên thường sử dụng stack đã được xây dựng sẵn trong Standard Template Library (STL) của C++ để tiết kiệm thời gian và đảm bảo độ ổn định.

**Khai báo thư viện:**
```cpp
#include <stack>
```

**Các phương thức cơ bản:**
- `s.push(x)`: Thêm x vào đỉnh ngăn xếp.
- `s.pop()`: Xóa phần tử ở đỉnh ngăn xếp (không trả về giá trị).
- `s.top()`: Trả về tham chiếu tới phần tử ở đỉnh ngăn xếp.
- `s.empty()`: Kiểm tra ngăn xếp rỗng (trả về true nếu rỗng, ngược lại false).
- `s.size()`: Trả về số lượng phần tử hiện có trong ngăn xếp.

**Ví dụ minh họa:**
```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Kích thước của Stack: " << s.size() << endl; // Kết quả: 3
    cout << "Phần tử ở đỉnh (Top): " << s.top() << endl;  // Kết quả: 30
    
    s.pop(); // Xóa 30 ra khỏi Stack
    cout << "Phần tử ở đỉnh sau khi Pop: " << s.top() << endl; // Kết quả: 20

    return 0;
}
```

**Lưu ý:** Ngoài thư viện `<stack>`, cấu trúc `<vector>` trong C++ cũng có thể được sử dụng như một Stack thông qua các hàm `push_back()` (tương đương push), `pop_back()` (tương đương pop), và `back()` (tương đương top).

---

## 5. Ứng dụng của Stack (Mở rộng)
Stack không chỉ là lý thuyết mà còn là cấu trúc dữ liệu cốt lõi đứng sau rất nhiều thuật toán và phần mềm trong thực tế.

### 5.1. Đảo ngược dữ liệu (Reversing Data)
Nhờ đặc tính LIFO (Vào sau ra trước), Stack là công cụ hoàn hảo để đảo ngược một chuỗi ký tự, một mảng hoặc một danh sách liên kết.

**Cách làm:** Duyệt từ đầu đến cuối dữ liệu, đẩy (Push) từng phần tử vào Stack. Sau đó, lấy (Pop) lần lượt các phần tử ra, thứ tự thu được sẽ là thứ tự đảo ngược so với ban đầu.

### 5.2. Chuyển đổi hệ cơ số (Base Conversion)
Stack thường được dùng để chuyển đổi một số nguyên từ hệ thập phân (cơ số 10) sang các hệ cơ số khác (như nhị phân, bát phân, thập lục phân).

**Cách làm (chuyển sang nhị phân):** Chia liên tiếp số thập phân cho 2, đẩy phần dư (0 hoặc 1) vào Stack. Khi phép chia kết thúc, việc Pop các phần tử từ Stack sẽ tạo thành dãy nhị phân hoàn chỉnh.

### 5.3. Kiểm tra tính hợp lệ của dãy ngoặc (Balanced Parentheses)
Đây là bài toán kinh điển trong trình biên dịch (Compiler) nhằm kiểm tra lỗi cú pháp của các biểu thức toán học hoặc mã nguồn code ((), [], {}).

**Thuật toán:** Duyệt qua chuỗi chứa dấu ngoặc.
- Gặp ngoặc mở (VD: (, [), ta Push vào Stack.
- Gặp ngoặc đóng (VD: ), ]), ta kiểm tra đỉnh Stack. Nếu phần tử ở đỉnh là ngoặc mở tương ứng, ta Pop nó ra. Nếu không tương ứng hoặc Stack đang rỗng, chuỗi ngoặc không hợp lệ.
- Kết thúc duyệt, nếu Stack rỗng hoàn toàn thì dãy ngoặc hợp lệ.

### 5.4. Tính toán và chuyển đổi biểu thức (Expression Evaluation)
Máy tính không tính toán biểu thức dưới dạng trung tố thông thường (VD: A + B * C) vì vướng bận dấu ngoặc và độ ưu tiên toán tử. Thay vào đó, máy tính dùng Stack để:
- Chuyển đổi biểu thức Trung tố (Infix) sang Hậu tố (Postfix) hoặc Tiền tố (Prefix).
- Tính toán trực tiếp giá trị của biểu thức Hậu tố/Tiền tố. Khi gặp toán hạng (số), đẩy vào Stack; khi gặp toán tử (+, -, *, /), lấy 2 phần tử ở đỉnh Stack ra để tính toán rồi lại đẩy kết quả vào Stack.

### 5.5. Khử đệ quy (Recursion Elimination)
Khi một chương trình gọi hàm đệ quy, máy tính thực chất sử dụng một Stack hệ thống (Call Stack) để lưu vết biến cục bộ và vị trí dòng lệnh trả về. Quá nhiều tầng đệ quy sẽ gây lỗi tràn bộ nhớ (Stack Overflow).

Chúng ta có thể tự dùng một Stack (do người dùng khai báo) để mô phỏng lại quá trình này, từ đó chuyển thuật toán đệ quy (như thuật toán tìm kiếm theo chiều sâu - DFS, hoặc duyệt cây nhị phân) thành thuật toán lặp (không đệ quy).

### 5.6. Stack Đơn Điệu (Monotonic Stack) - Ứng dụng nâng cao
Đây là một kỹ thuật cực kỳ mạnh mẽ trong lập trình thi đấu. Stack đơn điệu là một Stack mà các phần tử trong đó luôn được duy trì theo một chiều tăng dần hoặc giảm dần (từ đáy lên đỉnh).

**Bài toán áp dụng:**
- Tìm phần tử đầu tiên lớn hơn/nhỏ hơn nằm bên phải/trái của mỗi phần tử trong mảng (Next Greater Element).
- Tìm diện tích hình chữ nhật lớn nhất trong biểu đồ cột (Largest Rectangle in Histogram).

### 5.7. Ứng dụng trong phần mềm thực tế
- **Tính năng Undo/Redo (Hoàn tác):** Trong Word, Photoshop hay các Editor lập trình, mỗi thao tác của bạn được đưa vào một Stack. Khi nhấn Ctrl + Z, phần mềm sẽ Pop lệnh cuối cùng ra để đưa trạng thái về trước đó.
- **Lịch sử duyệt Web:** Nút Back và Forward của trình duyệt hoạt động dựa trên hai Stack song song chứa danh sách các URL bạn vừa truy cập.