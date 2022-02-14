/* CF - 1000 */
/*
A. Game 23
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp plays "Game 23". Initially he has a number ??
n
 and his goal is to transform it to ??
m
. In one move, he can multiply ??
n
 by 2
2
 or multiply ??
n
 by 3
3
. He can perform any number of moves.

Print the number of moves needed to transform ??
n
 to ??
m
. Print -1 if it is impossible to do so.

It is easy to prove that any way to transform ??
n
 to ??
m
 contains the same number of moves (i.e. number of moves doesn't depend on the way of transformation).

Input
The only line of the input contains two integers ??
n
 and ??
m
 (1²??²??²5?108
1
²
n
²
m
²
5
?
10
8
).

Output
Print the number of moves to transform ??
n
 to ??
m
, or -1 if there is no solution.

Examples
inputCopy
120 51840
outputCopy
7
inputCopy
42 42
outputCopy
0
inputCopy
48 72
outputCopy
-1
Note
In the first example, the possible sequence of moves is: 120?240?720?1440?4320?12960?25920?51840.
120
?
240
?
720
?
1440
?
4320
?
12960
?
25920
?
51840.
 The are 7
7
 steps in total.

In the second example, no moves are needed. Thus, the answer is 0
0
.

In the third example, it is impossible to transform 48
48
 to 72
72
.
*/

/* Time Complexity: O(m) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

template<typename T> T gcd(T a, T b) { return ( b ? __gcd(a, b) : a); }
template<typename T> T lcm(T a, T b) { return (a * (b / gcd(a, b))); }

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define trav(i, a) for (auto& i : a)
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
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< pi > vpi;

// mt19937_64 for 64 bit random numbers
mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());

const char nl = '\n';
const double PI = acos(-1);

int solve(int n, int m) {
    if (m % n != 0)
        return -1;

    int d = m / n;
    // assert d = 2^x * 3^y

    int cnt = 0;
    while (d % 2 == 0) {
        d /= 2;
        cnt++;
    }

    while (d % 3 == 0) {
        d /= 3;
        cnt++;
    }

    return d == 1 ? cnt : -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    cout << solve(n, m) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
