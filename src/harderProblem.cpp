// CF - 1100

/*
D. Harder Problem
time limit per test2 seconds
memory limit per test256 megabytes
Given a sequence of positive integers, a positive integer is called a mode of the sequence if it occurs the maximum number of times that any positive integer occurs. For example, the mode of [2,2,3] is 2. Any of 9, 8, or 7 can be considered to be a mode of the sequence [9,9,8,8,7,7].

You gave UFO an array 𝑎 of length 𝑛. To thank you, UFO decides to construct another array 𝑏 of length 𝑛 such that 𝑎𝑖 is a mode of the sequence [𝑏1,𝑏2,…,𝑏𝑖] for all 1≤𝑖≤𝑛.

However, UFO doesn't know how to construct array 𝑏, so you must help her. Note that 1≤𝑏𝑖≤𝑛 must hold for your array for all 1≤𝑖≤𝑛.

Input
The first line contains 𝑡 (1≤𝑡≤104) — the number of test cases.

The first line of each test case contains an integer 𝑛 (1≤𝑛≤2⋅105) — the length of 𝑎.

The following line of each test case contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤𝑛).

It is guaranteed that the sum of 𝑛 over all test cases does not exceed 2⋅105.

Output
For each test case, output 𝑛 numbers 𝑏1,𝑏2,…,𝑏𝑛 (1≤𝑏𝑖≤𝑛) on a new line. It can be shown that 𝑏 can always be constructed. If there are multiple possible arrays, you may print any.

Example
inputCopy
4
2
1 2
4
1 1 1 2
8
4 5 5 5 1 1 2 1
10
1 1 2 2 1 1 3 3 1 1
outputCopy
1 2
1 1 2 2
4 5 5 1 1 2 2 3
1 8 2 2 1 3 3 9 1 1
Note
Let's verify the correctness for our sample output in test case 2.

At 𝑖=1, 1 is the only possible mode of [1].
At 𝑖=2, 1 is the only possible mode of [1,1].
At 𝑖=3, 1 is the only possible mode of [1,1,2].
At 𝑖=4, 1 or 2 are both modes of [1,1,2,2]. Since 𝑎𝑖=2, this array is valid.
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
    // Greedy approach.
    // Need to construct a permutation of 1..n where first occurence position
    // matches.
    // This is because if multiple numbers have same max frequency, all are mode.
    //
    // Time: O(n)
    // Space: O(n)

    int n;
    cin >> n;
    vi a(n);
    trav(i, a) cin >> i;

    uset<int> s;
    vi res(n);

    forn(i, 0, n) {
        if (s.find(a[i]) == s.end()) {
            res[i] = a[i];
            s.insert(a[i]);
        }
    }

    queue<int> q;
    fore(i, 1, n) {
        if (s.find(i) == s.end())
            q.push(i);
    }

    forn(i, 0, n) {
        if (!res[i]) {
            res[i] = q.front();
            q.pop();
        }
    }

    trav(i, res) cout << i << ' ';
    cout << nl;
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
