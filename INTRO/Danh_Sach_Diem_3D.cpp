/*Hãy viết chương trình nhập vào một danh sách A gồm tọa độ n điểm trong không gian 3 chiều. 
Sau đó, nhập hai giá trị b và e, với b ≤ e, để chọn tập R chứa các điểm A[i] sao cho khoảng cách từ gốc tọa độ
O(0,0,0) đến điểm A[i] là d(O, A[i]) ∈ [b, e]. 
Thứ tự dò tìm từ đầu danh sách A đến cuối danh sách A.
Đầu vào:
- Dòng đầu là số n (1 ≤ n ≤ 10000).
- n dòng kế tiếp, mỗi dòng 3 số có phần thập phân x, y và z là giá trị các chiều của một điểm trong danh sách A.

- Sau cùng là b với e 
Đầu ra: Nếu tập R rỗng thì xuất ra "KHONG". Nếu R không rỗng thì liệt kê các giá trị x, y và z của tọa độ các điểm
trong R theo từng dòng, mỗi dòng là một điểm.*/

#include <iostream>
using namespace std;

struct iToaDo {
    double x, y, z;
};

bool Sosanh(iToaDo a, iToaDo b) {
    return (a.x == b.x && a.y == b.y && a.z == b.z);
}

int MySearch(iToaDo arr[], int n, iToaDo target) {
    for (int i = 0; i < n; i++) {
        if (Sosanh(arr[i], target)) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;

    iToaDo arr[10000];

    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y >> arr[i].z;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        iToaDo p;
        cin >> p.x >> p.y >> p.z;

        int pos = MySearch(arr, n, p);

        if (pos == -1)
            cout << "KHONG" << endl;
        else
            cout << pos << endl;
    }
}