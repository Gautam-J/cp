/* CF - 1100 */
/*
C. Division by Two and Permutation
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array a consisting of n positive integers. You can perform operations on it.

In one operation you can replace any element of the array ai with ⌊ai2⌋, that is, by an integer part of dividing ai by 2 (rounding down).

See if you can apply the operation some number of times (possible 0) to make the array a become a permutation of numbers from 1 to n —that is, so that it contains all numbers from 1 to n, each exactly once.

For example, if a=[1,8,25,2], n=4, then the answer is yes. You could do the following:

Replace 8 with ⌊82⌋=4, then a=[1,4,25,2].
Replace 25 with ⌊252⌋=12, then a=[1,4,12,2].
Replace 12 with ⌊122⌋=6, then a=[1,4,6,2].
Replace 6 with ⌊62⌋=3, then a=[1,4,3,2].
Input
The first line of input data contains an integer t (1≤t≤104) —the number of test cases.

Each test case contains exactly two lines. The first one contains an integer n (1≤n≤50), the second one contains integers a1,a2,…,an (1≤ai≤109).

Output
For each test case, output on a separate line:

YES if you can make the array a become a permutation of numbers from 1 to n,
NO otherwise.
You can output YES and NO in any case (for example, strings yEs, yes, Yes and YES will be recognized as a positive response).

Example
inputCopy
6
4
1 8 25 2
2
1 1
9
9 8 3 4 2 7 1 5 6
3
8 2 1
4
24 7 16 7
5
22 6 22 4 22
outputCopy
YES
NO
YES
NO
NO
YES
Note
The first test case is explained in the text of the problem statement.

In the second test case, it is not possible to get a permutation.

*/

/* Time Complexity: O(n lg n) */
/* Space Complexity: O(n) */

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

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

    int n = sz(a), x;
    vector<bool> used(n + 1, false);
    sort(a.rbegin(), a.rend());

    bool res = true;
    trav(i, a) {
        x = i;
        while (x > n || used[x])
            x /= 2;

        if (x > 0)
            used[x] = true;
        else
            res = false;
    }

    return res;
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
