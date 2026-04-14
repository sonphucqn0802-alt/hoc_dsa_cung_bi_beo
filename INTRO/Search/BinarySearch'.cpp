/*Thuật toán tìm kiếm nhị phân là một thuật toán tìm kiếm đơn giản nhưng có tốc độ tìm kiếm cực kỳ nhanh.

Ý tưởng của thuật toán là: với một mảng N phần tử đã được sắp xếp (tăng dần/hoặc giảm dần tùy theo người ra đề) và số nguyên x cần tìm, ta sẽ thực hiện tìm kiếm ở miền có khả năng xuất hiện x sau mỗi lần lặp.

Hãy cài đặt thuật toán tìm kiếm nhị phân để tìm vị trí của phần tử x trong mảng có N phần tử và đếm số lần duyệt qua các phần tử.

Input:
Dòng đầu tiên là số nguyên N dương (0 < N < 32000)

Dòng tiếp theo chứa N số nguyên Ai là các phần tử của mảng đã được sắp xếp tăng dần và không trùng nhau

Dòng cuối cùng là số nguyên x cần tìm

Output:
Dòng đầu tiên là vị trí của x được tìm thấy trong mảng. Nếu không tìm thấy thì xuất ra -1

Dòng tiếp theo là số lần duyệt qua các phần tử để tìm được x. Nếu không tìm thấy thì không cần xuất ra dòng này

*/

/*Cho một dãy số nguyên a gồm N phần tử a1,a2,…,aN.

Có Q truy vấn, mỗi truy vấn cho một số nguyên x. Bạn hãy trả lời xem số nguyên x này có trong dãy a hay không?

Lưu ý: Trong template đã đảm bảo mảng ban đầu sau khi nhập vào sẽ được sắp xếp, các bạn chỉ cần hoàn thành hàm myBinarySearch.

Input:
 - Dòng đầu tiên là 2 số nguyên dương N, Q (1≤N,Q≤105)
 - Dòng tiếp theo chứa N số nguyên ai(−109≤ai≤109)
 là các phần tử của mảng.

- Q dòng tiếp theo, mỗi dòng chứa một số x là câu hỏi của truy vấn.

Output:
Gồm Q dòng, mỗi dòng gồm một câu trả lời. Nếu x trong dãy a thì in ra ‘YES'. Ngược lại, in ra ‘NO'.*/

#include <iostream>
#include <algorithm>
using namespace std;

bool myBinarySearch(int a[], int n, int x, int &pos, int &count);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int x; cin >> x;
    int count = 0, pos =-1;
    if(myBinarySearch(arr, n, x, pos, count))
        cout << pos << "\n" << count;
    else cout << "-1";
    return 0;
}


bool myBinarySearch(int arr[], int n, int x, int &pos, int &count) {
     int left = 0; 
     int right = n-1;
     while (left <= right) {
          int mid = (left + right) / 2;
          if (arr[mid] == x) {
            pos = mid;
            count++;
            return true;
          }
          count++;
          if (arr[mid] > x) right = mid - 1;
          else left = mid + 1;
     }
     return false;
}