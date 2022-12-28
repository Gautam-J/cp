
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
#define shuf(v) shuffle(all(v), rng)
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
const ll MOD = 1e9+7;
/* const ld PI = acos(-1.0); */

void solve() {
    // Algorithm:
    // ==========
    // n = 5
    //
    // 01 02 03 04 05
    // 02 04 06 08 10
    // 03 06 09 12 15
    // 04 08 12 16 20
    // 05 10 15 20 25
    //
    // n * (n + 1)
    // -----------
    //      2
    //
    // n * (n + 1) * (2n + 1)
    // ----------------------
    //           6
    //
    // sum(i*(i-1) + i^2)
    // sum(i*(i-1)) + sum(i^2)
    //
    // sum(i*(i-1))
    // sum(i^2 - i)
    // sum(i^2) - sum(i)
    //
    // s = (sum(i^2) - sum(i)) + sum(i^2)
    // s = (4n^3 + 3n^2 - n) / 6
    // res = 2022 * s
    //
    // res = (337 * (4n^3 + 3n^2 - n)) mod (10^9+7)
    //
    // Time: O(1)
    // Space: O(1)

    ll t, n;
    cin >> t;
    while (t--) {
        cin >> n;

        ll a = ((((4%MOD) * (n%MOD)) % MOD) % MOD * (((n%MOD) * (n%MOD)) % MOD) % MOD) % MOD;
        ll b = ((3%MOD) * (n%MOD) * (n%MOD)) % MOD;
        ll c = n % MOD;
        ll d = ((a%MOD) + (b%MOD)) % MOD;
        ll res = ((d - c) % MOD + MOD) % MOD;
        cout << (337 * res) % MOD << nl;

        // ll ans = ((((n*(n+1)) % MOD) * (4*n-1)) % MOD * 337) % MOD;
        // cout << ans << nl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
