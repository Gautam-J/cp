/* CF - 800 */
/*
A. Perfect Permutation
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
A permutation is a sequence of integers p1, p2, ..., pn, consisting of n distinct positive integers, each of them doesn't exceed n. Let's denote the i-th element of permutation p as pi. We'll call number n the size of permutation p1, p2, ..., pn.

Nickolas adores permutations. He likes some permutations more than the others. He calls such permutations perfect. A perfect permutation is such permutation p that for any i (1 ≤ i ≤ n) (n is the permutation size) the following equations hold ppi = i and pi ≠ i. Nickolas asks you to print any perfect permutation of size n for the given n.

Input
A single line contains a single integer n (1 ≤ n ≤ 100) — the permutation size.

Output
If a perfect permutation of size n doesn't exist, print a single integer -1. Otherwise print n distinct integers from 1 to n, p1, p2, ..., pn — permutation p, that is perfect. Separate printed numbers by whitespaces.

Examples
inputCopy
1
outputCopy
-1
inputCopy
2
outputCopy
2 1
inputCopy
4
outputCopy
2 1 4 3
*/

/* Time Complexity: O(n) */
/* Space Complexity: O(n) */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define trav(a, x) for (auto& a : x)

typedef long long ll;
typedef vector<int> vi;

const char nl = '\n';

void printPermutation(int n) {
    if (n % 2 != 0) {
        cout << -1 << nl;
        return;
    }

    int res[n];
    FOR(i, n)
        res[i] = i + 1;

    int temp;
    for (int i = 0; i < n; i += 2)  {
        temp = res[i];
        res[i] = res[i + 1];
        res[i + 1] = temp;
    }

    FOR(i, n)
        cout << res[i] << " ";
    cout << nl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    printPermutation(n);

    return 0;
}
