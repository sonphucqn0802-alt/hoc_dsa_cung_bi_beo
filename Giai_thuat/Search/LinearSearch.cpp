#include <iostream>
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