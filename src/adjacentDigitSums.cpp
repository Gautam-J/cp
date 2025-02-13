// CF

/*
A. Adjacent Digit Sums
time limit per test1 second
memory limit per test256 megabytes
You are given two numbers 𝑥,𝑦. You need to determine if there exists an integer 𝑛 such that 𝑆(𝑛)=𝑥, 𝑆(𝑛+1)=𝑦.

Here, 𝑆(𝑎) denotes the sum of the digits of the number 𝑎 in the decimal numeral system.

Input
Each test contains multiple test cases. The first line contains the number of test cases 𝑡 (1≤𝑡≤500). The description of the test cases follows.

The first line of each test case contains two integers 𝑥,𝑦 (1≤𝑥≤1000,1≤𝑦≤1000).

Output
For each test case, print "NO" if a suitable 𝑛 does not exist. Otherwise, output "YES".

You can output each letter in any case (for example, "YES", "Yes", "yes", "yEs", "yEs" will be recognized as a positive answer).

Example
inputCopy
7
1 2
77 77
997 999
999 1
1000 1
1 11
18 1
outputCopy
Yes
No
No
Yes
No
No
Yes
Note
In the first test case, for example, 𝑛=100 works. 𝑆(100)=1, 𝑆(101)=2.

In the second test case, it can be shown that 𝑆(𝑛)≠𝑆(𝑛+1) for all 𝑛; therefore, the answer is No.

In the fourth test case, 𝑛=10111−1 works, which is a number consisting of 111 digits of 9.
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
    // k should be a non negative integer >= 0
    //
    // Time: O(1)
    // Space: O(1)

    // double x, y;
    // cin >> x >> y;
    // double k = (x + 1 - y) / 9.0;
    //
    // bool res = false;
    // if (k >= 0 && ceil(k) == floor(k))
    //     res = true;

    int x, y;
    cin >> x >> y;

    bool res = false;
    if (x + 1 >= y && (x + 1 - y) % 9 == 0)
        res = true;
    cout << (res ? "Yes" : "No") << nl;
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
