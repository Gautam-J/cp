/* CF - 800 */
/*
A. Boring Apartments
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
There is a building consisting of 10 000
10

000
 apartments numbered from 1
1
 to 10 000
10

000
, inclusive.

Call an apartment boring, if its number consists of the same digit. Examples of boring apartments are 11,2,777,9999
11
,
2
,
777
,
9999
 and so on.

Our character is a troublemaker, and he calls the intercoms of all boring apartments, till someone answers the call, in the following order:

First he calls all apartments consisting of digit 1
1
, in increasing order (1,11,111,1111
1
,
11
,
111
,
1111
).
Next he calls all apartments consisting of digit 2
2
, in increasing order (2,22,222,2222
2
,
22
,
222
,
2222
)
And so on.
The resident of the boring apartment ??
x
 answers the call, and our character stops calling anyone further.

Our character wants to know how many digits he pressed in total and your task is to help him to count the total number of keypresses.

For example, if the resident of boring apartment 22
22
 answered, then our character called apartments with numbers 1,11,111,1111,2,22
1
,
11
,
111
,
1111
,
2
,
22
and the total number of digits he pressed is 1+2+3+4+1+2=13
1
+
2
+
3
+
4
+
1
+
2
=
13
.

You have to answer ??
t
 independent test cases.

Input
The first line of the input contains one integer ??
t
 (1²??²36
1
²
t
²
36
) Ñ the number of test cases.

The only line of the test case contains one integer ??
x
 (1²??²9999
1
²
x
²
9999
) Ñ the apartment number of the resident who answered the call. It is guaranteed that ??
x
 consists of the same digit.

Output
For each test case, print the answer: how many digits our character pressed in total.

Example
inputCopy
4
22
9999
1
777
outputCopy
13
90
1
66
*/

/* Time Complexity: O(1) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
#include <string>
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

int solve(string& x) {
    int n = sz(x);
    int number = stoi(x) % 10;

    return ((number - 1) * 10) + (n * (n + 1) / 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    string x;
    while (t--) {
        cin >> x;
        cout << solve(x) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
