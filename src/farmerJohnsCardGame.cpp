// CF

/*
B. Farmer John's Card Game
time limit per test2 seconds
memory limit per test256 megabytes
Farmer John's 𝑛 cows are playing a card game! Farmer John has a deck of 𝑛⋅𝑚 cards numbered from 0 to 𝑛⋅𝑚−1. He distributes 𝑚 cards to each of his 𝑛 cows.

Farmer John wants the game to be fair, so each cow should only be able to play 1 card per round. He decides to determine a turn order, determined by a permutation∗ 𝑝 of length 𝑛, such that the 𝑝𝑖'th cow will be the 𝑖'th cow to place a card on top of the center pile in a round.

In other words, the following events happen in order in each round:

The 𝑝1'th cow places any card from their deck on top of the center pile.
The 𝑝2'th cow places any card from their deck on top of the center pile.
...
The 𝑝𝑛'th cow places any card from their deck on top of the center pile.
There is a catch. Initially, the center pile contains a card numbered −1. In order to place a card, the number of the card must be greater than the number of the card on top of the center pile. Then, the newly placed card becomes the top card of the center pile. If a cow cannot place any card in their deck, the game is considered to be lost.

Farmer John wonders: does there exist 𝑝 such that it is possible for all of his cows to empty their deck after playing all 𝑚 rounds of the game? If so, output any valid 𝑝. Otherwise, output −1.

∗A permutation of length 𝑛 contains each integer from 1 to 𝑛 exactly once
Input
The first line contains an integer 𝑡 (1≤𝑡≤400) — the number of test cases.

The first line of each test case contains two integers 𝑛 and 𝑚 (1≤𝑛⋅𝑚≤2000) — the number of cows and the number of cards each cow receives.

The following 𝑛 lines contain 𝑚 integers each – the cards received by each cow. It is guaranteed all given numbers (across all 𝑛 lines) are distinct and in the range from 0 to 𝑛⋅𝑚−1, inclusive.

It is guaranteed the sum of 𝑛⋅𝑚 over all test cases does not exceed 2000.

Output
For each test case, output the following on a new line:

If 𝑝 exists, output 𝑛 space-separated integers 𝑝1,𝑝2,…,𝑝𝑛.
Otherwise, output −1.
Example
inputCopy
4
2 3
0 4 2
1 5 3
1 1
0
2 2
1 2
0 3
4 1
1
2
0
3
outputCopy
1 2
1
-1
3 1 2 4
Note
In the first test case, one turn order that allows all cards to be played is by having the first cow go before the second cow. The cards played will be 0→1→2→3→4→5.

In the second test case, there is only one cow, so having the cow play all of her cards in increasing order will empty the deck.

In the third test case, it can be shown there is no valid turn order that allows all cards to be played.
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
    // Sort the cards of each cow, the difference between each adjacent card
    // should be exactly n. Else no solution.
    //
    // For every deck dealt to each cow, save the cow number against min element
    // to get the permutation.
    //
    // Time: O(n m log m)
    // Space: O(1)

    int n, m;
    cin >> n >> m;

    vi perm(n, 0);
    int cow = 1;
    vvi a(n, vi(m, 0));
    trav(r, a) {
        trav(c, r)
            cin >> c;

        int min_e = *min_element(allit(r));
        if (min_e < n)
            perm[min_e] = cow++;
    }

    trav(r, a)
        sort(allit(r));

    trav(r, a) {
        forn(i, 1, m) {
            if (r[i] - r[i - 1] != n) {
                cout << -1 << nl;
                return;
            }
        }
    }

    trav(i, perm)
        cout << i << " ";
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
