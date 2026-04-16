/*
Input
Dong dau tien la so nguyen N duong (0 < N < 200)

Dong tiep theo chua N so nguyen (voi gia tri moi so nguyen nho hon 2 * 10^9) la cac phan tu cua mang A

Output
In ra man hinh theo mau vi du:
Mang truoc khi sap xep:
3 0 8 2 1 4 7

Sap xep:
i = 1
Mang truoc khi xu ly: 3 0 8 2 1 4 7
Phan tu dang xet A[1] = 0
Chen 0 vao vi tri k = 0
Mang sau khi xu ly: 0 3 8 2 1 4 7

...
*/

#include <bits/stdc++.h>
using namespace std;

void Output(long long a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
}

void InsertionSort(long long a[], int n) {
    for (int i = 1; i < n; i++) {
        long long x = a[i];
        int k = i - 1;

        cout << "i = " << i << '\n';
        cout << "Mang truoc khi xu ly: ";
        Output(a, n);
        cout << "Phan tu dang xet A[" << i << "] = " << x << '\n';

        while (k >= 0 && a[k] > x) {
            a[k + 1] = a[k];
            k--;
        }

        k++;
        a[k] = x;

        cout << "Chen " << x << " vao vi tri k = " << k << '\n';
        cout << "Mang sau khi xu ly: ";
        Output(a, n);
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long A[10000];
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "Mang truoc khi sap xep:\n";
    Output(A, n);
    cout << '\n';

    cout << "Sap xep:\n";
    InsertionSort(A, n);

    cout << "Mang sau khi sap xep:\n";
    Output(A, n);

    return 0;
}
