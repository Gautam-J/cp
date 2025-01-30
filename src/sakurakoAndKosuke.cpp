// CF - 800

/*
A. Sakurako and Kosuke
time limit per test1 second
memory limit per test256 megabytes
Sakurako and Kosuke decided to play some games with a dot on a coordinate line. The dot is currently located in position 𝑥=0. They will be taking turns, and Sakurako will be the one to start.

On the 𝑖-th move, the current player will move the dot in some direction by 2⋅𝑖−1 units. Sakurako will always be moving the dot in the negative direction, whereas Kosuke will always move it in the positive direction.

In other words, the following will happen:

Sakurako will change the position of the dot by −1, 𝑥=−1 now
Kosuke will change the position of the dot by 3, 𝑥=2 now
Sakurako will change the position of the dot by −5, 𝑥=−3 now
⋯
They will keep on playing while the absolute value of the coordinate of the dot does not exceed 𝑛. More formally, the game continues while −𝑛≤𝑥≤𝑛. It can be proven that the game will always end.

Your task is to determine who will be the one who makes the last turn.

Input
The first line contains one integer 𝑡 (1≤𝑡≤100) — the number of games that Sakurako and Kosuke played.

Each game is described by one number 𝑛 (1≤𝑛≤100) — the number that defines the condition when the game ends.

Output
For each of the 𝑡 games, output a line with the result of that game. If Sakurako makes the last turn, output "Sakurako" (without quotes); else output "Kosuke".

Example
inputCopy
4
1
6
3
98
outputCopy
Kosuke
Sakurako
Kosuke
Sakurako
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
    // Brute force would work too, but if n is odd then Kosuke wins.
    //
    // Time: O(1)
    // Space: O(1)

    int n;
    cin >> n;
    cout << (n & 1 ? "Kosuke" : "Sakurako") << nl;
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
