// CF - 1200

/*
C. Uninteresting Number
time limit per test2 seconds
memory limit per test256 megabytes
You are given a number 𝑛 with a length of no more than 105.

You can perform the following operation any number of times: choose one of its digits, square it, and replace the original digit with the result. The result must be a digit (that is, if you choose the digit 𝑥, then the value of 𝑥2 must be less than 10).

Is it possible to obtain a number that is divisible by 9 through these operations?

Input
The first line contains an integer 𝑡 (1≤𝑡≤104) — the number of test cases.

The only line of each test case contains the number 𝑛, without leading zeros. The length of the number does not exceed 105.

It is guaranteed that the sum of the lengths of the numbers across all test cases does not exceed 105.

Output
For each test case, output "YES" if it is possible to obtain a number divisible by 9 using the described operations, and "NO" otherwise.

You can output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive answer.

Example
inputCopy
9
123
322
333333333333
9997
5472778912773
1234567890
23
33
52254522632
outputCopy
NO
YES
YES
NO
NO
YES
NO
YES
YES
Note
In the first example, from the integer 123, it is possible to obtain only 123, 143, 129, and 149, none of which are divisible by 9.

In the second example, you need to replace the second digit with its square; then 𝑛 will equal 342=38⋅9.

In the third example, the integer is already divisible by 9.
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
    // we can either convert 2 to 4 or 3 to 9.
    // i.e. add 2 or 6 to the number.
    // check if we have enough multiples of 2 and 6 to make sum of n % 9 == 0
    //
    // Time: O(n) where n is the length of the given string.
    // Space: O(1)

    string s;
    cin >> s;

    ll sum = 0, twc = 0, thc = 0;
    trav(c, s) {
        sum += (c - '0');
        if (c == '2') twc++;
        if (c == '3') thc++;
    }

    forn(i, 0, min(10ll, twc + 1)) {
        forn(j, 0, min(10ll, thc + 1)) {
            if ((sum + i * 2 + j * 6) % 9 == 0) {
                cout << "YES" << nl;
                return;
            }
        }
    }
    cout << "NO" << nl;
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
