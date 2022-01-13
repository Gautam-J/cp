/* CF - 800 */
/*
A. Stable Arrangement of Rooks
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You have an n×n chessboard and k rooks. Rows of this chessboard are numbered by integers from 1 to n from top to bottom and columns of this chessboard are numbered by integers from 1 to n from left to right. The cell (x,y) is the cell on the intersection of row x and collumn y for 1≤x≤n and 1≤y≤n.

The arrangement of rooks on this board is called good, if no rook is beaten by another rook.

A rook beats all the rooks that shares the same row or collumn with it.

The good arrangement of rooks on this board is called not stable, if it is possible to move one rook to the adjacent cell so arrangement becomes not good. Otherwise, the good arrangement is stable. Here, adjacent cells are the cells that share a side.

Such arrangement of 3 rooks on the 4×4 chessboard is good, but it is not stable: the rook from (1,1) can be moved to the adjacent cell (2,1) and rooks on cells (2,1) and (2,4) will beat each other.
Please, find any stable arrangement of k rooks on the n×n chessboard or report that there is no such arrangement.

Input
The first line contains a single integer t (1≤t≤100) — the number of test cases.

The first line of each test case contains two integers n, k (1≤k≤n≤40) — the size of the chessboard and the number of rooks.

Output
If there is a stable arrangement of k rooks on the n×n chessboard, output n lines of symbols . and R. The j-th symbol of the i-th line should be equals R if and only if there is a rook on the cell (i,j) in your arrangement.

If there are multiple solutions, you may output any of them.

If there is no stable arrangement, output −1.

Example
inputCopy
5
3 2
3 3
1 1
5 2
40 33
outputCopy
..R
...
R..
-1
R
.....
R....
.....
....R
.....
-1
Note
In the first test case, you should find stable arrangement of 2 rooks on the 3×3 chessboard. Placing them in cells (3,1) and (1,3) gives stable arrangement.

In the second test case it can be shown that it is impossbile to place 3 rooks on the 3×3 chessboard to get stable arrangement.

*/

/* Time Complexity: O(k) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

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

void solve(int n, int k) {
    if ((ceil((float)n / 2.0)) < k) {  //  ceil(n / 2) OR floor((n + 1) / 2)
        cout << -1 << nl;
        return;
    }

    vector<vector<char> > a(n, vector<char>(n, '.'));

    for (int i = 0; i < k; i++)
        a[2 * i][2 * i] = 'R';

    trav(i, a) {
        trav(j, i)
            cout << j;
        cout << nl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, k;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        solve(n, k);
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
