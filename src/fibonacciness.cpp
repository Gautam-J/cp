// CF

/*
A. Fibonacciness
time limit per test1 second
memory limit per test256 megabytes
There is an array of 5 integers. Initially, you only know 𝑎1,𝑎2,𝑎4,𝑎5. You may set 𝑎3 to any positive integer, negative integer, or zero. The Fibonacciness of the array is the number of integers 𝑖 (1≤𝑖≤3) such that 𝑎𝑖+2=𝑎𝑖+𝑎𝑖+1. Find the maximum Fibonacciness over all integer values of 𝑎3.

Input
The first line contains an integer 𝑡 (1≤𝑡≤500) — the number of test cases.

The only line of each test case contains four integers 𝑎1,𝑎2,𝑎4,𝑎5 (1≤𝑎𝑖≤100).

Output
For each test case, output the maximum Fibonacciness on a new line.

Example
inputCopy
6
1 1 3 5
1 3 2 1
8 10 28 100
100 1 100 1
1 100 1 100
100 100 100 100
outputCopy
3
2
2
1
1
2
Note
In the first test case, we can set 𝑎3 to 2 to achieve the maximal Fibonacciness of 3.

In the third test case, it can be shown that 2 is the maximum Fibonacciness that can be achieved. This can be done by setting 𝑎3 to 18.
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

void solve() {
    // Algorithm:
    // ==========
    // Be greedy and maximize fibonacciness.
    //
    // Time: O(1)
    // Space: O(1)

    vi a(5);
    int temp;
    forn(i, 0, 5) {
        if (i == 2) continue;
        cin >> temp;
        a[i] = temp;
    }

    if (a[0] + a[1] == a[4] - a[3])
        a[2] = a[0] + a[1];
    else
        a[2] = a[3] - a[1];

    int res = 0;
    if (a[0] + a[1] == a[2]) res++;
    if (a[1] + a[2] == a[3]) res++;
    if (a[2] + a[3] == a[4]) res++;

    cout << res << nl;
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
