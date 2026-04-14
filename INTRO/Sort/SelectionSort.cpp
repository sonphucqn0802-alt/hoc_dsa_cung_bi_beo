     /*Bài toán: Thuật toán sắp xếp chọn

Thuật toán selection sort cũng là một trong những thuật toán đơn giản.

Yêu cầu: Hãy cài đặt thuật toán sắp selection sort để sắp xếp lại tăng dần mảng có N phần tử. Trong lúc chạy thuật toán, nếu xảy ra hành động swap, hãy in ra mảng sau hành động swap đó. Bằng cách này, các bạn có thể hình dung được cách hoạt động của thuật toán sắp xếp.

Lưu ý: swap xảy ra nếu vị trí của phần tử nhỏ nhất khác vị trí của phần tử đang xét i

Input:

Dòng đầu tiên là số nguyên N dương (0 < N < 200)

Dòng tiếp theo chứa N số nguyên Ai là các phần tử của mảng

Output:

Các dòng tiếp theo in ra cấu hình của mảng A mỗi lần mảng A xảy ra hành động swap.*/
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
