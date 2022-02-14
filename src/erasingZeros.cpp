/* CF - 800 */
/*
A. Erasing Zeroes
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a string ??
s
. Each character is either 0 or 1.

You want all 1's in the string to form a contiguous subsegment. For example, if the string is 0, 1, 00111 or 01111100, then all 1's form a contiguous subsegment, and if the string is 0101, 100001 or 11111111111101, then this condition is not met.

You may erase some (possibly none) 0's from the string. What is the minimum number of 0's that you have to erase?

Input
The first line contains one integer ??
t
 (1²??²100
1
²
t
²
100
) Ñ the number of test cases.

Then ??
t
 lines follow, each representing a test case. Each line contains one string ??
s
 (1²|??|²100
1
²
|
s
|
²
100
); each character of ??
s
 is either 0 or 1.

Output
Print ??
t
 integers, where the ??
i
-th integer is the answer to the ??
i
-th testcase (the minimum number of 0's that you have to erase from ??
s
).

Example
inputCopy
3
010011
0
1111000
outputCopy
2
0
0
Note
In the first test case you have to delete the third and forth symbols from string 010011 (it turns into 0111).
*/

/* Time Complexity: O(n) where n is the length of the string */
/* Space Complexity: O(1) */

#include <algorithm>
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

int solve(string& s) {
    // 1. Find first occurence of 1.
    // 2. Find last occurence of 1.
    // 3. Within the above calculated bounds, find number of zeros.

    int res = 0;
    int first = s.find_first_of("1");
    int last = s.find_last_of("1");

    for (int i = first + 1; i < last; i++) {
        if (s[i] == '0')
            res++;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    string s;
    while (t--) {
        cin >> s;
        cout << solve(s) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
