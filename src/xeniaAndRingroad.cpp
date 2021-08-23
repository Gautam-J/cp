/* CF - 1000 */
/*
B. Xenia and Ringroad
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Xenia lives in a city that has n houses built along the main ringroad. The ringroad houses are numbered 1 through n in the clockwise order. The ringroad traffic is one way and also is clockwise.

Xenia has recently moved into the ringroad house number 1. As a result, she's got m things to do. In order to complete the i-th task, she needs to be in the house number ai and complete all tasks with numbers less than i. Initially, Xenia is in the house number 1, find the minimum time she needs to complete all her tasks if moving from a house to a neighboring one along the ringroad takes one unit of time.

Input
The first line contains two integers n and m (2 ≤ n ≤ 105, 1 ≤ m ≤ 105). The second line contains m integers a1, a2, ..., am (1 ≤ ai ≤ n). Note that Xenia can have multiple consecutive tasks in one house.

Output
Print a single integer — the time Xenia needs to complete all tasks.

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

Examples
inputCopy
4 3
3 2 3
outputCopy
6
inputCopy
4 3
2 3 3
outputCopy
2
Note
In the first test example the sequence of Xenia's moves along the ringroad looks as follows: 1 → 2 → 3 → 4 → 1 → 2 → 3. This is optimal sequence. So, she needs 6 time units.
*/

/* Time Complexity: O(n) */
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

ll minTime2(vi& a, int n) {
    int m = a.size();
    ll res = a[0] - 1;

    for (int i = 0; i < m - 1; i++) {
        if (a[i] < a[i + 1])
            res += (a[i + 1] - a[i]);
        if (a[i] > a[i + 1])
            res += ((n - a[i]) + a[i + 1]);
    }

    return res;
}

ll minTime(vi& a, int n) {
    /* The implementation method that gets accepted */

    int m = a.size();
    ll total = 0;

    for (int i = 0; i < m - 1; i++) {
        if (a[i + 1] < a[i]) {
            total++;
        }
    }

    return (ll)(total * n) + (ll)a[m - 1] - (ll)1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    vi a(m);
    trav(i, a)
        cin >> i;

    cout << minTime2(a, n) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
