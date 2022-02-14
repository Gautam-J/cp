/* CF - 800 */
/*
B. Fix You
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Consider a conveyor belt represented using a grid consisting of ??
n
 rows and ??
m
 columns. The cell in the ??
i
-th row from the top and the ??
j
-th column from the left is labelled (??,??)
(
i
,
j
)
.

Every cell, except (??,??)
(
n
,
m
)
, has a direction R (Right) or D (Down) assigned to it. If the cell (??,??)
(
i
,
j
)
 is assigned direction R, any luggage kept on that will move to the cell (??,??+1)
(
i
,
j
+
1
)
. Similarly, if the cell (??,??)
(
i
,
j
)
 is assigned direction D, any luggage kept on that will move to the cell (??+1,??)
(
i
+
1
,
j
)
. If at any moment, the luggage moves out of the grid, it is considered to be lost.

There is a counter at the cell (??,??)
(
n
,
m
)
 from where all luggage is picked. A conveyor belt is called functional if and only if any luggage reaches the counter regardless of which cell it is placed in initially. More formally, for every cell (??,??)
(
i
,
j
)
, any luggage placed in this cell should eventually end up in the cell (??,??)
(
n
,
m
)
.

This may not hold initially; you are, however, allowed to change the directions of some cells to make the conveyor belt functional. Please determine the minimum amount of cells you have to change.

Please note that it is always possible to make any conveyor belt functional by changing the directions of some set of cells.

Input
Each test contains multiple test cases. The first line contains the number of test cases ??
t
 (1²??²10
1
²
t
²
10
). Description of the test cases follows.

The first line of each test case contains two integers ??,??
n
,
m
 (1²??²100
1
²
n
²
100
, 1²??²100
1
²
m
²
100
)  Ñ the number of rows and columns, respectively.

The following ??
n
 lines each contain ??
m
 characters. The ??
j
-th character in the ??
i
-th line, ????,??
a
i
,
j
 is the initial direction of the cell (??,??)
(
i
,
j
)
. Please note that ????,??=
a
n
,
m
=
 C.

Output
For each case, output in a new line the minimum number of cells that you have to change to make the conveyor belt functional.

Example
inputCopy
4
3 3
RRD
DDR
RRC
1 4
DDDC
6 9
RDDDDDRRR
RRDDRRDDD
RRDRDRRDR
DDDDRDDRR
DRRDRDDDR
DDRDRRDDC
1 1
C
outputCopy
1
3
9
0
Note
In the first case, just changing the direction of (2,3)
(
2
,
3
)
 to D is enough.
*/

/* Time Complexity: O(n + m) */
/* Space Complexity: O(1) */

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

int solve(vector< vector<char> >& a, int n, int m) {
    int res = 0;

    // Rs in last column
    for (int i = 0; i < n - 1; i++) {
        if (a[i][m - 1] == 'R')
            res++;
    }

    // Ds in last row
    for (int i = 0; i < m - 1; i++) {
        if (a[n - 1][i] == 'D')
            res++;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, m;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        vector< vector<char> > a(n, vector<char>(m));

        trav(i, a) {
            trav(j, i)
                cin >> j;
        }

        cout << solve(a, n, m) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
