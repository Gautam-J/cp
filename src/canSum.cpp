/* Practice */
/*
Let n be the target sum. Let q be the number of nonnegative integers.
Say if the elements in the array can form the target sum.

You may use an element of the array as many times as needed.
*/

/* Time Complexity: O(nq) */
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

bool solve_recursive(int n, vi& a) {
    // Time Complexity: O(q^n)
    // Space Complexity: O(n)

    if (n == 0)
        return true;
    if (n < 0)  // numbers are nonnegative
        return false;

    trav(i, a) {
        if (solve_recursive(n - i, a))
            return true;
    }

    return false;
}

bool solve_dp(int n, vi& a) {
    // Time Complexity: O(nq)
    // Space Complexity: O(n)

    // dp[i] stores whether i can be formed as a sum of given elements
    bool dp[n + *max_element(all(a)) + 1];
    trav(i, dp)
        i = false;

    dp[0] = true;
    for (int i = 0; i <= n; i++) {
        if (dp[i]) {
            trav(j, a)
                dp[i + j] = true;
        }
    }

    return dp[n];
}

int main() {
    /* ios_base::sync_with_stdio(0); */
    /* cin.tie(0); */

    int n, q;
    cin >> n >> q;

    vi a(q);
    trav(i, a)
        cin >> i;

    cout << (solve_dp(n, a) ? "YES" : "NO") << nl;
    cout << (solve_recursive(n, a) ? "YES" : "NO") << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
