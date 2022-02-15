/* CF - 1000 */
/*
B. Chocolates
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You went to the store, selling ??
n
 types of chocolates. There are ????
a
i
 chocolates of type ??
i
 in stock.

You have unlimited amount of cash (so you are not restricted by any prices) and want to buy as many chocolates as possible. However if you buy ????
x
i
 chocolates of type ??
i
 (clearly, 0²????²????
0
²
x
i
²
a
i
), then for all 1²??<??
1
²
j
<
i
 at least one of the following must hold:

????=0
x
j
=
0
 (you bought zero chocolates of type ??
j
)
????<????
x
j
<
x
i
 (you bought less chocolates of type ??
j
 than of type ??
i
)
For example, the array ??=[0,0,1,2,10]
x
=
[
0
,
0
,
1
,
2
,
10
]
 satisfies the requirement above (assuming that all ????³????
a
i
³
x
i
), while arrays ??=[0,1,0]
x
=
[
0
,
1
,
0
]
, ??=[5,5]
x
=
[
5
,
5
]
 and ??=[3,2]
x
=
[
3
,
2
]
 don't.

Calculate the maximum number of chocolates you can buy.

Input
The first line contains an integer ??
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
), denoting the number of types of chocolate.

The next line contains ??
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
), denoting the number of chocolates of each type.

Output
Print the maximum number of chocolates you can buy.

Examples
inputCopy
5
1 2 1 3 6
outputCopy
10
inputCopy
5
3 2 5 4 10
outputCopy
20
inputCopy
4
1 1 1 1
outputCopy
1
Note
In the first example, it is optimal to buy: 0+0+1+3+6
0
+
0
+
1
+
3
+
6
 chocolates.

In the second example, it is optimal to buy: 1+2+3+4+10
1
+
2
+
3
+
4
+
10
 chocolates.

In the third example, it is optimal to buy: 0+0+0+1
0
+
0
+
0
+
1
 chocolates.
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

ll solve(vector<ll>& a) {
    int n = sz(a);
    ll ans = a[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] >= a[i + 1])
            a[i] = a[i + 1] - 1;

        if (a[i] == 0)
            break;
        ans += a[i];
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    trav(i, a)
        cin >> i;

    cout << solve(a) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
