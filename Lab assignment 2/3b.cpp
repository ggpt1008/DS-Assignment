#include<iostream>
using namespace std;

int binaryMissing(int arr[], int n)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = l + (l + r) / 2;
        if (arr[mid] != mid + 1)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l + 1;
}

int main() {
    int arr[]= {1,2,3,4,6};
    int n = 5;
    
    cout<<"Missing number :"<<binaryMissing(arr,5);

    return 0;
}