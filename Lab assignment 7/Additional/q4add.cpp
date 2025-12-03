#include <bits/stdc++.h>
using namespace std;

vector<int> sortEvenOddBruteforce(vector<int>& arr) {
    int n = arr.size();

    vector<int> evenPlaced;  
    vector<int> oddPlaced;   

    // Step 1: Separate even-index and odd-index elements
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            evenPlaced.push_back(arr[i]);
        else
            oddPlaced.push_back(arr[i]);
    }

    // Step 2: Sort even-index elements in increasing order
    sort(evenPlaced.begin(), evenPlaced.end());

    // Step 3: Sort odd-index elements in decreasing order
    sort(oddPlaced.begin(), oddPlaced.end(), greater<int>());

    // Step 4: Final result = all evens first + all odds after
    vector<int> result;
    for (int x : evenPlaced) result.push_back(x);
    for (int x : oddPlaced) result.push_back(x);

    return result;
}

int main() {
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7};

    vector<int> ans = sortEvenOddBruteforce(arr);

    cout << "Result: ";
    for (int x : ans) cout << x << " ";
}
