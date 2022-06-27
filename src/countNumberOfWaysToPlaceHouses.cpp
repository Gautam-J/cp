/* LC - Medium */
/*
There is a street with n * 2 plots, where there are n plots on each side of the street. The plots on each side are numbered from 1 to n. On each plot, a house can be placed.

Return the number of ways houses can be placed such that no two houses are adjacent to each other on the same side of the street. Since the answer may be very large, return it modulo 109 + 7.

Note that if a house is placed on the ith plot on one side of the street, a house can also be placed on the ith plot on the other side of the street.



Example 1:

Input: n = 1
Output: 4
Explanation:
Possible arrangements:
1. All plots are empty.
2. A house is placed on one side of the street.
3. A house is placed on the other side of the street.
4. Two houses are placed, one on each side of the street.
Example 2:


Input: n = 2
Output: 9
Explanation: The 9 possible arrangements are shown in the diagram above.


Constraints:

1 <= n <= 104
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
const ll MOD = 1e9 + 7;

int solve(int n) {
    // Algorithm:
    // let house = 1, space = 1
    // total = house + space
    // for i = 2, i <= n
    // house = space
    // space = total
    // total = (house + space) % MOD;
    //
    // total will give the number of ways to place houses in one side.
    // Thus, return (total * total) % MOD;
    //
    // Another approach is that the answer is square of fibonacci numbers
    // 0 0 1 1 2 3 5 8
    // n = 1, (2 * 2 = 4)
    // n = 2, (3 * 3 = 9)
    // n = 3, (5 * 5 = 25)
    // n = 4, (8 * 8 = 64)
    //
    // Time: O(n)
    // Space: O(1)

    ll house = 1, space = 1;
    ll total = house + space;
    fore(i, 2, n) {
        house = space;
        space = total;
        total = (house + space) % MOD;
    }

    return (total * total) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << solve(n) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
