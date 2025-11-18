// Implement the binary search algorithm regarded as a fast search algorithm
// with run-time complexity of Ο(log n) in comparison to the Linear Search.

#include <iostream>
using namespace std;

int main() {
    int arr[100], n, key;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements in sorted order:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    int low = 0, high = n - 1;
    int mid;
    bool found = false;

    // Binary Search
    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key) {
            cout << "Element found at index " << mid << " (Binary Search)\n";
            found = true;
            break;
        }

        else if (key < arr[mid]) {
            high = mid - 1;   // search left half
        } else {
            low = mid + 1;    // search right half
        }
    }

    if (!found) {
        cout << "Element not found in the array.\n";
    }

    return 0;
}
