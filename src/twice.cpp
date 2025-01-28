// CF - 800

/*
A. Twice
time limit per test1 second
memory limit per test256 megabytes
Kinich wakes up to the start of a new day. He turns on his phone, checks his mailbox, and finds a mysterious present. He decides to unbox the present.

Kinich unboxes an array 𝑎 with 𝑛 integers. Initially, Kinich's score is 0. He will perform the following operation any number of times:

Select two indices 𝑖 and 𝑗 (1≤𝑖<𝑗≤𝑛) such that neither 𝑖 nor 𝑗 has been chosen in any previous operation and 𝑎𝑖=𝑎𝑗. Then, add 1 to his score.
Output the maximum score Kinich can achieve after performing the aforementioned operation any number of times.

Input
The first line contains an integer 𝑡 (1≤𝑡≤500) — the number of test cases.

The first line of each test case contains an integer 𝑛 (1≤𝑛≤20) — the length of 𝑎.

The following line of each test case contains 𝑛 space-separated integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤𝑛).

Output
For each test case, output the maximum score achievable on a new line.

Example
inputCopy
5
1
1
2
2 2
2
1 2
4
1 2 3 1
6
1 2 3 1 2 3
outputCopy
0
1
0
1
3
Note
In the first and third testcases, Kinich cannot perform any operations.

In the second testcase, Kinich can perform one operation with 𝑖=1 and 𝑗=2.

In the fourth testcase, Kinich can perform one operation with 𝑖=1 and 𝑗=4.
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
    // Brute force approach which also works since n is less.
    //
    // Time: O(n^2)
    // Space: O(n)

    int n;
    cin >> n;
    vi a(n);
    trav(i, a) cin >> i;

    if (n < 2) {
        cout << 0 << nl;
        return;
    }

    int res = 0;
    vector<bool> seen(n, false);
    forn(i, 0, n) {
        debug(i, a[i]);
        forn(j, i + 1, n) {
            debug(j, a[j]);
            debug(seen[i], seen[j]);
            if (!seen[i] && !seen[j] && a[i] == a[j]) {
                debug(res);
                res++;
                seen[i] = true;
                seen[j] = true;
            }
        }
    }

    cout << res << nl;
}

void solve() {
    // Algorithm:
    // ==========
    // Sum of floor(count(i) / 2) for all i in given array.
    //
    // Time: O(n)
    // Space: O(n)

    int n;
    cin >> n;
    vi a(n);
    trav(i, a) cin >> i;

    umap<int, int> freq;
    trav(i, a) {
        if (freq.find(i) == freq.end())
            freq[i] = 1;
        else
            freq[i]++;
    }

    int res = 0;
    fore(i, 0, n)
        res += freq[i] / 2;

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
