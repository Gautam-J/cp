/* CF - 800 */
/*
A. Closing The Gap
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
There are n block towers in a row, where tower i has a height of ai. You're part of a building crew, and you want to make the buildings look as nice as possible. In a single day, you can perform the following operation:

Choose two indices i and j (1≤i,j≤n; i≠j), and move a block from tower i to tower j. This essentially decreases ai by 1 and increases aj by 1.
You think the ugliness of the buildings is the height difference between the tallest and shortest buildings. Formally, the ugliness is defined as max(a)−min(a).

What's the minimum possible ugliness you can achieve, after any number of days?

Input
The first line contains one integer t (1≤t≤1000) — the number of test cases. Then t cases follow.

The first line of each test case contains one integer n (2≤n≤100) — the number of buildings.

The second line of each test case contains n space separated integers a1,a2,…,an (1≤ai≤107) — the heights of the buildings.

Output
For each test case, output a single integer — the minimum possible ugliness of the buildings.

Example
inputCopy
3
3
10 10 10
4
3 2 1 2
5
1 2 3 1 5
outputCopy
0
0
1
Note
In the first test case, the ugliness is already 0.

In the second test case, you should do one operation, with i=1 and j=3. The new heights will now be [2,2,2,2], with an ugliness of 0.

In the third test case, you may do three operations:

with i=3 and j=1. The new array will now be [2,2,2,1,5],
with i=5 and j=4. The new array will now be [2,2,2,2,4],
with i=5 and j=3. The new array will now be [2,2,3,2,3].
The resulting ugliness is 1. It can be proven that this is the minimum possible ugliness for this test.
*/

/* Time Complexity: O(n) */
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
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';
const double PI = acos(-1);

int solve(vi& a) {
    int n = sz(a), sum = 0;
    trav(i, a)
        sum += i;

    return sum % n == 0 ? 0 : 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vi a(n);

        trav(i, a)
            cin >> i;

        cout << solve(a) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
