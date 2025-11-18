// Find two numbers in an array whose difference equals K. Given an array arr[] and a
// positive integer k, the task is to count all pairs (i, j) such that i < j and absolute value of
// (arr[i] - arr[j]) is equal to k

#include <iostream>
using namespace std;

int main() {
    int arr[100], n, k;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    int count = 0;

    // Check all pairs
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(arr[i] - arr[j]) == k) {
                count++;
                cout << "(" << arr[i] << ", " << arr[j] << ")\n";  
            }
        }
    }

    cout << "\nTotal pairs with difference " << k << " = " << count;

    return 0;
}

