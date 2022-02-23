/* CF - 800 */
/*
B. Avoid Local Maximums
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array ??
a
 of size ??
n
. Each element in this array is an integer between 1
1
 and 109
10
9
.

You can perform several operations to this array. During an operation, you can replace an element in the array with any integer between 1
1
and 109
10
9
.

Output the minimum number of operations needed such that the resulting array doesn't contain any local maximums, and the resulting array after the operations.

An element ????
a
i
 is a local maximum if it is strictly larger than both of its neighbors (that is, ????>?????1
a
i
>
a
i
?
1
 and ????>????+1
a
i
>
a
i
+
1
). Since ??1
a
1
 and ????
a
n
 have only one neighbor each, they will never be a local maximum.

Input
Each test contains multiple test cases. The first line will contain a single integer ??
t
 (1²??²10000)
(
1
²
t
²
10000
)
 Ñ the number of test cases. Then ??
t
test cases follow.

The first line of each test case contains a single integer ??
n
 (2²??²2?105)
(
2
²
n
²
2
?
10
5
)
 Ñ the size of the array ??
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
 (1²????²109)
(
1
²
a
i
²
10
9
)
, the elements of array.

It is guaranteed that the sum of ??
n
 over all test cases does not exceed 2?105
2
?
10
5
.

Output
For each test case, first output a line containing a single integer ??
m
 Ñ minimum number of operations required. Then ouput a line consist of ??
n
 integers Ñ the resulting array after the operations. Note that this array should differ in exactly ??
m
 elements from the initial array.

If there are multiple answers, print any.

Example
inputCopy
5
3
2 1 2
4
1 2 3 1
5
1 2 1 2 1
9
1 2 1 3 2 3 1 2 1
9
2 1 3 1 3 1 3 1 3
outputCopy
0
2 1 2
1
1 3 3 1
1
1 2 2 2 1
2
1 2 3 3 2 3 3 2 1
2
2 1 3 3 3 1 1 1 3
Note
In the first example, the array contains no local maximum, so we don't need to perform operations.

In the second example, we can change ??2
a
2
 to 3
3
, then the array don't have local maximums.
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

void solve(vi& a) {
    int n = sz(a), cnt = 0;

    fore(i, 1, n - 2) {
        if (a[i - 1] < a[i] && a[i + 1] < a[i]) {
            if (i < n - 2)
                a[i + 1] = max(a[i], a[i + 2]);
            else
                a[i + 1] = a[i];
            cnt++;
        }
    }

    cout << cnt << nl;
    trav(i, a)
        cout << i << " ";
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
