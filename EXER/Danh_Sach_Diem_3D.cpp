/* Hay viet chuong trinh nhap vao mot danh sach A gom toa do n diem trong
khong gian 3 chieu. Sau do, nhap hai gia tri b va e, voi b <= e, de chon
tap R chua cac diem A[i] sao cho khoang cach tu goc toa do O(0,0,0) den
diem A[i] thuoc doan [b, e]. Thu tu do tim tu dau danh sach A den cuoi
danh sach A.

Dau vao:
- Dong dau la so n (1 <= n <= 10000).
- n dong ke tiep, moi dong gom 3 so thuc x, y, z la toa do cua mot diem.
- Dong cuoi cung gom hai gia tri b va e.

Dau ra:
- Neu tap R rong thi xuat "KHONG".
- Nguoc lai, liet ke toa do x, y, z cua cac diem trong R, moi diem tren
  mot dong.
*/

#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

struct iToaDo {
    double x, y, z;
};

long double KhoangCachGoc(const iToaDo& p) {
    return sqrtl(1.0L * p.x * p.x + 1.0L * p.y * p.y + 1.0L * p.z * p.z);
}

int main() {
    int n;
    cin >> n;

    iToaDo arr[10000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y >> arr[i].z;
    }

    long double b, e;
    cin >> b >> e;

    const long double EPS = 1e-12L;
    bool found = false;

    cout << setprecision(15);

    for (int i = 0; i < n; i++) {
        long double distance = KhoangCachGoc(arr[i]);
        if (distance + EPS >= b && distance <= e + EPS) {
            found = true;
            cout << arr[i].x << ' ' << arr[i].y << ' ' << arr[i].z << '\n';
        }
    }

    if (!found) {
        cout << "KHONG";
    }

    return 0;
}
