/*Stack (Ngăn xếp)
Viết chương trình sử dụng Stack để lưu trữ số dương cho phép người dùng liên tục nhập yêu cầu 
(là số nguyên) từ bàn phím và chỉ dừng khi người dùng nhập -1. Lúc này, in ra màn hình "Ket thuc chuong trinh". 
Nếu giá trị nhập vào trong đoạn [1, 6] thì thực hiện những thao tác sau:

- Nếu nhập 1, cho phép người dùng thêm một phần tử mới có giá trị x (x được nhập từ bàn phím) vào Stack.

- Nếu nhập 2, thực hiện thao tác POP.

- Nếu nhập 3, in ra màn hình phần tử trên cùng của Stack theo cú pháp: "Top: <...>". 
Nếu Stack rỗng thì in ra "Stack is empty"

- Nếu nhập 4, in ra màn hình kích thước hiện tại của Stack theo cú pháp: "Size: <...>".

- Nếu nhập 5, in ra màn hình "Stack is empty" nếu Stack rỗng. Ngược lại, in "Stack is not empty"

- Nếu nhập 6, in ra màn hình "Stack: " kèm với toàn bộ các phần tử trong Stack theo thứ tự từ đầu đến cuối

Lưu ý: Các bạn có thể tự cài đặt STACK hoặc sử dụng thư viện có sẵn*/

#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

int main() {
    stack<int> s;
    int n;

    while (cin >> n) {
        switch (n) {
            case 1:
                {
                    // Thêm phần tử vào Stack
                    int x;
                    cin >> x;
                    s.push(x);
                    break;
                }
            case 2:
                // Thực hiện thao tác POP
                if (!s.empty()){
                    s.pop();
                }
                break;
            case 3:
                // In ra phần tử trên cùng của Stack
                if (!s.empty()){
                    cout << "Top: " << s.top() << endl;
                } else {
                    cout << "Stack is empty" << endl;
                }
                break;
            case 4:
                // In ra kích thước hiện tại của Stack
                cout << "Size: " << s.size() << endl;
                break;
            case 5:
                // Kiểm tra Stack rỗng
                if (s.empty()){
                    cout << "Stack is empty" << endl;
                } else {
                    cout << "Stack is not empty" << endl;
                }
                break;
            case 6:
                {
                    // In ra toàn bộ các phần tử trong Stack
                    stack<int>temp = s;
                    cout << "Stack: ";
                    while (!temp.empty()){
                        cout << temp.top() << " ";
                        temp.pop();
                    }
                    cout << endl;
                    break;
                }
            case -1:
                cout << "Ket thuc chuong trinh" << endl;
                return 0;
            default:
                cout << "Lua chon khong hop le" << endl;
                break;
        }
    }
    
    return 0;
}