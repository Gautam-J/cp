
/*
A. Hard Way
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Sam lives in Awesomeburg, its downtown has a triangular shape. Also, the following is true about the triangle:

its vertices have integer coordinates,
the coordinates of vertices are non-negative, and
its vertices are not on a single line.
He calls a point on the downtown's border (that is the border of the triangle) safe if he can reach this point from at least one point of the line ??=0
y
=
0
 walking along some straight line, without crossing the interior of the triangle.

In the picture the downtown is marked with grey color. The first path is invalid because it does not go along a straight line. The second path is invalid because it intersects with the interior of the downtown. The third and fourth paths are correct.
Find the total length of the unsafe parts of the downtown border. It can be proven that these parts are segments and their number is finite.

Input
Each test contains multiple test cases. The first line contains a single integer ??
t
 (1²??²1000
1
²
t
²
1000
) Ñ the number of test cases. Description of the test cases follows.

Each test case contains three lines, each of them contains two integers ????
x
i
, ????
y
i
 (0²????,????²109
0
²
x
i
,
y
i
²
10
9
) Ñ coordinates of the vertices of the downtown's border.

Output
For each test case print a single number Ñ the answer to the problem.

Your answer will be considered correct if its absolute or relative error does not exceed 10?9
10
?
9
. Formally let your answer be ??
a
, jury answer be ??
b
. Your answer will be considered correct if |?????|max(1,|??|)²10?9
|
a
?
b
|
max
(
1
,
|
b
|
)
²
10
?
9
.

Example
inputCopy
5
8 10
10 4
6 2
4 6
0 1
4 2
14 1
11 2
13 2
0 0
4 0
2 4
0 1
1 1
0 0
outputCopy
0.0000000
0
2.0000
0.00
1
Note
In the picture, the downtowns of the first three test cases are illustrated. Triangles are enumerated according to the indices of test cases they belong to.


In the first two test cases, all points on the borders of the downtowns are safe, thus the answers are 0
0
.

In the following picture unsafe points for the third test case are marked with black color:


In the fourth test case, all points on the border of the downtown are safe.
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
#define allit(a) a.begin(), a.end()
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

int solve(pi a, pi b, pi c) {
    if (a.second == b.second && c.second < a.second)
        return abs(a.first - b.first);
    if (b.second == c.second && a.second < b.second)
        return abs(b.first - c.first);
    if (a.second == c.second && b.second < a.second)
        return abs(a.first - c.first);
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    pi a, b, c;
    while (t--) {
        cin >> a.first >> a.second;
        cin >> b.first >> b.second;
        cin >> c.first >> c.second;
        cout << solve(a, b, c) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
