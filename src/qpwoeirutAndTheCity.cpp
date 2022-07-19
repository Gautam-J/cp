/* CF */
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
/* const ld PI = acos(-1.0); */

void solve() {
    // Algorithm:
    // If the number of buildings is odd, make all alternate buildings,
    // starting from second building as cool building.
    // If its even,
    // then calculate alternating forward prefix sum and
    // alternating backward prefix sum
    //
    // Time: O(n)
    // Space: O(1)

    int n;
    cin >> n;
    vi a(n);
    trav(i, a)
        cin >> i;

    ll res = 0;
    if (n % 2 == 1) {
        for (int i = 1; i < n; i += 2)
            res += max(0, max(a[i - 1], a[i + 1]) - a[i] + 1);
    } else {
        ll total = 0;
        for (int i = 1; i < n - 1; i += 2)
            total += max(0, max(a[i - 1], a[i + 1]) - a[i] + 1);

        res = total;
        for (int i = n - 2; i > 1; i -= 2) {
            total -= max(0, max(a[i - 2], a[i]) - a[i - 1] + 1);
            total += max(0, max(a[i - 1], a[i + 1]) - a[i] + 1);
            res = min(res, total);
        }
    }
    cout << res << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
