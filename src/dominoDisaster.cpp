/* CF - 800 */
/*
A. Domino Disaster
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Alice has a grid with 2 rows and n columns. She fully covers the grid using n dominoes of size 1×2 — Alice may place them vertically or horizontally, and each cell should be covered by exactly one domino.

Now, she decided to show one row of the grid to Bob. Help Bob and figure out what the other row of the grid looks like!

Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤5000) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer n (1≤n≤100) — the width of the grid.

The second line of each test case contains a string s consisting of n characters, each of which is either L, R, U, or D, representing the left, right, top, or bottom half of a domino, respectively (see notes for better understanding). This string represents one of the rows of the grid.

Additional constraint on the input: each input corresponds to at least one valid tiling.

Output
For each test case, output one string — the other row of the grid, using the same format as the input string. If there are multiple answers, print any.

Example
inputCopy
4
1
U
2
LR
5
LRDLR
6
UUUUUU
outputCopy
D
LR
LRULR
DDDDDD

Notes:

U
D

L R
L R

L R U L R
L R D L R

U U U U U
D D D D D
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
typedef vector<int> vi;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';
const double PI = acos(-1);

string solve(string& s) {
    string res;

    int n = sz(s);
    FOR(i, n) {
        if (s[i] == 'L') {  // || s[i] == 'R'
            res.push_back('L');
            res.push_back('R');
            i++;
        } else if (s[i] == 'U') {
            res.push_back('D');
        } else {
            res.push_back('U');
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    string s;
    while (t--) {
        cin >> n;
        cin >> s;
        cout << solve(s) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
