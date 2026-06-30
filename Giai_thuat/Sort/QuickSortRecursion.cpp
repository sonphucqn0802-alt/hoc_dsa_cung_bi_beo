/*Cài đặt thuật toán Quick Sort sắp xếp một mảng giảm dần*/

#include <iostream>
using namespace std;

void Output(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int i, int j) {
    int p = arr[i];
    int m = i;

    for (int k = i+1; k<=j ; k++) {
        if (arr[k] > p || arr[k] == p && rand() % 2 == 0) {
            m++;
            swap (arr[m], arr[k]);
        }
    }
    swap (arr[i], arr[m]);
    return m;
}

void QuickSort(int arr[], int low, int high){
    if (low < high) {
        int m = partition(arr, low, high);
        QuickSort(arr, low, m - 1);
        QuickSort(arr, m + 1, high);
    }
    cout << "Sap xep xong!" << endl;
}

int main() {
    int n;
    cin >> n;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Mang truoc khi sap xep:" << endl;
    Output(arr, n); cout << endl;
    cout << "Sap xep:" << endl;
    QuickSort(arr, 0, n - 1);
    cout << "Mang sau khi sap xep: " << endl;
    Output(arr, n);
    return 0;
}
