/* CF - 800 */
/*
A. LLPS
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
This problem's actual name, "Lexicographically Largest Palindromic Subsequence" is too long to fit into the page headline.

You are given string s consisting of lowercase English letters only. Find its lexicographically largest palindromic subsequence.

We'll call a non-empty string s[p1p2... pk] = sp1sp2... spk (1 ?²? p1?<?p2?<?...?<?pk ?²? |s|) a subsequence of string s = s1s2... s|s|, where |s| is the length of string s. For example, strings "abcb", "b" and "abacaba" are subsequences of string "abacaba".

String x = x1x2... x|x| is lexicographically larger than string y = y1y2... y|y| if either |x| > |y| and x1?=?y1, x2?=?y2, ...,?x|y|?=?y|y|, or there exists such number r (r?<?|x|, r?<?|y|) that x1?=?y1, x2?=?y2, ..., xr?=?yr and xr??+??1?>?yr??+??1. Characters in the strings are compared according to their ASCII codes. For example, string "ranger" is lexicographically larger than string "racecar" and string "poster" is lexicographically larger than string "post".

String s = s1s2... s|s| is a palindrome if it matches string rev(s) = s|s|s|s|?-?1... s1. In other words, a string is a palindrome if it reads the same way from left to right and from right to left. For example, palindromic strings are "racecar", "refer" and "z".

Input
The only input line contains a non-empty string s consisting of lowercase English letters only. Its length does not exceed 10.

Output
Print the lexicographically largest palindromic subsequence of string s.

Examples
inputCopy
radar
outputCopy
rr
inputCopy
bowwowwow
outputCopy
wwwww
inputCopy
codeforces
outputCopy
s
inputCopy
mississipp
outputCopy
ssss
Note
Among all distinct subsequences of string "radar" the following ones are palindromes: "a", "d", "r", "aa", "rr", "ada", "rar", "rdr", "raar" and "radar". The lexicographically largest of them is "rr".

Since the constraint on the input is very low, we can also do a brute force
method that would increase the time complexity to O((2^n) * n), i.e.,
compute all subsequences and check for the largest palindrome.

Another method would be to sort the given string and select the last chars.
This would use O(1) space, but time complexity will be O((n lg n) * n).

*/

/* Time Complexity: O(n) */
/* Space Complexity: O(n) */

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
    map<char, int> cnt;
    trav(i, s) {
        if (cnt.find(i) == cnt.end())
            cnt[i] = 1;
        else
            cnt[i]++;
    }

    char highest = s[0];
    trav(i, s) {
        if (i > highest)
            highest = i;
    }

    for (int i = 0; i < cnt[highest]; i++) {
        cout << highest;
    }
    cout << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    solve(s);

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
