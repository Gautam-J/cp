// CF

/*
A. Was there an Array?
time limit per test2 seconds
memory limit per test512 megabytes
For an array of integers 𝑎1,𝑎2,…,𝑎𝑛, we define its equality characteristic as the array 𝑏2,𝑏3,…,𝑏𝑛−1, where 𝑏𝑖=1 if the 𝑖-th element of the array 𝑎 is equal to both of its neighbors, and 𝑏𝑖=0 if the 𝑖-th element of the array 𝑎 is not equal to at least one of its neighbors.

For example, for the array [1,2,2,2,3,3,4,4,4,4], the equality characteristic will be [0,1,0,0,0,0,1,1].

You are given the array 𝑏2,𝑏3,…,𝑏𝑛−1. Your task is to determine whether there exists such an array 𝑎 for which the given array is the equality characteristic.

Input
The first line contains one integer 𝑡 (1≤𝑡≤1000) — the number of test cases.

Each test case consists of two lines:

the first line contains one integer 𝑛 (3≤𝑛≤100);
the second line contains 𝑛−2 integers 𝑏2,𝑏3,…,𝑏𝑛−1 (0≤𝑏𝑖≤1).
Output
For each test case, output YES if the array 𝑎 exists, or NO if such an array does not exist. Each letter can be printed in any case.

Example
inputCopy
3
10
0 1 0 0 0 0 1 1
3
1
10
0 1 0 1 1 0 0 1
outputCopy
YES
YES
NO
Note
In the first example, the array 𝑎=[1,2,2,2,3,3,4,4,4,4] is suitable.

In the second example, the array 𝑎=[7,7,7] is suitable.
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
    // Check if sequence 101 exists in b array.
    //
    // Time: O(n)
    // Space: O(1)

    int n;
    cin >> n;
    vi b(n - 2);
    trav(i, b) cin >> i;

    if (n < 3) {
        cout << "YES" << nl;
        return;
    }

    forn(i, 0, n - 4) {
        if (b[i] == 1 && b[i + 1] == 0 && b[i + 2] == 1) {
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
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
