/*Hãy hoàn thành hàm Sort(vector) để sắp xếp một dãy số nguyên, sao cho phần trước là các số chẵn tăng dần, phần sau là các số lẻ tăng dần.
Lưu ý:
1) Chỉ cài đặt hàm Sort và các hàm liên quan (nếu cần) để sắp xếp theo yêu cầu của đề bài.
2) Các hàm nhập, xuất đã được cài đặt sẵn, phù hợp với định dạng nhập xuất.*/

#include <iostream>
#include <vector>

using namespace std;

void Sort(vector<int> &);

int main()
{
    int n, k;
    vector<int> nums;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        nums.push_back(k);
    }
    Sort(nums);
    for (int i = 0; i < n; i++) {
        cout << nums[i] << ' ';
    }
    return 0;
}

void quickSort(vector<int>& v, int left, int right) {
    if (left >= right) return;
    
    int pivot = v[(left + right) / 2]; // Chọn chốt ở giữa
    int i = left, j = right;
    
    while (i <= j) {
        while (v[i] < pivot) i++; // Tìm phần tử lớn hơn hoặc bằng pivot bên trái
        while (v[j] > pivot) j--; // Tìm phần tử nhỏ hơn hoặc bằng pivot bên phải
        if (i <= j) {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    
    // Gọi đệ quy cho 2 nửa
    quickSort(v, left, j);
    quickSort(v, i, right);
}


void Sort(vector<int>& v) {
    if (v.empty()) return;

    int n = v.size();
    int left = 0, right = n - 1;
    
    while (left < right) {
        while (v[left] % 2 == 0) left++;
        while (v[right] % 2 == 1) right--;
        if (left < right) {
            swap(v[left], v[right]);
            left++;
            right--;
        }
    }
    int partitionIndex = left;
    while (partitionIndex < n && v[partitionIndex] % 2 == 0) partitionIndex++;

    // Sắp xếp các số chẵn bên trái
    quickSort(v, 0, partitionIndex - 1);
    
    // Sắp xếp các số lẻ bên phải
    quickSort(v, partitionIndex, n - 1);
}



