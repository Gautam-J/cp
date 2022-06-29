/* CF */
/*
There are ??
n
 piles of sand where the ??
i
-th pile has ????
a
i
 blocks of sand. The ??
i
-th pile is called too tall if 1<??<??
1
<
i
<
n
 and ????>?????1+????+1
a
i
>
a
i
?
1
+
a
i
+
1
. That is, a pile is too tall if it has more sand than its two neighbours combined. (Note that piles on the ends of the array cannot be too tall.)

You are given an integer ??
k
. An operation consists of picking ??
k
 consecutive piles of sand and adding one unit of sand to them all. Formally, pick 1²??,??²??
1
²
l
,
r
²
n
 such that ?????+1=??
r
?
l
+
1
=
k
. Then for all ??²??²??
l
²
i
²
r
, update ?????????+1
a
i
?
a
i
+
1
.

What is the maximum number of piles that can simultaneously be too tall after some (possibly zero) operations?

Input
The input consists of multiple test cases. The first line contains an integer ??
t
 (1²??²1000
1
²
t
²
1000
) Ñ the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers ??
n
 and ??
k
 (3²??²2?105
3
²
n
²
2
?
10
5
; 1²??²??
1
²
k
²
n
) Ñ the number of piles of sand and the size of the operation, respectively.

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
 (1²????²109
1
²
a
i
²
10
9
) Ñ the sizes of the piles.

It is guaranteed that the sum of ??
n
 over all test cases does not exceed 2?105
2
?
10
5
.

Output
For each test case, output a single integer Ñ the maximum number of piles that are simultaneously too tall after some (possibly zero) operations.

Example
inputCopy
3
5 2
2 9 2 4 1
4 4
1 3 2 1
3 1
1 3 1
outputCopy
2
0
1
Note
In the first test case, we can perform the following three operations:

Add one unit of sand to piles 1
1
 and 2
2
: [3,10,2,4,1]
[
3
,
10
,
2
,
4
,
1
]
.
Add one unit of sand to piles 4
4
 and 5
5
: [3,10,2,5,2]
[
3
,
10
,
2
,
5
,
2
]
.
Add one unit of sand to piles 3
3
 and 4
4
: [3,10,3,6,2]
[
3
,
10
,
3
,
6
,
2
]
.
Now piles 2
2
 and 4
4
 are too tall, so in this case the answer is 2
2
. It can be shown that it is impossible to make more than 2
2
 piles too tall.
In the second test case, any operation will increase all piles by 1
1
 unit, so the number of too tall piles will always be 0
0
.

In the third test case, we can increase any pile by 1
1
 unit of sand. It can be shown that the maximum number of too tall piles is 1
1
.
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

#define forn(i, n) for (int i = 0; i < n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
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

int solve(vi& a, int k) {
    // Algorithm:
    // If k == 1, then we can make every other pile greater
    // by how many ever times we want, except for the first and last pile.
    // Thus, we return floor((n - 1) / 2)
    //
    // If k > 1, then no matter how many ever operations we perform, the
    // number of too tall towers will remain the same, since we can't
    // individually increase a pile, without increasing it's neighbor.
    // Thus the answer will be the number of too tall piles in the given
    // array itself.
    //
    // Time: O(n)
    // Space: O(1)

    int res = 0, n = sz(a);

    if (k == 1)
        return (n - 1) / 2;

    fore(i, 1, n - 2) {
        if (a[i] > a[i - 1] + a[i + 1])
            res++;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vi a(n);
        trav(i, a)
            cin >> i;

        cout << solve(a, k) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
