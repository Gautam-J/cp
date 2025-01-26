// CF - 800

/*
A. Preparing for the Olympiad
time limit per test2 seconds
memory limit per test256 megabytes
Monocarp and Stereocarp are preparing for the Olympiad. There are 𝑛 days left until the Olympiad. On the 𝑖-th day, if Monocarp plans to practice, he will solve 𝑎𝑖 problems. Similarly, if Stereocarp plans to practice on the same day, he will solve 𝑏𝑖 problems.

Monocarp can train on any day he wants. However, Stereocarp watches Monocarp and follows a different schedule: if Monocarp trained on day 𝑖 and 𝑖<𝑛, then Stereocarp will train on day (𝑖+1).

Monocarp wants to organize his training process in a way that the difference between the number of problems he solves and the number of problems Stereocarp solves is as large as possible. Formally, Monocarp wants to maximize the value of (𝑚−𝑠), where 𝑚 is the number of problems he solves, and 𝑠 is the number of problems Stereocarp solves. Help Monocarp determine the maximum possible difference in the number of solved problems between them.

Input
The first line contains a single integer 𝑡 (1≤𝑡≤103) — the number of test cases.

The first line of each test case contains a single integer 𝑛 (1≤𝑛≤100).

The second line contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤100).

The third line contains 𝑛 integers 𝑏1,𝑏2,…,𝑏𝑛 (1≤𝑏𝑖≤100).

Output
For each test case, print a single integer — the maximum possible difference between the number of problems Monocarp solves and the number of problems Stereocarp solves.

Example
inputCopy
4
2
3 2
2 1
1
5
8
3
1 1 1
2 2 2
6
8 2 5 6 2 6
8 2 7 4 3 4
outputCopy
4
5
1
16
Note
Let's analyze the example from the statement:

In the first test case, it is optimal for Monocarp to train both days; then Stereocarp will train on day 2.
In the second test case, it is optimal for Monocarp to train on the only day, and Stereocarp will not train at all.
In the third test case, it is optimal for Monocarp to train on the last day (and only on that day).
In the fourth test case, it is optimal for Monocarp to train on days 1,3,4,6; then Stereocarp will train on days 2,4,5.
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
    // Be greedy and check if a[i] > b[i + 1]
    //
    // Time: O(n)
    // Space: O(1)

    int n;
    cin >> n;

    vi a(n), b(n);
    trav(i, a)
        cin >> i;
    trav(i, b)
        cin >> i;

    int res = a[n - 1];  // always train on last day
    forn(i, 0, n - 1)
        res += max(a[i] - b[i + 1], 0);  // if (a[i] > b[i + 1]) res += a[i] - b[i + 1];

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
