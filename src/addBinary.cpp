/* LC - Easy grind 21 */
/* Time Complexity: O(max(n, m)) */
/* Space Complexity: O(max(n, m)) */

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

string solve(string& a, string& b) {
    // Algorithm:
    // Initialize carry = 0, new string res
    // From right to left, traverse both the strings with independent pointers
    // while i >= 0 or j >= 0 or carry == 1
    //     if i >= 0
    //         carry += a[i] - '0'
    //         i--
    //     if j >= 0
    //         carry += b[j] - '0'
    //         j--
    //
    //     res += (carry % 2 + '0')
    //     carry /= 2
    //
    // res will now be the answer needed in reverse
    // Therefore, we reverse it and return it
    //
    // Time: O(max(n, m))
    // Space: O(max(n, m))

    string res;
    int i = a.size() - 1, j = b.size() - 1, carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        if (i >= 0)
            carry += a[i--] - '0';
        if (j >= 0)
            carry += b[j--] - '0';

        // usually string concatenation is O(n)
        // However s += 'a' is O(1) amortized
        // s = s + 'a' will create a new copy of s
        // s += 'a' will simply append 'a' to s
        // This is why the solution is O(n) in time
        res += (carry % 2 + '0');
        carry /= 2;
    }

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;
    cout << solve(a, b) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
