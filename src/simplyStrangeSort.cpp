/* CF - 800 */
/*
A. Simply Strange Sort
time limit per test2 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
You have a permutation: an array a=[a1,a2,…,an] of distinct integers from 1 to n. The length of the permutation n is odd.

Consider the following algorithm of sorting the permutation in increasing order.

A helper procedure of the algorithm, f(i), takes a single argument i (1≤i≤n−1) and does the following. If ai>ai+1, the values of ai and ai+1 are exchanged. Otherwise, the permutation doesn't change.

The algorithm consists of iterations, numbered with consecutive integers starting with 1. On the i-th iteration, the algorithm does the following:

if i is odd, call f(1),f(3),…,f(n−2);
if i is even, call f(2),f(4),…,f(n−1).
It can be proven that after a finite number of iterations the permutation will be sorted in increasing order.

After how many iterations will this happen for the first time?

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100). Description of the test cases follows.

The first line of each test case contains a single integer n (3≤n≤999; n is odd) — the length of the permutation.

The second line contains n distinct integers a1,a2,…,an (1≤ai≤n) — the permutation itself.

It is guaranteed that the sum of n over all test cases does not exceed 999.

Output
For each test case print the number of iterations after which the permutation will become sorted in increasing order for the first time.

If the given permutation is already sorted, print 0.

Example
inputCopy
3
3
3 2 1
7
4 5 7 1 3 2 6
5
1 2 3 4 5
outputCopy
3
5
0
Note
In the first test case, the permutation will be changing as follows:

after the 1-st iteration: [2,3,1];
after the 2-nd iteration: [2,1,3];
after the 3-rd iteration: [1,2,3].
In the second test case, the permutation will be changing as follows:

after the 1-st iteration: [4,5,1,7,2,3,6];
after the 2-nd iteration: [4,1,5,2,7,3,6];
after the 3-rd iteration: [1,4,2,5,3,7,6];
after the 4-th iteration: [1,2,4,3,5,6,7];
after the 5-th iteration: [1,2,3,4,5,6,7].
In the third test case, the permutation is already sorted and the answer is 0.
*/

/* Time Complexity: O(n^2) */
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

int solve(vi& a) {
    int n = a.size();
    int res = 0;

    while (!is_sorted(all(a))) {
        for (int i = res % 2; i + 1 < n; i += 2) {
            if (a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
        }
        res++;
    }

    return res;
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
