/*Cho trước một mảng có N phần tử. Hãy in ra  MEXi với 0≤i<n.

Biết rằng, MEXi là số nguyên nhỏ nhất lớn hơn hoặc bằng 0 mà không xuất hiện trong từ đầu mảng cho đến phần tử i.

Input:
Dòng đầu tiên là N 
(1≤N≤2×105)
 thể hiện số phần tử của mảng
Dòng tiếp theo chứ N số nguyên là các phần tử của mảng
Output:
N số nguyên tương ứng với MEXi

Giải thích: INPUT 5/1 0 5 2 3 OUTPUT 0 2 2 3 4
- Với i = 0, input {1}, số chưa xuất hiện đầu tiên tính từ 0 là 0.

- Với i = 1, input {1, 0}, số chưa xuất hiện đầu tiên tính từ 0 là 2.

- Với i = 2, input {1, 0, 5}, số chưa xuất hiện đầu tiên tính từ 0  là 2.

- Với i = 3, input {1, 0, 5, 2}, số chưa xuất hiện đầu tiên tính từ 0  là 3.

Với i = 4, input {1, 0, 5, 2, 3}, số chưa xuất hiện đầu tiên tính từ 0  là 4.*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector <int> present(n+2,0);
    int mex = 0;

    for (int i = 0; i<n; i++) {
        int x;
        cin >> x;

        if (x >= 0 && x <= n) {
            present[x]=1;
        }
        while (mex < n && present[mex]==1) mex ++; 
        cout << mex << " ";
    }
return 0;
}