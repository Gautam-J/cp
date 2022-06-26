
/*
You are given a 1-indexed array of ??
n
 integers, ??
a
, and an integer ??
z
. You can do the following operation any number (possibly zero) of times:

Select a positive integer ??
i
 such that 1²??²??
1
²
i
²
n
. Then, simutaneously set ????
a
i
 to (????or??)
(
a
i
or
?
z
)
 and set ??
z
 to (????and??)
(
a
i
and
?
z
)
. In other words, let ??
x
and ??
y
 respectively be the current values of ????
a
i
 and ??
z
. Then set ????
a
i
 to (??or??)
(
x
or
?
y
)
 and set ??
z
 to (??and??)
(
x
and
?
y
)
.
Here or
or
 and and
and
 denote the bitwise operations OR and AND respectively.

Find the maximum possible value of the maximum value in ??
a
 after any number (possibly zero) of operations.

Input
Each test contains multiple test cases. The first line contains the number of test cases ??
t
 (1²??²100
1
²
t
²
100
). Description of the test cases follows.

The first line of each test case contains two integers ??
n
 and ??
z
 (1²??²2000
1
²
n
²
2000
, 0²??<230
0
²
z
<
2
30
).

The second line of each test case contains ??
n
 integers ??1
a
1
,??2
a
2
,É
É
,????
a
n
 (0²????<230
0
²
a
i
<
2
30
).

It is guaranteed that the sum of ??
n
 over all test cases does not exceed 104
10
4
.

Output
For each test case, print one integer Ñ the answer to the problem.

Example
inputCopy
5
2 3
3 4
5 5
0 2 4 6 8
1 9
10
5 7
7 15 30 29 27
3 39548743
10293834 10284344 13635445
outputCopy
7
13
11
31
48234367
Note
In the first test case of the sample, one optimal sequence of operations is:

Do the operation with ??=1
i
=
1
. Now ??1
a
1
 becomes (3or3)=3
(
3
or
?
3
)
=
3
 and ??
z
 becomes (3and3)=3
(
3
and
?
3
)
=
3
.
Do the operation with ??=2
i
=
2
. Now ??2
a
2
 becomes (4or3)=7
(
4
or
?
3
)
=
7
 and ??
z
 becomes (4and3)=0
(
4
and
?
3
)
=
0
.
Do the operation with ??=1
i
=
1
. Now ??1
a
1
 becomes (3or0)=3
(
3
or
?
0
)
=
3
 and ??
z
 becomes (3and0)=0
(
3
and
?
0
)
=
0
.
After these operations, the sequence ??
a
 becomes [3,7]
[
3
,
7
]
, and the maximum value in it is 7
7
. We can prove that the maximum value in ??
a
 can never exceed 7
7
, so the answer is 7
7
.

In the fourth test case of the sample, one optimal sequence of operations is:

Do the operation with ??=1
i
=
1
. Now ??1
a
1
 becomes (7or7)=7
(
7
or
?
7
)
=
7
 and ??
z
 becomes (7and7)=7
(
7
and
?
7
)
=
7
.
Do the operation with ??=3
i
=
3
. Now ??3
a
3
 becomes (30or7)=31
(
30
or
?
7
)
=
31
 and ??
z
 becomes (30and7)=6
(
30
and
?
7
)
=
6
.
Do the operation with ??=5
i
=
5
. Now ??5
a
5
 becomes (27or6)=31
(
27
or
?
6
)
=
31
 and ??
z
 becomes (27and6)=2
(
27
and
?
6
)
=
2
.
*/

/* Time Complexity: O() */
/* Space Complexity: O() */

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

int solve(vi& a, int z) {
    // Algorithm:
    // Initialize global_max to -inf
    // Traverse through the array, and track the bitwise OR of a[i] and z
    // Return global_max
    //
    // Time: O(n)
    // Space: O(1)

    int globalMax = INT_MIN, localMax;
    forn(i, sz(a)) {
        localMax = a[i] | z;
        globalMax = max(globalMax, localMax);
    }
    return globalMax;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, z;
    cin >> t;
    while (t--) {
        cin >> n >> z;
        vi a(n);
        trav(i, a)
            cin >> i;

        cout << solve(a, z) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
