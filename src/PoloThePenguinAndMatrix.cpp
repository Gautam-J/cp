/* CF - 1400 */
/*
B. Polo the Penguin and Matrix
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Little penguin Polo has an n × m matrix, consisting of integers. Let's index the matrix rows from 1 to n from top to bottom and let's index the columns from 1 to m from left to right. Let's represent the matrix element on the intersection of row i and column j as aij.

In one move the penguin can add or subtract number d from some matrix element. Find the minimum number of moves needed to make all matrix elements equal. If the described plan is impossible to carry out, say so.

Input
The first line contains three integers n, m and d (1 ≤ n, m ≤ 100, 1 ≤ d ≤ 104) — the matrix sizes and the d parameter. Next n lines contain the matrix: the j-th integer in the i-th row is the matrix element aij (1 ≤ aij ≤ 104).

Output
In a single line print a single integer — the minimum number of moves the penguin needs to make all matrix elements equal. If that is impossible, print "-1" (without the quotes).

Examples
inputCopy
2 2 2
2 4
6 8
outputCopy
4
inputCopy
1 2 7
6 7
outputCopy
-1
*/

/* Time Complexity: O(k log k) where k = n * m. */
/* Space Complexity: O(n * m) */

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

int solve(vector<vi>& a, int d) {
    int n = sz(a);
    int m = sz(a[0]);

    vi b;
    FOR(i, n) {
        FOR(j, m)
            b.push_back(a[i][j]);
    }

    int mod = b[0] % d;
    trav(i, b) {
        if (i % d != mod)
            return -1;
    }

    sort(all(b));

    int median, s = sz(b);
    if (s % 2 == 0)
        median = b[(s / 2) - 1];
    else
        median = b[(s / 2)];

    int res = 0;
    trav(i, b) {
        res += (abs(median - i));
    }

    return res / d;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, d;
    cin >> n >> m >> d;

    vector<vi> a(n, vi(m, 0));
    FOR(i, n) {
        FOR(j, m)
            cin >> a[i][j];
    }

    cout << solve(a, d) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
