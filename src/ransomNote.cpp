/* LC - Easy grind 16 */
/* Time Complexity: O(n + m) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
#include <set>
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

bool solve(string& ransomNote, string& magazine) {
    // Algorithm:
    // Traverse through each letter in magazine, and increment freq
    // Traverse through each letter in ransomNote, and decrement freq
    // If freq reaches negative, then return false
    //
    // Finally return true
    //
    // Time: O(n + m) where n and m are lengths of strings respectively
    // Space: O(1)

    int freq[26] = { 0 };
    for (const char& c : magazine)
        freq[c - 'a']++;

    for (const char& c : ransomNote) {
        if (--freq[c - 'a'] < 0)
            return false;
    }

    return true;
}

bool solveSTL(string& ransomNote, string& magazine) {

    multiset<char> rs(ransomNote.begin(), ransomNote.end());
    multiset<char> mag(magazine.begin(), magazine.end());
    return includes(mag.begin(), mag.end(), rs.begin(), rs.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string rn, m;
    cin >> rn >> m;
    cout << (solve(rn, m) ? "YES" : "NO") << nl;
    cout << (solveSTL(rn, m) ? "YES" : "NO") << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
