/* Practice */
/*
Let n be the target sum. Let q be the number of nonnegative integers.
Say if the elements in the array can form the target sum.

You may use an element of the array as many times as needed.

If it is possible, return any one subset, else -1.
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

vi solve_recursive(int n, vi& a) {
    // Time Complexity: O(q^n)
    // Space Complexity: O(n)
    vi temp;

    if (n == 0)  // empty array
        return vi(0);
    if (n < 0)
        return vi {-1};

    trav(i, a) {
        temp = solve_recursive(n - i, a);
        if (temp.empty() || temp[0] != -1) {
            temp.push_back(i);
            return temp;
        }
    }

    return vi {-1};
}

vi solve_dp(int n, vi& a) {
    // Time Complexity: O(nq)
    // Space Complexity: O(n)

    // dp[i] stores the subset numbers that form the target sum i
    vi dp[n + *max_element(all(a)) + 1];
    trav(i, dp)
        i = vi {-1};

    dp[0] = vi(0);

    for (int i = 0; i <= n; i++) {
        if (dp[i].empty() || dp[i][0] != -1) {
            trav(j, a) {
                dp[i + j] = dp[i];
                dp[i + j].push_back(j);
            }
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

    vi res1 = solve_dp(n, a);
    vi res2 = solve_recursive(n, a);

    trav(i, res1)
        cout << i << " ";
    cout << nl;

    trav(j, res2)
        cout << j << " ";
    cout << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
