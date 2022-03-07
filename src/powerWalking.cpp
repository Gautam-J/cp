/* CR - 900 */
/*
B. Power Walking
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Sam is a kindergartener, and there are ??
n
 children in his group. He decided to create a team with some of his children to play "brawl:go 2".

Sam has ??
n
 power-ups, the ??
i
-th has type ????
a
i
. A child's strength is equal to the number of different types among power-ups he has.

For a team of size ??
k
, Sam will distribute all ??
n
 power-ups to ??
k
 children in such a way that each of the ??
k
 children receives at least one power-up, and each power-up is given to someone.

For each integer ??
k
 from 1
1
 to ??
n
, find the minimum sum of strengths of a team of ??
k
 children Sam can get.

Input
Each test contains multiple test cases. The first line contains a single integer ??
t
 (1²??²3?105
1
²
t
²
3
?
10
5
) Ñ the number of test cases. Description of the test cases follows.

The first line of each test case contains a single integer ??
n
 (1²??²3?105
1
²
n
²
3
?
10
5
).

The second line contains ??
n
 integers ??1,??2,É,????
a
1
,
a
2
,
É
,
a
n
 (1²????²109
1
²
a
i
²
10
9
) Ñ types of Sam's power-ups.

It is guaranteed that the sum of ??
n
 over all test cases does not exceed 3?105
3
?
10
5
.

Output
For every test case print ??
n
 integers.

The ??
k
-th integer should be equal to the minimum sum of strengths of children in the team of size ??
k
 that Sam can get.

Example
inputCopy
2
3
1 1 2
6
5 1 2 2 2 4
outputCopy
2 2 3
4 4 4 4 5 6
Note
One of the ways to give power-ups to minimise the sum of strengths in the first test case:

??=1:{1,1,2}
k
=
1
:
{
1
,
1
,
2
}
??=2:{1,1},{2}
k
=
2
:
{
1
,
1
}
,
{
2
}
??=3:{1},{1},{2}
k
=
3
:
{
1
}
,
{
1
}
,
{
2
}
One of the ways to give power-ups to minimise the sum of strengths in the second test case:

??=1:{1,2,2,2,4,5}
k
=
1
:
{
1
,
2
,
2
,
2
,
4
,
5
}
??=2:{2,2,2,4,5},{1}
k
=
2
:
{
2
,
2
,
2
,
4
,
5
}
,
{
1
}
??=3:{2,2,2,5},{1},{4}
k
=
3
:
{
2
,
2
,
2
,
5
}
,
{
1
}
,
{
4
}
??=4:{2,2,2},{1},{4},{5}
k
=
4
:
{
2
,
2
,
2
}
,
{
1
}
,
{
4
}
,
{
5
}
??=5:{2,2},{1},{2},{4},{5}
k
=
5
:
{
2
,
2
}
,
{
1
}
,
{
2
}
,
{
4
}
,
{
5
}
??=6:{1},{2},{2},{2},{4},{5}
*/

/* Time Complexity: O(n lg n) */
/* Space Complexity: O(n) */

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

void solve(vi& a) {
    set<int> s;
    trav(i, a)
        s.insert(i);

    int cnt = sz(s);
    int n = sz(a);
    fore(k, 1, n)
        cout << max(k, cnt) << " ";
    cout << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vi a(n);
        trav(i, a)
            cin >> i;
        solve(a);
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
