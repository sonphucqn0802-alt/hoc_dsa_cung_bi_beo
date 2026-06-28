/*MEX (minimum excluded) là một giá trị được sử dụng phổ biến trong Lý thuyết Trò chơi. 
MEX được định nghĩa là số tự nhiên nhỏ nhất chưa xuất hiện trong mảng.

Ví dụ:

  MEX() = 0.

  MEX([0, 2, 3]) = 1

  MEX([0, 1, 2, 3]) = 4.

Bạn hãy xác định MEX của một mảng cho trước?

Input:
Dòng đầu tiên chứa số nguyên N 
(1 ≤ N ≤ 10^6), là số lượng phần tử của mảng.
Dòng tiếp theo chứa N số nguyên ai(1 ≤ ai ≤ 10^9) là các phần tử của mảng.

Output:
Một số nguyên là giá trị MEX của dãy được cho.*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    
    int mex = 0;
    while (true) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (a[i] == mex) {
                found = true;
                break;
            }
        }
        if (!found) {
            break;
        }
        mex++;
    }
    
    cout << mex << endl;
    
    return 0;
}
