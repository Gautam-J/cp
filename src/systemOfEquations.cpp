/* CF - 800 */
/*
A. System of Equations
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Furik loves math lessons very much, so he doesn't attend them, unlike Rubik. But now Furik wants to get a good mark for math. For that Ms. Ivanova, his math teacher, gave him a new task. Furik solved the task immediately. Can you?

You are given a system of equations:


You should count, how many there are pairs of integers (a, b) (0 ≤ a, b) which satisfy the system.

Input
A single line contains two integers n, m (1 ≤ n, m ≤ 1000) — the parameters of the system. The numbers on the line are separated by a space.

Output
On a single line print the answer to the problem.

Examples
inputCopy
9 3
outputCopy
1
inputCopy
14 28
outputCopy
1
inputCopy
4 20
outputCopy
0
Note
In the first sample the suitable pair is integers (3, 0). In the second sample the suitable pair is integers (3, 5). In the third sample there is no suitable pair.
*/

/* Time Complexity: O(1) */
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

int solve(int n, int m) {
    int res = 0;

    FOR(i, 1001) {
        FOR(j, 1001) {
            if (pow(i, 2) + j == n && pow(j, 2) + i == m)
                res++;
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    cout << solve(n, m) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
