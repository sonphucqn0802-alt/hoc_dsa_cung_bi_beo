/*Cài đặt hàm MergeSort khi nhập vào một dãy số và sắp xếp theo thứ tự giảm dần, biết nếu input là 
7
3 0 8 2 1 4 7

thì output được trình bày như sau: 
Mang truoc khi sap xep:
3 0 8 2 1 4 7

Sap xep

Mang sau khi sap xep:
8 7 4 3 2 1 0*/
#include <iostream>
using namespace std;

void Output(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Merge(int arrA[], int low, int mid, int high) {
    int N = high - low + 1;
    int left = low, right = mid+1, bIdx = 0;
    int arrB[N];
    //compare and merge
    while (left<=mid && right<=high) {
        if (arrA[left] >= arrA[right]){
            arrB[bIdx] = arrA[left];
            left++;
        } else {
            arrB[bIdx] = arrA[right];
            right++;
        }
        bIdx++;
    }
    //check leftover value haven't been compared
    while (left<=mid) {
        arrB[bIdx] = arrA[left];
        left++;
        bIdx++;
    }
    while (right<=high) {
        arrB[bIdx] = arrA[right];
        right++;
        bIdx++;
    }

    //Copy back to original array
    for (int k=0; k<N; k++){
        arrA[low+k] = arrB[k];
    }
}

void MergeSort(int arrA[], int low, int high){
    if (low < high) {
        int mid = low + (high - low) / 2;
        MergeSort(arrA, low, mid);
        MergeSort(arrA, mid + 1, high);
        Merge(arrA, low, mid, high);
    }
}

int main() {
    int n;
    int arr[10000];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Mang truoc khi sap xep:" << endl;
    Output(arr, n);
    cout << "Sap xep" << endl;
    MergeSort(arr, 0, n-1);
    cout << "Mang sau khi sap xep:" << endl;
    Output(arr, n);
    return 0;
}