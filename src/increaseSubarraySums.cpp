/* CR - 1400 */
/*
C. Increase Subarray Sums
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array ??1,??2,É,????
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
, consisting of ??
n
 integers. You are also given an integer value ??
x
.

Let ??(??)
f
(
k
)
 be the maximum sum of a contiguous subarray of ??
a
 after applying the following operation: add ??
x
 to the elements on exactly ??
k
distinct positions. An empty subarray should also be considered, it has sum 0
0
.

Note that the subarray doesn't have to include all of the increased elements.

Calculate the maximum value of ??(??)
f
(
k
)
 for all ??
k
 from 0
0
 to ??
n
 independently.

Input
The first line contains a single integer ??
t
 (1²??²5000
1
²
t
²
5000
) Ñ the number of testcases.

The first line of the testcase contains two integers ??
n
 and ??
x
 (1²??²5000
1
²
n
²
5000
; 0²??²105
0
²
x
²
10
5
) Ñ the number of elements in the array and the value to add.

The second line contains ??
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
 (?105²????²105
?
10
5
²
a
i
²
10
5
).

The sum of ??
n
 over all testcases doesn't exceed 5000
5000
.

Output
For each testcase, print ??+1
n
+
1
 integers Ñ the maximum value of ??(??)
f
(
k
)
 for all ??
k
 from 0
0
 to ??
n
 independently.

Example
inputCopy
3
4 2
4 1 3 2
3 5
-2 -7 -1
10 2
-6 -1 -2 4 -6 -1 -4 4 -5 -4
outputCopy
10 12 14 16 18
0 4 4 5
4 6 6 7 7 7 7 8 8 8 8
Note
In the first testcase, it doesn't matter which elements you add ??
x
 to. The subarray with the maximum sum will always be the entire array. If you increase ??
k
 elements by ??
x
, ?????
k
?
x
 will be added to the sum.

In the second testcase:

For ??=0
k
=
0
, the empty subarray is the best option.
For ??=1
k
=
1
, it's optimal to increase the element at position 3
3
. The best sum becomes ?1+5=4
?
1
+
5
=
4
 for a subarray [3,3]
[
3
,
3
]
.
For ??=2
k
=
2
, it's optimal to increase the element at position 3
3
 and any other element. The best sum is still 4
4
 for a subarray [3,3]
[
3
,
3
]
.
For ??=3
k
=
3
, you have to increase all elements. The best sum becomes (?2+5)+(?7+5)+(?1+5)=5
(
?
2
+
5
)
+
(
?
7
+
5
)
+
(
?
1
+
5
)
=
5
 for a subarray [1,3]
[
1
,
3
]
.
*/

/* Time Complexity: O(n^2) */
/* Space Complexity: O(n) */

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

void solve(vi& a, int x) {
    // for each value k,
    // find the contiguous subsegment of length k that gives the maximum sum
    // Add x to all elements, find the new sum
    // if the sum of k is greater than all 0 to k - 1, output new sum or prev best

    int n = sz(a);
    vi mx(n + 1, imin);
    mx[0] = 0;

    int s;
    forn(l, n) {
        s = 0;
        fore(r, l, n - 1) {
            s += a[r];
            mx[r - l + 1] = max(mx[r - l + 1], s);
        }
    }

    vi ans(n + 1);
    int bst;
    forn(k, n + 1) {
        bst = 0;
        forn(i, n + 1)
            bst = max(bst, mx[i] + min(k, i) * x);
        ans[k] = bst;
    }

    trav(i, ans)
        cout << i << " ";
    cout << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, x;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        vi a(n);
        trav(i, a)
            cin >> i;
        solve(a, x);
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
