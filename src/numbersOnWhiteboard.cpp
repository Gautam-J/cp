/* CF - 1000 */
/*
C. Numbers on Whiteboard
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Numbers 1,2,3,É??
1
,
2
,
3
,
É
n
 (each integer from 1
1
 to ??
n
 once) are written on a board. In one operation you can erase any two numbers ??
a
 and ??
b
from the board and write one integer ??+??2
a
+
b
2
 rounded up instead.

You should perform the given operation ???1
n
?
1
 times and make the resulting number that will be left on the board as small as possible.

For example, if ??=4
n
=
4
, the following course of action is optimal:

choose ??=4
a
=
4
 and ??=2
b
=
2
, so the new number is 3
3
, and the whiteboard contains [1,3,3]
[
1
,
3
,
3
]
;
choose ??=3
a
=
3
 and ??=3
b
=
3
, so the new number is 3
3
, and the whiteboard contains [1,3]
[
1
,
3
]
;
choose ??=1
a
=
1
 and ??=3
b
=
3
, so the new number is 2
2
, and the whiteboard contains [2]
[
2
]
.
It's easy to see that after ???1
n
?
1
 operations, there will be left only one number. Your goal is to minimize it.

Input
The first line contains one integer ??
t
 (1²??²1000
1
²
t
²
1000
) Ñ the number of test cases.

The only line of each test case contains one integer ??
n
 (2²??²2?105
2
²
n
²
2
?
10
5
) Ñ the number of integers written on the board initially.

It's guaranteed that the total sum of ??
n
 over test cases doesn't exceed 2?105
2
?
10
5
.

Output
For each test case, in the first line, print the minimum possible number left on the board after ???1
n
?
1
 operations. Each of the next ???1
n
?
1
lines should contain two integers Ñ numbers ??
a
 and ??
b
 chosen and erased in each operation.

Example
inputCopy
1
4
outputCopy
2
2 4
3 3
3 1
*/

/* Time Complexity: O(n) */
/* Space Complexity: O(n) */

#include <bits/stdc++.h>
using namespace std;

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

void solve(int n) {
    vi a(n);
    FOR(i, n)
        a[i] = i + 1;

    int len = sz(a), x, y;
    vpi res;
    while (len > 1) {
        x = a[len - 1];
        y = a[len - 2];
        a.pop_back();
        a.pop_back();


        a.push_back((x + y + 1) / 2);
        res.emplace_back(x, y);
        len = sz(a);
    }

    cout << a[0] << nl;
    trav(i, res)
        cout << i.first << " " << i.second << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        solve(n);
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
