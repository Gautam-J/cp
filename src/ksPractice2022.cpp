/* KS - Practice 2022 */
/*
Problem
You have gathered N
N
 bags of candy and you want to distribute the candy amongst M
M
 kids. The i
i
-th bag contains Ci
C
i
 pieces of candy. You want to make sure that every kid get the same amount of candy and that the number of pieces of candy they receive is the greatest possible. You can open each bag and mix all pieces of candy before distributing them to the kids.
How many pieces of candy will remain after you share the candy amongst kids, based on the rules described above?
Input
The first line of the input gives the number of test cases, T
T
. T
T
 test cases follow.
Each test case consists of two lines. The first line of each test case contains two integers: integer N
N
, the number of candy bags, and M
M
, the number of kids.
The next line contains N
N
 non-negative integers C1,C2,É,CN
C
1
,
C
2
,
É
,
C
N
 representing array C
C
, where the i
i
-th integer represents the number of candies in the i
i
-th bag.
Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1
1
) and y is the number of candies that will remain if you divide candies between kids according to the rules described above.
Limits
Time limit: 40 seconds.
Memory limit: 1 GB.
Test Set 1
1²T²100
1
²
T
²
100
.
1²N²105
1
²
N
²
10
5
.
1²M²104
1
²
M
²
10
4
.
0²Ci²1000
0
²
C
i
²
1000
, for all i
i
 from 1
1
 to N
N
.
Sample
Sample Input
save_alt
content_copy
2
7 3
1 2 3 4 5 6 7
5 10
7 7 7 7 7
Sample Output
save_alt
content_copy
Case #1: 1
Case #2: 5
In Sample Case #1, we have N=7
N
=
7
 bags of candy. In total we have 1+2+3+4+5+6+7=28
1
+
2
+
3
+
4
+
5
+
6
+
7
=
28
 candies that we want to divide between M=3
M
=
3
 kids. Every kid can get 9
9
 pieces of candy, so 28?3?9=1
28
?
3
?
9
=
1
 pieces of candy will remain.
In Sample Case #2, we have N=5
N
=
5
 bags of candy. In total we have 7+7+7+7+7=35
7
+
7
+
7
+
7
+
7
=
35
 candies that we want to divide between M=10
M
=
10
 kids. Every kid can get 3
3
pieces of candy, so 35?10?3=5
35
?
10
?
3
=
5
 pieces of candy will remain.
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
const ld PI = acos(-1.0);

int solve(vi& a, int m) {
    int sum = 0;
    trav(i, a)
        sum += i;

    return sum % m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, n, m;
    cin >> T;

    forn(t, T) {
        cin >> n >> m;
        vi a(n);
        trav(i, a)
            cin >> i;
        cout << "Case #" << t + 1 << ": " << solve(a, m) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
