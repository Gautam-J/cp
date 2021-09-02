/* CF - 1200 */
/*
A. DZY Loves Chessboard
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
DZY loves chessboard, and he enjoys playing with it.

He has a chessboard of n rows and m columns. Some cells of the chessboard are bad, others are good. For every good cell, DZY wants to put a chessman on it. Each chessman is either white or black. After putting all chessmen, DZY wants that no two chessmen with the same color are on two adjacent cells. Two cells are adjacent if and only if they share a common edge.

You task is to find any suitable placement of chessmen on the given chessboard.

Input
The first line contains two space-separated integers n and m (1 ≤ n, m ≤ 100).

Each of the next n lines contains a string of m characters: the j-th character of the i-th string is either "." or "-". A "." means that the corresponding cell (in the i-th row and the j-th column) is good, while a "-" means it is bad.

Output
Output must contain n lines, each line must contain a string of m characters. The j-th character of the i-th string should be either "W", "B" or "-". Character "W" means the chessman on the cell is white, "B" means it is black, "-" means the cell is a bad cell.

If multiple answers exist, print any of them. It is guaranteed that at least one answer exists.

Examples
inputCopy
1 1
.
outputCopy
B
inputCopy
2 2
..
..
outputCopy
BW
WB
inputCopy
3 3
.-.
---
--.
outputCopy
B-B
---
--B
Note
In the first sample, DZY puts a single black chessman. Of course putting a white one is also OK.

In the second sample, all 4 cells are good. No two same chessmen share an edge in the sample output.

In the third sample, no good cells are adjacent. So you can just put 3 chessmen, no matter what their colors are.
*/

/* Time Complexity: O(nm) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define trav(i, a) for (auto& i : a)
#define debug(x) cout << "[DEBUG] " << #x << "=" << x << '\n'

typedef long long ll;
typedef vector<int> vi;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';
const double PI = acos(-1);

void printBoard(vector<vector<char>>& a, int n, int m) {
    // WBWBWBWBWB
    // BWBWBWBWBW
    // WBWBWBWBWB
    // except for '-'

    char startPlayer = 'B';
    char player = 'W';

    for (int i = 0; i < n; i++) {
        if (a[i][0] != '-')
            a[i][0] = startPlayer;

        for (int j = 1; j < m; j++) {
            if (j == 1) {
                if (startPlayer == 'B')
                    player = 'W';
                else
                    player = 'B';
            }

            if (a[i][j] != '-') {
                a[i][j] = player;
            }

            if (player == 'B')
                player = 'W';
            else
                player = 'B';
        }

        if (startPlayer == 'B')
            startPlayer = 'W';
        else
            startPlayer = 'B';
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j];
        }
        cout << nl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> a(n, vector<char> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    printBoard(a, n, m);

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
