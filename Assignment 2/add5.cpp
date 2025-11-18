// Given a fixed-length integer array arr, duplicate each occurrence of two (2), shifting the
// remaining elements to the right.
// Note that elements beyond the length of the original array are not written. Do the above
// modifications to the input array in place and do not return anything.

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[100]; // fixed large enough

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 1: Count occurrences of 2
    int count2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 2)
            count2++;
    }

    int i = n - 1;           // original end
    int j = n - 1 + count2;  // new end (virtual)

    // Step 2: Traverse from right to left
    while (i >= 0 && j >= 0) {
        if (arr[i] != 2) {
            if (j < n)  // only write inside array boundary
                arr[j] = arr[i];
            j--;
        } else {
            // Write 2 twice
            if (j < n)
                arr[j] = 2;
            j--;

            if (j < n)
                arr[j] = 2;
            j--;
        }
        i--;
    }

    cout << "Modified array: ";
    for (int k = 0; k < n; k++) {
        cout << arr[k] << " ";
    }

    return 0;
}
