// CSES

/*
Time limit: 1.00 s
Memory limit: 512 MB

Consider an infinite string that consists of all positive integers in increasing order:
12345678910111213141516171819202122232425...
Your task is to process q queries of the form: what is the digit at position k in the string?
Input
The first input line has an integer q: the number of queries.
After this, there are q lines that describe the queries. Each line has an integer k: a 1-indexed position in the string.
Output
For each query, print the corresponding digit.
Constraints

1 \le q \le 1000
1 \le k \le 10^{18}

Example
Input:
3
7
19
12

Output:
7
4
1
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
    // Calculate the length of the digit k falls under.
    // Using modular arthimatic, calculate the digit position of the number.
    //
    // Time: O(log_10 k)
    // Space: O(1)

    ll k;
    cin >> k;

    if (k < 10) {
        cout << k << nl;
        return;
    }

    int d = 1;
    while (1) {
        ll start = 1;
        forn(i, 1, d)
            start *= 10;

        ll numbers = 9 * start;
        ll cnt = numbers * d;

        if (k <= cnt)
            break;

        k -= cnt;
        d++;
    }

    ll start = 1;
    forn(i, 1, d)
        start *= 10;

    ll number = start + (k - 1) / d;
    ll pos = (k - 1) % d;
    string s = to_string(number);

    cout << s[pos] << nl;
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
