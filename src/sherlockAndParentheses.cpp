/* Kick start practice round 2 2022 */
/*
Sherlock and Watson have recently enrolled in a computer programming course. Today, the tutor taught them about the balanced parentheses problem. A string S
S
consisting only of characters ( and/or ) is balanced if:
It is an empty string, or:
It has the form (S
S
), where S
S
 is a balanced string, or:
It has the form S1S2
S
1
S
2
, where S1
S
1
 is a balanced string and S2
S
2
 is a balanced string.
Sherlock coded up the solution very quickly and started bragging about how good he is, so Watson gave him a problem to test his knowledge. He asked Sherlock to generate a string S
S
 of `L + R` characters, in which there are a total of L
L
 left parentheses ( and a total of R
R
 right parentheses ). Moreover, the string must have as many different balanced non-empty substrings as possible. (Two substrings are considered different as long as they start and end at different indexes of the string, even if their content happens to be the same). Note that S
S
itself does not have to be balanced.
Sherlock is sure that once he knows the maximum possible number of balanced non-empty substrings, he will be able to solve the problem. Can you help him find that maximum number?
Input
The first line of the input gives the number of test cases, T
T
. T
T
 test cases follow.
Each test case consists of one line with two integers: L
L
 and R
R
.
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
 is the answer, as described above.
Limits
Time limit: 20 seconds.
Memory limit: 1 GB.
1²T²100
1
²
T
²
100
.
Test Set 1
0²L²20
0
²
L
²
20
.
0²R²20
0
²
R
²
20
.
1²L+R²20
1
²
L
+
R
²
20
.
Test Set 2
0²L²105
0
²
L
²
10
5
.
0²R²105
0
²
R
²
10
5
.
1²L+R²105
1
²
L
+
R
²
10
5
.
Sample
Sample Input
save_alt
content_copy
3
1 0
1 1
3 2
Sample Output
save_alt
content_copy
Case #1: 0
Case #2: 1
Case #3: 3
In Sample Case #1, the only possible string is (. There are no balanced non-empty substrings.
In Sample Case #2, the optimal string is (). There is only one balanced non-empty substring: the entire string itself.
In Sample Case #3, both strings ()()( and (()() give the same optimal answer.
For the case ()()(, for example, the three balanced substrings are () from indexes 1
1
 to 2
2
, () from indexes 3
3
 to 4
4
, and ()() from indexes 1
1
 to 4
4
.
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

int solve(int l, int r) {
    // Algorithm:
    // Let n = min(l, r)
    // Return sum of first n numbers
    //
    // Why does that give the answer?
    // Say the l=4, r=7
    // Then, we can have the string as ()()()())))
    // No matter the value of r, as long as its greater than l,
    // the number of balanced substrings does not change.
    // Thus, we choose n = min(l, r)
    //
    // Now, considering the balanced string: ()()()()
    // Number of balanced substrings will be
    // ()
    // ()()
    // ()()()
    // ()()()()
    // where each row i can be in any permutation, and still containing
    // i number of substrings.
    //
    // Time: O(1)
    // Space: O(1)

    int minE = l < r ? l : r;
    int res = (minE * (minE + 1)) / 2;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, l, r;
    cin >> T;
    fore(t, 1, T) {
        cin >> l >> r;
        cout << "Case #" << t << ": ";
        cout << solve(l, r) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
