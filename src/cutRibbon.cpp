/* CF - 1300 */
/*
A. Cut Ribbon
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarpus has a ribbon, its length is n. He wants to cut the ribbon in a way that fulfils the following two conditions:

After the cutting each ribbon piece should have length a, b or c.
After the cutting the number of ribbon pieces should be maximum.
Help Polycarpus and find the number of ribbon pieces after the required cutting.

Input
The first line contains four space-separated integers n, a, b and c (1 ≤ n, a, b, c ≤ 4000) — the length of the original ribbon and the acceptable lengths of the ribbon pieces after the cutting, correspondingly. The numbers a, b and c can coincide.

Output
Print a single number — the maximum possible number of ribbon pieces. It is guaranteed that at least one correct ribbon cutting exists.

Examples
inputCopy
5 5 3 2
outputCopy
2
inputCopy
7 5 5 2
outputCopy
2
Note
In the first example Polycarpus can cut the ribbon in such way: the first piece has length 2, the second piece has length 3.

In the second example Polycarpus can cut the ribbon in such way: the first piece has length 5, the second piece has length 2.

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

int maxCuts(int n, int a, int b, int c) {
    int x, y, z;
    int dp[n + 1];

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        x = y = z = -1;

        if (a <= i)
            x = dp[i - a];
        if (b <= i)
            y = dp[i - b];
        if (c <= i)
            z = dp[i - c];

        if (x == -1 && y == -1 && z == -1)
            dp[i] = -1;
        else
            dp[i] = max({x, y, z}) + 1;
    }

    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    cout << maxCuts(n, a, b, c) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
