/* CF - 800 */
/*
A. LCM Problem
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Let ??????(??,??)
L
C
M
(
x
,
y
)
 be the minimum positive integer that is divisible by both ??
x
 and ??
y
. For example, ??????(13,37)=481
L
C
M
(
13
,
37
)
=
481
, ??????(9,6)=18
L
C
M
(
9
,
6
)
=
18
.

You are given two integers ??
l
 and ??
r
. Find two integers ??
x
 and ??
y
 such that ??²??<??²??
l
²
x
<
y
²
r
 and ??²??????(??,??)²??
l
²
L
C
M
(
x
,
y
)
²
r
.

Input
The first line contains one integer ??
t
 (1²??²10000
1
²
t
²
10000
) Ñ the number of test cases.

Each test case is represented by one line containing two integers ??
l
 and ??
r
 (1²??<??²109
1
²
l
<
r
²
10
9
).

Output
For each test case, print two integers:

if it is impossible to find integers ??
x
 and ??
y
 meeting the constraints in the statement, print two integers equal to ?1
?
1
;
otherwise, print the values of ??
x
 and ??
y
 (if there are multiple valid answers, you may print any of them).
Example
inputCopy
4
1 1337
13 69
2 4
88 89
outputCopy
6 7
14 21
2 4
-1 -1
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
/* const ld PI = acos(-1.0); */

void solve(int l, int r) {
    if (2 * l > r) {
        cout << -1 << " " << -1 << nl;
        return;
    }

    cout << l << " " << 2 * l << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, l, r;
    cin >> t;
    while (t--) {
        cin >> l >> r;
        solve(l, r);
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
