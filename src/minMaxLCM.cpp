/* CC - SnackDown 2021 */
/*
You are given two positive integers X and K.

You have to output the minimum and maximum value of LCM(i,j) where X≤i<j≤X⋅K.

We define LCM(i,j) for two positive integers i and j as the minimum positive integer y such that both i and j divide y without remainder.

Input Format
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, two space separated integers X and K.
Output Format
For each testcase, output two space separated integers - the minimum and maximum possible value respectively of LCM(i,j) where X≤i<j≤X⋅K.

Constraints
1≤T≤105
1≤X≤108
2≤K≤108
It is guaranteed that, for each test case, X⋅K≤109
Sample Input 1
2
4 3
2 3
Sample Output 1
8 132
4 30
Explanation
Test Case 1: We want to find the minimum and maximum value of LCM(i,j) for 4≤i<j≤12. It is easy to verify that the LCM(4,8)=8 is the minimum possible value whereas LCM(11,12)=132 is the maximum value.

Test Case 2: We want to find the minimum and maximum value of LCM(i,j) for 2≤i<j≤6. The maximum value is obtained for the pair (5,6) whereas the minimum is obtained for the pair (2,4).
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    ll x, y;
    cin >> t;
    while (t--) {
        cin >> x >> y;
        cout << 2 * x << " ";
        cout << x * y * (x * y - 1) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
