// CF - 800

/*
B. Normal Problem
time limit per test1 second
memory limit per test256 megabytes
A string consisting of only characters 'p', 'q', and 'w' is painted on a glass window of a store. Ship walks past the store, standing directly in front of the glass window, and observes string 𝑎. Ship then heads inside the store, looks directly at the same glass window, and observes string 𝑏.

Ship gives you string 𝑎. Your job is to find and output 𝑏.

Input
The first line contains an integer 𝑡 (1≤𝑡≤100) — the number of test cases.

The only line of each test case contains a string 𝑎 (1≤|𝑎|≤100) — the string Ship observes from outside the store. It is guaranteed that 𝑎 only contains characters 'p', 'q', and 'w'.

Output
For each test case, output string 𝑏, the string Ship observes from inside the store, on a new line.

Example
inputCopy
5
qwq
ppppp
pppwwwqqq
wqpqwpqwwqp
pqpqpqpq
outputCopy
pwp
qqqqq
pppwwwqqq
qpwwpqwpqpw
pqpqpqpq
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
    // Reverse the string and swap q and p to get mirror image.
    //
    // Time: O(n)
    // Space: O(n)

    string s;
    cin >> s;

    reverse(allit(s));
    int n = sz(s);
    forn(i, 0, n) {
        if (s[i] == 'p') s[i] = 'q';
        else if (s[i] == 'q') s[i] = 'p';
    }
    cout << s << nl;
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
