/*[share chung] Binary Search #2
Thuật toán tìm kiếm nhị phân là một thuật toán tìm kiếm đơn giản nhưng có tốc độ tìm kiếm cực kỳ nhanh. Tuy nhiên, đa phần các hướng dẫn và khóa học trên mạng đều hướng dẫn người học cài đặt trên mảng số nguyên trong khi trong thực tế chỉ cần mảng có thể sắp xếp được thì ra có thể áp dụng thuật toán tìm kiếm nhị phân.

Hãy cài đặt thuật toán tìm kiếm nhị phân trên mảng chuỗi có N phần tử.

Input:
Dòng đầu tiên là số nguyên N dương (0 < N < 2000)

N dòng tiếp theo chứa các phần tử Ai trong mảng, mỗi phần tử là một chuỗi với độ dài không quá 10. Các phần tử này đã được sắp xếp theo thứ tự bảng chữ cái

Dòng cuối cùng là chuỗi x cần tìm

Output:
Dòng đầu tiên là vị trí của x được tìm thấy trong mảng. Nếu không tìm thấy thì xuất ra -1

Dòng tiếp theo là số lần duyệt qua các phần tử để tìm được x. Nếu không tìm thấy thì không cần xuất ra dòng này*/

#include <bits/stdc++.h>
using namespace std;

int strBinarySearch(int n, string A[]){
     string x; cin >>x;
     int left = 0, right = n-1;
     int count = 0;

     while (left<=right) {
          int mid = (left + right)/2;
          count ++;

          if (A[mid]==x) {
               cout << mid << endl;
               cout << count;
               return 0;
          }
          else if (A[mid] < x) {
               left = mid +1;
          }
          else {
               right = mid -1;
          }
     }
     cout << "-1" << endl;
     return 0;
}



int main(){
     int N;
     string A[2000];
     cin >> N;
     for (int i = 0; i< N; i++) {
          cin>>A[i];
     }
     strBinarySearch(N, A);

     return 0;
}