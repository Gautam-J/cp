/* CF - 800 */
/*
A. Square String?
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A string is called square if it is some string written twice in a row. For example, the strings "aa", "abcabc", "abab" and "baabaa" are square. But the strings "aaa", "abaaab" and "abcdabc" are not square.

For a given string s determine if it is square.

Input
The first line of input data contains an integer t (1≤t≤100) —the number of test cases.

This is followed by t lines, each containing a description of one test case. The given strings consist only of lowercase Latin letters and have lengths between 1 and 100 inclusive.

Output
For each test case, output on a separate line:

YES if the string in the corresponding test case is square,
NO otherwise.
You can output YES and NO in any case (for example, strings yEs, yes, Yes and YES will be recognized as a positive response).
*/

/* Time Complexity: O(n) where n is the length of the word. */
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
    int n = sz(s);
    return (s.substr(0, n / 2) == s.substr(n / 2));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    string s;
    cin >> t;

    while (t--) {
        cin >> s;
        cout << (solve(s) ? "YES" : "NO") << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
