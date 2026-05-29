#include <iostream>
#include <algorithm>
using namespace std;

bool myBinarySearch(int a[], int n, int x, int &pos, int &count);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int x; cin >> x;
    int count = 0, pos =-1;
    if(myBinarySearch(arr, n, x, pos, count))
        cout << pos << "\n" << count;
    else cout << "-1";
    return 0;
}


bool myBinarySearch(int arr[], int n, int x, int &pos, int &count) {
     int left = 0; 
     int right = n-1;
     while (left <= right) {
          int mid = (left + right) / 2;
          if (arr[mid] == x) {
            pos = mid;
            count++;
            return true;
          }
          count++;
          if (arr[mid] > x) right = mid - 1;
          else left = mid + 1;
     }
     return false;
}