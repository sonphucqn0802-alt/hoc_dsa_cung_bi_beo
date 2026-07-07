/*Cho một tập N điểm (x,y,z)
 trên không gian 3 chiều Oxyz. 
 Bạn hãy sắp xếp và in ra các điểm tăng dần theo x, nếu x bằng nhau thì sắp xếp các điểm giảm dần theo y, nếu y bằng nhau thì sắp xếp các điểm tăng dần theo z.*/


#include <iostream>
#include <vector>

using namespace std;

struct Diem {
    int x;
    int y;
    int z;
};

void quickSortDiem (vector<Diem>& points, int left, int right){
    if (left >= right) return;

    int mid = left + (right -left) /2;
    Diem pivot = points [mid];

    int i = left;
    int j = right;

    while (i<=j) {
        while (points[i].x < pivot.x || (points[i].x == pivot.x && points[i].y > pivot.y) || (points[i].x == pivot.x && points[i].y == pivot.y && points[i].z < pivot.z)) i++;
        while (points[j].x > pivot.x || (points[j].x == pivot.x && points[j].y < pivot.y) || (points[j].x == pivot.x && points[j].y == pivot.y && points[j].z > pivot.z)) j--;
        
        if (i<=j) {
            swap(points[i], points[j]);
            i++;
            j--;
        }
    }
    if (left < j) quickSortDiem (points, left, j);
    if (i < right) quickSortDiem (points, i, right);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector <Diem> points(n);
    for (int i = 0; i< n; i++) {
        cin >> points[i].x >> points[i].y >> points[i].z;
    }

    quickSortDiem(points, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << points[i].x << " " << points[i].y << " " << points[i].z << "\n";
    }

    return 0;
}