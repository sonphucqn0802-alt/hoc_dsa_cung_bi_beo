/*Hãy viết chương trình nhập vào một danh sách A gồm tọa độ n điểm trong không gian 3 chiều. Sau đó, nhập hai giá trị b và e, với b ≤ e, để chọn tập R chứa các điểm A[i] sao cho khoảng cách từ gốc tọa độ O(0,0,0) đến điểm A[i] là d(O, A[i]) ∈ [b, e]. Thứ tự dò tìm từ đầu danh sách A đến cuối danh sách A.
Đầu vào:
- Dòng đầu là số n (1 ≤ n ≤ 10000).
- n dòng kế tiếp, mỗi dòng 3 số có phần thập phân x, y và z là giá trị các chiều của một điểm trong danh sách A.

- Sau cùng là b với e 
Đầu ra: Nếu tập R rỗng thì xuất ra "KHONG". Nếu R không rỗng thì liệt kê các giá trị x, y và z của tọa độ các điểm trong R theo từng dòng, mỗi dòng là một điểm.*/

#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x,y,z;
};

void ipPoint(Point &p) {
    cin >> p.x >> p.y >> p.z;
}

long double distance(Point &p1, Point &p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z));
}


int main() {
    int n;
    cin >> n;
    Point origin = {0, 0, 0};

    Point points[n];
    for (int i = 0; i < n; i++) {
        ipPoint(points[i]);
    }

    double b,e;
    cin >> b >> e;
    

    bool found = false;
    for (int i = 0; i<n; i++) {
        long double dist = distance(origin, points[i]);
        if (dist >= b && dist <= e) {
            found = true;
            cout << points[i].x << " " << points[i].y << " " << points[i].z << endl;
        }
    }
    
    if (!found) {
        cout << "KHONG" << endl;
    }

    return 0;
}