// CF - 800

/*
B. Journey
time limit per test1 second
memory limit per test256 megabytes
Monocarp decided to embark on a long hiking journey.

He decided that on the first day he would walk 𝑎 kilometers, on the second day he would walk 𝑏 kilometers, on the third day he would walk 𝑐 kilometers, on the fourth day, just like on the first, he would walk 𝑎 kilometers, on the fifth day, just like on the second, he would walk 𝑏 kilometers, on the sixth day, just like on the third, he would walk 𝑐 kilometers, and so on.

Monocarp will complete his journey on the day when he has walked at least 𝑛 kilometers in total. Your task is to determine the day on which Monocarp will complete his journey.

Input
The first line contains one integer 𝑡 (1≤𝑡≤104) — the number of test cases.

Each test case consists of one line containing four integers 𝑛, 𝑎, 𝑏, 𝑐 (1≤𝑛≤109; 1≤𝑎,𝑏,𝑐≤106).

Output
For each test case, output one integer — the day on which Monocarp will have walked at least 𝑛 kilometers in total and will complete his journey.

Example
inputCopy
4
12 1 5 3
6 6 7 4
16 3 4 1
1000000000 1 1 1
outputCopy
5
1
6
1000000000
Note
In the first example, over the first four days, Monocarp will cover 1+5+3+1=10 kilometers. On the fifth day, he will cover another 5 kilometers, meaning that in total over five days he will have covered 10+5=15 kilometers. Since 𝑛=12, Monocarp will complete his journey on the fifth day.

In the second example, Monocarp will cover 6 kilometers on the first day. Since 𝑛=6, Monocarp will complete his journey on the very first day.

In the third example, Monocarp will cover 3+4+1+3+4+1=16 kilometers over the first six days. Since 𝑛=16, Monocarp will complete his journey on the sixth day.
*/

#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

// template<typename T> T gcd(T a, T b) { return ( b ? __gcd(a, b) : a); }
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
    // Brute force approach gives TLE.
    //
    // Time: O(n)
    // Space: O(1)

    int n;
    cin >> n;

    vi a(3);
    trav(i, a) cin >> i;

    int days = 0, total = 0, index = 0;
    while (total < n) {
        total += a[index];
        days++;
        index = (index + 1) % 3;
    }
    cout << days << nl;
}

void solve() {
    // Algorithm:
    // ==========
    // Check how many times the total sum of (a + b + c) divides n.
    // Take remainder and check with each km per day.
    //
    // Time: O(1)
    // Space: O(1)

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int n_triples = n / (a + b + c);
    int res = n_triples * 3;

    int remaining = n % (a + b + c);
    if (remaining == 0)
        cout << res << nl;
    else if (remaining <= a)
        cout << res + 1 << nl;
    else if (remaining <= (a + b))
        cout << res + 2 << nl;
    else
        cout << res + 3 << nl;
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
