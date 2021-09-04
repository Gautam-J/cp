/* Practice */
/*
You are a traveller on a 2D grid. You start from the top-left corner
and your goal is to travel to the bottom-right corner.

You may only move down or right. In how many ways can you travel to
your goal, on a grid of dimensions m * n?
*/

/* Time Complexity: O(nm) */
/* Space Complexity: O(nm) */

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

ll solve_recursive(int m, int n) {
    // Time Complexity: O(2^(n + m))
    // Space Complexity: O(n + m)

    if (m == 1 || n == 1)
        return 1;

    return solve_recursive(m - 1, n) + solve_recursive(m, n - 1);
}

ll solve_dp(int m, int n) {
    // Time Complexity: O(nm)
    // Space Complexity: O(nm)

    // dp[i][j] stores the number of ways you can reach the point i, j
    ll dp[m + 1][n + 1];

    // if either of the m or n is 1, dp[i][j] = 1
    for (int i = 1; i <= m; i++)
        dp[i][1] = 1;

    for (int j = 1; j <= n; j++)
        dp[1][j] = 1;

    for (int i = 2; i <= m; i++ ) {
        for (ll j = 2; j <= n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m][n];
}

int main() {
    /* ios_base::sync_with_stdio(0); */
    /* cin.tie(0); */

    int m, n;
    cin >> m >> n;

    cout << solve_dp(m, n) << nl;
    cout << solve_recursive(m, n) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
