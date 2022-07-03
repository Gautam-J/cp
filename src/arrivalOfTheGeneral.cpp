/* CF - 800 */
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

int solve(vi& a) {
    // Algorithm:
    // Find the maxElement and its index
    // Find the minElement and its index
    //
    // If minElement index < maxElement index, then while swapping
    // minElement will move forward by 1 index. Thus, increment minElement
    // index by 1.
    //
    // number of swaps needed for maxElement to be in first position is
    // the index value itself.
    // number of swaps needed for minElement to be in the last position is
    // n - 1 - minElement index
    //
    // Return the sum of the above two
    //
    // Although the other algorithm gets accepted, and share the same
    // complexities, this is a bit more faster and optimized due to removal
    // of many for loops.
    //
    // Time: O(n)
    // Space: O(1)

    int minE = imax, maxE = imin;
    int minEI, maxEI, n = sz(a);

    forn(i, 0, n) {
        // strictly greater than to get the left most max element
        if (a[i] > maxE) {
            maxE = a[i];
            maxEI = i;
        }

        // greater than or equal to get the right most min element
        if (a[i] <= minE) {
            minE = a[i];
            minEI = i;
        }
    }

    if (minEI < maxEI)
        minEI++;

    int swapsForMaxE = maxEI;
    int swapsForMinE = (n - 1 - minEI);

    return swapsForMaxE + swapsForMinE;
}

int solve2(vi& a) {
    // Algorithm:
    // Find the max element from left to right,
    // keep swapping until it is the first.
    // Find the min element from right to left,
    // keep swapping until it is the last.
    //
    // Return the total number of swaps.
    //
    // Time: O(n)
    // Space: O(1)

    int n = sz(a);
    int maxE = imin, minE = imax;
    int maxEIndex, minEIndex;

    forn(i, 0, n) {
        if (a[i] > maxE) {
            maxE = a[i];
            maxEIndex = i;
        }
    }

    int res = 0;
    for (int i = maxEIndex; i > 0; i--) {
        swap(a[i], a[i - 1]);
        res++;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] < minE) {
            minE = a[i];
            minEIndex = i;
        }
    }

    for (int i = minEIndex; i < n - 1; i++) {
        swap(a[i], a[i + 1]);
        res++;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    trav(i, a)
        cin >> i;
    cout << solve(a) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
