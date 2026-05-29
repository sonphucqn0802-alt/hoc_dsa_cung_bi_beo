#include <iostream>
#include <algorithm>
using namespace std;

bool myBinarySearch(int a[], int n, int x);

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int x; 
    while (q--){
        cin >> x;
        if (myBinarySearch(arr, n, x))
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}


bool myBinarySearch(int a[], int n, int x) {
     int left = 0; 
     int right = n-1;
     while (left <= right) {
          int mid = (left + right) / 2;
          if (a[mid] == x) return true;
          if (a[mid] > x) right = mid - 1;
          else left = mid + 1;
     }
     return false;
}