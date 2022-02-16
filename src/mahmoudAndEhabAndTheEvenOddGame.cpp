/* CF - 800 */
/*
A. Mahmoud and Ehab and the even-odd game
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Mahmoud and Ehab play a game called the even-odd game. Ehab chooses his favorite integer n and then they take turns, starting from Mahmoud. In each player's turn, he has to choose an integer a and subtract it from n such that:

1?²?a?²?n.
If it's Mahmoud's turn, a has to be even, but if it's Ehab's turn, a has to be odd.
If the current player can't choose any number satisfying the conditions, he loses. Can you determine the winner if they both play optimally?

Input
The only line contains an integer n (1?²?n?²?109), the number at the beginning of the game.

Output
Output "Mahmoud" (without quotes) if Mahmoud wins and "Ehab" (without quotes) otherwise.

Examples
inputCopy
1
outputCopy
Ehab
inputCopy
2
outputCopy
Mahmoud
Note
In the first sample, Mahmoud can't choose any integer a initially because there is no positive even integer less than or equal to 1 so Ehab wins.

In the second sample, Mahmoud has to choose a?=?2 and subtract it from n. It's Ehab's turn and n?=?0. There is no positive odd integer less than or equal to 0 so Mahmoud wins.
*/

/* Time Complexity: O(1) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

template<typename T> T gcd(T a, T b) { return ( b ? __gcd(a, b) : a); }
template<typename T> T lcm(T a, T b) { return (a * (b / gcd(a, b))); }

#define forn(i, n) for (int i = 0; i < n; i++)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; i++)
#define trav(i, a) for (auto& i : a)
#define all(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define SHUF(v) shuffle(all(v), mt_rand)
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

// mt19937_64 for 64 bit random numbers
mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());

const char nl = '\n';
/* const ld PI = acos(-1.0); */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if (n % 2 == 0)
        cout << "Mahmoud" << nl;
    else
        cout << "Ehab" << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
