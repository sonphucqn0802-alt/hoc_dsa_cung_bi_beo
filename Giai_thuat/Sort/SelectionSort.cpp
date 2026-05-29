     #include <bits/stdc++.h>
     using namespace std;

     void MySelectionSort(long long arr[], int n) {
          for (int i = 0; i < n; i++) {
               int min = i;
               for (int j = i + 1; j < n; j++) {
                    if (arr[j] < arr[min])
                         min = j;
               }    
               swap(arr[i], arr[min]);
               if (i!=min){
                    for (int i = 0; i<n; i++) {
                         cout << arr[i] << " ";
                    }
                    cout << endl;
               }
          }    
     }
     int main () {
          ios_base::sync_with_stdio(false);
          cin.tie(nullptr);
          cout.tie(nullptr);
          
          int n;
          long long arr[10000];
          cin >> n;
          for (int i = 0; i < n; i++)
               cin >> arr[i];
          MySelectionSort(arr, n);

          return 0;
     }
