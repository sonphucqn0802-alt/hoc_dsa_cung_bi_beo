/*
Input
Dòng đầu tiên là số nguyên N dương (0 < N < 200)

Dòng tiếp theo chứa N số nguyên (với giá trị mỗi số nguyên nhỏ hơn 2 * 10^9) là các phần tử của mảng A

Output
In ra màn hình theo mẫu ví dụ:
Mang truoc khi sap xep:
3 0 8 2 1 4 7

Sap xep:
i = 1
Mang truoc khi xu ly: 3 0 8 2 1 4 7
Phan tu dang xet A[1] = 0
Chen 0 vao vi tri k = 0
Mang sau khi xu ly: 0 3 8 2 1 4 7

i = 2
Mang truoc khi xu ly: 0 3 8 2 1 4 7
Phan tu dang xet A[2] = 8
Chen 8 vao vi tri k = 2
Mang sau khi xu ly: 0 3 8 2 1 4 7

i = 3
Mang truoc khi xu ly: 0 3 8 2 1 4 7
Phan tu dang xet A[3] = 2
Chen 2 vao vi tri k = 1
Mang sau khi xu ly: 0 2 3 8 1 4 7

i = 4
Mang truoc khi xu ly: 0 2 3 8 1 4 7
Phan tu dang xet A[4] = 1
Chen 1 vao vi tri k = 1
Mang sau khi xu ly: 0 1 2 3 8 4 7

i = 5
Mang truoc khi xu ly: 0 1 2 3 8 4 7
Phan tu dang xet A[5] = 4
Chen 4 vao vi tri k = 4
Mang sau khi xu ly: 0 1 2 3 4 8 7

i = 6
Mang truoc khi xu ly: 0 1 2 3 4 8 7
Phan tu dang xet A[6] = 7
Chen 7 vao vi tri k = 5
Mang sau khi xu ly: 0 1 2 3 4 7 8

Mang sau khi sap xep:
0 1 2 3 4 7 8
*/

#include <iostream>
using namespace std;

void Output(int *a, int n){
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

void InsertionSort(int a[], int n){
     int k, x;
     for (int i = 1; i < n; i++){
        k = i - 1;
        x = a[i];

        for (; k >= 0 && a[k] > a[i]; k--);

        k++;

        for (int j = i; j > k; j--)
            a[j] = a[j - 1];
        a[k] = x;
          cout << "Mang sau khi xu ly: ";
          Output(a, n);
     }
}

int main() {
    int A[] = {3, 0, 8, 2, 1, 4, 7};
    int n = 7;
    
    cout << "Mang truoc khi sap xep:\n";
    Output(A, n);
    
    InsertionSort(A, n);

    cout << "Mang sau khi sap xep:\n";
    Output(A, n);
    
    return 0;
}