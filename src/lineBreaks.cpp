// CF - 800

/*
A. Line Breaks
time limit per test1 second
memory limit per test256 megabytes
Kostya has a text 𝑠 consisting of 𝑛 words made up of Latin alphabet letters. He also has two strips on which he must write the text. The first strip can hold 𝑚 characters, while the second can hold as many as needed.

Kostya must choose a number 𝑥 and write the first 𝑥 words from 𝑠 on the first strip, while all the remaining words are written on the second strip. To save space, the words are written without gaps, but each word must be entirely on one strip.

Since space on the second strip is very valuable, Kostya asks you to choose the maximum possible number 𝑥 such that all words 𝑠1,𝑠2,…,𝑠𝑥 fit on the first strip of length 𝑚.

Input
The first line contains an integer 𝑡 (1≤𝑡≤1000) — the number of test cases.

The first line of each test case contains two integers 𝑛 and 𝑚 (1≤𝑛≤50; 1≤𝑚≤500) — the number of words in the list and the maximum number of characters that can be on the first strip.

The next 𝑛 lines contain one word 𝑠𝑖 of lowercase Latin letters, where the length of 𝑠𝑖 does not exceed 10.

Output
For each test case, output the maximum number of words 𝑥 such that the first 𝑥 words have a total length of no more than 𝑚.

Example
inputCopy
5
3 1
a
b
c
2 9
alpha
beta
4 12
hello
world
and
codeforces
3 2
ab
c
d
3 2
abc
ab
a
outputCopy
1
2
2
1
0
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
    // Greedy. Keep track of total length of words in order.
    //
    // Time: O(n)
    // Space: O(1)

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    trav(w, a) cin >> w;

    int l, res = 0, sum = 0;
    trav(w, a) {
        l = sz(w);
        if (sum + l > m) break;
        sum += l;
        res++;
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
