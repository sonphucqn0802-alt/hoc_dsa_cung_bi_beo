/*
Input
Dòng đầu tiên là số nguyên N dương (0 < N < 200)

Dòng tiếp theo chứa N số nguyên (với giá trị mỗi số nguyên nhỏ hơn 2 * 10^9) là các phần tử của mảng A

Output
In ra màn hình theo mẫu ví dụ :
Mang truoc khi sap xep:
3 0 8 2 1 4 7

Sap xep:
i = 0
Mang truoc khi swap: 3 0 8 2 1 4 7
Phan tu nho nhat trong doan [1, 6]: 0
Swap 3 va 0
Mang sau khi swap: 0 3 8 2 1 4 7

i = 1
Mang truoc khi swap: 0 3 8 2 1 4 7
Phan tu nho nhat trong doan [2, 6]: 1
Swap 3 va 1
Mang sau khi swap: 0 1 8 2 3 4 7

i = 2
Mang truoc khi swap: 0 1 8 2 3 4 7
Phan tu nho nhat trong doan [3, 6]: 2
Swap 8 va 2
Mang sau khi swap: 0 1 2 8 3 4 7

i = 3
Mang truoc khi swap: 0 1 2 8 3 4 7
Phan tu nho nhat trong doan [4, 6]: 3
Swap 8 va 3
Mang sau khi swap: 0 1 2 3 8 4 7

i = 4
Mang truoc khi swap: 0 1 2 3 8 4 7
Phan tu nho nhat trong doan [5, 6]: 4
Swap 8 va 4
Mang sau khi swap: 0 1 2 3 4 8 7

i = 5
Mang truoc khi swap: 0 1 2 3 4 8 7
Phan tu nho nhat trong doan [6, 6]: 7
Swap 8 va 7
Mang sau khi swap: 0 1 2 3 4 7 8

Mang sau khi sap xep:
0 1 2 3 4 7 8
*/

#include <bits/stdc++.h>
using namespace std;  

void Output(long long arr[], int n) {
     for (int i = 0; i < n; i++)
          cout << arr[i] << " ";
     cout << endl;
}

void SelectionSort(long long arr[], int n) {
     for (int i = 0; i < n-1; i++) {
          cout << "i = " << i << endl;
          cout << "Mang truoc khi swap: ";
          Output(arr, n);
          // Tim phan tu nho nhat trong doan [i, n-1]
          int idx = i;
          for (int j = i + 1; j < n; j++) {
               if (arr[j] < arr[idx])
                    idx = j;
          }
          cout << "Phan tu nho nhat trong doan [" << i+1 << ", " << n-1 << "]: " << arr[idx] << endl;
          cout << "Swap " << arr[i] << " va " << arr[idx] << endl;
          swap(arr[i], arr[idx]);
          cout << "Mang sau khi swap: ";
          Output(arr, n);
          cout << endl;
     }    
}

int main () {
     ios_base::sync_with_stdio(false);
     cin.tie(nullptr);
     cout.tie(nullptr);
     
     int n;    
     long long arr[10000];
     cin >> n;
     for (int i = 0; i < n; i++)
          cin >> arr[i];


     cout << "Mang truoc khi sap xep:" << endl;
     Output(arr, n);
     cout << endl;
     cout << "Sap xep:" << endl;
     SelectionSort(arr, n);
     cout << "Mang sau khi sap xep:" << endl;
     Output(arr, n);
     return 0;
}