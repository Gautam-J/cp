
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
    // Brute force approach which also works, but extremely inefficient.
    //
    // Time: O(k^2)
    // Space: O(k)

    int k;
    cin >> k;
    vi a(k);
    trav(i, a) cin >> i;

    umap<int, int> cnt;
    trav(i, a) {
        if (cnt.find(i) == cnt.end())
            cnt[i] = 1;
        else
            cnt[i]++;
    }

    int n = k - 2;

    fore(i, 1, n) {
        fore(j, i, n) {
            if (i * j == n) {
                if (i == j && cnt[i] > 1) {
                    cout << i << ' ' << j << nl;
                    return;
                }
                if (cnt[i] > 0 && cnt[j] > 0) {
                    cout << i << ' ' << j << nl;
                    return;
                }
            }
        }
    }
}

void solve() {
    // Algorithm:
    // ==========
    // Using freq array instead of hashmap.
    // Remove inner loop using MOD check.
    //
    // Time: O(k)
    // Space: O(k)

    int k;
    cin >> k;
    vi a(k);
    trav(i, a) cin >> i;

    vi freq(k + 1, 0);
    trav(i, a) freq[i]++;

    int n = k - 2;
    forn(i, 1, k + 1) {
        if (i * i == n && freq[i] > 1) {  // edge case
            cout << i << ' ' << i << nl;
            return;
        }

        if (n % i == 0 && freq[i] > 0 and freq[n / i] > 0) {
            cout << i << ' ' << n / i << nl;
            return;
        }
    }
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
