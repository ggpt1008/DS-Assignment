#include <iostream>
#include <string>
using namespace std;

bool isSubstring(string X, string Y) {
    int n = Y.length();
    int m = X.length();

    if (m > n) return false;

    for (int i = 0; i <= n - m; i++) ///finds starting point
    {
        int k = 0;
        while (k < m && Y[i + k] == X[k]) {
            k++;
        }
        if (k == m) return true;
    }
    return false;
}

bool possible(string s) {
    int n = s.length();
    if (n < 3) return false;

    for (int i = 1; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {

            string A = s.substr(0, i);
            string B = s.substr(i, j - i);
            string C = s.substr(j);

            if (isSubstring(A, B) && isSubstring(A, C)) return true;
            if (isSubstring(B, A) && isSubstring(B, C)) return true;
            if (isSubstring(C, A) && isSubstring(C, B)) return true;
        }
    }
    return false;
}

int main() {
    string s;
    cin >> s;

    if (possible(s))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}