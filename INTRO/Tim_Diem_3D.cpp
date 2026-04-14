/*Hãy viết chương trình nhập vào một danh sách A gồm tọa độ n điểm trong không gian 3 chiều. Sau đó, nhập m điểm pi
và kiểm tra xem các điểm pi này có xuất hiện trong danh sách A hay không.
Đầu vào:
- Dòng đầu là số n (1 ≤ n ≤ 10000)
- n dòng kế tiếp, mỗi dòng 3 số có phần thập phân lần lượt là giá trị x, y và z của điểm trong danh sách.
- Dòng tiếp theo là số m (1 ≤ m ≤ 3500).
- m dòng tiếp theo, mỗi dòng có 3 số có phần thập phân lần lượt là giá trị x, y và z của điểm pi.
Đầu ra: Gồm m dòng, dòng thứ i là kết quả tìm điểm pi trong A. Kết quả tìm là
- "KHONG" nếu không tìm thấy,
- Chỉ số của điểm đầu tiên được tìm thấy trong A theo hướng tìm từ đầu danh sách đến cuối danh sách.*/

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