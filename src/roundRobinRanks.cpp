/* CC - SnackDown 2021 */
/*
A round-robin tournament is being held in Chefland among N teams numbered 1,2,...,N. Every team play with all other teams exactly once. All games have only two possible results - win or loss. A win yields 2 points to the winning team while a loss yields no points. What is the maximum number of points a team finishing at the Kth position can score?

Note: If two teams have the same points then the team with the higher team number achieves the better rank.

Input Format
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains a single line of input, two space-separated integers N,K.
Output Format
For each testcase, output in a single line an integer - the maximum points the team ranked K in the round-robin tournament can score.

Constraints
1≤T≤105
1≤K≤N≤109
Sample Input 1
3
3 3
4 1
7 4
Sample Output 1
2
6
8
Explanation
Test Case 1: There are 3 teams in the tournament. The maximum score will be achieved by the team coming 3rd when all teams win 1 match and lose the other one. Hence the maximum possible score will be 2(2⋅1) points.

Test Case 2: There are 4 teams in the tournament. The maximum score will be achieved by the team coming 1st when they beat all teams in the tournament. Hence the maximum possible score will be 6(2⋅3) points.
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

int solve(int n, int k) {
    int temp = (2 * n - k - 1) / 2;  // floor
    return temp * 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cout << solve(n, k) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
