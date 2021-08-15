/* CF - 900 */
/*
A. Subset Mex
time limit per test1 second
memory limit per test512 megabytes
inputstandard input
outputstandard output
Given a set of integers (it can contain equal elements).

You have to split it into two subsets A and B (both of them can contain equal elements or be empty). You have to maximize the value of mex(A)+mex(B).

Here mex of a set denotes the smallest non-negative integer that doesn't exist in the set. For example:

mex({1,4,0,2,2,1})=3
mex({3,3,2,1,3,0,0})=4
mex(∅)=0 (mex for empty set)
The set is splitted into two subsets A and B if for any integer number x the number of occurrences of x into this set is equal to the sum of the number of occurrences of x into A and the number of occurrences of x into B.

Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤100) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer n (1≤n≤100) — the size of the set.

The second line of each testcase contains n integers a1,a2,…an (0≤ai≤100) — the numbers in the set.

Output
For each test case, print the maximum value of mex(A)+mex(B).

Example
inputCopy
4
6
0 2 1 5 0 1
3
0 1 2
4
0 2 0 1
6
1 2 3 4 5 6
outputCopy
5
3
4
0
Note
In the first test case, A={0,1,2},B={0,1,5} is a possible choice.

In the second test case, A={0,1,2},B=∅ is a possible choice.

In the third test case, A={0,1,2},B={0} is a possible choice.

In the fourth test case, A={1,3,5},B={2,4,6} is a possible choice.
*/

/* Time Complexity: O(n) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef vector<int> vi;

int maxValue(vi& a) {
    int mexA = 0, mexB = 0;
    int n = a.size();
    vi cnt(103);

    FOR(i, n)
        cnt[a[i]]++;

    FOR(i, 101) {
        if (cnt[i] < 2) {
            mexA = i;
            break;
        }
    }

    if (!cnt[mexA])
        mexB = mexA;
    else {
        for (int i = mexA + 1; i < 101; i++)
            if (cnt[i] < 1) {
                mexB = i;
                break;
            }
    }

    return mexA + mexB;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vi a(n);
        for (int& x : a)
            cin >> x;

        cout << maxValue(a) << '\n';
    }

    return 0;
}
