/* CTCI */
/* Given two strings, check if one is a permutation of the other. */

/* First method is to sort the strings and check for equality. */

/* Time Complexity: O(a log a + b log b) */
/* Space Complexity: O(N) */

/* Second method checks for identical character counts. */

/* Time Complexity: O(a + b) */
/* Space Complexity: O(1) */

/* where a is the number of chars in str1, b is the number of chars in str2 */

#include <bits/stdc++.h>
using namespace std;

bool checkPermutation(string str1, string str2) {
    // if the strings are not of equal length, they are not permutations
    if (str1.length() != str2.length())
        return false;

    // sort the strings O(n log n)
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    // return bool value is they are equal or not
    return str1 == str2;
}

bool checkPermutation2(string str1, string str2) {
    // if the strings are not of equal length, they are not permutations
    if (str1.length() != str2.length())
        return false;

    // initialize array with zeros, assuming 128 ASCII chars
    int letters[128] = {0};

    // count number of each characters in str1
    for (char c : str1) {
        letters[c]++;
    }

    // check for char count
    for (int i = 0; i < str2.length(); i++) {
        int c = (int) str2.at(i);
        letters[c]--;

        if (letters[c] < 0)
            return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    cout << checkPermutation(str1, str2) << "\n";
    cout << checkPermutation2(str1, str2) << "\n";

    return 0;
}
