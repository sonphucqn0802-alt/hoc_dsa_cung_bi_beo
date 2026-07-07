/*Hãy hoàn thành hàm InsertionSort(Hocsinh [], int) để sắp xếp mảng học sinh, có n phần tử,
theo thứ tự tăng dần của họ tên, đồng thời trả về số lần dịch chuyển phần tử trong quá trình sắp xếp. 

Thứ tự của họ tên cũng chính là thứ tự chuỗi theo bảng chữ cái.
Lưu ý:
1) Chỉ cài đặt hàm InsertionSort.
2) Kiểu dữ liệu đã được cài đặt sẵn. Sinh viên có thể đọc để sử dụng.
3) Đầu vào và đầu ra đã được xử lý sẵn và phù hợp với định dạng nhập/xuất.*/


#include <iostream>

using namespace std;

struct Hocsinh {
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};
void Input(Hocsinh &x) {
    cin >> x.Maso;
    getline(cin>>ws, x.Hoten);
    cin >> x.Namsinh;
    cin >> x.Gioitinh;
    cin >> x.TBK;
}
void Output(Hocsinh hs) {
    cout << '[' << hs.Maso << "\t" << hs.Hoten << "\t" << hs.Gioitinh << "\t" << hs.Namsinh << "\t" << hs.TBK << "]\n";
}


int InsertionSort(Hocsinh [] , int);

int main()
{
    Hocsinh *ls = NULL;
    int n;
    cin >> n;
    ls = new Hocsinh[n];
    for (int i = 0; i < n; i++) {
        Input(ls[i]);
    }
    cout << InsertionSort(ls, n) << endl;
    for (int i = 0; i < n; i++) {
        Output(ls[i]);
    }
    delete [] ls;
    return 0;
}

int InsertionSort(Hocsinh ls[], int n) {
    int count = 0;
    for (int i = 1; i<n; i++){
        Hocsinh key = ls[i];
        int k = i-1;
        while (k>=0 && ls[k].Hoten > key.Hoten) {
            ls[k+1] = ls[k];
            k--;
            count++;
        }
        ls[k+1] = key;
    }

    return count;
}


