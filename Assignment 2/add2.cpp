// String Split Challenge
// You are given a string consisting of lowercase English alphabets. Your task is to determine
// if it's possible to split this string into three non-empty parts (substrings) where one of
// these parts is a substring of both remaining parts

#include <iostream>
#include <string>
using namespace std;

// Function to check if x is a substring of y
bool isSub(string x, string y) {
    return y.find(x) != string::npos;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    int n = s.length();

    // Split string into A | B | C
    for (int i = 0; i < n - 2; i++) {
        string A = s.substr(0, i + 1);
        for (int j = i + 1; j < n - 1; j++) {
            string B = s.substr(i + 1, j - i);
            string C = s.substr(j + 1);

            // Check all 3 possible conditions
            if ((isSub(A, B) && isSub(A, C)) ||
                (isSub(B, A) && isSub(B, C)) ||
                (isSub(C, A) && isSub(C, B))) {
                    
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";
    return 0;
}
