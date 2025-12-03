#include<iostream>
using namespace std;

void selectionSort(Int arr[], int n) {

    for(int i =0;i<n;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex],arr[i]);
    }
}

int main() {
    int odd[5] = {1,7,9,2,3};

    selectionSort(odd, 5); 

    cout << "Sorted array: ";
    for(int i=0; i<5; i++){
        cout << odd[i] << " ";
    }
    cout << endl;

    return 0;
}
