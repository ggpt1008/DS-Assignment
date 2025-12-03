#include <bits/stdc++.h>
using namespace std;

int maxIceCream(vector<int>& costs, int coins) {
    // Step 1: Sort the costs in increasing order
    sort(costs.begin(), costs.end());

    int count = 0;

    // Step 2: Buy the cheapest bars first
    for (int price : costs) {
        if (coins >= price) {
            coins -= price;
            count++;
        } else {
            break;  // can't buy more
        }
    }

    return count;
}

int main() {
    vector<int> costs = {1, 3, 2, 4, 1};
    int coins = 7;

    cout << "Maximum ice creams: " << maxIceCream(costs, coins);
    return 0;
}
