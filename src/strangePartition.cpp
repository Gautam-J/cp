/* CF - 900 */
/*
A. Strange Partition
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array a of length n, and an integer x. You can perform the following operation as many times as you would like (possibly zero): replace two adjacent elements of the array by their sum. For example, if the initial array was [3,6,9], in a single operation one can replace the last two elements by their sum, yielding an array [3,15], or replace the first two elements to get an array [9,9]. Note that the size of the array decreases after each operation.

The beauty of an array b=[b1,…,bk] is defined as ∑ki=1⌈bix⌉, which means that we divide each element by x, round it up to the nearest integer, and sum up the resulting values. For example, if x=3, and the array is [4,11,6], the beauty of the array is equal to ⌈43⌉+⌈113⌉+⌈63⌉=2+4+2=8.

Please determine the minimum and the maximum beauty you can get by performing some operations on the original array.

Input
The first input line contains a single integer t — the number of test cases (1≤t≤1000).

The first line of each test case contains two integers n and x (1≤n≤105, 1≤x≤109).

The next line contains n integers a1,a2,…,an (1≤ai≤109), the elements of the array a.

It is guaranteed that the sum of values of n over all test cases does not exceed 105.

Output
For each test case output two integers — the minimal and the maximal possible beauty.

Example
inputCopy
2
3 3
3 6 9
3 3
6 4 11
outputCopy
6 6
7 8
Note
In the first test case the beauty of the array does not change if we perform any operations.

In the second example we can leave the array unchanged to attain the maximum beauty, and to get the minimum beauty one can replace two elements 4 and 11 with their sum, yielding an array [6,15], which has its beauty equal to 7.
*/

/* Time Complexity: O(n) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef vector<int> vi;

void findMinAndMax(vi& arr, int x) {
    int n = arr.size();
    ll sum = 0;
    ll min = 0;
    ll max = 0;

    FOR(i, n) {
        max += ceil((double)arr[i] / (double)x);
        sum += arr[i];
    }

    min = ceil((double)sum / (double)x);

    cout << min << " " << max << '\n';

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, x;
    cin >> t;

    while (t--) {
        cin >> n >> x;
        vi arr(n);
        FOR(i, n)
            cin >> arr[i];

        findMinAndMax(arr, x);
    }

    return 0;
}
