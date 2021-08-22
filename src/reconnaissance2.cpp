/* CF - 800 */
/*
A. Reconnaissance 2
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
n soldiers stand in a circle. For each soldier his height ai is known. A reconnaissance unit can be made of such two neighbouring soldiers, whose heights difference is minimal, i.e. |ai - aj| is minimal. So each of them will be less noticeable with the other. Output any pair of soldiers that can form a reconnaissance unit.

Input
The first line contains integer n (2 ≤ n ≤ 100) — amount of soldiers. Then follow the heights of the soldiers in their order in the circle — n space-separated integers a1, a2, ..., an (1 ≤ ai ≤ 1000). The soldier heights are given in clockwise or counterclockwise direction.

Output
Output two integers — indexes of neighbouring soldiers, who should form a reconnaissance unit. If there are many optimum solutions, output any of them. Remember, that the soldiers stand in a circle.

Examples
inputCopy
5
10 12 13 15 10
outputCopy
5 1
inputCopy
4
10 20 30 40
outputCopy
1 2
*/

/* Time Complexity: O(n) */
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

void minPair(vi& a) {
    int n = a.size();
    int pairStart;

    int best = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        if (abs(a[i] - a[i + 1]) < best) {
            best = abs(a[i] - a[i + 1]);
            pairStart = i + 1;
        }
    }

    if (abs(a[0] - a[n - 1]) < best)
        pairStart = n;

    cout << pairStart << " ";
    cout << (pairStart == n ? 1 : pairStart + 1) << nl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vi a(n);
    trav(i, a)
        cin >> i;

    minPair(a);

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
