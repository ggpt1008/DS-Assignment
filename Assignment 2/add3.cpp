// String Anagrams
// Given two strings str1 and str2, determine if they form an anagram pair.
// Note: Two strings are considered anagrams if one string can be rearranged to form the other
// string.
#include <iostream>
using namespace std;

int main() {
    string str1, str2;
    int freq1[26] = {0};
    int freq2[26] = {0};

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    // If lengths are different, not anagrams
    if (str1.length() != str2.length()) {
        cout << "Not Anagrams";
        return 0;
    }

    // Count letter frequency of str1
    for (int i = 0; i < str1.length(); i++) {
        freq1[str1[i] - 'a']++;
    }

    // Count letter frequency of str2
    for (int i = 0; i < str2.length(); i++) {
        freq2[str2[i] - 'a']++;
    }

    // Compare both frequency arrays
    for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i]) {
            cout << "Not Anagrams";
            return 0;
        }
    }

    cout << "Anagrams";

    return 0;
}
