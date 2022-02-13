/* CF - 800 */
/*
A. Crazy Computer
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
ZS the Coder is coding on a crazy computer. If you don't type in a word for a c consecutive seconds, everything you typed disappear!

More formally, if you typed a word at second a and then the next word at second b, then if b?-?a?²?c, just the new word is appended to other words on the screen. If b?-?a?>?c, then everything on the screen disappears and after that the word you have typed appears on the screen.

For example, if c?=?5 and you typed words at seconds 1,?3,?8,?14,?19,?20 then at the second 8 there will be 3 words on the screen. After that, everything disappears at the second 13 because nothing was typed. At the seconds 14 and 19 another two words are typed, and finally, at the second 20, one more word is typed, and a total of 3 words remain on the screen.

You're given the times when ZS the Coder typed the words. Determine how many words remain on the screen after he finished typing everything.

Input
The first line contains two integers n and c (1?²?n?²?100?000,?1?²?c?²?109) Ñ the number of words ZS the Coder typed and the crazy computer delay respectively.

The next line contains n integers t1,?t2,?...,?tn (1?²?t1?<?t2?<?...?<?tn?²?109), where ti denotes the second when ZS the Coder typed the i-th word.

Output
Print a single positive integer, the number of words that remain on the screen after all n words was typed, in other words, at the second tn.

Examples
inputCopy
6 5
1 3 8 14 19 20
outputCopy
3
inputCopy
6 1
1 3 5 7 9 10
outputCopy
2
Note
The first sample is already explained in the problem statement.

For the second sample, after typing the first word at the second 1, it disappears because the next word is typed at the second 3 and 3?-?1?>?1. Similarly, only 1 word will remain at the second 9. Then, a word is typed at the second 10, so there will be two words on the screen, as the old word won't disappear because 10?-?9?²?1.
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

int solve(vi& a, int c) {
    int nWords = 0, n = sz(a);

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            nWords++;
            continue;
        }

        if (a[i] - a[i - 1] <= c)
            nWords++;
        else
            nWords = 1;
    }

    return nWords;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;

    vi a(n);
    trav(i, a)
        cin >> i;

    cout << solve(a, c) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
