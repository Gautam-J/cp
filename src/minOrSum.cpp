
/*
A. Min Or Sum
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array ??
a
 of size ??
n
.

You can perform the following operation on the array:

Choose two different integers ??,??
i
,
j
 (1²??<??²??
(
1
²
i
<
j
²
n
), replace ????
a
i
 with ??
x
 and ????
a
j
 with ??
y
. In order not to break the array, ????|????=??|??
a
i
|
a
j
=
x
|
y
 must be held, where |
|
 denotes the bitwise OR operation. Notice that ??
x
 and ??
y
 are non-negative integers.
Please output the minimum sum of the array you can get after using the operation above any number of times.

Input
Each test contains multiple test cases. The first line contains the number of test cases ??
t
 (1²??²1000)
(
1
²
t
²
1000
)
. Description of the test cases follows.

The first line of each test case contains an integer ??
n
 (2²??²100)
(
2
²
n
²
100
)
 Ñ the size of array ??
a
.

The second line of each test case contains ??
n
 integers ??1,??2,É,????
a
1
,
a
2
,
É
,
a
n
 (0²????<230)
(
0
²
a
i
<
2
30
)
.

Output
For each test case, print one number in a line Ñ the minimum possible sum of the array.

Example
inputCopy
4
3
1 3 2
5
1 2 4 8 16
2
6 6
3
3 5 6
outputCopy
3
31
6
7
Note
In the first example, you can perform the following operations to obtain the array [1,0,2]
[
1
,
0
,
2
]
:

1. choose ??=1,??=2
i
=
1
,
j
=
2
, change ??1=1
a
1
=
1
 and ??2=2
a
2
=
2
, it's valid since 1|3=1|2
1
|
3
=
1
|
2
. The array becomes [1,2,2]
[
1
,
2
,
2
]
.

2. choose ??=2,??=3
i
=
2
,
j
=
3
, change ??2=0
a
2
=
0
 and ??3=2
a
3
=
2
, it's valid since 2|2=0|2
2
|
2
=
0
|
2
. The array becomes [1,0,2]
[
1
,
0
,
2
]
.

We can prove that the minimum sum is 1+0+2=3
1
+
0
+
2
=
3

In the second example, We don't need any operations.
*/

/* Time Complexity: O(n) */
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
#define allit(a) a.begin(), a.end()
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

int solve(vi& a) {
    int res = 0;
    trav(i, a)
        res |= i;

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vi a(n);
        trav(i, a)
            cin >> i;
        cout << solve(a) << nl;
    }


#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
