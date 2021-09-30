/* CF - 800 */
/*
A. Casimir's String Solitaire
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Casimir has a string s which consists of capital Latin letters 'A', 'B', and 'C' only. Each turn he can choose to do one of the two following actions:

he can either erase exactly one letter 'A' and exactly one letter 'B' from arbitrary places of the string (these letters don't have to be adjacent);
or he can erase exactly one letter 'B' and exactly one letter 'C' from arbitrary places in the string (these letters don't have to be adjacent).
Therefore, each turn the length of the string is decreased exactly by 2. All turns are independent so for each turn, Casimir can choose any of two possible actions.

For example, with s = "ABCABC" he can obtain a string s = "ACBC" in one turn (by erasing the first occurrence of 'B' and the second occurrence of 'A'). There are also many other options for a turn aside from this particular example.

For a given string s determine whether there is a sequence of actions leading to an empty string. In other words, Casimir's goal is to erase all letters from the string. Is there a way to do this?

Input
The first line contains an integer t (1≤t≤1000) — the number of test cases.

Each test case is described by one string s, for which you need to determine if it can be fully erased by some sequence of turns. The string s consists of capital letters 'A', 'B', 'C' and has a length from 1 to 50 letters, inclusive.

Output
Print t lines, each line containing the answer to the corresponding test case. The answer to a test case should be YES if there is a way to fully erase the corresponding string and NO otherwise.

You may print every letter in any case you want (so, for example, the strings yEs, yes, Yes, and YES will all be recognized as positive answers).

Example
inputCopy
6
ABACAB
ABBA
AC
ABC
CABCBB
BCBCBCBCBCBCBCBC
outputCopy
NO
YES
NO
NO
YES
YES
*/

/* Time Complexity: O(n) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define trav(i, a) for (auto& i : a)

#ifdef _GLIBCXX_DEBUG
#define debug(x) cerr << "\e[91m"<<"[DEBUG] "<<__func__<<":"<<__LINE__<<" [" << #x << "] = [" << x << "]" << "\e[39m" << '\n';
#else
#define debug(x)
#endif

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';
const double PI = acos(-1);

bool solve(string& s) {
    unordered_map<char, int> cnt;

    trav(c, s) {
        if (cnt.find(c) == cnt.end())
            cnt[c] = 1;
        else
            cnt[c]++;
    }

    return (cnt['B'] == (cnt['A'] + cnt['C']));

    // simple method
    // check if count of B is equal to half the length of the string
    return (count(all(s), 'B') == (int)(s.size() / 2));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    string s;
    while (t--) {
        cin >> s;
        cout << (solve(s) ? "YES" : "NO") << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
