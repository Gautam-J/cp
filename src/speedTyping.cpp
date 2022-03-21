/* KS - 2022 */
/*
Problem
Barbara is a speed typer. In order to check her typing speed, she performs a speed test. She is given a string I
I
 that she is supposed to type.
While Barbara is typing, she may make some mistakes, such as pressing the wrong key. As her typing speed is important to her, she does not want to spend additional time correcting the mistakes, so she continues to type with the errors until she finishes the speed test. After she finishes the speed test, she produces a P
P
.
Now she wonders how many extra letters she needs to delete in order to get I
I
 from P
P
. It is possible that Barbara made a mistake and P
P
 cannot be converted back to I
I
just by deleting some letters. In particular, it is possible that Barbara missed some letters.
Help Barbara find out how many extra letters she needs to remove in order to obtain I
I
 or if I
I
 cannot be obtained from P
P
 by removing letters then output IMPOSSIBLE.
Input
The first line of the input gives the number of test cases, T
T
. T
T
 test cases follow.
Each test case has 2
2
 lines. The first line of each test case is an input string I
I
 (that denotes the string that the typing test has provided). The next line is the produced string P
P
 (that Barbara has entered).
Output
For each test case, output one line containing Case #x
x
: y
y
, where x
x
 is the test case number (starting from 1
1
) and y
y
 is the number of extra letters that need to be removed in order to obtain I
I
. If it is not possible to obtain I
I
 then output IMPOSSIBLE as y
y
.
Limits
Memory limit: 1 GB.
1²T²100
1
²
T
²
100
.
Both the strings contain letters from a-z and A-Z.
Length of the given strings will be 1²|I|,|P|²105
1
²
|
I
|
,
|
P
|
²
10
5
.
Test Set 1
Time limit: 20 seconds.
All letters in I
I
 are the same.
Test Set 2
Time limit: 40 seconds.
*/

/* Time Complexity: O(n) where n is the length of string P */
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

bool isSubsequence(string& I, string& P) {
    // Is I a subsequence of P
    int N = sz(I);
    int M = sz(P);
    int ptrI = 0, ptrP = 0;

    while (ptrI < N && ptrP < M) {
        if (P[ptrP] == I[ptrI]) {
            ptrP++;
            ptrI++;
        } else {
            ptrP++;
        }
    }

    return ptrI == N;
}

void solve(string& I, string& P) {
    if (!isSubsequence(I, P))
        cout << "IMPOSSIBLE" << nl;
    else
        cout << sz(P) - sz(I) << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    string I, P;
    cin >> t;
    fore(i, 1, t) {
        cin >> I >> P;
        cout << "Case #" << i << ": ";
        solve(I, P);
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
