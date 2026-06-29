/*Cài đặt hàm InsertionSort khi nhập vào một dãy số và sắp xếp theo thứ tự giảm dần, biết nếu input là 
7
3 0 8 2 1 4 7

thì output được trình bày như sau:

Mang truoc khi sap xep:
3 0 8 2 1 4 7

Sap xep:
i = 1
Mang truoc khi xu ly: 3 0 8 2 1 4 7
Phan tu dang xet A[1] = 0
Chen 0 vao vi tri k = 1
Mang sau khi xu ly: 3 0 8 2 1 4 7

i = 2
Mang truoc khi xu ly: 3 0 8 2 1 4 7
Phan tu dang xet A[2] = 8
Chen 8 vao vi tri k = 0
Mang sau khi xu ly: 8 3 0 2 1 4 7

i = 3
Mang truoc khi xu ly: 8 3 0 2 1 4 7
Phan tu dang xet A[3] = 2
Chen 2 vao vi tri k = 2
Mang sau khi xu ly: 8 3 2 0 1 4 7

i = 4
Mang truoc khi xu ly: 8 3 2 0 1 4 7
Phan tu dang xet A[4] = 1
Chen 1 vao vi tri k = 3
Mang sau khi xu ly: 8 3 2 1 0 4 7

i = 5
Mang truoc khi xu ly: 8 3 2 1 0 4 7
Phan tu dang xet A[5] = 4
Chen 4 vao vi tri k = 1
Mang sau khi xu ly: 8 4 3 2 1 0 7

i = 6
Mang truoc khi xu ly: 8 4 3 2 1 0 7
Phan tu dang xet A[6] = 7
Chen 7 vao vi tri k = 1
Mang sau khi xu ly: 8 7 4 3 2 1 0

Mang sau khi sap xep:
8 7 4 3 2 1 0
*/
#include <bits/stdc++.h>
using namespace std;

void printArr(long long arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

void MyInsertionSort(long long arr[], int n) {
        for (int i = 1; i<n; i++){
            cout << "i = " << i << "\n";
            cout << "Mang truoc khi xu ly: "; printArr(arr, n);
            cout << "Phan tu dang xet A[" << i << "] = " << arr[i] << "\n";
            int key = arr[i];
            int x = i-1;
            while (x>=0 && arr[x] < key) {
                arr[x+1] = arr[x];
                x--;
            }
            cout << "Chen " << key << " vao vi tri k = " << x+1 << "\n";    
            arr[x+1] = key;
            cout << "Mang sau khi xu ly: "; printArr(arr, n); cout << "\n";

        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long arr[10000];
    cin >> n;    
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Mang truoc khi sap xep:\n";
    printArr(arr, n); cout << "\n";

    cout << "Sap xep:\n";
    MyInsertionSort(arr, n);

    cout << "Mang sau khi sap xep:\n";
    printArr(arr, n);
    return 0;
}