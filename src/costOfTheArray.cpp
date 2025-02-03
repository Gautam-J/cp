// CF

/*
B. Cost of the Array
time limit per test1 second
memory limit per test256 megabytes
You are given an array 𝑎 of length 𝑛 and an even integer 𝑘 (2≤𝑘≤𝑛). You need to split the array 𝑎 into exactly 𝑘 non-empty subarrays† such that each element of the array 𝑎 belongs to exactly one subarray.

Next, all subarrays with even indices (second, fourth, …, 𝑘-th) are concatenated into a single array 𝑏. After that, 0 is added to the end of the array 𝑏.

The cost of the array 𝑏 is defined as the minimum index 𝑖 such that 𝑏𝑖≠𝑖. For example, the cost of the array 𝑏=[1,2,4,5,0] is 3, since 𝑏1=1, 𝑏2=2, and 𝑏3≠3. Determine the minimum cost of the array 𝑏 that can be obtained with an optimal partitioning of the array 𝑎 into subarrays.

†An array 𝑥 is a subarray of an array 𝑦 if 𝑥 can be obtained from 𝑦 by the deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.

Input
Each test consists of multiple test cases. The first line contains a single integer 𝑡 (1≤𝑡≤104) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers 𝑛 and 𝑘 (2≤𝑘≤𝑛≤2⋅105, 𝑘 is even) — the length of the array 𝑎 and the number of subarrays.

The second line of each test case contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤109) — the elements of the array 𝑎.

It is guaranteed that the sum of 𝑛 over all test cases does not exceed 2⋅105.

Output
For each test case, output a single integer — the minimum cost of the array 𝑏 that can be obtained.

Example
inputCopy
4
3 2
1 1 1
8 8
1 1 2 2 3 3 4 4
5 4
1 1 1 2 2
5 4
1 1 1000000000 2 2
outputCopy
2
5
2
1
Note
In the first test case, there are only two possible partitionings: [[1],[1,1]] and [[1,1],[1]]. In either case, 𝑏1=1, and 𝑏2≠2, so the cost is 2.

In the second test case, there is only one possible partitioning, where 𝑏=[1,2,3,4,0], so the cost is 5 (𝑏5=0≠5).

In the third test case, the following partitioning works: [[1],[1,1],[2],[2]]. Then 𝑏=[1,1,2,0], and the cost is 2.
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
    // If n equals k, then simply loop through the elements in even index
    // and return min index where a[i] <> i. Else, last index + 1 (zero).
    //
    // If n != k, then assume the second subarray to have maximum elements
    // If all elements are not 1, then output 1, else 2.
    //
    // Time: O(n)
    // Space: O(1)

    int n, k;
    cin >> n >> k;
    vi a(n);
    trav(i, a) cin >> i;

    int res;
    if (n == k) {
        res = (n / 2) + 1;
        for (int i = 1; i <= (n / 2); i++) {
            if (a[(i * 2) - 1] != i) {
                res = i;
                break;
            }
        }
    } else {
        res = 2;
        fore(i, 1, n - k + 1) {
            if (a[i] != 1) {
                res = 1;
                break;
            }
        }
    }
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
