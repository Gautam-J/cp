/* CF - 800 */
/*
A. Sum of Round Numbers
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A positive (strictly greater than zero) integer is called round if it is of the form d00...0. In other words, a positive integer is round if all its digits except the leftmost (most significant) are equal to zero. In particular, all numbers from 1
1
 to 9
9
 (inclusive) are round.

For example, the following numbers are round: 4000
4000
, 1
1
, 9
9
, 800
800
, 90
90
. The following numbers are not round: 110
110
, 707
707
, 222
222
, 1001
1001
.

You are given a positive integer ??
n
 (1²??²104
1
²
n
²
10
4
). Represent the number ??
n
 as a sum of round numbers using the minimum number of summands (addends). In other words, you need to represent the given number ??
n
 as a sum of the least number of terms, each of which is a round number.

Input
The first line contains an integer ??
t
 (1²??²104
1
²
t
²
10
4
) Ñ the number of test cases in the input. Then ??
t
 test cases follow.

Each test case is a line containing an integer ??
n
 (1²??²104
1
²
n
²
10
4
).

Output
Print ??
t
 answers to the test cases. Each answer must begin with an integer ??
k
 Ñ the minimum number of summands. Next, ??
k
 terms must follow, each of which is a round number, and their sum is ??
n
. The terms can be printed in any order. If there are several answers, print any of them.

Example
inputCopy
5
5009
7
9876
10000
10
outputCopy
2
5000 9
1
7
4
800 70 6 9000
1
10000
1
10
*/

/* Time Complexity: O(log_10 n) */
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

void solve(int n) {
    int digit, i = 0;
    vi ans;

    while (n) {
        digit = n % 10;
        if (digit != 0) {
            ans.push_back((pow(10, i)) * digit);
        }
        n /= 10;
        i++;
    }
    cout << sz(ans) << nl;

    trav(j, ans)
        cout << j << " ";
    cout << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        solve(n);
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
