/* CF - 1200 */
/*
A. Shooshuns and Sequence
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
One day shooshuns found a sequence of n integers, written on a blackboard. The shooshuns can perform one operation with it, the operation consists of two steps:

Find the number that goes k-th in the current sequence and add the same number to the end of the sequence;
Delete the first number of the current sequence.
The shooshuns wonder after how many operations all numbers on the board will be the same and whether all numbers will ever be the same.

Input
The first line contains two space-separated integers n and k (1 ≤ k ≤ n ≤ 105).

The second line contains n space-separated integers: a1, a2, ..., an (1 ≤ ai ≤ 105) — the sequence that the shooshuns found.

Output
Print the minimum number of operations, required for all numbers on the blackboard to become the same. If it is impossible to achieve, print -1.

Examples
inputCopy
3 2
3 1 1
outputCopy
1
inputCopy
3 1
3 1 1
outputCopy
-1
Note
In the first test case after the first operation the blackboard will have sequence [1, 1, 1]. So, one operation is enough to make all numbers the same. Thus, the answer equals one.

In the second test case the sequence will never consist of the same numbers. It will always contain at least two distinct numbers 3 and 1. Thus, the answer equals -1.

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

int solve(vi& a, int k) {

    int n = sz(a);
    int last = 0, cnt = 1;
    trav(i, a) {
        if (i == last)
            cnt++;
        else
            cnt = 1;

        last = i;
    }

    return (cnt + k > n ? n - cnt : -1);

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vi a(n);
    trav(i, a)
        cin >> i;

    cout << solve(a, k) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
