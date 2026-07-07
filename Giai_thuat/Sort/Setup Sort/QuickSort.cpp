/*Cài đặt thuật toán Quick Sort sắp xếp một mảng giảm dần*/

#include <iostream>
#include <vector>

using namespace std;

// Hàm tiện ích để in mảng theo định dạng yêu cầu
void printArray(const vector<int>& A) {
    for (size_t i = 0; i < A.size(); ++i) {
        cout << A[i] << (i + 1 < A.size() ? " " : "");
    }
    cout << "\n";
}

void quickSortDecreasing(vector<int>& A, int left, int right) {
    if (left >= right) return;

    // 1. In trạng thái TRƯỚC khi phân hoạch (partition)
    cout << "Truoc: ";
    printArray(A);

    // 2. Chọn Pivot ở vị trí giữa mảng
    int mid = left + (right - left) / 2;
    int pivot = A[mid];
    
    cout << "Left=" << left << " - Right=" << right << " - Pivot=" << pivot << "\n";

    // 3. Phân hoạch Hoare (Hoare Partition) hoán đổi để sắp xếp giảm dần
    int i = left;
    int j = right;

    while (i <= j) {
        // Vì sắp xếp GIẢM DẦN:
        // Đi từ bên trái, tìm phần tử nhỏ hơn pivot để đổi ra sau
        while (A[i] > pivot) i++;
        // Đi từ bên phải, tìm phần tử lớn hơn pivot để đổi lên trước
        while (A[j] < pivot) j--;

        if (i <= j) {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }

    // 4. In trạng thái SAU khi phân hoạch xong bước này
    cout << "Sau: ";
    printArray(A);

    // 5. Đệ quy các nhánh (chỉ gọi nếu đoạn có từ 2 phần tử trở lên)
    if (left < j)  quickSortDecreasing(A, left, j);
    if (i < right) quickSortDecreasing(A, i, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    cout << "Mang truoc khi sap xep:\n";
    printArray(A);
    
    cout << "Sap xep:\n";
    quickSortDecreasing(A, 0, A.size() - 1);

    cout << "Mang sau khi sap xep:\n";
    printArray(A);

    return 0;
}