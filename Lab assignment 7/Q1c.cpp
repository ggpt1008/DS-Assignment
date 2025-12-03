#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n) {

    for(int i=1; i<n; i++){
        bool swapped = false;
        for(int j=0; j<n-i; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false)
            break;
    }
}

int main() {

    int even[6] = {10,1,7,6,14,9};

    bubbleSort(even,6); 
    cout << "Final array: ";
    for(int i=0; i<6; i++){
        cout << even[i] << " ";
    }
    cout << endl;

    return 0;
}