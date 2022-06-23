/* DE Shaw - Internship */
/*
Given 2 arrays of players with eating capacity a[i], b[i].
Players may compete in any order.
if a[i] > b[i], then a wins.
Return maximum wins
*/

/* Time Complexity: O(nlogn) */
/* Space Complexity: O(n) */

#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

template<typename T> T gcd(T a, T b) { return ( b ? __gcd(a, b) : a); }
template<typename T> T lcm(T a, T b) { return (a * (b / gcd(a, b))); }

#define forn(i, n) for (int i = 0; i < n; i++)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; i++)
#define trav(i, a) for (auto& i : a)
#define allit(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define SHUF(v) shuffle(all(v), mt_rand)
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

// mt19937_64 for 64 bit random numbers
mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());

const char nl = '\n';
/* const ld PI = acos(-1.0); */

typedef struct Player {
    int capacity;
    char team;
} Player;

int solve(vi& a, vi& b) {
    sort(allit(a));
    sort(allit(b));

    vector<Player> c;
    int i = 0, j = 0;
    int n = sz(a);
    Player p;
    while (i < n && j < n) {
        if (a[i] <= b[j]) {
            p = { a[i], 'A' };
            i++;
        } else {
            p = { b[j], 'B' };
            j++;
        }
        c.pb(p);
    }

    while (i < n) {
        p = { a[i], 'A' };
        c.pb(p);
        i++;
    }

    while (j < n) {
        p = { a[j], 'B' };
        c.pb(p);
        j++;
    }

    for (const auto& P : c) {
        cout << P.capacity << " " << P.team << endl;
    }

    int res = 0;
    for (int q = 0; i < (2 * n) - 1; i++) {
        if (c[q].team == 'B' && c[q + 1].team == 'A' && c[q].capacity < c[q + 1].capacity)
            res++;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vi a(n), b(n);
    trav(i, a)
        cin >> i;
    trav(i, b)
        cin >> i;

    cout << solve(a, b) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
