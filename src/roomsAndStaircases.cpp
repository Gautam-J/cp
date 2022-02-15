/* CF - 1000 */
/*
B. Rooms and Staircases
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Nikolay lives in a two-storied house. There are ??
n
 rooms on each floor, arranged in a row and numbered from one from left to right. So each room can be represented by the number of the floor and the number of the room on this floor (room number is an integer between 1
1
 and ??
n
).

If Nikolay is currently in some room, he can move to any of the neighbouring rooms (if they exist). Rooms with numbers ??
i
 and ??+1
i
+
1
 on each floor are neighbouring, for all 1²??²???1
1
²
i
²
n
?
1
. There may also be staircases that connect two rooms from different floors having the same numbers. If there is a staircase connecting the room ??
x
 on the first floor and the room ??
x
 on the second floor, then Nikolay can use it to move from one room to another.

The picture illustrates a house with ??=4
n
=
4
. There is a staircase between the room 2
2
 on the first floor and the room 2
2
 on the second floor, and another staircase between the room 4
4
 on the first floor and the room 4
4
 on the second floor. The arrows denote possible directions in which Nikolay can move. The picture corresponds to the string "0101" in the input.
Nikolay wants to move through some rooms in his house. To do this, he firstly chooses any room where he starts. Then Nikolay moves between rooms according to the aforementioned rules. Nikolay never visits the same room twice (he won't enter a room where he has already been).

Calculate the maximum number of rooms Nikolay can visit during his tour, if:

he can start in any room on any floor of his choice,
and he won't visit the same room twice.
Input
The first line of the input contains one integer ??
t
 (1²??²100
1
²
t
²
100
) Ñ the number of test cases in the input. Then test cases follow. Each test case consists of two lines.

The first line contains one integer ??
n
 (1²??²1000)
(
1
²
n
²
1
000
)
 Ñ the number of rooms on each floor.

The second line contains one string consisting of ??
n
 characters, each character is either a '0' or a '1'. If the ??
i
-th character is a '1', then there is a staircase between the room ??
i
 on the first floor and the room ??
i
 on the second floor. If the ??
i
-th character is a '0', then there is no staircase between the room ??
i
 on the first floor and the room ??
i
 on the second floor.

In hacks it is allowed to use only one test case in the input, so ??=1
t
=
1
 should be satisfied.

Output
For each test case print one integer Ñ the maximum number of rooms Nikolay can visit during his tour, if he can start in any room on any floor, and he won't visit the same room twice.

Example
inputCopy
4
5
00100
8
00000000
5
11111
3
110
outputCopy
6
8
10
6
Note
In the first test case Nikolay may start in the first room of the first floor. Then he moves to the second room on the first floor, and then Ñ to the third room on the first floor. Then he uses a staircase to get to the third room on the second floor. Then he goes to the fourth room on the second floor, and then Ñ to the fifth room on the second floor. So, Nikolay visits 6
6
 rooms.

There are no staircases in the second test case, so Nikolay can only visit all rooms on the same floor (if he starts in the leftmost or in the rightmost room).

In the third test case it is possible to visit all rooms: first floor, first room ?
?
 second floor, first room ?
?
 second floor, second room ?
?
 first floor, second room ?
?
 first floor, third room ?
?
 second floor, third room ?
?
 second floor, fourth room ?
?
 first floor, fourth room ?
?
 first floor, fifth room ?
?
 second floor, fifth room.

In the fourth test case it is also possible to visit all rooms: second floor, third room ?
?
 second floor, second room ?
?
 second floor, first room ?
?
 first floor, first room ?
?
 first floor, second room ?
?
 first floor, third room.
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

#define forn(i, n) for (int i = 0; i < n; i++)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; i++)
#define trav(i, a) for (auto& i : a)
#define all(a) a.begin(), a.end()
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
const ld PI = acos(-1.0);

int solve(string& s) {
    int n = sz(s);

    if (s[0] == '1' || s[n - 1] == '1')
        return 2 * n;

    bool allZeros = true;
    trav(i, s) {
        if (i == '1') {
            allZeros = false;
            break;
        }
    }

    if (allZeros)
        return n;

    int leftmostStair = s.find_first_of('1');
    int rightmostStair = s.find_last_of('1');

    return ((2 * n) - 2 * min(leftmostStair, n - 1 - rightmostStair));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    string s;
    cin >> t;

    while (t--) {
        cin >> n;
        cin >> s;
        cout << solve(s) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
