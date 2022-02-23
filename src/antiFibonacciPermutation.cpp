
/*
B. Anti-Fibonacci Permutation
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Let's call a permutation ??
p
 of length ??
n
 anti-Fibonacci if the condition ?????2+?????1­????
p
i
?
2
+
p
i
?
1
­
p
i
 holds for all ??
i
 (3²??²??
3
²
i
²
n
). Recall that the permutation is the array of length ??
n
 which contains each integer from 1
1
 to ??
n
 exactly once.

Your task is for a given number ??
n
 print ??
n
 distinct anti-Fibonacci permutations of length ??
n
.

Input
The first line contains a single integer ??
t
 (1²??²48
1
²
t
²
48
) Ñ the number of test cases.

The single line of each test case contains a single integer ??
n
 (3²??²50
3
²
n
²
50
).

Output
For each test case, print ??
n
 lines. Each line should contain an anti-Fibonacci permutation of length ??
n
. In each test case, you cannot print any permutation more than once.

If there are multiple answers, print any of them. It can be shown that it is always possible to find ??
n
 different anti-Fibonacci permutations of size ??
n
 under the constraints of the problem.

Example
inputCopy
2
4
3
outputCopy
4 1 3 2
1 2 4 3
3 4 1 2
2 4 1 3
3 2 1
1 3 2
3 1 2
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

void solve(int n) {
    vi a(n);
    forn(i, n)
        a[i] = i + 1;
    reverse(allit(a));

    trav(i, a)
        cout << i << " ";
    cout << nl;

    forn(j, n - 1) {
        swap(a[j], a[j + 1]);
        trav(i, a)
            cout << i << " ";
        cout << nl;
        swap(a[j], a[j + 1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        solve(n);
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
