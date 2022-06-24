/* LC - Easy */
/*
Given a string of English letters s, return the greatest English letter which occurs as both a lowercase and uppercase letter in s. The returned letter should be in uppercase. If no such letter exists, return an empty string.

An English letter b is greater than another letter a if b appears after a in the English alphabet.
*/

/* Time Complexity: O(n) */
/* Space Complexity: O(n) even if its (n) max is 52, which is relatively small */

#include <bits/stdc++.h>
#include <bitset>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

template<typename T> T gcd(T a, T b) { return ( b ? __gcd(a, b) : a); }
template<typename T> T lcm(T a, T b) { return (a * (b / gcd(a, b))); }

#define forn(i, n) for (int i = 0; i < n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define trav(i, a) for (const auto& i : a)
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

string solve1(string& s) {
    // Algorithm:
    // Insert all elements into a set.
    // From the last alphabet, i.e., z, check if i and I are both present in the set.
    // If so, simply return I.
    // After the for loop, return an empty string.
    //
    // Time: O(n)
    // Space: O(n)

    uset<char> seen;
    for (const char& c : s)
        seen.insert(c);  // O(1)

    char lower = 'z', tempLower;
    char upper = 'Z', tempUpper;

    for (int i = 0; i < 26; i++) {
        tempUpper = upper - i;
        tempLower = lower - i;

        if (seen.find(tempUpper) != seen.end() && seen.find(tempLower) != seen.end())
            return string() + tempUpper;
    }
    return "";
}

string solve2(string& s) {
    // Time: O(nlogn)
    // Space: O(n)

    sort(s.rbegin(), s.rend());

    uset<char> seen;
    char greaterChar = '0';
    for (const char& c : s) {
        if (islower(c))
            seen.insert(c);
        else
            // check if the lowercase of c is in seen
            if (seen.find(tolower(c)) != seen.end())
                greaterChar = max(greaterChar, c);
    }

    return greaterChar == '0' ? "" : string() + (char)toupper(greaterChar);
}

string solve3(string& s) {
    // Time: O(n)
    // Space: O(1)

    bitset<52> isThere;
    char greaterChar = '0';
    int n = sz(s);

    for (int i = 0; i < n; ++i) {
        if (s[i] >= 'a')
            isThere[s[i] - 'a' + 26] = 1;
        else
            isThere[s[i] - 'A'] = 1;
    }

    for (int i = 0; i < 26; ++i) {
        if (isThere[i] && isThere[i + 26]) {
            if ('A' + i > greaterChar)
                greaterChar = 'A' + i;
        }
    }

    string res = "";
    if (greaterChar != '0')
        res += greaterChar;

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    cout << solve1(s) << nl;
    cout << solve2(s) << nl;
    cout << solve3(s) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
