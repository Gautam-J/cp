/* CF - 800 */
/*
This winter is so cold in Nvodsk! A group of n friends decided to buy k bottles of a soft drink called "Take-It-Light" to warm up a bit. Each bottle has l milliliters of the drink. Also they bought c limes and cut each of them into d slices. After that they found p grams of salt.

To make a toast, each friend needs nl milliliters of the drink, a slice of lime and np grams of salt. The friends want to make as many toasts as they can, provided they all drink the same amount. How many toasts can each friend make?

Input
The first and only line contains positive integers n, k, l, c, d, p, nl, np, not exceeding 1000 and no less than 1. The numbers are separated by exactly one space.

Output
Print a single integer Ñ the number of toasts each friend can make.

Examples
inputCopy
3 4 5 10 8 100 3 1
outputCopy
2
inputCopy
5 100 10 1 19 90 4 3
outputCopy
3
inputCopy
10 1000 1000 25 23 1 50 1
outputCopy
0
Note
A comment to the first sample:

Overall the friends have 4?*?5?=?20 milliliters of the drink, it is enough to make 20?/?3?=?6 toasts. The limes are enough for 10?*?8?=?80 toasts and the salt is enough for 100?/?1?=?100 toasts. However, there are 3 friends in the group, so the answer is min(6,?80,?100)?/?3?=?2.
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

#define forn(i, l, r) for (int i = (int)l; i < (int)r; ++i)
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

int solve(int n, int k, int l, int c, int d, int p, int nL, int nP) {
    // Algorithm:
    // let A = (k * l) / nl
    // let B = (c * d)
    // let C = p / nP
    //
    // return min(A, B, C) / n
    //
    // Time: O(1)
    // Space: O(1)

    int A = (k * l) / nL;
    int B = c * d;
    int C = p / nP;

    return min({ A, B, C }) / n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, l, c, d, p, nL, nP;
    cin >> n >> k >> l >> c >> d >> p >> nL >> nP;
    cout << solve(n, k, l, c, d, p, nL, nP) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
