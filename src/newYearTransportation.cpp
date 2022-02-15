/* CF - 1000 */
/*
A. New Year Transportation
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
New Year is coming in Line World! In this world, there are n cells numbered by integers from 1 to n, as a 1???n board. People live in cells. However, it was hard to move between distinct cells, because of the difficulty of escaping the cell. People wanted to meet people who live in other cells.

So, user tncks0121 has made a transportation system to move between these cells, to celebrate the New Year. First, he thought of n?-?1 positive integers a1,?a2,?...,?an?-?1. For every integer i where 1?²?i?²?n?-?1 the condition 1?²?ai?²?n?-?i holds. Next, he made n?-?1 portals, numbered by integers from 1 to n?-?1. The i-th (1?²?i?²?n?-?1) portal connects cell i and cell (i?+?ai), and one can travel from cell i to cell (i?+?ai) using the i-th portal. Unfortunately, one cannot use the portal backwards, which means one cannot move from cell (i?+?ai) to cell i using the i-th portal. It is easy to see that because of condition 1?²?ai?²?n?-?i one can't leave the Line World using portals.

Currently, I am standing at cell 1, and I want to go to cell t. However, I don't know whether it is possible to go there. Please determine whether I can go to cell t by only using the construted transportation system.

Input
The first line contains two space-separated integers n (3?²?n?²?3???104) and t (2?²?t?²?n) Ñ the number of cells, and the index of the cell which I want to go to.

The second line contains n?-?1 space-separated integers a1,?a2,?...,?an?-?1 (1?²?ai?²?n?-?i). It is guaranteed, that using the given transportation system, one cannot leave the Line World.

Output
If I can go to cell t using the transportation system, print "YES". Otherwise, print "NO".

Examples
inputCopy
8 4
1 2 1 2 1 2 1
outputCopy
YES
inputCopy
8 5
1 2 1 2 1 1 1
outputCopy
NO
Note
In the first sample, the visited cells are: 1,?2,?4; so we can successfully visit the cell 4.

In the second sample, the possible cells to visit are: 1,?2,?4,?6,?7,?8; so we can't visit the cell 5, which we want to visit.
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

bool solve(vi& a, int t) {
    // DFS to check if vertex t is reachable from vertex 1

    int i = 1;
    while (i < t)
        i += a[i - 1];

    return (i == t);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;
    vi a(n);
    trav(i, a)
        cin >> i;

    cout << (solve(a, t) ? "YES" : "NO") << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
