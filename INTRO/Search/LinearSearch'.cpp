/*Thuật toán tìm kiếm tuyến tính là một trong những thuật toán tìm kiếm đơn giản và dễ dàng cài đặt nhất. Ý tưởng của thuật toán là: với một mảng cho trước có N phần tử và phần tử cần tìm x, duyệt từ đầu mảng đến cuối mảng cho đến khi tìm được phần tử x.

Yêu cầu: Hãy cài đặt thuật toán tìm kiếm tuyến tính để tìm vị trí của x đầu tiên trong mảng có N phần tử và đếm số lần duyệt qua các phần tử.

Input:
Dòng đầu tiên là số nguyên N dương (0 < N < 10000)

Dòng tiếp theo chứa N số nguyên Ai là các phần tử của mảng

Dòng cuối cùng là số nguyên x cần tìm

Output:
Dòng đầu tiên là vị trí của x đầu tiên trong mảng nếu tìm được. Nếu không tìm thấy thì xuất ra -1

Số lần duyệt qua các phần tử của mảng (từ đầu mảng đến cuối) để tìm được x

Dòng thứ ba là vị trí của x đầu tiên trong mảng (đếm từ cuối đến đầu) nếu tìm được. Nếu không tìm thấy thì xuất ra -1

Số lần duyệt qua các phần tử của mảng (từ cuối mảng đến đầu) để tìm được x

Nếu như ở 2 dòng đầu tiên mà không tìm thấy thì không cần xuất ra 2 dòng tiếp theo*/

#include <bits/stdc++.h>
using namespace std;


void search(int arr[], int N, int x){
     int vitri1 = -1;
     int count1 = 0;
     int vitri2 = -1;
     int count2 = 0;
     for (int i=0; i<N; i++){
          if (arr[i]==x) {
               vitri1 = i;
               count1++;
               break;
          }
          count1++;
          vitri1=-1;
     }
     for (int i=N-1;i>=0;i--) {
          if (arr[i]==x) {
               vitri2 = N-i-1;
               count2++;
               break;
          }
          count2++;
          vitri2=-1;
     }

     if (vitri1==-1) {
          cout << "-1" << endl;
     }
     else {
          cout << vitri1 << endl;
          cout << count1 << endl;
          cout << vitri2 << endl;
          cout << count2 << endl;
     }
}

int main() {
     int N,x;
     cin >> N;
     int arr[N+1];
     for (int i=0; i<N; i++)
          cin >> arr[i];
     cin >> x;
     search (arr, N, x);

}