#include<iostream>
using namespace std;
int main(){
    int k, n,cnt=0;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"The array is: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"  ";
    }
    
    cout<<endl<<"Enter the positive integer k: ";
    cin>>k;

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]-arr[j]==k || arr[i]-arr[j]==-k){
                cnt+=1;
            }
        }
    }

    cout<<"The number of pairs in the array whose difference is equal to k are: "<<cnt<<endl;

    return 0;
}