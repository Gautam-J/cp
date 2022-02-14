/* CF - 800 */
/*
A. C+=
time limit per test2 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
Leo has developed a new programming language C+=. In C+=, integer variables can only be changed with a "+=" operation that adds the right-hand side value to the left-hand side variable. For example, performing "a += b" when a = 2
2
, b = 3
3
 changes the value of a to 5
5
(the value of b does not change).

In a prototype program Leo has two integer variables a and b, initialized with some positive values. He can perform any number of operations "a += b" or "b += a". Leo wants to test handling large integers, so he wants to make the value of either a or b strictly greater than a given value ??
n
. What is the smallest number of operations he has to perform?

Input
The first line contains a single integer ??
T
 (1²??²100
1
²
T
²
100
) Ñ the number of test cases.

Each of the following ??
T
 lines describes a single test case, and contains three integers ??,??,??
a
,
b
,
n
 (1²??,??²??²109
1
²
a
,
b
²
n
²
10
9
) Ñ initial values of a and b, and the value one of the variables has to exceed, respectively.

Output
For each test case print a single integer Ñ the smallest number of operations needed. Separate answers with line breaks.

Example
inputCopy
2
1 2 3
5 4 100
outputCopy
2
7
Note
In the first case we cannot make a variable exceed 3
3
 in one operation. One way of achieving this in two operations is to perform "b += a" twice.
*/

/* Time Complexity: O(lg n) */
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

int solve(int a, int b, int n) {
    int cnt = 0, sum = 0;

    while (sum <= n) {
        if (a > b) {
            b += a;
            sum = b;
            cnt++;
        } else {
            a += b;
            sum = a;
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, a, b, n;
    cin >> t;

    while (t--) {
        cin >> a >> b >> n;
        cout << solve(a, b, n) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
