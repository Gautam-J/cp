/* CF - 800 */
/*
A. Floor Number
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vasya goes to visit his classmate Petya. Vasya knows that Petya's apartment number is ??
n
.

There is only one entrance in Petya's house and the distribution of apartments is the following: the first floor contains 2
2
 apartments, every other floor contains ??
x
 apartments each. Apartments are numbered starting from one, from the first floor. I.e. apartments on the first floor have numbers 1
1
 and 2
2
, apartments on the second floor have numbers from 3
3
 to (??+2)
(
x
+
2
)
, apartments on the third floor have numbers from (??+3)
(
x
+
3
)
 to (2???+2)
(
2
?
x
+
2
)
, and so on.

Your task is to find the number of floor on which Petya lives. Assume that the house is always high enough to fit at least ??
n
 apartments.

You have to answer ??
t
 independent test cases.

Input
The first line of the input contains one integer ??
t
 (1²??²1000
1
²
t
²
1000
) Ñ the number of test cases. Then ??
t
 test cases follow.

The only line of the test case contains two integers ??
n
 and ??
x
 (1²??,??²1000
1
²
n
,
x
²
1000
) Ñ the number of Petya's apartment and the number of apartments on each floor of the house except the first one (there are two apartments on the first floor).

Output
For each test case, print the answer: the number of floor on which Petya lives.

Example
inputCopy
4
7 3
1 5
22 5
987 13
outputCopy
3
1
5
77
Note
Consider the first test case of the example: the first floor contains apartments with numbers 1
1
 and 2
2
, the second one contains apartments with numbers 3
3
, 4
4
 and 5
5
, the third one contains apartments with numbers 6
6
, 7
7
 and 8
8
. Therefore, Petya lives on the third floor.

In the second test case of the example, Petya lives in the apartment 1
1
 which is on the first floor.
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

int solve(int n, int x) {
    if (n <= 2)
        return 1;

    return ((n - 3) / x) + 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, x;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        cout << solve(n, x) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
