/* CF - 800 */
/*
A. The Miracle and the Sleeper
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given two integers l and r, l≤r. Find the largest possible value of amodb over all pairs (a,b) of integers for which r≥a≥b≥l.

As a reminder, amodb is a remainder we get when dividing a by b. For example, 26mod8=2.

Input
Each test contains multiple test cases.

The first line contains one positive integer t (1≤t≤104), denoting the number of test cases. Description of the test cases follows.

The only line of each test case contains two integers l, r (1≤l≤r≤109).

Output
For every test case, output the largest possible value of amodb over all pairs (a,b) of integers for which r≥a≥b≥l.

Example
inputCopy
4
1 1
999999999 1000000000
8 26
1 999999999
outputCopy
0
1
12
499999999
Note
In the first test case, the only allowed pair is (a,b)=(1,1), for which amodb=1mod1=0.

In the second test case, the optimal choice is pair (a,b)=(1000000000,999999999), for which amodb=1.
*/

/* Time Complexity: O(1) */
/* Space Complexity: O(1) */

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

int solve(int l, int r) {
    if (r < 2 * l)
        return r - l;

    return (r - 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, l, r;
    cin >> t;

    while (t--) {
        cin >> l >> r;
        cout << solve(l, r) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
