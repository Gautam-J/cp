/* CF - 1000 */
/*
A. Donut Shops
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
There are two rival donut shops.

The first shop sells donuts at retail: each donut costs ??
a
 dollars.

The second shop sells donuts only in bulk: box of ??
b
 donuts costs ??
c
 dollars. So if you want to buy ??
x
 donuts from this shop, then you have to buy the smallest number of boxes such that the total number of donuts in them is greater or equal to ??
x
.

You want to determine two positive integer values:

how many donuts can you buy so that they are strictly cheaper in the first shop than in the second shop?
how many donuts can you buy so that they are strictly cheaper in the second shop than in the first shop?
If any of these values doesn't exist then that value should be equal to ?1
?
1
. If there are multiple possible answers, then print any of them.

The printed values should be less or equal to 109
10
9
. It can be shown that under the given constraints such values always exist if any values exist at all.

Input
The first line contains a single integer ??
t
 (1²??²1000
1
²
t
²
1000
) Ñ the number of testcases.

Each of the next ??
t
 lines contains three integers ??
a
, ??
b
 and ??
c
 (1²??²109
1
²
a
²
10
9
, 2²??²109
2
²
b
²
10
9
, 1²??²109
1
²
c
²
10
9
).

Output
For each testcase print two positive integers. For both shops print such ??
x
 that buying ??
x
 donuts in this shop is strictly cheaper than buying ??
x
 donuts in the other shop. ??
x
 should be greater than 0
0
 and less or equal to 109
10
9
.

If there is no such ??
x
, then print ?1
?
1
. If there are multiple answers, then print any of them.

Example
inputCopy
4
5 10 4
4 5 20
2 2 3
1000000000 1000000000 1000000000
outputCopy
-1 20
8 -1
1 2
-1 1000000000
Note
In the first testcase buying any number of donuts will be cheaper in the second shop. For example, for 3
3
 or 5
5
 donuts you'll have to buy a box of 10
10
 donuts for 4
4
 dollars. 3
3
 or 5
5
 donuts in the first shop would cost you 15
15
 or 25
25
 dollars, respectively, however. For 20
20
 donuts you'll have to buy two boxes for 8
8
 dollars total. Note that 3
3
 and 5
5
 are also valid answers for the second shop, along with many other answers.

In the second testcase buying any number of donuts will be either cheaper in the first shop or the same price. 8
8
 donuts cost 32
32
 dollars in the first shop and 40
40
 dollars in the second shop (because you have to buy two boxes). 10
10
 donuts will cost 40
40
 dollars in both shops, so 10
10
 is not a valid answer for any of the shops.

In the third testcase 1
1
 donut costs 2
2
 and 3
3
 dollars, respectively. 2
2
 donuts cost 4
4
 and 3
3
 dollars. Thus, 1
1
 is a valid answer for the first shop and 2
2
 is a valid answer for the second shop.

In the fourth testcase 109
10
9
 donuts cost 1018
10
18
 dollars in the first shop and 109
10
9
 dollars in the second shop.
*/

/* Time Complexity: O(1) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

template<typename T> T gcd(T a, T b) { return ( b ? __gcd(a, b) : a); }
template<typename T> T lcm(T a, T b) { return (a * (b / gcd(a, b))); }

#define forn(i, n) for (int i = 0; i < n; i++)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; i++)
#define trav(i, a) for (auto& i : a)
#define all(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
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
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< pi > vpi;

// mt19937_64 for 64 bit random numbers
mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());

const char nl = '\n';
const ld PI = acos(-1.0);

void solve(ll a, ll b, ll c) {
    cout << ((a < c) ? 1 : -1) << " ";
    cout << ((c < (a * b)) ? b : -1) << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t, a, b, c;
    cin >> t;

    while (t--) {
        cin >> a >> b >> c;
        solve(a, b, c);
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
