// CF - 800

/*
C. Hard Problem
time limit per test1 second
memory limit per test256 megabytes
Ball is the teacher in Paperfold University. The seats of his classroom are arranged in 2 rows with 𝑚 seats each.

Ball is teaching 𝑎+𝑏+𝑐 monkeys, and he wants to assign as many monkeys to a seat as possible. Ball knows that 𝑎 of them only want to sit in row 1, 𝑏 of them only want to sit in row 2, and 𝑐 of them have no preference. Only one monkey may sit in each seat, and each monkey's preference must be followed if it is seated.

What is the maximum number of monkeys that Ball can seat?

Input
The first line contains an integer 𝑡 (1≤𝑡≤104) — the number of test cases.

Each test case contains four integers 𝑚, 𝑎, 𝑏, and 𝑐 (1≤𝑚,𝑎,𝑏,𝑐≤108).

Output
For each test case, output the maximum number of monkeys you can seat.

Example
inputCopy
5
10 5 5 10
3 6 1 1
15 14 12 4
1 1 1 1
420 6 9 69
outputCopy
20
5
30
2
84
Note
In the second test case, 6 monkeys want to sit in the front row, but only 3 seats are available. The monkeys that have no preference and the monkeys who prefer sitting in the second row can sit in the second row together. Thus, the answer is 3+2=5.
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
    // Greedy approach of starting with a monkeys in row1,
    // b monkeys in row2, and remaining c monkeys wherever possible.
    //
    // Time: O(1)
    // Space: O(1)

    int m, a, b, c;
    cin >> m >> a >> b >> c;

    int res = 0, r1_sa = m, r2_sa = m;

    int r1_m = min(r1_sa, a);
    res += r1_m;
    r1_sa -= r1_m;

    int r2_m = min(r2_sa, b);
    res += r2_m;
    r2_sa -= r2_m;

    int rem_sa = r1_sa + r2_sa;
    res += min(rem_sa, c);
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
