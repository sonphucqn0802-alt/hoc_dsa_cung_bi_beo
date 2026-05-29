#include <bits/stdc++.h>
using namespace std;

int strBinarySearch(int n, string A[]){
     string x; cin >>x;
     int left = 0, right = n-1;
     int count = 0;

     while (left<=right) {
          int mid = (left + right)/2;
          count ++;

          if (A[mid]==x) {
               cout << mid << endl;
               cout << count;
               return 0;
          }
          else if (A[mid] < x) {
               left = mid +1;
          }
          else {
               right = mid -1;
          }
     }
     cout << "-1" << endl;
     return 0;
}



int main(){
     int N;
     string A[2000];
     cin >> N;
     for (int i = 0; i< N; i++) {
          cin>>A[i];
     }
     strBinarySearch(N, A);

     return 0;
}