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
