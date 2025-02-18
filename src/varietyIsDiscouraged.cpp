// CF

/*
B. Variety is Discouraged
time limit per test1.5 seconds
memory limit per test256 megabytes
Define the score of an arbitrary array 𝑏 to be the length of 𝑏 minus the number of distinct elements in 𝑏. For example:

The score of [1,2,2,4] is 1, as it has length 4 and only 3 distinct elements (1, 2, 4).
The score of [1,1,1] is 2, as it has length 3 and only 1 distinct element (1).
The empty array has a score of 0.
You have an array 𝑎. You need to remove some non-empty contiguous subarray from 𝑎 at most once.

More formally, you can do the following at most once:

pick two integers 𝑙, 𝑟 where 1≤𝑙≤𝑟≤𝑛, and
delete the contiguous subarray [𝑎𝑙,…,𝑎𝑟] from 𝑎 (that is, replace 𝑎 with [𝑎1,…,𝑎𝑙−1,𝑎𝑟+1,…,𝑎𝑛]).
Output an operation such that the score of 𝑎 is maximum; if there are multiple answers, output one that minimises the final length of 𝑎 after the operation. If there are still multiple answers, you may output any of them.

Input
The first line contains an integer 𝑡 (1≤𝑡≤104) — the number of testcases.

The first line of each testcase contains an integer 𝑛 (1≤𝑛≤2⋅105) — the length of the array 𝑎.

The second line of each testcase contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤𝑛).

The sum of 𝑛 across all testcases does not exceed 2⋅105.

Output
For each testcase, if you wish to not make a move, output 0.

Otherwise, output two integers 𝑙 and 𝑟 (1≤𝑙≤𝑟≤𝑛), representing the left and right bound of the removed subarray.

The removed subarray should be chosen such that the score is maximized, and over all such answers choose any of them that minimises the final length of the array.

Example
inputCopy
3
1
1
5
1 1 1 1 1
4
2 1 3 2
outputCopy
1 1
0
2 3
Note
In the first testcase, we have two options:

do nothing: the score of [1] is 1−1=0.
remove the subarray with 𝑙=1, 𝑟=1: we remove the only element, and we get an empty array with score 0.
Therefore, the maximum score possible is 0. However, since we need to additionally minimise the final length of the array, we must output the second option with 𝑙=𝑟=1. Note that the first option of doing nothing is incorrect, since it has a longer final length.
In the second testcase, no subarray is selected, so after which 𝑎 is still [1,1,1,1,1]. This has length 5 and 1 distinct element, so it has a score of 5−1=4. This can be proven to be a shortest array which maximises the score.

In the third testcase, the subarray selected is [2,1,3,2], after which 𝑎 becomes [2,2]. This has length 2 and 1 distinct element, so it has a score of 2−1=1. This can be proven to be a shortest array which maximises the score.
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
    // Find the longest subarray of elements that have freq = 1
    //
    // Time: O(n)
    // Space: O(n)

    int n;
    cin >> n;
    vi a(n);
    trav(i, a) cin >> i;

    vi freq(n + 1, 0);
    trav(i, a) freq[i]++;

    vi dp(n + 1, 0);
    if (freq[a[0]] == 1)
        dp[0] = 1;

    forn(i, 1, n) {
        if (freq[a[i]] == 1)
            dp[i] = dp[i - 1] + 1;
    }

    int max_e = *max_element(allit(dp));
    if (max_e == 0) {
        cout << 0 << nl;
        return;
    }

    forn(i, 0, n) {
        if (dp[i] == max_e) {
            cout << i - dp[i] + 2 << " " << i + 1 << nl;
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
