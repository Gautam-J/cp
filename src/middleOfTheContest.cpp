/* CF - 1000 */
/*
A. Middle of the Contest
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp is going to participate in the contest. It starts at ?1:??1
h
1
:
m
1
 and ends at ?2:??2
h
2
:
m
2
. It is guaranteed that the contest lasts an even number of minutes (i.e. ??1%2=??2%2
m
1
%
2
=
m
2
%
2
, where ??%??
x
%
y
 is ??
x
 modulo ??
y
). It is also guaranteed that the entire contest is held during a single day. And finally it is guaranteed that the contest lasts at least two minutes.

Polycarp wants to know the time of the midpoint of the contest. For example, if the contest lasts from 10:00
10
:
00
 to 11:00
11
:
00
 then the answer is 10:30
10
:
30
, if the contest lasts from 11:10
11
:
10
 to 11:12
11
:
12
 then the answer is 11:11
11
:
11
.

Input
The first line of the input contains two integers ?1
h
1
 and ??1
m
1
 in the format hh:mm.

The second line of the input contains two integers ?2
h
2
 and ??2
m
2
 in the same format (hh:mm).

It is guaranteed that 0²?1,?2²23
0
²
h
1
,
h
2
²
23
 and 0²??1,??2²59
0
²
m
1
,
m
2
²
59
.

It is guaranteed that the contest lasts an even number of minutes (i.e. ??1%2=??2%2
m
1
%
2
=
m
2
%
2
, where ??%??
x
%
y
 is ??
x
 modulo ??
y
). It is also guaranteed that the entire contest is held during a single day. And finally it is guaranteed that the contest lasts at least two minutes.

Output
Print two integers ?3
h
3
 and ??3
m
3
 (0²?3²23,0²??3²59
0
²
h
3
²
23
,
0
²
m
3
²
59
) corresponding to the midpoint of the contest in the format hh:mm. Print each number as exactly two digits (prepend a number with leading zero if needed), separate them with ':'.

Examples
inputCopy
10:00
11:00
outputCopy
10:30
inputCopy
11:10
11:12
outputCopy
11:11
inputCopy
01:02
03:02
outputCopy
02:02
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

void solve(int sh, int sm, int eh, int em) {
    int t1 = sh * 60 + sm;
    int t2 = eh * 60 + em;
    int middle = (t1 + t2) / 2;

    printf("%02d:%02d", middle/60, middle%60);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int sh, sm, eh, em;
    scanf("%d:%d", &sh, &sm);
    scanf("%d:%d", &eh, &em);
    solve(sh, sm, eh, em);

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
