/* CF - 1000 */
/*
A. Jzzhu and Children
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
There are n children in Jzzhu's school. Jzzhu is going to give some candies to them. Let's number all the children from 1 to n. The i-th child wants to get at least ai candies.

Jzzhu asks children to line up. Initially, the i-th child stands at the i-th place of the line. Then Jzzhu start distribution of the candies. He follows the algorithm:

Give m candies to the first child of the line.
If this child still haven't got enough candies, then the child goes to the end of the line, else the child go home.
Repeat the first two steps while the line is not empty.
Consider all the children in the order they go home. Jzzhu wants to know, which child will be the last in this order?

Input
The first line contains two integers n, m (1 ≤ n ≤ 100; 1 ≤ m ≤ 100). The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 100).

Output
Output a single integer, representing the number of the last child.

Examples
inputCopy
5 2
1 3 1 4 2
outputCopy
4
inputCopy
6 4
1 1 2 2 3 3
outputCopy
6
Note
Let's consider the first sample.

Firstly child 1 gets 2 candies and go home. Then child 2 gets 2 candies and go to the end of the line. Currently the line looks like [3, 4, 5, 2] (indices of the children in order of the line). Then child 3 gets 2 candies and go home, and then child 4 gets 2 candies and goes to the end of the line. Currently the line looks like [5, 2, 4]. Then child 5 gets 2 candies and goes home. Then child 2 gets two candies and goes home, and finally child 4 gets 2 candies and goes home.

Child 4 is the last one who goes home.

*/

/* Both the given solutions are accepted in codeforces. */

/* Time Complexity: O(n) */
/* Space Complexity: O(n) and O(1) for the second. */

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

int getLastChild(vi& a, int m) {
    // simulating the entire process using a queue
    // index -> child
    map<int, int> child;

    int n = a.size();
    FOR(i, n)
        child[i + 1] = a[i];

    queue<int> line;
    for (int i = 1; i <= n; i++)
        line.push(i);

    int i;
    while (line.size() > 1) {
        i = line.front();
        line.pop();

        if (child[i] - m > 0) {
            line.push(i);
            child[i] -= m;
        }
    }

    return line.front();
}

int getLastChild2(vi& a, int m) {
    // optimal answer
    int n = a.size();
    int res = 0;
    int best = INT_MIN;

    int tries;
    FOR(i, n) {
        tries = ceil((float)a[i] / (float)m);
        if (tries >= best) {
            best = tries;
            res = i + 1;
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vi a(n);
    trav(i, a)
        cin >> i;

    cout << getLastChild2(a, m) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
