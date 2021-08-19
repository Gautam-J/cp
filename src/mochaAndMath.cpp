/* CF - 900 */
/*
A. Mocha and Math
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Mocha is a young girl from high school. She has learned so much interesting knowledge from her teachers, especially her math teacher. Recently, Mocha is learning about binary system and very interested in bitwise operation.

This day, Mocha got a sequence a of length n. In each operation, she can select an arbitrary interval [l,r] and for all values i (0≤i≤r−l), replace al+i with al+i&ar−i at the same time, where & denotes the bitwise AND operation. This operation can be performed any number of times.

For example, if n=5, the array is [a1,a2,a3,a4,a5], and Mocha selects the interval [2,5], then the new array is [a1,a2&a5,a3&a4,a4&a3,a5&a2].

Now Mocha wants to minimize the maximum value in the sequence. As her best friend, can you help her to get the answer?

Input
Each test contains multiple test cases.

The first line contains a single integer t (1≤t≤100) — the number of test cases. Each test case consists of two lines.

The first line of each test case contains a single integer n (1≤n≤100) — the length of the sequence.

The second line of each test case contains n integers a1,a2,…,an (0≤ai≤109).

Output
For each test case, print one integer — the minimal value of the maximum value in the sequence.

Example
inputCopy
4
2
1 2
3
1 1 3
4
3 11 3 7
5
11 7 15 3 7
outputCopy
0
1
3
3
Note
In the first test case, Mocha can choose the interval [1,2], then the sequence becomes [0,0], where the first element is 1&2, and the second element is 2&1.

In the second test case, Mocha can choose the interval [1,3], then the sequence becomes [1,1,1], where the first element is 1&3, the second element is 1&1, and the third element is 3&1.

*/

/* Time Complexity: O(n) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef vector<int> vi;

int solve(vi& a) {
    int n = a.size();
    int result = a[0];

    for (int i = 1; i < n; i++)
        result &= a[i];

    return result;
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
        cout << solve(a) << '\n';
    }

    return 0;
}
