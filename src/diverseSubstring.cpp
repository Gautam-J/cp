/* CF - 1000 */
/*
A. Diverse Substring
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a string ??
s
, consisting of ??
n
 lowercase Latin letters.

A substring of string ??
s
 is a continuous segment of letters from ??
s
. For example, "defor" is a substring of "codeforces" and "fors" is not.

The length of the substring is the number of letters in it.

Let's call some string of length ??
n
 diverse if and only if there is no letter to appear strictly more than ??2
n
2
 times. For example, strings "abc" and "iltlml" are diverse and strings "aab" and "zz" are not.

Your task is to find any diverse substring of string ??
s
 or report that there is none. Note that it is not required to maximize or minimize the length of the resulting substring.

Input
The first line contains a single integer ??
n
 (1²??²1000
1
²
n
²
1000
) Ñ the length of string ??
s
.

The second line is the string ??
s
, consisting of exactly ??
n
 lowercase Latin letters.

Output
Print "NO" if there is no diverse substring in the string ??
s
.

Otherwise the first line should contain "YES". The second line should contain any diverse substring of string ??
s
.

Examples
inputCopy
10
codeforces
outputCopy
YES
code
inputCopy
5
aaaaa
outputCopy
NO
Note
The first example has lots of correct answers.
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

void solve(string& s) {
    int n = sz(s);
    int i = 0;

    while (i < n - 1) {
        if (s[i] != s[i + 1]) {
            cout << "YES" << nl << s[i] << s[i + 1] << nl;
            return;
        }

        i++;
    }

    cout << "NO" << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n;
    cin >> s;
    solve(s);

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
