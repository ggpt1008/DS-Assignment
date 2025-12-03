#include<iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for(int i=1; i<n; i++){
        int temp = arr[i];
        int j =i-1;

        while(j>=00 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main() {
    int odd[7] = {10, 1, 7, 4, 8, 2, 11};

    insertionSort(odd, 7); 

    cout << "Final array: ";
    for (int i = 0; i < 7; i++) {   
        cout << odd[i] << " ";
    }
    cout << endl;

    return 0;
}