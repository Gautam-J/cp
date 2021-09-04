/* DP - Practice */
/*
Given a number n, print the nth fibonacci number.

The series is as follows: 0, 1, 1, 2, 3, 5, 8, 13, ...
with f_0 = 0 and f_1 = 1.
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

int solve_recursive(int n) {
    // Time Complexity: O(2^n)
    // Space Complexity: O(n) for call stack space, else O(1)

    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    /* if (n < 2) */
    /*     return n; */

    return (solve_recursive(n - 1) + solve_recursive(n - 2));
}

int solve_dp(int n) {
    // Time Complexity: O(n)
    // Space Complexity: O(n)

    // dp[i] stores the ith fibonacci number
    int dp[n + 1];

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

int main() {
    /* ios_base::sync_with_stdio(0); */
    /* cin.tie(0); */

    int n;
    cin >> n;

    cout << solve_dp(n) << nl;
    cout << solve_recursive(n) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
