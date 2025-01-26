// CF - 800

/*
A. Easy Problem
time limit per test1 second
memory limit per test256 megabytes
Cube is given an integer 𝑛. She wants to know how many ordered pairs of positive integers (𝑎,𝑏) there are such that 𝑎=𝑛−𝑏. Since Cube is not very good at math, please help her!

Input
The first line contains an integer 𝑡 (1≤𝑡≤99) — the number of test cases.

The only line of each test case contains an integer 𝑛 (2≤𝑛≤100).

Output
For each test case, output the number of ordered pairs (𝑎,𝑏) on a new line.

Example
inputCopy
3
2
4
6
outputCopy
1
3
5
Note
In the first test case, the only ordered pair that works is (𝑎,𝑏)=(1,1).

In the second test case, the three ordered pairs of (𝑎,𝑏) that work are (3,1),(2,2),(1,3).
*/

#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

template<typename T> T gcd(T a, T b) { return ( b ? __gcd(a, b) : a); }
template<typename T> T lcm(T a, T b) { return (a * (b / gcd(a, b))); }

#define forn(i, l, r) for (int i = (int)l; i < (int)r; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define trav(i, a) for (auto& i : a)
#define allit(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define shuf(v) shuffle(allit(v), rng)
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

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const char nl = '\n';
// const ll MOD = 1e9+7;
// const ld PI = acos(-1.0);

void solve1() {
    // Algorithm:
    // ==========
    // Brute force approach works too.
    //
    // Time: O(n**2)
    // Space: O(1)

    int n;
    cin >> n;

    int res = 0;
    forn(i, 0, n) {
        forn(j, 0, n)
            if (i + j == n) res++;
    }

    cout << res << nl;
}

void solve() {
    // Algorithm:
    // ==========
    // n - 1
    //
    // Time: O(1)
    // Space: O(1)

    int n;
    cin >> n;
    cout << n - 1 << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--)
        solve();

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
