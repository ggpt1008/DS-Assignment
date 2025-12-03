#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool canBeSorted(vector<int>& A) {
    stack<int> S;
    int expected = 1;

    for (int i = 0; i < A.size(); i++) {
        S.push(A[i]);

        while (!S.empty() && S.top() == expected) {
            S.pop();
            expected++;
        }
    }

    return S.empty();
}

int main() {
    vector<int> A = {3, 1, 2};

    if (canBeSorted(A))
        cout << "Yes, array B can be sorted in ascending order.\n";
    else
        cout << "No, array B cannot be sorted in ascending order.\n";

    return 0;
}