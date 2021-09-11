/* CF - 1200 */
/*
B. Kuriyama Mirai's Stones
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Kuriyama Mirai has killed many monsters and got many (namely n) stones. She numbers the stones from 1 to n. The cost of the i-th stone is vi. Kuriyama Mirai wants to know something about these stones so she will ask you two kinds of questions:

She will tell you two numbers, l and r (1 ≤ l ≤ r ≤ n), and you should tell her .
Let ui be the cost of the i-th cheapest stone (the cost that will be on the i-th place if we arrange all the stone costs in non-decreasing order). This time she will tell you two numbers, l and r (1 ≤ l ≤ r ≤ n), and you should tell her .
For every question you should give the correct answer, or Kuriyama Mirai will say "fuyukai desu" and then become unhappy.

Input
The first line contains an integer n (1 ≤ n ≤ 105). The second line contains n integers: v1, v2, ..., vn (1 ≤ vi ≤ 109) — costs of the stones.

The third line contains an integer m (1 ≤ m ≤ 105) — the number of Kuriyama Mirai's questions. Then follow m lines, each line contains three integers type, l and r (1 ≤ l ≤ r ≤ n; 1 ≤ type ≤ 2), describing a question. If type equal to 1, then you should output the answer for the first question, else you should output the answer for the second one.

Output
Print m lines. Each line must contain an integer — the answer to Kuriyama Mirai's question. Print the answers to the questions in the order of input.

Examples
inputCopy
6
6 4 2 7 2 7
3
2 3 6
1 3 4
1 1 6
outputCopy
24
9
28
inputCopy
4
5 5 2 3
10
1 2 4
2 1 4
1 1 1
2 1 4
2 1 2
1 1 1
1 3 3
1 1 3
1 4 4
1 2 2
outputCopy
10
15
5
15
5
5
2
12
3
5
Note
Please note that the answers to the questions may overflow 32-bit integer type.
*/

/* Time Complexity: O(n lg n + m) */
/* Space Complexity: O(n) */

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

ll solve(ll dp[], ll dpSorted[], int type, int l, int r) {
    if (type == 1)
        return dp[r] - dp[l - 1];

    return dpSorted[r] - dpSorted[l - 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vi a(n);
    trav(i, a)
        cin >> i;

    vi sa;
    trav(i, a)
        sa.push_back(i);

    sort(all(sa));

    ll dp[n + 1];
    dp[0] = 0;
    dp[1] = a[0];
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + a[i - 1];
    }

    ll dpSorted[n + 1];
    dpSorted[0] = 0;
    dpSorted[1] = sa[0];
    for (int i = 2; i <= n; i++) {
        dpSorted[i] = dpSorted[i - 1] + sa[i - 1];
    }

    int t, type, l, r;
    cin >> t;
    while (t--) {
        cin >> type >> l >> r;
        cout << solve(dp, dpSorted, type, l, r) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
