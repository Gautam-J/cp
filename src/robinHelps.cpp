// CF - 800

/*
A. Robin Helps
time limit per test1 second
memory limit per test256 megabytes
There is a little bit of the outlaw in everyone, and a little bit of the hero too.
The heroic outlaw Robin Hood is famous for taking from the rich and giving to the poor.

Robin encounters 𝑛 people starting from the 1-st and ending with the 𝑛-th. The 𝑖-th person has 𝑎𝑖 gold. If 𝑎𝑖≥𝑘, Robin will take all 𝑎𝑖 gold, and if 𝑎𝑖=0, Robin will give 1 gold if he has any. Robin starts with 0 gold.

Find out how many people Robin gives gold to.

Input
The first line of the input contains a single integer 𝑡 (1≤𝑡≤104) — the number of test cases.

The first line of each test case contains two integers 𝑛, 𝑘 (1≤𝑛≤50,1≤𝑘≤100) — the number of people and the threshold at which Robin Hood takes the gold.

The second line of each test case contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (0≤𝑎𝑖≤100) — the gold of each person.

Output
For each test case, output a single integer, the number of people that will get gold from Robin Hood.

Example
inputCopy
4
2 2
2 0
3 2
3 0 0
6 2
0 3 0 0 0 0
2 5
5 4
outputCopy
1
2
3
0
Note
In the first test case, Robin takes 2 gold from the first person and gives a gold to the second person.

In the second test case, Robin takes 3 gold and gives 1 gold to each of the next 2 people.

In the third test case, Robin takes 3 gold and so only gives gold to 3 other people.
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
    // Greedy brute force implementation.
    //
    // Time: O(n)
    // Space: O(1)

    int n, k;
    cin >> n >> k;
    vi a(n);
    trav(i, a) cin >> i;

    int res = 0;
    int curr = 0;
    trav(i, a) {
        if (i >= k) curr += i;
        else if (i == 0 && curr > 0) curr--, res++;
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
