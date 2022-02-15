/* CF - 1000 */
/*
A. Balanced Rating Changes
time limit per test1 second
memory limit per test512 megabytes
inputstandard input
outputstandard output
Another Codeforces Round has just finished! It has gathered ??
n
 participants, and according to the results, the expected rating change of participant ??
i
 is ????
a
i
. These rating changes are perfectly balanced Ñ their sum is equal to 0
0
.

Unfortunately, due to minor technical glitches, the round is declared semi-rated. It means that all rating changes must be divided by two.

There are two conditions though:

For each participant ??
i
, their modified rating change ????
b
i
 must be integer, and as close to ????2
a
i
2
 as possible. It means that either ????=?????2?
b
i
=
?
a
i
2
?
or ????=?????2?
b
i
=
?
a
i
2
?
. In particular, if ????
a
i
 is even, ????=????2
b
i
=
a
i
2
. Here ????
?
x
?
 denotes rounding down to the largest integer not greater than ??
x
, and ????
?
x
?
denotes rounding up to the smallest integer not smaller than ??
x
.
The modified rating changes must be perfectly balanced Ñ their sum must be equal to 0
0
.
Can you help with that?

Input
The first line contains a single integer ??
n
 (2²??²13845
2
²
n
²
13
845
), denoting the number of participants.

Each of the next ??
n
 lines contains a single integer ????
a
i
 (?336²????²1164
?
336
²
a
i
²
1164
), denoting the rating change of the ??
i
-th participant.

The sum of all ????
a
i
 is equal to 0
0
.

Output
Output ??
n
 integers ????
b
i
, each denoting the modified rating change of the ??
i
-th participant in order of input.

For any ??
i
, it must be true that either ????=?????2?
b
i
=
?
a
i
2
?
 or ????=?????2?
b
i
=
?
a
i
2
?
. The sum of all ????
b
i
 must be equal to 0
0
.

If there are multiple solutions, print any. We can show that a solution exists for any valid input.

Examples
inputCopy
3
10
-5
-5
outputCopy
5
-2
-3
inputCopy
7
-7
-29
0
3
24
-29
38
outputCopy
-3
-15
0
2
12
-15
19
Note
In the first example, ??1=5
b
1
=
5
, ??2=?3
b
2
=
?
3
 and ??3=?2
b
3
=
?
2
 is another correct solution.

In the second example there are 6
6
 possible solutions, one of them is shown in the example output.
*/

/* Time Complexity: O(n) */
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

void solve(vi& a) {
    int flag = 1;
    trav(i, a) {
        if (i % 2 == 0)
            cout << i / 2 << nl;
        else {
            cout << (i + flag) / 2 << nl;
            flag *= -1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    trav(i, a)
        cin >> i;

    solve(a);

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
