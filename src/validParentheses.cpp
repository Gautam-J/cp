/* LC - Easy */
/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.


Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true


Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

/* Time Complexity: O(n) */
/* Space Complexity: O(n) */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define trav(i, a) for (auto& i : a)
#define debug(x) cout << "[DEBUG] " << #x << "=" << x << '\n'

typedef long long ll;
typedef vector<int> vi;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';
const double PI = acos(-1);

bool isValid(string& s) {
    stack<char> myStack;

    bool balanced = true;
    int n = s.size();
    int i = 0;
    char top;

    while (i < n && balanced) {

        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            myStack.push(s[i]);
        } else {

            if (myStack.empty())
                balanced = false;
            else {
                top = myStack.top();
                myStack.pop();

                if (!((top == '(' && s[i] == ')') ||
                    (top == '[' && s[i] == ']') ||
                    (top == '{' && s[i] == '}')))
                    balanced = false;
            }
        }

        i++;
    }

    return (balanced && myStack.empty());
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    cout << (isValid(s) ? "YES" : "NO") << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
