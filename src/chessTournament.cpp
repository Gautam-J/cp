/* CF - 1000 */
/*
B. Chess Tournament
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
A chess tournament will be held soon, where n chess players will take part. Every participant will play one game against every other participant. Each game ends in either a win for one player and a loss for another player, or a draw for both players.

Each of the players has their own expectations about the tournament, they can be one of two types:

a player wants not to lose any game (i. e. finish the tournament with zero losses);
a player wants to win at least one game.
You have to determine if there exists an outcome for all the matches such that all the players meet their expectations. If there are several possible outcomes, print any of them. If there are none, report that it's impossible.

Input
The first line contains a single integer t (1≤t≤200) — the number of test cases.

The first line of each test case contains one integer n (2≤n≤50) — the number of chess players.

The second line contains the string s (|s|=n; si∈{1,2}). If si=1, then the i-th player has expectations of the first type, otherwise of the second type.

Output
For each test case, print the answer in the following format:

In the first line, print NO if it is impossible to meet the expectations of all players.

Otherwise, print YES, and the matrix of size n×n in the next n lines.

The matrix element in the i-th row and j-th column should be equal to:

+, if the i-th player won in a game against the j-th player;
-, if the i-th player lost in a game against the j-th player;
=, if the i-th and j-th players' game resulted in a draw;
X, if i=j.
Example
inputCopy
3
3
111
2
21
4
2122
outputCopy
YES
X==
=X=
==X
NO
YES
X--+
+X++
+-X-
--+X
*/

/* Time Complexity: O(n) */
/* Space Complexity: O(n^2) */

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

void solve(string& s) {
    int n = sz(s);

    vi id;
    FOR(i, n) {
        if (s[i] == '2')
            id.push_back(i);
    }

    int k = sz(id);
    if (k == 1 || k == 2) {
        cout << "NO" << nl;
        return;
    }

    // initialize as =
    vector<string> t(n, string(n, '='));
    FOR(i, n)
        t[i][i] = 'X';

    int x, y;
    FOR(i, k) {
        x = id[i];
        y = id[(i + 1) % k];
        t[x][y] = '+';
        t[y][x] = '-';
    }

    cout << "YES" << nl;
    FOR(i, n)
        cout << t[i] << nl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    string s;
    while (t--) {
        cin >> n;
        cin >> s;

        solve(s);
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
