/* CF - 1300 */
/*
C. Inversion Graph
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a permutation ??1,??2,É,????
p
1
,
p
2
,
É
,
p
n
. Then, an undirected graph is constructed in the following way: add an edge between vertices ??
i
, ??
j
 such that ??<??
i
<
j
 if and only if ????>????
p
i
>
p
j
. Your task is to count the number of connected components in this graph.

Two vertices ??
u
 and ??
v
 belong to the same connected component if and only if there is at least one path along edges connecting ??
u
 and ??
v
.

A permutation is an array consisting of ??
n
 distinct integers from 1
1
 to ??
n
 in arbitrary order. For example, [2,3,1,5,4]
[
2
,
3
,
1
,
5
,
4
]
 is a permutation, but [1,2,2]
[
1
,
2
,
2
]
 is not a permutation (2
2
 appears twice in the array) and [1,3,4]
[
1
,
3
,
4
]
 is also not a permutation (??=3
n
=
3
 but there is 4
4
 in the array).

Input
Each test contains multiple test cases. The first line contains a single integer ??
t
 (1²??²105
1
²
t
²
10
5
) Ñ the number of test cases. Description of the test cases follows.

The first line of each test case contains a single integer ??
n
 (1²??²105
1
²
n
²
10
5
) Ñ the length of the permutation.

The second line of each test case contains ??
n
 integers ??1,??2,É,????
p
1
,
p
2
,
É
,
p
n
 (1²????²??
1
²
p
i
²
n
) Ñ the elements of the permutation.

It is guaranteed that the sum of ??
n
 over all test cases does not exceed 2?105
2
?
10
5
.

Output
For each test case, print one integer ??
k
 Ñ the number of connected components.

Example
inputCopy
6
3
1 2 3
5
2 1 4 3 5
6
6 1 4 2 5 3
1
1
6
3 2 1 6 5 4
5
3 1 5 2 4
outputCopy
3
3
1
1
2
1
Note
Each separate test case is depicted in the image below. The colored squares represent the elements of the permutation. For one permutation, each color represents some connected component. The number of distinct colors is the answer.
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

int solve(vi& a) {
    int n = sz(a);
    int maxEl = 0, cnt = 0;

    forn(i, n) {
        maxEl = max(maxEl, a[i]);
        if (maxEl == i + 1)
            cnt++;
    }

    return cnt;
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
