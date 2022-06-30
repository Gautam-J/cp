/* CF - 1200 */
/*
Luke Skywalker gave Chewbacca an integer number x. Chewbacca isn't good at numbers but he loves inverting digits in them. Inverting digit t means replacing it with digit 9?-?t.

Help Chewbacca to transform the initial number x to the minimum possible positive number by inverting some (possibly, zero) digits. The decimal representation of the final number shouldn't start with a zero.

Input
The first line contains a single integer x (1?²?x?²?1018) Ñ the number that Luke Skywalker gave to Chewbacca.

Output
Print the minimum possible positive number that Chewbacca can obtain after inverting some digits. The number shouldn't contain leading zeroes.

Examples
inputCopy
27
outputCopy
22
inputCopy
4545
outputCopy
4444
*/

/* Time Complexity: O(log_10 n) */
/* Space Complexity: O(log_10 n) */

#include <bits/stdc++.h>
#include <string>
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

ll reverseNumber(ll n) {
    // Algorithm
    // For every digit, multiply the res by 10 and add the digit
    //
    // Time: O(log_10 n)
    // Space: O(log_10 n)

    ll reverse = 0;
    int digit;
    while (n) {
        digit = n % 10;
        n /= 10;
        reverse = (reverse * 10) + digit;
    }

    return reverse;
}

ll solve1(ll n) {
    // Algorithm:
    // For every digit t in n,
    // if t > 4, replace with 9 - t
    //
    // Reverse the number and return
    //
    // Time: O(log_10 n)
    // Space: O(log_10 n)

    ll inverted = 0;
    int digit;
    while (n > 9) {
        digit = n % 10;
        n /= 10;

        if (digit > 4)
            digit = 9 - digit;

        inverted = (inverted * 10) + digit;
    }

    if (n > 4 && n != 9)
        n = 9 - n;

    inverted = (inverted * 10) + n;
    return reverseNumber(inverted);
}

string solve(ll n) {
    // Algorithm
    // Convert number to string
    // For each digit in number,
    // If first digit == 9, continue with second digit
    // if digit > 4, replace with 9 - digit
    //
    // The only difference is that we can output numbers ending with 0
    //
    // Time: O(log_10 n)
    // Space: O(log_10 n)

    string s = to_string(n);

    int len = sz(s);
    forn(i, 0, len) {
        if (i == 0 && s[i] == '9')
            continue;

        if (s[i] > '4')
            s[i] = '9' - stoi(string() + s[i]);
    }

    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    cout << solve(n) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
