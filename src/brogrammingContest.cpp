// CF

/*
A. Brogramming Contest
time limit per test1 second
memory limit per test256 megabytes
One day after waking up, your friend challenged you to a brogramming contest. In a brogramming contest, you are given a binary string∗ 𝑠 of length 𝑛 and an initially empty binary string 𝑡. During a brogramming contest, you can make either of the following moves any number of times:

remove some suffix† from 𝑠 and place it at the end of 𝑡, or
remove some suffix from 𝑡 and place it at the end of 𝑠.
To win the brogramming contest, you must make the minimum number of moves required to make 𝑠 contain only the character 𝟶 and 𝑡 contain only the character 𝟷. Find the minimum number of moves required.
∗A binary string is a string consisting of characters 𝟶 and 𝟷.
†A string 𝑎 is a suffix of a string 𝑏 if 𝑎 can be obtained from deletion of several (possibly, zero or all) elements from the beginning of 𝑏.
Input
The first line contains an integer 𝑡 (1≤𝑡≤100) — the number of test cases.

The first line of each test case is an integer 𝑛 (1≤𝑛≤1000) — the length of the string 𝑠.

The second line of each test case contains the binary string 𝑠.

The sum of 𝑛 across all test cases does not exceed 1000.

Output
For each testcase, output the minimum number of moves required.

Example
inputCopy
5
5
00110
4
1111
3
001
5
00000
3
101
outputCopy
2
1
1
0
3
Note
An optimal solution to the first test case is as follows:

𝑠=𝟶𝟶𝟷𝟷𝟶, 𝑡= empty string.
𝑠=𝟶𝟶, 𝑡=𝟷𝟷𝟶.
𝑠=𝟶𝟶𝟶, 𝑡=𝟷𝟷.
It can be proven that there is no solution using less than 2 moves.

In the second test case, you have to move the whole string from 𝑠 to 𝑡 in one move.

In the fourth test case, you don't have to do any moves.
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
    // Count the no of occurences of 01 and 10, add 1 if a[0] = 1
    //
    // Time: O(n)
    // Space: O(1)

    int n;
    cin >> n;
    string s;
    cin >> s;

    int res = 0;
    if (s.at(0) == '1') res++;

    forn(i, 0, n - 1) {
        if (s.at(i) != s.at(i + 1)) res++;
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
