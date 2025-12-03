#include<iostream>
using namespace std;

void bubbleArray(int arr[], int n) {
    for(int i = 1; i < n; i++) { // i -> round
        bool swapped = false;
        for(int j = 0; j < n - i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        if(!swapped) {
            break;
        }
    }
}

int main() {

    int even[7] = {64,34,25,12,22,11,90};

    bubbleArray(even,6); // sort in-place

    cout << "Final array: ";
    for(int i=0; i<6; i++){
        cout << even[i] << " ";
    }
    cout << endl;


    return 0;
}