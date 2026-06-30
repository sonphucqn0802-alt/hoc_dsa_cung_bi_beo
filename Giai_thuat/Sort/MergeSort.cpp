/*Cài đặt hàm MergeSort khi nhập vào một dãy số và sắp xếp theo thứ tự giảm dần, biết nếu input là 
7
3 0 8 2 1 4 7

thì output được trình bày như sau: 
Mang truoc khi sap xep:
3 0 8 2 1 4 7

Sap xep
k = 1
Mang A (truoc khi chia): 3 0 8 2 1 4 7
Mang B: 3 8 1 7
Mang C: 0 2 4
Mang A (sau khi gop): 3 0 8 2 4 1 7

k = 2
Mang A (truoc khi chia): 3 0 8 2 4 1 7
Mang B: 3 0 4 1
Mang C: 8 2 7
Mang A (sau khi gop): 8 3 2 0 7 4 1

k = 4
Mang A (truoc khi chia): 8 3 2 0 7 4 1
Mang B: 8 3 2 0
Mang C: 7 4 1
Mang A (sau khi gop): 8 7 4 3 2 1 0

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

// Hàm thực hiện một lượt tách và gộp theo bước k
void ProcessStep(int arrA[], int n, int k) {
    int arrB[100], arrC[100];
    int bCount = 0, cCount = 0;
    
    // 1. Tách mảng A thành B và C dựa trên bước k
    int i = 0;
    bool toB = true; // Cờ quyết định bỏ vào B hay C
    while (i < n) {
        // Nhặt tối đa k phần tử
        for (int step = 0; step < k && i < n; step++) {
            if (toB) {
                arrB[bCount++] = arrA[i++];
            } else {
                arrC[cCount++] = arrA[i++];
            }
        }
        toB = !toB; // Đổi phe sau khi nhặt đủ k phần tử
    }

    // In trạng thái trước khi chia và hai mảng B, C
    cout << "Mang A (truoc khi chia): "; Output(arrA, n);
    cout << "Mang B: "; Output(arrB, bCount);
    cout << "Mang C: "; Output(arrC, cCount);

    // 2. Trộn ngược B và C vào A (Theo quy tắc giảm dần giống mẫu của bạn)
    int bIdx = 0, cIdx = 0, aIdx = 0;
    
    // Trộn từng cặp phân đoạn độ dài k từ B và C
    while (bIdx < bCount || cIdx < cCount) {
        int bEnd = min(bIdx + k, bCount);
        int cEnd = min(cIdx + k, cCount);
        
        int currB = bIdx;
        int currC = cIdx;
        
        // Trộn giảm dần hai đoạn hiện tại
        while (currB < bEnd && currC < cEnd) {
            if (arrB[currB] >= arrC[currC]) {
                arrA[aIdx++] = arrB[currB++];
            } else {
                arrA[aIdx++] = arrC[currC++];
            }
        }
        
        // Chép nốt phần dư của đoạn B
        while (currB < bEnd) {
            arrA[aIdx++] = arrB[currB++];
        }
        
        // Chép nốt phần dư của đoạn C
        while (currC < cEnd) {
            arrA[aIdx++] = arrC[currC++];
        }
        
        // Cập nhật chỉ số tổng để nhảy sang đoạn tiếp theo
        bIdx = bEnd;
        cIdx = cEnd;
    }

    cout << "Mang A (sau khi gop): "; Output(arrA, n);
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    
    // Sửa lỗi cấp phát mảng tĩnh với biến n chưa khởi tạo
    int arr[100]; 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Mang truoc khi sap xep:" << endl;
    Output(arr, n);
    cout << endl;
    
    cout << "Sap xep:" << endl;
    // Chạy vòng lặp tăng bước k nhân đôi sau mỗi lượt: 1, 2, 4... cho đến khi bao phủ mảng
    for (int k = 1; k < n; k *= 2) {
        cout << "k = " << k << endl;
        ProcessStep(arr, n, k);
    }
    
    cout << "Mang sau khi sap xep:" << endl;
    Output(arr, n);
    
    return 0;
}