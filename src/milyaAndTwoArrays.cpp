// CF

/*
A. Milya and Two Arrays
time limit per test1 second
memory limit per test256 megabytes
An array is called good if for any element 𝑥 that appears in this array, it holds that 𝑥 appears at least twice in this array. For example, the arrays [1,2,1,1,2], [3,3], and [1,2,4,1,2,4] are good, while the arrays [1], [1,2,1], and [2,3,4,4] are not good.

Milya has two good arrays 𝑎 and 𝑏 of length 𝑛. She can rearrange the elements in array 𝑎 in any way. After that, she obtains an array 𝑐 of length 𝑛, where 𝑐𝑖=𝑎𝑖+𝑏𝑖 (1≤𝑖≤𝑛).

Determine whether Milya can rearrange the elements in array 𝑎 such that there are at least 3 distinct elements in array 𝑐.

Input
Each test consists of multiple test cases. The first line contains a single integer 𝑡 (1≤𝑡≤1000) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer 𝑛 (3≤𝑛≤50) — the length of the arrays 𝑎 and 𝑏.

The second line of each test case contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤109) — the elements of the array 𝑎.

The third line of each test case contains 𝑛 integers 𝑏1,𝑏2,…,𝑏𝑛 (1≤𝑏𝑖≤109) — the elements of the array 𝑏.

Output
For each test case, output «YES» (without quotes) if it is possible to obtain at least 3 distinct elements in array 𝑐, and «NO» otherwise.

You can output each letter in any case (for example, «YES», «Yes», «yes», «yEs» will be recognized as a positive answer).

Example
inputCopy
5
4
1 2 1 2
1 2 1 2
6
1 2 3 3 2 1
1 1 1 1 1 1
3
1 1 1
1 1 1
6
1 52 52 3 1 3
59 4 3 59 3 4
4
100 1 100 1
2 2 2 2
outputCopy
YES
YES
NO
YES
NO
Note
In the first test case, you can swap the second and third elements. Then the array 𝑎=[1,1,2,2], 𝑏=[1,2,1,2], and then 𝑐=[2,3,3,4].

In the second test case, you can leave the elements unchanged. Then 𝑐=[2,3,4,4,3,2].

In the third test case, the array 𝑎 will not change from rearranging the elements in it. Then 𝑐=[2,2,2], so the answer is «NO».
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
    // Number of distinct elements in a and b should be either
    // either a or b should have more than 2 distinct elements.
    // or a and b both should have more than 1 distinct element.
    // Thus,number of distinct elements in a and b together should be at least 4.
    //
    // Time: O(n)
    // Space: O(n)

    int n;
    cin >> n;
    vi a(n), b(n);
    trav(i, a) cin >> i;
    trav(i, b) cin >> i;

    uset<int> s1, s2;
    trav(i, a) s1.insert(i);
    trav(i, b) s2.insert(i);

    bool res = sz(s1) + sz(s2) < 4;

    // bool res = false;
    // if (sz(s1) > 2 || sz(s2) > 2)
    //     res = true;
    // else if (sz(s1) > 1 && sz(s2) > 1)
    //     res = true;

    cout << (res ? "NO" : "YES") << nl;
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
