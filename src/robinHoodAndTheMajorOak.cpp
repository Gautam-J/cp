// CF - 800

/*
B. Robin Hood and the Major Oak
time limit per test1 second
memory limit per test256 megabytes
In Sherwood, the trees are our shelter, and we are all children of the forest.
The Major Oak in Sherwood is known for its majestic foliage, which provided shelter to Robin Hood and his band of merry men and women.

The Major Oak grows 𝑖𝑖 new leaves in the 𝑖-th year. It starts with 1 leaf in year 1.

Leaves last for 𝑘 years on the tree. In other words, leaves grown in year 𝑖 last between years 𝑖 and 𝑖+𝑘−1 inclusive.

Robin considers even numbers lucky. Help Robin determine whether the Major Oak will have an even number of leaves in year 𝑛.

Input
The first line of the input contains a single integer 𝑡 (1≤𝑡≤104) — the number of test cases.

Each test case consists of two integers 𝑛, 𝑘 (1≤𝑛≤109, 1≤𝑘≤𝑛) — the requested year and the number of years during which the leaves remain.

Output
For each test case, output one line, "YES" if in year 𝑛 the Major Oak will have an even number of leaves and "NO" otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
inputCopy
5
1 1
2 1
2 2
3 2
4 4
outputCopy
NO
YES
NO
NO
YES
Note
In the first test case, there is only 1 leaf.

In the second test case, 𝑘=1, so in the 2-nd year there will be 22=4 leaves.

In the third test case, 𝑘=2, so in the 2-nd year there will be 1+22=5 leaves.

In the fourth test case, 𝑘=2, so in the 3-rd year there will be 22+33=4+27=31 leaves.
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
    // Parity of i power i is same as i.
    // Therefore compute the parity of numbers from left to right.
    // If parity of odd count of numbers is odd, then no else yes.
    // However this gives TLE.
    //
    // Time: O(n)
    // Space: O(1)

    int n, k;
    cin >> n >> k;

    int left = n - k + 1;
    int right = n;

    int oc = 0;
    fore(i, left, right)
        oc += (i & 1);

    cout << ((oc & 1) ? "NO" : "YES") << nl;
}

void solve() {
    // Algorithm:
    // ==========
    // Parity of i power i is same as i.
    // Therefore compute the parity of numbers from left to right.
    // If parity of odd count of numbers is odd, then no else yes.
    // Calculate the number of odd count of numbers without loop.
    //
    // Time: O(1)
    // Space: O(1)

    int n, k;
    cin >> n >> k;

    int oc;
    if (n & 1)
        oc = (k + 1) / 2;  // floor division
    else
        oc = k / 2;

    cout << ((oc & 1) ? "NO" : "YES") << nl;
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
