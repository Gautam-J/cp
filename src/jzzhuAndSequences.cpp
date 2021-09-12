/* CF - 1300 */
/*
B. Jzzhu and Sequences
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Jzzhu has invented a kind of sequences, they meet the following property:


You are given x and y, please calculate fn modulo 1000000007 (109 + 7).

Input
The first line contains two integers x and y (|x|, |y| ≤ 109). The second line contains a single integer n (1 ≤ n ≤ 2·109).

Output
Output a single integer representing fn modulo 1000000007 (109 + 7).

Examples
inputCopy
2 3
3
outputCopy
1
inputCopy
0 -1
2
outputCopy
1000000006
Note
In the first sample, f2 = f1 + f3, 3 = 2 + f3, f3 = 1.

In the second sample, f2 =  - 1;  - 1 modulo (109 + 7) equals (109 + 6).
*/

/* Time Complexity: O(1) */
/* Space Complexity: O(1) */

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
const ll MOD = 1000000007;

ll solve(ll x, ll y, ll n) {
    ll dp[] = {x, y, y - x, -x, -y, x - y};

    // a % b == ((a % b) + b) % b
    // (a % b) - 1 == (a - 1) % b

    ll res = dp[(n - 1) % 6];
    return (res % MOD + MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll x, y, n;
    cin >> x >> y >> n;

    cout << solve(x, y, n) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
