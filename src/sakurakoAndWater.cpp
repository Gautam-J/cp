// CF - 900

/*
B. Sakurako and Water
time limit per test2 seconds
memory limit per test256 megabytes
During her journey with Kosuke, Sakurako and Kosuke found a valley that can be represented as a matrix of size 𝑛×𝑛, where at the intersection of the 𝑖-th row and the 𝑗-th column is a mountain with a height of 𝑎𝑖,𝑗. If 𝑎𝑖,𝑗<0, then there is a lake there.

Kosuke is very afraid of water, so Sakurako needs to help him:

With her magic, she can select a square area of mountains and increase the height of each mountain on the main diagonal of that area by exactly one.
More formally, she can choose a submatrix with the upper left corner located at (𝑖,𝑗) and the lower right corner at (𝑝,𝑞), such that 𝑝−𝑖=𝑞−𝑗. She can then add one to each element at the intersection of the (𝑖+𝑘)-th row and the (𝑗+𝑘)-th column, for all 𝑘 such that 0≤𝑘≤𝑝−𝑖.

Determine the minimum number of times Sakurako must use her magic so that there are no lakes.

Input
The first line contains a single integer 𝑡 (1≤𝑡≤200) — the number of test cases.

Each test case is described as follows:

The first line of each test case consists of a single number 𝑛 (1≤𝑛≤500).
Each of the following 𝑛 lines consists of 𝑛 integers separated by spaces, which correspond to the heights of the mountains in the valley 𝑎 (−105≤𝑎𝑖,𝑗≤105).
It is guaranteed that the sum of 𝑛 across all test cases does not exceed 1000.

Output
For each test case, output the minimum number of times Sakurako will have to use her magic so that all lakes disappear.

Example
inputCopy
4
1
1
2
-1 2
3 0
3
1 2 3
-2 1 -1
0 0 -1
5
1 1 -1 -1 3
-3 1 4 4 -4
-1 -1 3 0 -5
4 5 3 -3 -1
3 1 -3 -1 5
outputCopy
0
1
4
19
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

void solve1() {
    // Algorithm:
    // ==========
    // Calculate the minimum value that is less that 0 for each diagonal
    // from top left to bottom right, for each square starting from bottom left
    // to top right.
    // Sum of each diagonal's calculated value is the result.
    //
    // Time: O(n^2)
    // Space: O(n)

    int n;
    cin >> n;
    vvi a(n, vi(n, 0));
    trav(r, a) {
        trav(c, r)
            cin >> c;
    }

    vector<ll> d;
    int diag_sum;
    for (int startCol = 0; startCol < n; startCol++) {
        int col = startCol;
        int row = n - 1;

        diag_sum = 0;
        // Print diagonal starting from (row, col)
        while (col >= 0 && row >= 0) {
            if (a[row][col] < 0)
                diag_sum = min(a[row][col], diag_sum);
            col--;
            row--;

        }
        d.pb(abs(diag_sum));
    }

    for (int startCol = n - 1; startCol >= 1; startCol--) {
        int col = startCol;
        int row = 0;

        diag_sum = 0;
        // Print diagonal starting from (row, col)
        while (col < n && row < n) {
            if (a[row][col] < 0)
                diag_sum = min(a[row][col], diag_sum);
            col++;
            row++;
        }
        d.pb(abs(diag_sum));
    }

    ll res = 0;
    trav(i, d)
        res += i;
    cout << res << nl;
}

void solve() {
    // Algorithm:
    // ==========
    // Cleaner code.
    //
    // Time: O(n^2)
    // Space: O(n)

    int n;
    cin >> n;
    vvi a(n, vi(n, 0));
    trav(r, a) {
        trav(c, r)
            cin >> c;
    }

    umap<int, int> mn;
    forn(i, 0, n) {
        forn(j, 0, n) {
            if (mn.find(i - j) == mn.end())
                mn[i - j] = 0;
            mn[i - j] = min(a[i][j], mn[i - j]);
        }
    }

    ll res = 0;
    trav(i, mn)
        res -= i.second;

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
