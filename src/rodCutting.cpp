/* CLRS */
/*
Given a rod of length n inches, and a table of prices p_i for i=1,2,\dots,n, determine the maximum revenue r_n obtainable by cutting up the rod
and selling the pieces. If the price p_n is large enough, we may not need to cut the rod at all. The rod can be cut n-1 number of times.
*/

/* Time Complexity: O(n^2) */
/* Space Complexity: O(n) */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef vector<int> vi;

int maxRevenue(vi& p) {
    int q, n = p.size();

    map<int, int> dp;
    dp[0] = 0;

    for (int j = 1; j <= n; j++) {

        q = INT_MIN;
        for (int i = 1; i <= j; i++)
            q = max(q, p[i - 1] + dp[j - i]);  // i - 1 because of zero based indexing

        dp[j] = q;
    }

    return dp.at(n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vi p(n);
    for (auto& i : p)
        cin >> i;

    cout << maxRevenue(p) << '\n';

    return 0;
}
