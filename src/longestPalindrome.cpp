/* LC - Easy grind 18 */
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

int solve(string& s) {
    // Algorithm:
    // Traverse through the string and track frequency of each char.
    //
    // Let res = 0
    // For every char whose freq is greater than 1, i.e. 2, 3, 4, ..., n
    // add the floored down even frequency number to res.
    // For example, if freq is 7, add 6 to res
    // If freq is 5, add 4 to res
    // These are the counts of even letters that can be used
    //
    // Now res gives the number of even letters that can be used
    // If res is equal to length of original string, return s
    // Else, we can add one more letter in the middle, and make the
    // palindrome longer by 1 char.
    // Thus, return res + 1
    //
    // This is the faster, and less memory usage solution
    //
    // Time: O(n)
    // Space: O(n)

    unordered_map<char, int> count;
    for (const char& c : s) {
        if (count.find(c) != count.end())
            count[c]++;
        else
            count[c] = 1;
    }

    int res = 0;
    for (const auto& p : count) {
        if (p.second > 1)
            res += p.second - (p.second % 2);
    }

    if (res == s.size())
        return res;

    return res + 1;
}

int solve1(string& s) {
    // Algorithm:
    // Initialize an empty set
    // For each char in s, if c not in set, add to set. Else, remove from set
    // After this, the length of the set will be equal to the number of chars
    // with odd frequency
    //
    // If there is atleast 1 letter with an odd frequency,
    // return the number of letters with even freq + 1
    //
    // If there are no letters with odd freq, the given string itself
    // is a palindrome, thus return the length of the string
    //
    // Time: O(n)
    // Space: O(n)

    uset<char> letters;
    for (const char& c : s) {
        if (letters.find(c) == letters.end())
            letters.insert(c);
        else
            letters.erase(c);
    }

    int oddLetters = letters.size();

    if (oddLetters > 0)
        return s.size() - oddLetters + 1;

    return s.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    cout << solve(s) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
