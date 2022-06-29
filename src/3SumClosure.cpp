/* CF - C */
/*
You are given an array ??
a
 of length ??
n
. The array is called 3SUM-closed if for all distinct indices ??
i
, ??
j
, ??
k
, the sum ????+????+????
a
i
+
a
j
+
a
k
 is an element of the array. More formally, ??
a
 is 3SUM-closed if for all integers 1²??<??<??²??
1
²
i
<
j
<
k
²
n
, there exists some integer 1²??²??
1
²
l
²
n
 such that ????+????+????=????
a
i
+
a
j
+
a
k
=
a
l
.

Determine if ??
a
 is 3SUM-closed.

Input
The first line contains an integer ??
t
 (1²??²1000
1
²
t
²
1000
) Ñ the number of test cases.

The first line of each test case contains an integer ??
n
 (3²??²2?105
3
²
n
²
2
?
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
 (?109²????²109
?
10
9
²
a
i
²
10
9
) Ñ the elements of the array.

It is guaranteed that the sum of ??
n
 across all test cases does not exceed 2?105
2
?
10
5
.

Output
For each test case, output "YES" (without quotes) if ??
a
 is 3SUM-closed and "NO" (without quotes) otherwise.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes" and "Yes" will be recognized as a positive response).

Example
inputCopy
4
3
-1 0 1
5
1 -2 -2 1 -3
6
0 0 0 0 0 0
4
-1 2 -3 4
outputCopy
YES
NO
YES
NO
Note
In the first test case, there is only one triple where ??=1
i
=
1
, ??=2
j
=
2
, ??=3
k
=
3
. In this case, ??1+??2+??3=0
a
1
+
a
2
+
a
3
=
0
, which is an element of the array (??2=0
a
2
=
0
), so the array is 3SUM-closed.

In the second test case, ??1+??4+??5=?1
a
1
+
a
4
+
a
5
=
?
1
, which is not an element of the array. Therefore, the array is not 3SUM-closed.

In the third test case, ????+????+????=0
a
i
+
a
j
+
a
k
=
0
 for all distinct ??
i
, ??
j
, ??
k
, and 0
0
 is an element of the array, so the array is 3SUM-closed.
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

bool solve() {
    // Algorithm:
    // Careful Brute Force
    // If the array contains at least 3 positive elements,
    // their sum will be greater than the maximum element as the 3 elements
    // will also include the maximum element, for some i, j, k
    // If the array contains at least 3 negative elements,
    // their sum will be smaller than the minimum element as the 3 elements
    // will also include the minimum element, for some i, j, k
    // Thus, if there are more than 2 positive numbers, or
    // more than 2 negative numbers, return false
    //
    // The remaining value is 0. We don't need to iterate through all the 0s.
    // Therefore, we can keep only 2 zeros, and remove the rest of them.
    // This reduces the length of the array to a maximum of 6 elements, i.e.,
    // 2 pos, 2 neg, 2 zeros.
    //
    // This search space is so small that we can effectively apply brute force
    //
    // Time: O(1), or O(6^3) to be specific
    // Space: O(1), or O(6) to be specific
    //
    // Space can be converted into true O(1), by increasing time to O(6^4)

    int n, x;
    cin >> n;
    vi pos, neg, a;

    forn(i, n) {
        cin >> x;
        if (x > 0)
            pos.pb(x);
        else if (x < 0)
            neg.pb(x);
        else if (sz(a) < 2)
            a.pb(x);
    }

    if (sz(pos) > 2 || sz(neg) > 2)
        return false;

    trav(i, pos)
        a.pb(i);
    trav(i, neg)
        a.pb(i);

    uset<int> digits;
    trav(i, a)
        digits.insert(i);

    int localSum, l = sz(a);
    for (int i = 0; i < l; ++i) {
        for (int j = i + 1; j < l; j++) {
            for (int k = j + 1; k < l; k++) {
                localSum = a[i] + a[j] + a[k];
                if (digits.find(localSum) == digits.end())
                    return false;
            }
        }
    }

    return true;
}

bool solve1(vi& a) {
    // Algorithm:
    // Brute Force (TLE)
    // Initialize a set containing the numbers given.
    // Traverse through the array, nested for thrice, calculate all localSums
    // check if that localSum is in set, if not return false
    //
    // Time: O(n^3)
    // Space: O(n)

    uset<int> digits;
    trav(i, a)
        digits.insert(i);

    int n = sz(a), localSum;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                localSum = a[i] + a[j] + a[k];
                if (digits.find(localSum) == digits.end())
                    return false;
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cout << (solve() ? "YES" : "NO") << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
