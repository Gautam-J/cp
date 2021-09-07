/* CF - 1200 */
/*
B. Sail
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
The polar bears are going fishing. They plan to sail from (sx, sy) to (ex, ey). However, the boat can only sail by wind. At each second, the wind blows in one of these directions: east, south, west or north. Assume the boat is currently at (x, y).

If the wind blows to the east, the boat will move to (x + 1, y).
If the wind blows to the south, the boat will move to (x, y - 1).
If the wind blows to the west, the boat will move to (x - 1, y).
If the wind blows to the north, the boat will move to (x, y + 1).
Alternatively, they can hold the boat by the anchor. In this case, the boat stays at (x, y). Given the wind direction for t seconds, what is the earliest time they sail to (ex, ey)?

Input
The first line contains five integers t, sx, sy, ex, ey (1 ≤ t ≤ 105,  - 109 ≤ sx, sy, ex, ey ≤ 109). The starting location and the ending location will be different.

The second line contains t characters, the i-th character is the wind blowing direction at the i-th second. It will be one of the four possibilities: "E" (east), "S" (south), "W" (west) and "N" (north).

Output
If they can reach (ex, ey) within t seconds, print the earliest time they can achieve it. Otherwise, print "-1" (without quotes).

Examples
inputCopy
5 0 0 1 1
SESNW
outputCopy
4
inputCopy
10 5 3 3 6
NENSWESNEE
outputCopy
-1
Note
In the first sample, they can stay at seconds 1, 3, and move at seconds 2, 4.

In the second sample, they cannot sail to the destination.
*/

/* Time Complexity: O(t) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define trav(i, a) for (auto& i : a)

#ifdef _GLIBCXX_DEBUG
#define debug(x) cerr << "\e[91m"<<"[DEBUG] "<<__func__<<":"<<__LINE__<<" [" << #x << "] = [" << x << "]" << "\e[39m" << '\n';
#else
#define debug(x)
#endif

typedef long long ll;
typedef vector<int> vi;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';
const double PI = acos(-1);

int solve(int sx, int sy, int ex, int ey, string& s) {
    int res = 0;

    trav(i, s) {
        if (i == 'N' && ey > sy) {
            sy++;
        } else if (i == 'S' && ey < sy) {
            sy--;
        } else if (i == 'E' && sx < ex) {
            sx++;
        } else if (i == 'W' && sx > ex) {
            sx--;
        }

        res++;

        if (sx == ex && sy == ey)
            return res;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, sx, sy, ex, ey;
    cin >> t;
    cin >> sx >> sy >> ex >> ey;

    string s;
    cin >> s;

    cout << solve(sx, sy, ex, ey, s) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
