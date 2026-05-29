#include <bits/stdc++.h>
using namespace std;


void search(int arr[], int N, int x){
     int vitri1 = -1;
     int count1 = 0;
     int vitri2 = -1;
     int count2 = 0;
     for (int i=0; i<N; i++){
          if (arr[i]==x) {
               vitri1 = i;
               count1++;
               break;
          }
          count1++;
          vitri1=-1;
     }
     for (int i=N-1;i>=0;i--) {
          if (arr[i]==x) {
               vitri2 = N-i-1;
               count2++;
               break;
          }
          count2++;
          vitri2=-1;
     }

     if (vitri1==-1) {
          cout << "-1" << endl;
     }
     else {
          cout << vitri1 << endl;
          cout << count1 << endl;
          cout << vitri2 << endl;
          cout << count2 << endl;
     }
}

int main() {
     int N,x;
     cin >> N;
     int arr[N+1];
     for (int i=0; i<N; i++)
          cin >> arr[i];
     cin >> x;
     search (arr, N, x);

}