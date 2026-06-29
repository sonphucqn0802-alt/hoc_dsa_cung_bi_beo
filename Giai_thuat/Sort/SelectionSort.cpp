/*Cài đặt hàm SelectionSort khi nhập vào một dãy số và sắp xếp theo thứ tự tăng dần, biết nếu input là 
     7
     3 0 8 2 1 4 7
     thì output được trình bày như sau:
     
     Mang truoc khi sap xep:
     3 0 8 2 1 4 7

     Sap xep:
     i = 0
     Mang truoc khi swap: 3 0 8 2 1 4 7
     Phan tu lon nhat trong doan [1, 6]: 8
     Swap 3 va 8
     Mang sau khi swap: 8 0 3 2 1 4 7

     i = 1
     Mang truoc khi swap: 8 0 3 2 1 4 7
     Phan tu lon nhat trong doan [2, 6]: 7
     Swap 0 va 7
     Mang sau khi swap: 8 7 3 2 1 4 0

     i = 2
     Mang truoc khi swap: 8 7 3 2 1 4 0
     Phan tu lon nhat trong doan [3, 6]: 4
     Swap 3 va 4
     Mang sau khi swap: 8 7 4 2 1 3 0

     i = 3
     Mang truoc khi swap: 8 7 4 2 1 3 0
     Phan tu lon nhat trong doan [4, 6]: 3
     Swap 2 va 3
     Mang sau khi swap: 8 7 4 3 1 2 0

     i = 4
     Mang truoc khi swap: 8 7 4 3 1 2 0
     Phan tu lon nhat trong doan [5, 6]: 2
     Swap 1 va 2
     Mang sau khi swap: 8 7 4 3 2 1 0

     i = 5
     Mang truoc khi swap: 8 7 4 3 2 1 0
     Phan tu lon nhat trong doan [6, 6]: 1
     Swap 1 va 1
     Mang sau khi swap: 8 7 4 3 2 1 0

     Mang sau khi sap xep:
     8 7 4 3 2 1 0
     
     */
#include <bits/stdc++.h>
using namespace std;


void PrintArray(long long arr[], int n) {
     for (int i = 0; i < n; i++)
          cout << arr[i] << " ";
     cout << endl;
}

void MySelectionSort(long long arr[], int n) {
     for (int i = 0; i< n-1; i++) {
          cout << "i = " << i << endl;
          cout << "Mang truoc khi swap: ";
          PrintArray(arr, n);
          int maxIndex = i;
          for (int j=i+1; j<n;j++){
               if (arr[j] > arr[maxIndex]){
                    maxIndex = j;
               }
          }
          cout << "Phan tu lon nhat trong doan [" << i+1 << ", " << n-1 << "]: " << arr[maxIndex] << endl;
          cout << "Swap " << arr[i] << " va " << arr[maxIndex] << endl;
          swap(arr[i], arr[maxIndex]);
          cout << "Mang sau khi swap: ";
          PrintArray(arr, n); cout << endl;
     } 
     cout << endl;  
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
     PrintArray(arr, n); cout << endl;
     cout << "Sap xep:" << endl;
     MySelectionSort(arr, n);
     cout << "Mang sau khi sap xep:" << endl;
     PrintArray(arr, n);

     return 0;
}
