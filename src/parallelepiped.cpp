/* CF - 1100 */
/*
A. Parallelepiped
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You've got a rectangular parallelepiped with integer edge lengths. You know the areas of its three faces that have a common vertex. Your task is to find the sum of lengths of all 12 edges of this parallelepiped.

Input
The first and the single line contains three space-separated integers — the areas of the parallelepiped's faces. The area's values are positive ( > 0) and do not exceed 104. It is guaranteed that there exists at least one parallelepiped that satisfies the problem statement.

Output
Print a single number — the sum of all edges of the parallelepiped.

Examples
inputCopy
1 1 1
outputCopy
12
inputCopy
4 6 6
outputCopy
28
Note
In the first sample the parallelepiped has sizes 1 × 1 × 1, in the second one — 2 × 2 × 3.
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

int getSum(int ac, int ab, int bc) {

    float a = sqrt(((float)ac / (float)bc) * (float)ab);
    float b = (float)ab / a;
    float c = (float)bc / b;

    return 4 * (a + b + c);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    cout << getSum(a, b, c) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
