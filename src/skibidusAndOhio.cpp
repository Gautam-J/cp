// CF

/*
B. Skibidus and Ohio
time limit per test1 second
memory limit per test256 megabytes
Skibidus is given a string 𝑠 that consists of lowercase Latin letters. If 𝑠 contains more than 1 letter, he can:

Choose an index 𝑖 (1≤𝑖≤|𝑠|−1, |𝑠| denotes the current length of 𝑠) such that 𝑠𝑖=𝑠𝑖+1. Replace 𝑠𝑖 with any lowercase Latin letter of his choice. Remove 𝑠𝑖+1 from the string.
Skibidus must determine the minimum possible length he can achieve through any number of operations.

Input
The first line contains an integer 𝑡 (1≤𝑡≤100) — the number of test cases.

The only line of each test case contains a string 𝑠 (1≤|𝑠|≤100). It is guaranteed 𝑠 only contains lowercase Latin letters.

Output
For each test case, output an integer on the new line, the minimum achievable length of 𝑠.

Example
inputCopy
4
baa
skibidus
cc
ohio
outputCopy
1
8
1
4
Note
In the first test case, Skibidus can:

Perform an operation on 𝑖=2. He replaces 𝑠2 with b and removes 𝑠3 from the string. Then, 𝑠 becomes bb.
Perform an operation on 𝑖=1. He replaces 𝑠1 with b and removes 𝑠2 from the string. Then, 𝑠 becomes b.
Because 𝑠 only contains 1 letter, Skibidus cannot perform any more operations.
Therefore, the answer is 1 for the first test case.

In the second test case, he cannot perform an operation on any index. Therefore, the answer is still the length of the initial string, 8.
*/

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
#define shuf(v) shuffle(allit(v), rng)
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

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const char nl = '\n';
// const ll MOD = 1e9+7;
// const ld PI = acos(-1.0);

void solve() {
    // Algorithm:
    // ==========
    // If there exists any i such that s[i] = s[i + 1],
    // then answer is 1 since s[i + 1] can be replaced by either s[i - 1]
    // or s[i + 2] and it keeps going...
    // Else, output the length of the string.
    //
    // Time: O(n)
    // Space: O(1)

    string s;
    cin >> s;
    int n = sz(s);

    if (n == 1) {
        cout << 1 << nl;
        return;
    }

    bool res = false;
    forn(i, 0, n - 1) {
        if (s[i] == s[i + 1]) {
            res = true;
            break;
        }
    }

    cout << (res ? 1 : n) << nl;

    // if (n == 2) {
    //     if (s[0] == s[1])
    //         cout << 1 << nl;
    //     else
    //         cout << 2 << nl;
    //     return;
    // }



    // forn(i, 0, n - 1) {
    //     if (s[i] == s[i + 1]) {
    //         if (i == n - 2) {
    //
    //         }
    //     }
    // }
    // cout << res << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--)
        solve();

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
