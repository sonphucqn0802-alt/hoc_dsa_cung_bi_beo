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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n,0);
    for (int i = 0; i < n; i++) {
         int x;
         cin >> x;
         if (x>=0 && x<=n){
            a[x]=1;
         }
    }
    
    
    int mex = 0;
    while (mex < n && a[mex] == 1){
        mex ++;
    }
    
    cout << mex << endl;
    
    return 0;
}
