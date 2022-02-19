/* CF - 1100 */
/*
B. Odd Swap Sort
time limit per test1 second
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
. You can perform operations on the array. In each operation you can choose an integer ??
i
 (1²??<??
1
²
i
<
n
), and swap elements ????
a
i
 and ????+1
a
i
+
1
 of the array, if ????+????+1
a
i
+
a
i
+
1
 is odd.

Determine whether it can be sorted in non-decreasing order using this operation any number of times.

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
) Ñ the length of the array.

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
) Ñ the elements of the array.

It is guaranteed that the sum of ??
n
 over all test cases does not exceed 2?105
2
?
10
5
.

Output
For each test case, print "Yes" or "No" depending on whether you can or can not sort the given array.

You may print each letter in any case (for example, "YES", "Yes", "yes", "yEs" will all be recognized as positive answer).

Example
inputCopy
4
4
1 6 31 14
2
4 2
5
2 9 6 7 10
3
6 6 6
outputCopy
Yes
No
No
Yes
Note
In the first test case, we can simply swap 31
31
 and 14
14
 (31+14=45
31
+
14
=
45
 which is odd) and obtain the non-decreasing array [1,6,14,31]
[
1
,
6
,
14
,
31
]
.

In the second test case, the only way we could sort the array is by swapping 4
4
 and 2
2
, but this is impossible, since their sum 4+2=6
4
+
2
=
6
 is even.

In the third test case, there is no way to make the array non-decreasing.

In the fourth test case, the array is already non-decreasing.
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

bool solve(vi& a) {
    int prevOdd = -1, prevEven = -1;

    trav(i, a) {
        if (i % 2 == 0) {
            if (i >= prevEven) {
                prevEven = i;
            } else {
                return false;
            }
        } else {
            if (i >= prevOdd) {
                prevOdd = i;
            } else {
                return false;
            }
        }
    }

    return true;
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

        cout << (solve(a) ? "YES" : "NO") << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
