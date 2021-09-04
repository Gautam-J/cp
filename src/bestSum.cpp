/* Practice */
/*
Let n be the target sum. Let q be the number of nonnegative integers.
Return the shortest combination of numbers that add up to target sum.

You may use an element of the array as many times as needed.
If there is a tie, any combination may be returned.
*/

/* A greedy algorithm of always taking the largest element does NOT work! */

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
    // Time Complexity: O(q^n + n) + n for copying array
    // Space Complexity: O(n)

    vi temp;
    vi combination;

    if (n == 0)
        return vi(0);
    if (n < 0)
        return vi {-1};

    vi best = {-1};
    trav(i, a) {
        temp = solve_recursive(n - i, a);
        if (temp.empty() || temp[0] != -1) {
            combination = temp;
            combination.push_back(i);
            if (best[0] == -1 || combination.size() < best.size())
                best = combination;
        }
    }

    return best;
}

vi solve_dp(int n, vi& a) {
    // Time Complexity: O(nq)
    // Space Complexity: O(n)

    // dp[i] stores the best combination that adds upto target sum i
    vi dp[n + *max_element(all(a)) + 1];
    trav(i, dp)
        i = vi {-1};

    dp[0] = vi(0);

    vi temp;
    for (int i = 0; i <= n; i++) {
        if (dp[i].empty() || dp[i][0] != -1) {
            trav(j, a) {
                temp = dp[i];
                temp.push_back(j);
                if ((!dp[i + j].empty() && dp[i + j][0] == -1) || temp.size() < dp[i + j].size())
                    dp[i + j] = temp;
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
