#include<iostream>
using namespace std;

int  binarySearch(int arr[], int n, int key ){

    int start = 0;
    int e = n-1;
    int mid = start + (e-start)/2;

    while(start<=e) {
        if(key == arr[mid]){
            return mid;
        }
        if(key > arr[mid]){
            start = mid +1;
        }
        else {
            e = mid -1;
        }
        mid = start + (e-start)/2;
    }
    return -1;
}

int main() {

    int b[6] = {1,3,5,7,9,11};
    cout<<"Index of 11 is "<<binarySearch(b,6,11);

    return 0;
}