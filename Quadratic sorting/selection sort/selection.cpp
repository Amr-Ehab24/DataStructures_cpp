#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr [],int n){
    int minIN;

    for ( int i = 0; i <n-1 ; ++i) {
        minIN=i;
        for (int j = i+1; j <n ; ++j) {
            if(arr[j]<arr[minIN])
                minIN=j;


        }
        swap(arr[minIN],arr[i]);
        for (int t = 0; t <n ; ++t) {
            cout<<arr[t]<<" ";


        }
        cout<<'\n';


        }







}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i <n ; ++i) {
        cin>>arr[i];
    }
    selectionSort(arr,n);





    return 0;
}


