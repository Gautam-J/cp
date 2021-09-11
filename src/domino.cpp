/* CF - 1200 */
/*
A. Domino
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Valera has got n domino pieces in a row. Each piece consists of two halves — the upper one and the lower one. Each of the halves contains a number from 1 to 6. Valera loves even integers very much, so he wants the sum of the numbers on the upper halves and the sum of the numbers on the lower halves to be even.

To do that, Valera can rotate the dominoes by 180 degrees. After the rotation the upper and the lower halves swap places. This action takes one second. Help Valera find out the minimum time he must spend rotating dominoes to make his wish come true.

Input
The first line contains integer n (1 ≤ n ≤ 100), denoting the number of dominoes Valera has. Next n lines contain two space-separated integers xi, yi (1 ≤ xi, yi ≤ 6). Number xi is initially written on the upper half of the i-th domino, yi is initially written on the lower half.

Output
Print a single number — the minimum required number of seconds. If Valera can't do the task in any time, print  - 1.

Examples
inputCopy
2
4 2
6 4
outputCopy
0
inputCopy
1
2 3
outputCopy
-1
inputCopy
3
1 4
2 3
4 4
outputCopy
1
Note
In the first test case the sum of the numbers on the upper halves equals 10 and the sum of the numbers on the lower halves equals 6. Both numbers are even, so Valera doesn't required to do anything.

In the second sample Valera has only one piece of domino. It is written 3 on the one of its halves, therefore one of the sums will always be odd.

In the third case Valera can rotate the first piece, and after that the sum on the upper halves will be equal to 10, and the sum on the lower halves will be equal to 8.

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
typedef vector<int> vi;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';
const double PI = acos(-1);

int solve(vi& upp, vi& low) {
    int uppSum = 0, lowSum = 0;

    int n = sz(upp);
    FOR(i, n) {
        uppSum += upp[i];
        lowSum += low[i];
    }

    if (uppSum % 2 == 0 && lowSum % 2 == 0)
        return 0;

    if (uppSum % 2 != 0 && lowSum % 2 != 0) {
        FOR(i, n) {
            if (upp[i] % 2 == 0 && low[i] % 2 != 0)
                return 1;
            if (upp[i] % 2 != 0 && low[i] % 2 == 0)
                return 1;
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vi upp, low;
    int x, y;
    FOR(i, n) {
        cin >> x >> y;
        upp.push_back(x);
        low.push_back(y);
    }

    cout << solve(upp, low) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
