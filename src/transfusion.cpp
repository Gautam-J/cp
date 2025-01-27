// CF - 1100

/*
B. Transfusion
time limit per test2 seconds
memory limit per test256 megabytes
You are given an array 𝑎 of length 𝑛. In one operation, you can pick an index 𝑖 from 2 to 𝑛−1 inclusive, and do one of the following actions:

Decrease 𝑎𝑖−1 by 1, then increase 𝑎𝑖+1 by 1.
Decrease 𝑎𝑖+1 by 1, then increase 𝑎𝑖−1 by 1.
After each operation, all the values must be non-negative. Can you make all the elements equal after any number of operations?

Input
First line of input consists of one integer 𝑡 (1≤𝑡≤104)  — the number of test cases.

First line of each test case consists of one integer 𝑛 (3≤𝑛≤2⋅105).

Second line of each test case consists of 𝑛 integers 𝑎𝑖 (1≤𝑎𝑖≤109).

It is guaranteed that the sum of 𝑛 of all test cases doesn't exceed 2⋅105.

Output
For each test case, print "YES" without quotation marks if it is possible to make all the elements equal after any number of operations; otherwise, print "NO" without quotation marks.

You can print answers in any register: "yes", "YeS", "nO"  — will also be considered correct.

Example
inputCopy
8
3
3 2 1
3
1 1 3
4
1 2 5 4
4
1 6 6 1
5
6 2 1 4 2
4
1 4 2 1
5
3 1 2 1 3
3
2 4 2
outputCopy
YES
NO
YES
NO
YES
NO
NO
NO
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
    // The sum of all elements in its parity should be divisible by the
    // number of positions of that parity.
    // i.e. sum of all elemnents in odd index MOD number of odd indices == 0
    // and sum of all elemnents in even index MOD number of even indices == 0
    //
    // Time: O(n)
    // Space: O(1)

    int n;
    cin >> n;
    vi a(n);
    trav(i, a) cin >> i;

    ll ods = 0, evs = 0;
    forn(i, 0, n) {
        if (i & 1) ods += a[i];
        else evs += a[i];
    }

    int odc = n / 2, evc = n / 2;
    if (n & 1) evc++;

    if (ods % odc != 0 || evs % evc != 0 || ods / odc != evs / evc)
        cout << "NO" << nl;
    else
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
