/* CF - 900 */
/*
A. Shifting Stacks
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You have n stacks of blocks. The i-th stack contains hi blocks and it's height is the number of blocks in it. In one move you can take a block from the i-th stack (if there is at least one block) and put it to the i+1-th stack. Can you make the sequence of heights strictly increasing?

Note that the number of stacks always remains n: stacks don't disappear when they have 0 blocks.

Input
First line contains a single integer t (1≤t≤104) — the number of test cases.

The first line of each test case contains a single integer n (1≤n≤100). The second line of each test case contains n integers hi (0≤hi≤109) — starting heights of the stacks.

It's guaranteed that the sum of all n does not exceed 104.

Output
For each test case output YES if you can make the sequence of heights strictly increasing and NO otherwise.

You may print each letter in any case (for example, YES, Yes, yes, yEs will all be recognized as positive answer).

Example
inputCopy
6
2
1 2
2
1 0
3
4 4 4
2
0 0
3
0 1 0
4
1000000000 1000000000 1000000000 1000000000
outputCopy
YES
YES
YES
NO
NO
YES
Note
In the first test case there is no need to make any moves, the sequence of heights is already increasing.

In the second test case we need to move one block from the first stack to the second. Then the heights become 0 1.

In the third test case we could move one block from the first stack to the second and then from the second to the third, which would make the heights 3 4 5.

In the fourth test case we can't make a move, but the sequence is not increasing, so the answer is NO.

In the fifth test case we can only make one move (from the second to the third stack), which would make the heights 0 0 1. Both 0 1 0 and 0 0 1 are not increasing sequences, so the answer is NO.
*/

/* Time Complexity: O(n) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>& a) {
    long long sum = 0;
    int need = 0;
    bool ans = true;

    for (int j = 0; j < a.size(); j++) {
        need += j;
        sum += a[j];

        if (sum < need)
            ans = false;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << (solve(a) ? "YES\n" : "NO\n");
    }

    return 0;
}
