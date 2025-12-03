//Duplicate each occurrence of two (2), shifting the remaining elements to the right.
#include<iostream>
using namespace std;
int main(){
    int n, temp;
    cout<<"Enter the no. of elements in the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    for(int i=0; i<n-1; i++){
        if(arr[i]==2){
            for(int j=n-1; j>i; j--){
                arr[j+1]=arr[j];
            }
            arr[i+1]=2;
            i++;
        }
    }

    cout<<"The Updated Array is: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"  ";
    }
    return 0;
}