// Design the Logic to Find a Missing Number in a Sorted Array. Given an array of
// n-1 distinct integers in the range of 1 to n, find the missing number in it in a Sorted
// Array
// (a) Linear time
// (b) Using binary search

// a) 
// #include <iostream>
// using namespace std;

// int main() {
//     int arr[100], n;

//     cout << "Enter n (last number): ";
//     cin >> n;

//     cout << "Enter " << n-1 << " sorted elements:\n";
//     for (int i = 0; i < n-1; i++)
//         cin >> arr[i];

//     int expectedSum = n * (n + 1) / 2;
//     int actualSum = 0;

//     for (int i = 0; i < n-1; i++)
//         actualSum += arr[i];

//     int missing = expectedSum - actualSum;

//     cout << "Missing number (Linear Method): " << missing;

//     return 0;
// }

// B)

#include <iostream>
using namespace std;

int main() {
    int arr[100], n;

    cout << "Enter n (last number): ";
    cin >> n;

    cout << "Enter " << n-1 << " sorted elements:\n";
    for (int i = 0; i < n-1; i++)
        cin >> arr[i];

    int low = 0, high = n - 2;
    int missing = n;   // assume last number missing

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == mid + 1) {
            // left part correct → go right
            low = mid + 1;
        } 
        else {
            // mismatch found → possible missing
            missing = mid + 1;
            high = mid - 1;
        }
    }

    cout << "Missing number (Binary Search Method): " << missing;

    return 0;
}


