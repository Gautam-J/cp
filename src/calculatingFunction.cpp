/* CF - 800 */
/*
A. Calculating Function
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
For a positive integer n let's define a function f:

f(n) =  - 1 + 2 - 3 + .. + ( - 1)nn

Your task is to calculate f(n) for a given integer n.

Input
The single line contains the positive integer n (1 ≤ n ≤ 1015).

Output
Print f(n) in a single line.

Examples
inputCopy
4
outputCopy
2
inputCopy
5
outputCopy
-3
Note
f(4) =  - 1 + 2 - 3 + 4 = 2

f(5) =  - 1 + 2 - 3 + 4 - 5 =  - 3
*/

/* Time Complexity: O(1) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

long long calculate(long long n) {
    if (n % 2 == 0)
        return n / 2;

    return ((n + 1) / 2) * (-1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    cout << calculate(n) << "\n";

    return 0;
}
