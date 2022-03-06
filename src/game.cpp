
/*
A. Game
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are playing a very popular computer game. The next level consists of ??
n
 consecutive locations, numbered from 1
1
 to ??
n
, each of them containing either land or water. It is known that the first and last locations contain land, and for completing the level you have to move from the first location to the last. Also, if you become inside a location with water, you will die, so you can only move between locations with land.

You can jump between adjacent locations for free, as well as no more than once jump from any location with land ??
i
 to any location with land ??+??
i
+
x
, spending ??
x
 coins (??³0
x
³
0
).

Your task is to spend the minimum possible number of coins to move from the first location to the last one.

Note that this is always possible since both the first and last locations are the land locations.

Input
There are several test cases in the input data. The first line contains a single integer ??
t
 (1²??²100
1
²
t
²
100
) Ñ the number of test cases. This is followed by the test cases description.

The first line of each test case contains one integer ??
n
 (2²??²100
2
²
n
²
100
) Ñ the number of locations.

The second line of the test case contains a sequence of integers ??1,??2,É,????
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
 (0²????²1
0
²
a
i
²
1
), where ????=1
a
i
=
1
 means that the ??
i
-th location is the location with land, and ????=0
a
i
=
0
 means that the ??
i
-th location is the location with water. It is guaranteed that ??1=1
a
1
=
1
 and ????=1
a
n
=
1
.

Output
For each test case print a single integer Ñ the answer to the problem.

Example
inputCopy
3
2
1 1
5
1 0 1 0 1
4
1 0 1 1
outputCopy
0
4
2
Note
In the first test case, it is enough to make one free jump from the first location to the second one, which is also the last one, so the answer is 0
0
.

In the second test case, the only way to move from the first location to the last one is to jump between them, which will cost 4
4
 coins.

In the third test case, you can jump from the first location to the third for 2
2
 coins, and then jump to the fourth location for free, so the answer is 2
2
. It can be shown that this is the optimal way.
*/

/* Time Complexity: O(n) */
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

int solve(vi& a) {
    int n = sz(a), i, j;

    for (i = 0; i < n; i++) {
        if (a[i] == 0)
            break;
    }

    for (j = n - 1; j >= i; j--) {
        if (a[j] == 0)
            break;
    }

    if (i == n)
        return 0;

    return j - i + 2;
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
