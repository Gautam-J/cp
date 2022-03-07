/* CR - 800 */
/*
A. Doors and Keys
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The knight is standing in front of a long and narrow hallway. A princess is waiting at the end of it.

In a hallway there are three doors: a red door, a green door and a blue door. The doors are placed one after another, however, possibly in a different order. To proceed to the next door, the knight must first open the door before.

Each door can be only opened with a key of the corresponding color. So three keys: a red key, a green key and a blue key Ñ are also placed somewhere in the hallway. To open the door, the knight should first pick up the key of its color.

The knight has a map of the hallway. It can be transcribed as a string, consisting of six characters:

R, G, B Ñ denoting red, green and blue doors, respectively;
r, g, b Ñ denoting red, green and blue keys, respectively.
Each of these six characters appears in the string exactly once.

The knight is standing at the beginning of the hallway Ñ on the left on the map.

Given a map of the hallway, determine if the knight can open all doors and meet the princess at the end of the hallway.

Input
The first line contains a single integer ??
t
 (1²??²720
1
²
t
²
720
) Ñ the number of testcases.

Each testcase consists of a single string. Each character is one of R, G, B (for the doors), r, g, b (for the keys), and each of them appears exactly once.

Output
For each testcase, print YES if the knight can open all doors. Otherwise, print NO.

Example
inputCopy
4
rgbBRG
RgbrBG
bBrRgG
rgRGBb
outputCopy
YES
NO
YES
NO
Note
In the first testcase, the knight first collects all keys, then opens all doors with them.

In the second testcase, there is a red door right in front of the knight, but he doesn't have a key for it.

In the third testcase, the key to each door is in front of each respective door, so the knight collects the key and uses it immediately three times.

In the fourth testcase, the knight can't open the blue door.
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

bool solve(string& s) {
    int redKey = s.find('r');
    int blueKey = s.find('b');
    int greenKey = s.find('g');

    int redDoor = s.find('R');
    int blueDoor = s.find('B');
    int greenDoor = s.find('G');

    return (redKey < redDoor && blueKey < blueDoor && greenKey < greenDoor);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        cout << (solve(s) ? "YES" : "NO") << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
