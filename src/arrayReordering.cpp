/* CF - 900 */
/*
B. Array Reodering
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array a consisting of n integers.

Let's call a pair of indices i, j good if 1≤i<j≤n and gcd(ai,2aj)>1 (where gcd(x,y) is the greatest common divisor of x and y).

Find the maximum number of good index pairs if you can reorder the array a in an arbitrary way.

Input
The first line contains a single integer t (1≤t≤1000) — the number of test cases.

The first line of the test case contains a single integer n (2≤n≤2000) — the number of elements in the array.

The second line of the test case contains n integers a1,a2,…,an (1≤ai≤105).

It is guaranteed that the sum of n over all test cases does not exceed 2000.

Output
For each test case, output a single integer — the maximum number of good index pairs if you can reorder the array a in an arbitrary way.

Example
inputCopy
3
4
3 6 5 3
2
1 7
5
1 4 2 4 1
outputCopy
4
0
9
Note
In the first example, the array elements can be rearranged as follows: [6,3,5,3].

In the third example, the array elements can be rearranged as follows: [4,4,2,1,1].
*/

/* Time Complexity: O(n^2) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        // place all even numbers first, then odd numbers
        sort(arr.begin(), arr.end(), [](int x, int y) {
            return x % 2 < y % 2;
        });

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++)
                ans += __gcd(arr[i], arr[j] * 2) > 1;
        }

        cout << ans << '\n';
    }

    return 0;
}
