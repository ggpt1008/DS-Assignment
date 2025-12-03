#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;

    cout << "Enter size of arrays: ";
    cin >> n;

    vector<int> a(n), b(n);

    cout << "Enter elements of array a: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << "Enter elements of array b: ";
    for (int i = 0; i < n; i++) cin >> b[i];

   
    cout << "Enter k: ";
    cin >> k;

    vector<int> allSums;

    // Step 1: Generate all possible sums
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            allSums.push_back(a[i] + b[j]);
        }
    }

    // Step 2: Sort all sums in descending order
    sort(allSums.begin(), allSums.end(), greater<int>());

    // Step 3: Print top k sums
    cout << "Top " << k << " maximum sum combinations: ";
    for (int i = 0; i < k; i++) {
        cout << allSums[i] << " ";
    }

    return 0;
}
