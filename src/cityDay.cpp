/* CF - 1000 */
/*
A. City Day
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
For years, the Day of city N was held in the most rainy day of summer. New mayor decided to break this tradition and select a not-so-rainy day for the celebration. The mayor knows the weather forecast for the ??
n
 days of summer. On the ??
i
-th day, ????
a
i
 millimeters of rain will fall. All values ????
a
i
 are distinct.

The mayor knows that citizens will watch the weather ??
x
 days before the celebration and ??
y
 days after. Because of that, he says that a day ??
d
 is not-so-rainy if ????
a
d
 is smaller than rain amounts at each of ??
x
 days before day ??
d
 and and each of ??
y
 days after day ??
d
. In other words, ????<????
a
d
<
a
j
 should hold for all ?????²??<??
d
?
x
²
j
<
d
 and ??<??²??+??
d
<
j
²
d
+
y
. Citizens only watch the weather during summer, so we only consider such ??
j
 that 1²??²??
1
²
j
²
n
.

Help mayor find the earliest not-so-rainy day of summer.

Input
The first line contains three integers ??
n
, ??
x
 and ??
y
 (1²??²100000
1
²
n
²
100
000
, 0²??,??²7
0
²
x
,
y
²
7
) Ñ the number of days in summer, the number of days citizens watch the weather before the celebration and the number of days they do that after.

The second line contains ??
n
 distinct integers ??1
a
1
, ??2
a
2
, ..., ????
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
), where ????
a
i
 denotes the rain amount on the ??
i
-th day.

Output
Print a single integer Ñ the index of the earliest not-so-rainy day of summer. We can show that the answer always exists.

Examples
inputCopy
10 2 2
10 9 6 7 8 3 2 1 4 5
outputCopy
3
inputCopy
10 2 3
10 9 6 7 8 3 2 1 4 5
outputCopy
8
inputCopy
5 5 5
100000 10000 1000 100 10
outputCopy
5
Note
In the first example days 3
3
 and 8
8
 are not-so-rainy. The 3
3
-rd day is earlier.

In the second example day 3
3
 is not not-so-rainy, because 3+??=6
3
+
y
=
6
 and ??3>??6
a
3
>
a
6
. Thus, day 8
8
 is the answer. Note that 8+??=11
8
+
y
=
11
, but we don't consider day 11
11
, because it is not summer.
*/

/* Time Complexity: O(n * (x + y)) */
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

int solve(vi& a, int x, int y) {
    int n = sz(a);

    fore(i, 1, n) {
        bool prev = true;
        for (int j = i - 1; j >= i - x && j >= 1; j--) {
            if (a[j - 1] < a[i - 1]) {
                prev = false;
                break;
            }
        }

        if (!prev)
            continue;

        bool next = true;
        for (int j = i + 1; j <= i + y && j <= n; j++) {
            if (a[j - 1] < a[i - 1]) {
                next = false;
                break;
            }
        }

        if (prev && next)
            return i;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y;
    cin >> n >> x >> y;
    vi a(n);
    trav(i, a)
        cin >> i;

    cout << solve(a, x, y) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
