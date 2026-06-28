/*Tìm kiếm tuyến tính hay tìm kiếm tuần tự là một thuật toán tìm kiếm cơ bản để tìm kiếm một phần tử trong danh sách theo thứ tự tuần tự. Nó hoạt động bằng cách duyệt qua từng phần tử trong danh sách và so sánh phần tử đó với phần tử cần tìm kiếm cho đến khi tìm thấy hoặc đến cuối danh sách.

Cách thức hoạt động:

Bắt đầu từ đầu danh sách.
So sánh phần tử hiện tại với phần tử cần tìm kiếm.
Nếu hai phần tử bằng nhau, thuật toán trả về vị trí của phần tử cần tìm kiếm và dừng.
Nếu hai phần tử không bằng nhau, thuật toán di chuyển đến phần tử tiếp theo trong danh sách và lặp lại bước 2 và 3.
Nếu thuật toán duyệt qua toàn bộ danh sách mà không tìm thấy phần tử cần tìm kiếm, nó sẽ trả về thông báo "Không tìm thấy".
Hãy cài đặt hàm int search(int arr[], int N, int x) để tìm kiểm phần từ x ở vị trí thứ mấy trong mảng arr có kích thước N, nếu không tìm thấy thì trả về -1

Ví dụ 1

với tham số 

arr[] = {9,6,7,2,7} ,N = 5 , x = 7

thì hàm search(int arr[], int N, int x) sẽ trả về giá trị 2

 

Ví dụ 2

với tham số 

arr[] = {9,6,7,2,7} ,N = 5 , x = 4

thì hàm search(int arr[], int N, int x) sẽ trả về giá trị -1*/#include <iostream>
using namespace std;
int search(int arr[], int N, int x){
     int index = 0;
     for (int i=0; i<N; i++){
          if (arr[i]==x) {
               index = i;
               break;
          }
          index=-1;
     }
     return index;
}

int main(){
    int arr[100],n,x;
    cin>>n;
    for (int i = 0; i < n ; i++)    
        cin>>arr[i];
    cin>>x;
    cout<<search(arr, n, x)<<endl;
    return 0;
}