/* CF - 800 */
/*
A. CQXYM Count Permutations
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
CQXYM is counting permutations length of 2n.

A permutation is an array consisting of n distinct integers from 1 to n in arbitrary order. For example, [2,3,1,5,4] is a permutation, but [1,2,2] is not a permutation (2 appears twice in the array) and [1,3,4] is also not a permutation (n=3 but there is 4 in the array).

A permutation p(length of 2n) will be counted only if the number of i satisfying pi<pi+1 is no less than n. For example:

Permutation [1,2,3,4] will count, because the number of such i that pi<pi+1 equals 3 (i=1, i=2, i=3).
Permutation [3,2,1,4] won't count, because the number of such i that pi<pi+1 equals 1 (i=3).
CQXYM wants you to help him to count the number of such permutations modulo 1000000007 (109+7).

In addition, modulo operation is to get the remainder. For example:

7mod3=1, because 7=3⋅2+1,
15mod4=3, because 15=4⋅3+3.
Input
The input consists of multiple test cases.

The first line contains an integer t(t≥1) — the number of test cases. The description of the test cases follows.

Only one line of each test case contains an integer n(1≤n≤105).

It is guaranteed that the sum of n over all test cases does not exceed 105
Output
For each test case, print the answer in a single line.

Example
inputCopy
4
1
2
9
91234
outputCopy
1
12
830455698
890287984
Note
n=1, there is only one permutation that satisfies the condition: [1,2].
In permutation [1,2], p1<p2, and there is one i=1 satisfy the condition. Since 1≥n, this permutation should be counted. In permutation [2,1], p1>p2. Because 0<n, this permutation should not be counted.

n=2, there are 12 permutations: [1,2,3,4],[1,2,4,3],[1,3,2,4],[1,3,4,2],[1,4,2,3],[2,1,3,4],[2,3,1,4],[2,3,4,1],[2,4,1,3],[3,1,2,4],[3,4,1,2],[4,1,2,3].
*/

/* Time Complexity: O(n) */
/* Space Complexity: O(n) */

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
const ll MOD = 1000000007;
int f[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    f[1] = 1;
    for (int i = 2; i < 100001; i++)
        f[i] = ((i<<1)-1ll) * f[i-1]%MOD * (i<<1)%MOD;


    int t;
    cin >> t;

    ll n;
    while (t--) {
        cin >> n;
        cout << f[n] << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
