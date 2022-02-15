/* CF - 1300 */
/*
B. OR in Matrix
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Let's define logical OR as an operation on two logical values (i. e. values that belong to the set {0,?1}) that is equal to 1 if either or both of the logical values is set to 1, otherwise it is 0. We can define logical OR of three or more logical values in the same manner:

 where  is equal to 1 if some ai?=?1, otherwise it is equal to 0.

Nam has a matrix A consisting of m rows and n columns. The rows are numbered from 1 to m, columns are numbered from 1 to n. Element at row i (1?²?i?²?m) and column j (1?²?j?²?n) is denoted as Aij. All elements of A are either 0 or 1. From matrix A, Nam creates another matrix B of the same size using formula:

.

(Bij is OR of all elements in row i and column j of matrix A)

Nam gives you matrix B and challenges you to guess matrix A. Although Nam is smart, he could probably make a mistake while calculating matrix B, since size of A can be large.

Input
The first line contains two integer m and n (1?²?m,?n?²?100), number of rows and number of columns of matrices respectively.

The next m lines each contain n integers separated by spaces describing rows of matrix B (each element of B is either 0 or 1).

Output
In the first line, print "NO" if Nam has made a mistake when calculating B, otherwise print "YES". If the first line is "YES", then also print m rows consisting of n integers representing matrix A that can produce given matrix B. If there are several solutions print any one.

Examples
inputCopy
2 2
1 0
0 0
outputCopy
NO
inputCopy
2 3
1 1 1
1 1 1
outputCopy
YES
1 1 1
1 1 1
inputCopy
2 3
0 1 0
1 1 1
outputCopy
YES
0 0 0
0 1 0
*/

// Can implement in O(n * m) time also

/* Time Complexity: O(n * m * (n + m)) */
/* Space Complexity: O(n * m) */

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
const ld PI = acos(-1.0);

void solve(vvi& b, int m, int n) {
    vvi a(m, vi(n, 1));
    vvi c(m, vi(n, 0));

    forn(i, m) {
        forn(j, n) {
            if (b[i][j] == 0) {
                forn(k, n)
                    a[i][k] = 0;
                forn(k, m)
                    a[k][j] = 0;
            }
        }
    }

    forn(i, m) {
        forn(j, n) {
            if (a[i][j]) {
                forn(k, n)
                    c[i][k] = 1;
                forn(k, m)
                    c[k][j] = 1;
            }
        }
    }

    if (b != c)
        cout << "NO" << nl;
    else {
        cout << "YES" << nl;
        trav(i, a) {
            trav(j, i)
                cout << j << " ";
            cout << nl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    vvi b(m, vi(n));
    trav(i, b) {
        trav(j, i)
            cin >> j;
    }

    solve(b, m, n);

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
