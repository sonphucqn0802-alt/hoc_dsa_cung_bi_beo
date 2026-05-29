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