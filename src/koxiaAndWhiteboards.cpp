
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
// const ll MOD = 1e9+7;
// const ld PI = acos(-1.0);

void solve() {
    // Algorithm:
    // ==========
    // Because we have to replace b_m at the end, it will definitely be on the
    // board. Therefore, we add that to the sum.
    //
    // Now we can just take the largest (n - 1) numbers from all available
    // numbers and add that to sum. We can do so by sorting all (n+m-1) numbers.
    //
    // Time: O((n+m)log(n+m))
    // Space: O(n+m)

    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vi a(n+m);
        trav(i, a)
            cin >> i;

        sort(a.begin(), a.end() - 1);
        reverse(allit(a));

        ll res = 0;
        forn(i, 0, n)
            res += a[i];

        cout << res << nl;
    }

}

void solve1() {
    // Algorithm:
    // ==========
    // Greedy Algorithm.
    // For every value in array sub, check which value in board has greatest diff
    // and replace it.
    //
    // Time: O(nm)
    // Space: O(1)

    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vi board(n), sub(m);
        trav(i, board)
            cin >> i;
        trav(i, sub)
            cin >> i;

        forn(i, 0, m) {
            int new_value = sub[i];

            int greatest_diff_index = 0, diff = new_value - board[0];
            forn(j, 1, n) {
                if (new_value - board[j] > diff) {
                    diff = new_value - board[j];
                    greatest_diff_index = j;
                }
            }

            board[greatest_diff_index] = new_value;
        }

        ll sum = 0;
        trav(i, board)
            sum += i;

        cout << sum << nl;
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
