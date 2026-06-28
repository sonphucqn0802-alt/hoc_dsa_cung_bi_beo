/*Trọng số của một mảng được định nghĩa là sự khác biệt giữa phần tử lớn nhất và nhỏ nhất của mảng. Ví dụ: trọng số của mảng [3, 7, 1, 2] là (7 - 1) = 6, trọng số của mảng [2] là (2 - 2) = 0, trọng số của mảng trống là 0.

Cho một mảng A có độ dài N. Bạn phải chia các phần tử của A thành hai dãy con S1 và S2 (một trong S1, S2 có thể trống) sao cho:

Mỗi phần tử của mảng A chỉ thuộc một trong hai dãy S1 hoặc S2.

Tổng trọng số của hai dãy S1 và S2 là lớn nhất.

Bạn in ra đáp án lớn nhất có thể của tổng trọng số của hai dãy S1 và S2.
 

Input:
Dòng đầu tiên chứa T là số lượng test. Mô tả các trường hợp thử nghiệm T như sau:

Với mỗi test case:

Dòng đầu tiên chứa N là kích thước của mảng A.

Dòng thứ hai chứa N số nguyên A[1], A[2],....., A[N] - biểu thị các phần tử của A.

Ràng buộc:
1 <= T <= 10^4

2 <= N <= 10^5

1 <= A[i] <= 10^9

Tổng của N trên tất cả các test case không quá 2x10^5

Output:
Đối với mỗi trường hợp thử nghiệm, hãy in tổng trọng số tối đa có thể có của hai dãy con.
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    // Các biến lưu trữ 2 giá trị lớn nhất và 2 giá trị nhỏ nhất
    long long max1 = -1, max2 = -1;
    long long min1 = LLONG_MAX, min2 = LLONG_MAX;

    vector<long long> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        long long x = A[i];

        // Cập nhật 2 phần tử lớn nhất
        if (x > max1) {
            max2 = max1;
            max1 = x;
        } else if (x > max2) {
            max2 = x;
        }

        // Cập nhật 2 phần tử nhỏ nhất
        if (x < min1) {
            min2 = min1;
            min1 = x;
        } else if (x < min2) {
            min2 = x;
        }
    }

    // Tính 2 trường hợp: 
    // 1. Cho tất cả vào 1 dãy (hoặc n < 4)
    long long ans1 = max1 - min1;
    // 2. Chia đều 2 phần tử lớn nhất và nhỏ nhất cho 2 dãy
    long long ans2 = max1 + max2 - min1 - min2;

    // In ra đáp án tối ưu
    if (ans2 > ans1) {
        cout << ans2 << "\n";
    } else {
        cout << ans1 << "\n";
    }
}

int main() {
    // Tối ưu I/O để chạy nhanh hơn do giới hạn testcases lớn
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}