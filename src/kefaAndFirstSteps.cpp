/* CF - 900 */
/*
A. Kefa and First Steps
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Kefa decided to make some money doing business on the Internet for exactly n days. He knows that on the i-th day (1 ≤ i ≤ n) he makes ai money. Kefa loves progress, that's why he wants to know the length of the maximum non-decreasing subsegment in sequence ai. Let us remind you that the subsegment of the sequence is its continuous fragment. A subsegment of numbers is called non-decreasing if all numbers in it follow in the non-decreasing order.

Help Kefa cope with this task!

Input
The first line contains integer n (1 ≤ n ≤ 105).

The second line contains n integers a1,  a2,  ...,  an (1 ≤ ai ≤ 109).

Output
Print a single integer — the length of the maximum non-decreasing subsegment of sequence a.

Examples
inputCopy
6
2 2 1 3 4 1
outputCopy
3
inputCopy
3
2 2 9
outputCopy
3
Note
In the first test the maximum non-decreasing subsegment is the numbers from the third to the fifth one.

In the second test the maximum non-decreasing subsegment is the numbers from the first to the third one.
*/

/* Time Complexity: O(n) */
/* Space Complexity: O(n) if using proper DP, else O(1) */

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

int solve(vi& a) {
    // proper bottom up DP approach

    int n = a.size();
    int dp[n];

    dp[0] = 1;
    int best = dp[0];

    for (int i = 1; i < n; i++) {
        if (a[i - 1] <= a[i]) {
            dp[i] = dp[i - 1] + 1;
        } else {
            dp[i] = 1;
        }

        best = max(best, dp[i]);
    }

    return best;
}

int solve2(vi& a) {
    // similar to kadane's algorithm
    // does NOT use extra space

    int n = a.size();
    int res;
    int best = 1;

    for (int i = 1; i < n; i++) {
        if (a[i - 1] <= a[i]) {
            best++;
        } else {
            res = max(res, best);
            best = 1;
        }

        res = max(res, best);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vi a(n);
    trav(i, a)
        cin >> i;

    cout << solve(a) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
