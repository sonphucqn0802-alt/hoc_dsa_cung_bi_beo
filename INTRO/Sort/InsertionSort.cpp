#include <bits/stdc++.h>
using namespace std;

void printArr(long long arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

void MyInsertionSort(long long arr[], int n) {
    for (int i = 1; i < n; i++) {
        long long e = arr[i];
        int k = i - 1;

        // dịch các phần tử >= e sang phải
        while (k >= 0 && arr[k] >= e) {
            arr[k + 1] = arr[k];   // shift
            printArr(arr, n);      // in sau mỗi lần dời
            k--;
        }

        // chèn e vào đúng chỗ (nếu có thay đổi vị trí hoặc kể cả luôn in theo đề)
        arr[k + 1] = e;
        printArr(arr, n);          // in sau hành động gán/chèn
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long arr[10000];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    MyInsertionSort(arr, n);
    return 0;
}