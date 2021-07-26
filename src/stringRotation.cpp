/* check if one word is a rotation of another word */
/* Use one call to the isSubstring() function */

/* we check if there is a way to split s1 into x and y such that */
/* xy = s1 and yx = s2, i.e., s2 will always be a substring of s1s1 */

#include <bits/stdc++.h>
using namespace std;

bool isRotation(string s1, string s2) {
    int len = s1.length();

    /* check that s1 and s2 are equal length and not empty */
    if (len == s2.length() && len > 0) {
        /* concat s1 and s2 within new buffer */
        string s1s1 = s1 + s1;
        return s1s1.find(s2) != std::string::npos;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;

    getline(cin, s1);
    getline(cin, s2);

    cout << isRotation(s1, s2) << "\n";

    return 0;
}
