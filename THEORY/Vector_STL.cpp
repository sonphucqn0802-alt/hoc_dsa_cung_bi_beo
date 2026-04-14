#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void inTieuDe(const string& tieuDe) {
    cout << "\n===== " << tieuDe << " =====\n";
}

template <typename T>
void inVector(const vector<T>& v, const string& tenVector) {
    cout << tenVector << " = [";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i + 1 < v.size()) {
            cout << ", ";
        }
    }
    cout << "]\n";
}

void demoKhoiTao() {
    inTieuDe("1. Khoi tao vector");

    vector<int> rong;
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b(5);
    vector<int> c(4, 7);

    inVector(rong, "rong");
    inVector(a, "a");
    inVector(b, "b");
    inVector(c, "c");

    cout << "a.size() = " << a.size() << '\n';
    cout << "rong.empty() = " << (rong.empty() ? "true" : "false") << '\n';
}

void demoThemXoaCuoi() {
    inTieuDe("2. Them va xoa cuoi vector");

    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    inVector(v, "v sau push_back");

    v.pop_back();
    inVector(v, "v sau pop_back");

    cout << "Phan tu dau: " << v.front() << '\n';
    cout << "Phan tu cuoi: " << v.back() << '\n';
}

void demoTruyCap() {
    inTieuDe("3. Truy cap phan tu");

    vector<int> v = {5, 10, 15, 20};

    cout << "v[0] = " << v[0] << '\n';
    cout << "v.at(2) = " << v.at(2) << '\n';

    v[1] = 99;
    inVector(v, "v sau khi doi v[1]");
}

void demoDuyetVector() {
    inTieuDe("4. Duyet vector");

    vector<int> v = {2, 4, 6, 8};

    cout << "Duyet bang chi so: ";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << ' ';
    }
    cout << '\n';

    cout << "Duyet bang range-based for: ";
    for (int x : v) {
        cout << x << ' ';
    }
    cout << '\n';
}

void demoInsertErase() {
    inTieuDe("5. Chen va xoa o giua vector");

    vector<int> v = {1, 2, 4, 5};
    inVector(v, "v ban dau");

    v.insert(v.begin() + 2, 3);
    inVector(v, "v sau insert so 3 vao vi tri index 2");

    v.erase(v.begin() + 1);
    inVector(v, "v sau erase phan tu tai index 1");
}

void demoSort() {
    inTieuDe("6. Sap xep vector");

    vector<int> v = {7, 2, 9, 1, 5};
    inVector(v, "v ban dau");

    sort(v.begin(), v.end());
    inVector(v, "v sau sort tang dan");

    reverse(v.begin(), v.end());
    inVector(v, "v sau reverse");
}

void demoVector2D() {
    inTieuDe("7. Vector 2 chieu");

    vector<vector<int>> maTran = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (size_t i = 0; i < maTran.size(); ++i) {
        cout << "Hang " << i << ": ";
        for (int x : maTran[i]) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}

void demoStringVector() {
    inTieuDe("8. Vector chuoi");

    vector<string> monHoc = {"CTDL", "OOP", "DSA"};
    monHoc.push_back("STL");

    cout << "Danh sach mon hoc:\n";
    for (const string& mon : monHoc) {
        cout << "- " << mon << '\n';
    }
}

int main() {
    cout << "CHUONG TRINH HOC VECTOR TRONG C++\n";

    demoKhoiTao();
    demoThemXoaCuoi();
    demoTruyCap();
    demoDuyetVector();
    demoInsertErase();
    demoSort();
    demoVector2D();
    demoStringVector();

    cout << "\nGoi y tu hoc:\n";
    cout << "1. Thu doi du lieu trong tung demo.\n";
    cout << "2. Thu them lenh clear(), resize(), assign().\n";
    cout << "3. Thu viet bai toan nhap n so vao vector va tim max/min.\n";

    return 0;
}
