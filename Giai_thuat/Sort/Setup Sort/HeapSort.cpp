/*Cài đặt thuật toán Heap Sort sắp xếp một mảng giảm dần*/

#include <bits/stdc++.h>



using namespace std;
void printArray(const vector<int>& a, int n, int total) {
    for (int i = 0; i < total; ++i) {
        if (i == n) cout << "| ";
        cout << a[i] << (i == total - 1 ? "" : " ");
    }
    cout << endl;
}

void heapify(vector<int>& a, int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] < a[smallest]) smallest = l;
    if (r < n && a[r] < a[smallest]) smallest = r;

    if (smallest != i) {
        swap(a[i], a[smallest]);
        heapify(a, n, smallest);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    cout << "Mang truoc khi sap xep:" << endl;
    for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? "" : " ");
    cout << "\n\nSap xep:" << endl;


    // Build min heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }

    cout << "Mang sau khi BuildHeap: ";
    for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? "" : " ");
    cout << endl;

    for (int i = n - 1; i > 0; i--) {
        cout << "Swap " << a[0] << " va " << a[i] << endl;
        swap(a[0], a[i]);
        heapify(a, i, 0);
        cout << "\nMang sau khi heapify voi n = " << i << ": ";
        printArray(a, i, n);
    }
// 
    cout << "Mang sau khi sap xep:" << endl;
    for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? "" : " ");

    return 0;
}