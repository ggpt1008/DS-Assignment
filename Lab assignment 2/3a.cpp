#include<iostream>
using namespace std;

int missingNumber(int arr[], int n) {

    for(int i=0;i<n-1;i++) {
        if(arr[i] != i+1){ // means index barabar nhi hai 
            return i+1;
        }
    }
    return n;
}

int main() {

    int arr[] = {1,2,3,5,6,7};
    int n = 7;

    cout<<"Missing number :" <<missingNumber(arr,n)<<endl;

    return 0;
}