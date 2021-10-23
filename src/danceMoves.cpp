/* CC - SnackDown 2021 */
/*
This year Chef is participating in a Dancing competition. The dance performance will be done on a linear stage marked with integral positions. Initially, Chef is present at position X and Chef's dance partner is at position Y. Chef can perform two kinds of dance moves.

If Chef is currently at position k, Chef can:

Moonwalk to position k+2, or
Slide to position k−1
Chef wants to find the minimum number of moves required to reach his partner. Can you help him find this number?

Input Format
First line will contain a single integer T, the number of testcases. Then the description of T testcases follows.
Each testcase contains a single line with two space-separated integers X,Y, representing the initial positions of Chef and his dance partner, respectively.
Output Format
For each testcase, print in a separate line, a single integer, the minimum number of moves required by Chef to reach his dance partner.

Constraints
1≤T≤103
−103≤X,Y≤103
Sample Input 1
4
3 8
-11 -5
57 492
-677 913
Sample Output 1
4
3
219
795
Explanation
Test Case 1: Chef will perform Moonwalk thrice, followed by a slide reaching at position 8. This makes 4 dance steps in total.
Test Case 2: Performing Moonwalk thrice will take Chef to his dance partner.
*/

/* Time Complexity: O(1) */
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

int solve(int x, int y) {
    if (x == y)
        return 0;

    if (x > y)
        return x - y;

    int steps = ceil((float)(y - x) / (float)2);
    if (x + (steps * 2) > y)
        return steps + 1;

    return steps;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, x, y;
    cin >> t;
    while (t--) {
        cin >> x >> y;
        cout << solve(x, y) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
