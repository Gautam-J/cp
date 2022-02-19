/* CF - 800 */
/*
A. Reverse
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
 of length ??
n
. You have to choose two integers ??,??
l
,
r
 (1²??²??²??
1
²
l
²
r
²
n
) and reverse the subsegment [??,??]
[
l
,
r
]
 of the permutation. The permutation will become ??1,??2,É,?????1,????,?????1,É,????,????+1,????+2,É,????
p
1
,
p
2
,
É
,
p
l
?
1
,
p
r
,
p
r
?
1
,
É
,
p
l
,
p
r
+
1
,
p
r
+
2
,
É
,
p
n
.

Find the lexicographically smallest permutation that can be obtained by performing exactly one reverse operation on the initial permutation.

Note that for two distinct permutations of equal length ??
a
 and ??
b
, ??
a
 is lexicographically smaller than ??
b
 if at the first position they differ, ??
a
 has the smaller element.

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
 (1²??²500
1
²
t
²
500
) Ñ the number of test cases. Description of the test cases follows.

The first line of each test case contains a single integer ??
n
 (1²??²500
1
²
n
²
500
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

Output
For each test case print the lexicographically smallest permutation you can obtain.

Example
inputCopy
4
1
1
3
2 1 3
4
1 4 2 3
5
1 2 3 4 5
outputCopy
1
1 2 3
1 2 4 3
1 2 3 4 5
Note
In the first test case, the permutation has length 1
1
, so the only possible segment is [1,1]
[
1
,
1
]
. The resulting permutation is [1]
[
1
]
.

In the second test case, we can obtain the identity permutation by reversing the segment [1,2]
[
1
,
2
]
. The resulting permutation is [1,2,3]
[
1
,
2
,
3
]
.

In the third test case, the best possible segment is [2,3]
[
2
,
3
]
. The resulting permutation is [1,2,4,3]
[
1
,
2
,
4
,
3
]
.

In the fourth test case, there is no lexicographically smaller permutation, so we can leave it unchanged by choosing the segment [1,1]
[
1
,
1
]
. The resulting permutation is [1,2,3,4,5]
[
1
,
2
,
3
,
4
,
5
]
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

void solve(vi& a) {
    int n = sz(a), l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != i + 1) {
            l = i;
            break;
        }
    }

    for (int i = l; i < n; i++) {
        if (a[i] == l + 1) {
            r = i;
            break;
        }
    }

    for (int i = 0; i < l; i++)
        cout << a[i] << " ";
    for (int i = r; i >= l; i--)
        cout << a[i] << " ";
    for (int i = r + 1; i < n; i++)
        cout << a[i] << " ";
    cout << nl;
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

        solve(a);
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
