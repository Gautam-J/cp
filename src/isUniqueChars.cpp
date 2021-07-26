/* Algorithm to check if a string has all unique characters. */

/* Time Complexity: O(N) */
/* Space Complexity: O(1) */

/* Time Complexity can be said as constant too, as it will never iterate */
/* more than 128 times. Space Complexity is constant as it takes 128 bits.*/

/* If additional data structures are not to be used, we can manually compare */
/* each char to every other char, resulting in a O(n^2) time and O(1) space. */

/* Another method would be to sort the string, and check for neighboring chars. */
/* This typically results in O(n log n) time, but can take up more space. */

#include <bits/stdc++.h>
using namespace std;

bool isUniqueChars(string str) {
    // string length exceeds the number of unique characters (128 in ASCII)
    // then it is obvious that the string contains duplicate characters
    if (str.length() > 128)
        return false;

    bitset<128> char_set;

    for (int i = 0; i < str.length(); i++) {
        // take the ASCII value of the char
        int val = str[i];

        // have the ASCII value as unique key/index
        if (char_set[val])
            return false;

        char_set[val] = true;
    }

    return true;
}

bool isUniqueChars2(string str) {
    // assuming str contains only lowercase letters from a to z
    // we can use the checker int variable as a bit vector
    int checker = 0;
    for (int i = 0; i < str.length(); i++) {
        // str.at() does an additional out of bounds checking
        int val = str.at(i) - 'a';
        if ((checker & (1 << val)) > 0)
            return false;
        checker |= (1 << val);
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;

    getline(cin, str);
    cout << isUniqueChars(str) << "\n";
    cout << isUniqueChars2(str) << "\n";

    return 0;
}
