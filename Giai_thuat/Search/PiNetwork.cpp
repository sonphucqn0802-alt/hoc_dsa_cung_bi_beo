/*Pi Network
Sàn giao dịch tiền ảo Bạn Đá Trà đang hót hòn họt với đồng Pi và đã có sự tham gia
giao của N người mua và M người bán. Người tham gia sàn giao dịch có thể tự do đưa
ra mức giá riêng mà họ cảm thấy thoải mái để thuận mua vừa bán. Mỗi người bán chỉ
chịu bán đi Pi của mình với mức giá cao hơn X đô la. Ngược lại, mỗi người mua chỉ
chịu mua Pi với mức giá thấp hơn X đô la.
Với tư cách là học trò của Mr.Bịp và anh Quyết FLC, bạn cần xác định mức giá tối thiểu
X (với X là số nguyên) sao cho tại mức giá này, tổng số người bán không nhỏ hơn tổng
số người mua. Bằng cách tạo ra một sự cân bằng giữa cung và cầu trên sàn giao dịch,
mục tiêu của chúng ta là tăng giá trị của đồng Pi lên 1 tỷ / Pi để bất kỳ ai cũng có thể
trở thành tỷ phú.
Input:
 Dòng đầu tiên chứa hai số nguyên N, M (1 ≤ 𝑁, 𝑀 ≤ 2 × 10ହ) là số lượng
người bán và số lượng người mua tham gia sàn giao dịch
 Dòng tiếp theo chứa N số 𝑎ଵ
, 𝑎ଶ
, … , 𝑎ே với (1 ≤ 𝑎௜ ≤ 10ଽ) là mức giá tối thiểu
của người bán 𝑎௜
 sẽ bán
 Dòng cuối cùng chứa M số 𝑏ଵ
, 𝑏ଶ
, … , 𝑏ெ với (1 ≤ 𝑏௜ ≤ 10ଽ) là mức giá tối đa
mà người mua 𝑏௜
 chịu bỏ tiền ra mua.
Output:
 In ra mức giá đồng Pi tối thiểu để cân bằng sự cung cầu của thị trường.

Input
3 4
110 90 120
100 80 120 10000
Ouput
110
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector <int> Ban(N), Mua(M);
    for (int i = 0; i < N; i++) {
        cin >> Ban[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> Mua[i];
    }

    sort(Ban.begin(), Ban.end());
    sort(Mua.begin(), Mua.end());

    int left = 1, right = 1000000005; // Đặt right lớn hơn 10^9 một chút
    int ans = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Đếm số người bán có mức giá <= mid
        // upper_bound trả về iterator trỏ đến phần tử đầu tiên > mid
        int so_nguoi_ban = upper_bound(Ban.begin(), Ban.end(), mid) - Ban.begin();

        // Đếm số người mua có mức giá >= mid
        // lower_bound trả về iterator trỏ đến phần tử đầu tiên >= mid
        int so_nguoi_mua = Mua.end() - lower_bound(Mua.begin(), Mua.end(), mid);

        if (so_nguoi_ban >= so_nguoi_mua) {
            ans = mid;         // Ghi nhận mức giá này hợp lệ
            right = mid - 1;   // Cố gắng tìm mức giá nhỏ hơn
        } else {
            left = mid + 1;    // Thiếu người bán, phải tăng giá lên
        }
    }

    cout << ans << "\n";
    return 0;
}