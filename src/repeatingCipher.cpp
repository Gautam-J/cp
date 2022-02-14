/* CF - 800 */
/*
A. Repeating Cipher
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp loves ciphers. He has invented his own cipher called repeating.

Repeating cipher is used for strings. To encrypt the string ??=??1??2É????
s
=
s
1
s
2
É
s
m
 (1²??²10
1
²
m
²
10
), Polycarp uses the following algorithm:

he writes down ??1
s
1
 ones,
he writes down ??2
s
2
 twice,
he writes down ??3
s
3
 three times,
...
he writes down ????
s
m
 ??
m
 times.
For example, if ??
s
="bab" the process is: "b" ?
?
 "baa" ?
?
 "baabbb". So the encrypted ??
s
="bab" is "baabbb".

Given string ??
t
 Ñ the result of encryption of some string ??
s
. Your task is to decrypt it, i.?e. find the string ??
s
.

Input
The first line contains integer ??
n
 (1²??²55
1
²
n
²
55
) Ñ the length of the encrypted string. The second line of the input contains ??
t
 Ñ the result of encryption of some string ??
s
. It contains only lowercase Latin letters. The length of ??
t
 is exactly ??
n
.

It is guaranteed that the answer to the test exists.

Output
Print such string ??
s
 that after encryption it equals ??
t
.

Examples
inputCopy
6
baabbb
outputCopy
bab
inputCopy
10
ooopppssss
outputCopy
oops
inputCopy
1
z
outputCopy
z
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

void solve(string& s) {
    int n = sz(s);

    int cnt = 0;
    for (int i = 0; i < n;) {
        cout << s[i];
        cnt++;
        i += cnt;
    }
    cout << nl;
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
