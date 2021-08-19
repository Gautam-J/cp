/* LC - Medium */
/*
Given a string s, find the length of the longest substring without repeating characters.



Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0


Constraints:

0 <= s.length <= 5 * 10^4
s consists of English letters, digits, symbols and spaces.
*/

/* Time Complexity: O(n) where n is the length of the string */
/* Space Complexity: O(n) where n is the length of the string */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define trav(a, x) for (auto& a : x)

typedef long long ll;
typedef vector<int> vi;

const char nl = '\n';

int getLength(string& s) {
    int n = s.size();
    int len = 0, left = 0, right = 0;
    unordered_set<char> seen;

    while (right < n) {
        // if not seen
        if (seen.find(s[right]) == seen.end()) {
            seen.insert(s[right]);
            len = max(len, right - left + 1);
            right++;
        } else {
            seen.erase(s[left]);
            left++;
        }
    }
    return len;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    cout << getLength(s) << nl;

    return 0;
}
