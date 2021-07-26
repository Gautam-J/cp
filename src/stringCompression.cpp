/* basic string compression using the counts of repeated characters. */
/* If the compressed string is not smaller, return original string */

/* Time Complexity: O(N) */
/* Space Complecity: O(N) */

/* where N is the length of the original string */

#include <bits/stdc++.h>
using namespace std;

int countCompression(string str) {
    int compressedLength = 0;
    int countConsecutive = 0;

    for (int i = 0; i < str.length(); i++) {
        countConsecutive++;

        /* if next char is different, increase length */
        if (i + 1 >= str.length() || str.at(i) != str.at(i + 1)) {
            compressedLength += 1 + to_string(countConsecutive).length();
            countConsecutive = 0;
        }
    }
    return compressedLength;
}

string compress(string str) {
    /* check final length and return input string if it would be longer */
    int finalLength = countCompression(str);
    if (finalLength >= str.length())
        return str;

    /* initial capacity */
    vector<char> compressed(finalLength);
    int countConsecutive = 0;

    for (int i = 0; i < str.length(); i++) {
        countConsecutive++;

        /* if next char is different, append this char to result */
        if (i + 1 >= str.length() || str.at(i) != str.at(i + 1)) {
            compressed.push_back(str.at(i));
            compressed.push_back((char)countConsecutive);
            countConsecutive = 0;
        }
    }

    /* convert vector<char> to string */
    string s(compressed.begin(), compressed.end());
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;

    getline(cin, str);
    str = compress(str);
    cout << str << "\n";

    return 0;
}
