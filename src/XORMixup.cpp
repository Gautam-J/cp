/* CF */
/*
There is an array ??
a
 with ???1
n
?
1
 integers. Let ??
x
 be the bitwise XOR of all elements of the array. The number ??
x
 is added to the end of the array ??
a
 (now it has length ??
n
), and then the elements are shuffled.

You are given the newly formed array ??
a
. What is ??
x
? If there are multiple possible values of ??
x
, you can output any of them.

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

The first line of each test case contains an integer ??
n
 (2²??²100
2
²
n
²
100
) Ñ the number of integers in the resulting array ??
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
 (0²????²127
0
²
a
i
²
127
) Ñ the elements of the newly formed array ??
a
.

Additional constraint on the input: the array ??
a
 is made by the process described in the statement; that is, some value of ??
x
 exists.

Output
For each test case, output a single integer Ñ the value of ??
x
, as described in the statement. If there are multiple possible values of ??
x
, output any of them.

Example
inputCopy
4
4
4 3 2 5
5
6 1 10 7 10
6
6 6 6 6 6 6
3
100 100 0
outputCopy
3
7
6
0
Note
In the first test case, one possible array ??
a
 is ??=[2,5,4]
a
=
[
2
,
5
,
4
]
. Then ??=2?5?4=3
x
=
2
?
5
?
4
=
3
 (?
?
 denotes the bitwise XOR), so the new array is [2,5,4,3]
[
2
,
5
,
4
,
3
]
. Afterwards, the array is shuffled to form [4,3,2,5]
[
4
,
3
,
2
,
5
]
.

In the second test case, one possible array ??
a
 is ??=[1,10,6,10]
a
=
[
1
,
10
,
6
,
10
]
. Then ??=1?10?6?10=7
x
=
1
?
10
?
6
?
10
=
7
, so the new array is [1,10,6,10,7]
[
1
,
10
,
6
,
10
,
7
]
. Afterwards, the array is shuffled to form [6,1,10,7,10]
[
6
,
1
,
10
,
7
,
10
]
.

In the third test case, all elements of the array are equal to 6
6
, so ??=6
x
=
6
.

In the fourth test case, one possible array ??
a
 is ??=[100,100]
a
=
[
100
,
100
]
. Then ??=100?100=0
x
=
100
?
100
=
0
, so the new array is [100,100,0]
[
100
,
100
,
0
]
. Afterwards, the array is shuffled to form [100,100,0]
[
100
,
100
,
0
]
. (Note that after the shuffle, the array can remain the same.)
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

int solve(vi& a) {
    // Algorithm:
    // Any number in the given output can be the answer
    //
    // XOR(i, i) = 0
    // XOR(i, 0) = i
    //
    // Assume x = a1 XOR a2 XOR ... XOR aN, i.e. XOR of all elements
    // We can prove that a1 = x XOR a2 XOR a3 XOR ... XOR aN, i.e.
    // a1 will be equal to XOR of all elements (XOR)
    //                     XOR of all elements except a1
    // Thus, all same elements cancel out each other.
    //
    // Time: O(1)
    // Space: O(1)

    return a[0];
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
