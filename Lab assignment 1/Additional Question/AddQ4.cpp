//Sort an array of 0s, 1s and 2s
#include<iostream>
using namespace std;
int main(){
    int n, temp;
    cout<<"Enter the no. of elements in the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array containing only 0s, 1s or 2s: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    cout<<"The Sorted Array is: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"  ";
    }
    return 0;
}
