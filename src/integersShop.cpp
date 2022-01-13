/* CF - 1500 */
/*
B. Integers Shop
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The integers shop sells n segments. The i-th of them contains all integers from li to ri and costs ci coins.

Tomorrow Vasya will go to this shop and will buy some segments there. He will get all integers that appear in at least one of bought segments. The total cost of the purchase is the sum of costs of all segments in it.

After shopping, Vasya will get some more integers as a gift. He will get integer x as a gift if and only if all of the following conditions are satisfied:

Vasya hasn't bought x.
Vasya has bought integer l that is less than x.
Vasya has bought integer r that is greater than x.
Vasya can get integer x as a gift only once so he won't have the same integers after receiving a gift.

For example, if Vasya buys segment [2,4] for 20 coins and segment [7,8] for 22 coins, he spends 42 coins and receives integers 2,3,4,7,8 from these segments. He also gets integers 5 and 6 as a gift.

Due to the technical issues only the first s segments (that is, segments [l1,r1],[l2,r2],…,[ls,rs]) will be available tomorrow in the shop.

Vasya wants to get (to buy or to get as a gift) as many integers as possible. If he can do this in differents ways, he selects the cheapest of them.

For each s from 1 to n, find how many coins will Vasya spend if only the first s segments will be available.

Input
The first line contains a single integer t (1≤t≤1000) — the number of test cases.

The first line of each test case contains the single integer n (1≤n≤105) — the number of segments in the shop.

Each of next n lines contains three integers li, ri, ci (1≤li≤ri≤109,1≤ci≤109) — the ends of the i-th segments and its cost.

It is guaranteed that the total sum of n over all test cases doesn't exceed 2⋅105.

Output
For each test case output n integers: the s-th (1≤s≤n) of them should be the number of coins Vasia will spend in the shop if only the first s segments will be available.

Example
inputCopy
3
2
2 4 20
7 8 22
2
5 11 42
5 11 42
6
1 4 4
5 8 9
7 8 7
2 10 252
1 11 271
1 10 1
outputCopy
20
42
42
42
4
13
11
256
271
271
Note
In the first test case if s=1 then Vasya can buy only the segment [2,4] for 20 coins and get 3 integers.

The way to get 7 integers for 42 coins in case s=2 is described in the statement.

In the second test case note, that there can be the same segments in the shop.
*/

/* Time Complexity: O(n) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

void dbg_out() { cerr << endl; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

template<typename T> T gcd(T a, T b) { return ( b ? __gcd(a, b) : a); }
template<typename T> T lcm(T a, T b) { return (a * (b / gcd(a, b))); }

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define trav(i, a) for (auto& i : a)
#define pb push_back
#define SHUF(v) shuffle(all(v), mt_rand)
#define umap unordered_map
#define uset unordered_set
#define imax INT_MAX
#define imin INT_MIN

#ifdef _GLIBCXX_DEBUG
#define debug(...) cerr << "[DEBUG]: [" << #__VA_ARGS__ << "]:", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< pi > vpi;

// mt19937_64 for 64 bit random numbers
mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());

const char nl = '\n';
const double PI = acos(-1);

void solve(vvi& a) {
    int l, r, c, ans;

    pi low = { imax, imax };
    pi high = { imin, imin };
    pi single = { imin, imin };

    trav(i, a) {
        l = i[0];
        r = i[1];
        c = i[2];

        low = min(low, { l, c });
        high = max(high, { r, -c });
        single = max(single, { r - l, -c });

        ans = low.second - high.second;
        if (single.first == high.first - low.first)
            ans = min(ans, -single.second);

        cout << ans << nl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vvi a(n, vi(3, 0));

        trav(i, a) {
            trav(j, i) {
                cin >> j;
            }
        }
        solve(a);
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
