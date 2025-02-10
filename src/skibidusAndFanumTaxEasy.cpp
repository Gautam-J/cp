// CF

/*
This is the easy version of the problem. In this version, 𝑚=1.

Skibidus has obtained two arrays 𝑎 and 𝑏, containing 𝑛 and 𝑚 elements respectively. For each integer 𝑖 from 1 to 𝑛, he is allowed to perform the operation at most once:

Choose an integer 𝑗 such that 1≤𝑗≤𝑚. Set 𝑎𝑖:=𝑏𝑗−𝑎𝑖. Note that 𝑎𝑖 may become non-positive as a result of this operation.
Skibidus needs your help determining whether he can sort 𝑎 in non-decreasing order∗ by performing the above operation some number of times.

∗𝑎 is sorted in non-decreasing order if 𝑎1≤𝑎2≤…≤𝑎𝑛.
Input
The first line contains an integer 𝑡 (1≤𝑡≤104) — the number of test cases.

The first line of each test case contains two integers 𝑛 and 𝑚 (1≤𝑛≤2⋅105, 𝐦 = 1).

The following line of each test case contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤109).

The following line of each test case contains 𝑚 integers 𝑏1,𝑏2,…,𝑏𝑚 (1≤𝑏𝑖≤109).

It is guaranteed that the sum of 𝑛 and the sum of 𝑚 over all test cases does not exceed 2⋅105.

Output
For each test case, if it is possible to sort 𝑎 in non-decreasing order, print "YES" on a new line. Otherwise, print "NO" on a new line.

You can output the answer in any case. For example, the strings "yEs", "yes", and "Yes" will also be recognized as positive responses.

Example
inputCopy
5
1 1
5
9
3 1
1 4 3
3
4 1
1 4 2 5
6
4 1
5 4 10 5
4
3 1
9 8 7
8
outputCopy
YES
NO
YES
NO
YES
Note
In the first test case, [5] is already sorted.

In the second test case, it can be shown that it is impossible.

In the third test case, we can set 𝑎3:=𝑏1−𝑎3=6−2=4. The sequence [1,4,4,5] is in nondecreasing order.

In the last case, we can apply operations on each index. The sequence becomes [−1,0,1], which is in nondecreasing order.
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
    // Make the first element as small as possible.
    // Make the next element as small as possible while being greater than the current element.
    //
    // In the end, if the array is sorted in non decreasing order, then YES else NO
    //
    // Time: O(n)
    // Space: O(1)

    int n, m;
    cin >> n >> m;
    vi a(n);
    trav(i, a) cin >> i;
    int b;
    cin >> b;

    if (n == 1) {
        cout << "YES" << nl;
        return;
    }

    a[0] = min(a[0], b - a[0]);
    forn(i, 1, n) {
        if (a[i] >= a[i - 1] && b - a[i] >= a[i - 1])
            a[i] = min(a[i], b - a[i]);
        else if (b - a[i] >= a[i - 1])
            a[i] = b - a[i];
    }

    bool res = true;
    forn(i, 1, n) {
        if (a[i] < a[i - 1]) {
            res = false;
            break;
        }
    }
    cout << (res ? "YES" : "NO") << "\n";
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
