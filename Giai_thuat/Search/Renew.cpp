/*ĐỔI MỚI

Thành phố quyết định chặt hạ hết n cây xanh hiện có trong thành phố để trồng chỉ một loại cây mới. 
Nhiệm vụ được giao cho Công ty Cây xanh thành phố. Do hạn chế về thiết bị Công ty chỉ tổ chức được 2 đội đốn hạ cây. 
Đội I hạ được a cây mỗi ngày, nhưng cứ mối ngày thứ k thì phải nghỉ để bảo dưỡng kỹ thuật, tức là đội I sẽ nghỉ vào 
các ngày k, 2k, 3k, . . . 
Đội II hạ được b cây mỗi ngày, nhưng cứ mỗi ngày thứ m thì phải nghỉ để bảo dưỡng kỹ thuật, tức là đội II sẽ nghỉ vào 
các ngày m, 2m, 3m, . . . Ở ngày nghỉ, số cây chặt hạ của đội sẽ là 0. Cả hai đội bắt đầu công việc vào cùng một ngày 
và làm việc song song với nhau.

Công việc trồng cây mới sẽ bắt đầu sau khi toàn bộ cây cũ đã bị đốn hạ.

Hãy xác định sau bao nhiêu ngày thì có thể bắt đầu việc trồng mới cây.

Dữ liệu: Vào từ thiết bị nhập chuẩn gồm một dòng chứa 5 số nguyên a, k, b, m và n 
(1 ≤ a, b ≤ 109, 2 ≤ k, m ≤ 1018, 1 ≤ n ≤ 1018).

Kết quả: Đưa ra thiết bị xuất chuẩn một số nguyên – số ngày tính được.*/


#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long a, k, b, m, n;
    cin >> a >> k >> b >> m >> n;

    long long left = 1, right = n / min(a, b) + 1;
    long long ans = right;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        long long days_a = mid - mid / k;
        long long days_b = mid - mid / m;

        // 1. Kiểm tra xem riêng Đội I có chặt xong không
        // (n + a - 1) / a là công thức làm tròn lên của n / a
        if (days_a >= (n + a - 1) / a) {
            ans = mid;
            right = mid - 1;
            continue;
        }

        // 2. Kiểm tra xem riêng Đội II có chặt xong không
        if (days_b >= (n + b - 1) / b) {
            ans = mid;
            right = mid - 1;
            continue;
        }


        long long cut_a = (mid - mid / k) * a;
        long long cut_b = (mid - mid / m) * b;

        if (cut_a + cut_b >= n) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
