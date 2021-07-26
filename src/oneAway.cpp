/* Given 2 strings, check if they are one (or zero) edits aways. */
/* Types of edits include insert a char, delete a char, and replace a char */

/* We can implement a type of brute force algorithm */

/* Time Complexity: O(N) */
/* Space Complexity: O(N) */

/* where N is the length of the shorter string (for time complexity) */

#include <bits/stdc++.h>
using namespace std;

bool oneEditReplace(string s1, string s2) {
    bool foundDifference = false;

    for(int i = 0; i < s1.length(); i++) {
        if (s1.at(i) != s2.at(i)) {
            if (foundDifference)
                return false;

            foundDifference = true;
        }
    }
    return true;
}

/* check if you can insert a char into s1 to make s2 */
bool oneEditInsert(string s1, string s2) {
    int index1 = 0, index2 = 0;

    while (index2 < s2.length() && index1 < s1.length()) {
        if (s1.at(index1) != s2.at(index2)) {
            if (index1 != index2)
                return false;
            index2++;
        } else {
            index1++;
            index2++;
        }
    }
    return true;
}

/* checking the lengths of the strings will tell us what edit can be made */
bool oneEditAway(string first, string second) {
    if (first.length() == second.length())
        return oneEditReplace(first, second);
    if (first.length() + 1 == second.length())
        return oneEditInsert(first, second);
    if (first.length() - 1 == second.length())
        return oneEditInsert(second, first);

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str1, str2;

    getline(cin, str1);
    getline(cin, str2);
    cout << oneEditAway(str1, str2) << "\n";

    return 0;
}
