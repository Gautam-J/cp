
/*
B. Vlad and Candies
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Not so long ago, Vlad had a birthday, for which he was presented with a package of candies. There were ??
n
 types of candies, there are ????
a
i
candies of the type ??
i
 (1²??²??
1
²
i
²
n
).

Vlad decided to eat exactly one candy every time, choosing any of the candies of a type that is currently the most frequent (if there are several such types, he can choose any of them). To get the maximum pleasure from eating, Vlad does not want to eat two candies of the same type in a row.

Help him figure out if he can eat all the candies without eating two identical candies in a row.

Input
The first line of input data contains an integer ??
t
 (1²??²104
1
²
t
²
10
4
) Ñ the number of input test cases.

The following is a description of ??
t
 test cases of input, two lines for each.

The first line of the case contains the single number ??
n
 (1²??²2?105
1
²
n
²
2
?
10
5
) Ñ the number of types of candies in the package.

The second line of the case contains ??
n
 integers ????
a
i
 (1²????²109
1
²
a
i
²
10
9
) Ñ the number of candies of the type ??
i
.

It is guaranteed that the sum of ??
n
 for all cases does not exceed 2?105
2
?
10
5
.

Output
Output ??
t
 lines, each of which contains the answer to the corresponding test case of input. As an answer, output "YES" if Vlad can eat candy as planned, and "NO" otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

Example
inputCopy
6
2
2 3
1
2
5
1 6 2 4 3
4
2 2 2 1
3
1 1000000000 999999999
1
1
outputCopy
YES
NO
NO
YES
YES
YES
Note
In the first example, it is necessary to eat sweets in this order:

a candy of the type 2
2
, it is the most frequent, now ??=[2,2]
a
=
[
2
,
2
]
;
a candy of the type 1
1
, there are the same number of candies of the type 2
2
, but we just ate one, now ??=[1,2]
a
=
[
1
,
2
]
;
a candy of the type 2
2
, it is the most frequent, now ??=[1,1]
a
=
[
1
,
1
]
;
a candy of the type 1
1
, now ??=[0,1]
a
=
[
0
,
1
]
;
a candy of the type 2
2
, now ??=[0,0]
a
=
[
0
,
0
]
 and the candy has run out.
In the second example, all the candies are of the same type and it is impossible to eat them without eating two identical ones in a row.

In the third example, first of all, a candy of the type 2
2
 will be eaten, after which this kind will remain the only kind that is the most frequent, and you will have to eat a candy of the type 2
2
 again.
*/

/* Time Complexity: O(n lg n) can be done in O(n) also */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
#include <pthread.h>
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

bool solve(vi& a) {
    a.pb(0);
    sort(allit(a));
    int n = sz(a);

    return a[n - 1] - a[n - 2] <= 1;
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
