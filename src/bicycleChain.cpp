/* CF - 900 */
/*
A. Bicycle Chain
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vasya's bicycle chain drive consists of two parts: n stars are attached to the pedal axle, m stars are attached to the rear wheel axle. The chain helps to rotate the rear wheel by transmitting the pedal rotation.

We know that the i-th star on the pedal axle has ai (0 < a1 < a2 < ... < an) teeth, and the j-th star on the rear wheel axle has bj (0 < b1 < b2 < ... < bm) teeth. Any pair (i, j) (1 ≤ i ≤ n; 1 ≤ j ≤ m) is called a gear and sets the indexes of stars to which the chain is currently attached. Gear (i, j) has a gear ratio, equal to the value .

Since Vasya likes integers, he wants to find such gears (i, j), that their ratios are integers. On the other hand, Vasya likes fast driving, so among all "integer" gears (i, j) he wants to choose a gear with the maximum ratio. Help him to find the number of such gears.

In the problem, fraction  denotes division in real numbers, that is, no rounding is performed.

Input
The first input line contains integer n (1 ≤ n ≤ 50) — the number of stars on the bicycle's pedal axle. The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 104) in the order of strict increasing.

The third input line contains integer m (1 ≤ m ≤ 50) — the number of stars on the rear wheel axle. The fourth line contains m integers b1, b2, ..., bm (1 ≤ bi ≤ 104) in the order of strict increasing.

It is guaranteed that there exists at least one gear (i, j), that its gear ratio is an integer. The numbers on the lines are separated by spaces.

Output
Print the number of "integer" gears with the maximum ratio among all "integer" gears.

Examples
inputCopy
2
4 5
3
12 13 15
outputCopy
2
inputCopy
4
1 2 3 4
5
10 11 12 13 14
outputCopy
1
Note
In the first sample the maximum "integer" gear ratio equals 3. There are two gears that have such gear ratio. For one of them a1 = 4, b1 = 12, and for the other a2 = 5, b3 = 15.
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

int maxGear(vi& a, vi& b) {

    int maxRatio = INT_MIN, cnt = 0;
    trav(j, b) {
        trav(i, a) {
            if (j % i == 0) {
                if ((j / i) > maxRatio) {
                    maxRatio = (j / i);
                    cnt = 1;
                } else if ((j / i) == maxRatio) {
                    cnt++;
                }
            }
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n;
    vi a(n);
    trav(i, a)
        cin >> i;

    cin >> m;
    vi b(m);
    trav(j, b)
        cin >> j;

    cout << maxGear(a, b) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
