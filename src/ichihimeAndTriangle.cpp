/* CF - 800 */
/*
A. Ichihime and Triangle
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Ichihime is the current priestess of the Mahjong Soul Temple. She claims to be human, despite her cat ears.

These days the temple is holding a math contest. Usually, Ichihime lacks interest in these things, but this time the prize for the winner is her favorite Ñ cookies. Ichihime decides to attend the contest. Now she is solving the following problem.



You are given four positive integers ??
a
, ??
b
, ??
c
, ??
d
, such that ??²??²??²??
a
²
b
²
c
²
d
.

Your task is to find three integers ??
x
, ??
y
, ??
z
, satisfying the following conditions:

??²??²??
a
²
x
²
b
.
??²??²??
b
²
y
²
c
.
??²??²??
c
²
z
²
d
.
There exists a triangle with a positive non-zero area and the lengths of its three sides are ??
x
, ??
y
, and ??
z
.
Ichihime desires to get the cookie, but the problem seems too hard for her. Can you help her?

Input
The first line contains a single integer ??
t
 (1²??²1000
1
²
t
²
1000
)  Ñ the number of test cases.

The next ??
t
 lines describe test cases. Each test case is given as four space-separated integers ??
a
, ??
b
, ??
c
, ??
d
 (1²??²??²??²??²109
1
²
a
²
b
²
c
²
d
²
10
9
).

Output
For each test case, print three integers ??
x
, ??
y
, ??
z
  Ñ the integers you found satisfying the conditions given in the statement.

It is guaranteed that the answer always exists. If there are multiple answers, print any.

Example
inputCopy
4
1 3 5 7
1 5 5 7
100000 200000 300000 400000
1 1 977539810 977539810
outputCopy
3 4 5
5 5 5
182690 214748 300999
1 977539810 977539810
Note
One of the possible solutions to the first test case:
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, a, b, c, d;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        cout << b << " " << c << " " << c << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
