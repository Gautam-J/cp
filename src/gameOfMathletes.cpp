// CF

/*
C. Game of Mathletes
time limit per test2 seconds
memory limit per test256 megabytes
Alice and Bob are playing a game. There are 𝑛 (𝑛 is even) integers written on a blackboard, represented by 𝑥1,𝑥2,…,𝑥𝑛. There is also a given integer 𝑘 and an integer score that is initially 0. The game lasts for 𝑛2 turns, in which the following events happen sequentially:

Alice selects an integer from the blackboard and erases it. Let's call Alice's chosen integer 𝑎.
Bob selects an integer from the blackboard and erases it. Let's call Bob's chosen integer 𝑏.
If 𝑎+𝑏=𝑘, add 1 to score.
Alice is playing to minimize the score while Bob is playing to maximize the score. Assuming both players use optimal strategies, what is the score after the game ends?

Input
The first line contains an integer 𝑡 (1≤𝑡≤104) — the number of test cases.

The first line of each test case contains two integers 𝑛 and 𝑘 (2≤𝑛≤2⋅105,1≤𝑘≤2⋅𝑛, 𝑛 is even).

The second line of each test case contains 𝑛 integers 𝑥1,𝑥2,…,𝑥𝑛 (1≤𝑥𝑖≤𝑛) — the integers on the blackboard.

It is guaranteed that the sum of 𝑛 over all test cases does not exceed 2⋅105.

Output
For each test case, output the score if both players play optimally.

Example
inputCopy
4
4 4
1 2 3 2
8 15
1 2 3 4 5 6 7 8
6 1
1 1 1 1 1 1
16 9
3 1 4 1 5 9 2 6 5 3 5 8 9 7 9 3
outputCopy
2
1
0
4
Note
In the first test case, one way the game may go is as follows:

Alice selects 1 and Bob selects 3. The score increases as 1+3=4. Now the two integers remaining on the blackboard are 2 and 2.
Alice and Bob both select 2. The score increases as 2+2=4.
The game ends as the blackboard now has no integers.
In the third test case, it is impossible for the sum of Alice and Bob's selected integers to be 1, so we answer 0.

Note that this is just an example of how the game may proceed for demonstration purposes. This may not be Alice or Bob's most optimal strategies.
*/

#include <algorithm>
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
    // Alice's choice does not matter, optimize only Bob's choice.
    //
    // Time: O(n)
    // Space: O(n)

    int n, k;
    cin >> n >> k;

    vi a(n);
    trav(i, a)
        cin >> i;

    umap<int, int> c;
    trav(i, a) {
        if (c.find(i) == c.end())
            c[i] = 1;
        else
            c[i]++;
    }

    int score = 0;
    fore(i, 1, k / 2) {
        if (i == k - i)
            score += c[i] / 2;
        else
            score += min(c[i], c[k - i]);
    }

    cout << score << nl;
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
