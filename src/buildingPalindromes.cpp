/* Kick start practice round 2 2022 */
/*
Anna has a row of N
N
 blocks, each with exactly one letter from A to Z written on it. The blocks are numbered 1,2,?,N
1
,
2
,
?
,
N
 from left to right.
Today, she is learning about palindromes. A palindrome is a string that is the same written forwards and backwards. For example, ANNA, RACECAR, AAA and X are all palindromes, while AB, FROG and YOYO are not.
Bob wants to test how well Anna understands palindromes, and will ask her Q
Q
questions. The i-th question is: can Anna form a palindrome using all of the blocks numbered from Li
L
i
 to Ri
R
i
, inclusive? She may rearrange the blocks if necessary. After each question, Anna puts the blocks back in their original positions.
Please help Anna by finding out how many of Bob's questions she can answer "yes" to.
Input
The first line of the input gives the number of test cases, T
T
. T
T
 test cases follow. Each test case starts with a line containing the two integers N
N
 and Q
Q
, the number of blocks and the number of questions, respectively. Then, another line follows, containing a string of N
N
 uppercase characters (A to Z). Then, Q
Q
 lines follow. The i-th line contains the two integers Li
L
i
 and Ri
R
i
, describing the i-th question.
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
 is the number of questions Anna can answer "yes" to.
Limits
Time limit: 30 seconds.
Memory limit: 1 GB.
1²T²100
1
²
T
²
100
.
1²Li²Ri²N
1
²
L
i
²
R
i
²
N
.
Test Set 1
1²N²20
1
²
N
²
20
.
1²Q²20
1
²
Q
²
20
.
Test Set 2
1²N²100000
1
²
N
²
100000
.
1²Q²100000
1
²
Q
²
100000
.
Sample
Sample Input
save_alt
content_copy
2
7 5
ABAACCA
3 6
4 4
2 5
6 7
3 7
3 5
XYZ
1 3
1 3
1 3
1 3
1 3
Sample Output
save_alt
content_copy
Case #1: 3
Case #2: 0

In Sample Case #1, N
N
 = 7
7
 and Q
Q
 = 5
5
.
For the first question, Anna must use the blocks AACC. She can rearrange these blocks into the palindrome ACCA (or CAAC).
For the second question, Anna must use the blocks A. This is already a palindrome, so she does not need to rearrange them.
For the third question, Anna must use the blocks BAAC. These blocks cannot be rearranged into a palindrome.
For the fourth question, Anna must use the blocks CA. These blocks cannot be rearranged into a palindrome.
For the fifth question, Anna must use the blocks AACCA. She can rearrange these blocks to form the palindrome ACACA (or CAAAC).
In total, she is able to answer "yes" to 3
3
 of Bob's questions, so the answer is 3
3
.
In Sample Case #2, N
N
 = 3
3
 and Q
Q
 = 5
5
. For the first question, Anna must use the blocks XYZ to create a palindrome. This is impossible, and since the rest of Bob's questions are the same as the first one, the answer is 0
0
.
*/

/* Time Complexity: O() */
/* Space Complexity: O() */

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

bool isPalindrome(string& s, int l, int r) {
    // Algorithm
    // Initialize a map for counting the frequency of letters
    // Traverse through the string, and update hashmap accordingly
    // Count the number of letters occurring odd number of times
    // Count the number of letters occurring even number of times
    //
    // If the length of the string is even,
    // then there should be no letters occuring odd number of times
    // If the length of the string is odd,
    // then there should be exactly one letter occuring once in the string
    // If none of the above satisfies, then the string is not a palindrome
    //
    // Time: O(n), where n is the length of the string to be checked
    // Space: O(n), where n is the length of the string to be checked

    umap<char, int> count;
    fore(i, l - 1, r - 1) {
        if (count.find(s[i]) != count.end())
            count[s[i]]++;
        else
            count[s[i]] = 1;
    }

    int oddCount = 0;
    trav(p, count)
        oddCount += p.second % 2;

    int n = r - l + 1;
    if (n % 2 == 0)
        return oddCount == 0;

    return oddCount == 1;
}

int solve(string& s, vpi& indices) {
    // Algorithm:
    // DP
    //
    // Construct a table of size N x N and initialize to 0
    // dp[i][j] = 1 if s from i to j is a palindrome
    //
    // Base cases
    // dp[i][i] = 1
    // dp[i][i + 1] = 1 if s[i] == s[i + 1]
    //
    // dp[i][j] = 1 if dp[i + 1][j - 1] == 1 and s[i] == s[j]
    //
    // For other cases, manually pre-compute if it is a palindrome or not
    // Once the dp table is ready, simply check for the value at given indices
    // Keep track of the number of palindromes available
    // Finally return it
    //
    // Time: O(n^3) where n is the length of the string
    // Space: O(n^3) where n is the length of the string

    int n = sz(s);
    int dp[n + 1][n + 1];

    // initialize to 0
    forn(i, n + 1) {
        forn(j, n + 1)
            dp[i][j] = 0;
    }

    // base cases
    fore(i, 1, n)
        dp[i][i] = 1;

    fore(i, 1, n - 1) {
        if (s[i - 1] == s[i])
            dp[i][i + 1] = 1;
    }

    // TODO: Compute dp values using existing values
    // This solution gives TLE in set 2
    fore(i, 1, n - 2) {
        fore(j, i + 2, n)
            dp[i][j] = isPalindrome(s, i, j);
    }

    // display table
    /* fore(i, 1, n) { */
    /*     fore(j, 1, n) */
    /*         cout << dp[i][j] << " "; */
    /*     cout << nl; */
    /* } */

    int res = 0;
    trav(p, indices)
        res += dp[p.first][p.second];

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, n, q;
    string s;

    cin >> T;
    fore(t, 1, T) {
        cin >> n >> q;
        cin >> s;

        vpi indices(q);
        trav(p, indices)
            cin >> p.first >> p.second;

        cout << "Case #" << t << ": " << solve(s, indices) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
