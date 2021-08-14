/* CF - 900 */
/*
B. Permutation Sort
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a permutation a consisting of n numbers 1, 2, ..., n (a permutation is an array in which each element from 1 to n occurs exactly once).

You can perform the following operation: choose some subarray (contiguous subsegment) of a and rearrange the elements in it in any way you want. But this operation cannot be applied to the whole array.

For example, if a=[2,1,4,5,3] and we want to apply the operation to the subarray a[2,4] (the subarray containing all elements from the 2-nd to the 4-th), then after the operation, the array can become a=[2,5,1,4,3] or, for example, a=[2,1,5,4,3].

Your task is to calculate the minimum number of operations described above to sort the permutation a in ascending order.

Input
The first line contains a single integer t (1≤t≤2000) — the number of test cases.

The first line of the test case contains a single integer n (3≤n≤50) — the number of elements in the permutation.

The second line of the test case contains n distinct integers from 1 to n — the given permutation a.

Output
For each test case, output a single integer — the minimum number of operations described above to sort the array a in ascending order.

Example
inputCopy
3
4
1 3 2 4
3
1 2 3
5
2 1 4 5 3
outputCopy
1
0
2
Note
In the explanations, a[i,j] defines the subarray of a that starts from the i-th element and ends with the j-th element.

In the first test case of the example, you can select the subarray a[2,3] and swap the elements in it.

In the second test case of the example, the permutation is already sorted, so you don't need to apply any operations.

In the third test case of the example, you can select the subarray a[3,5] and reorder the elements in it so a becomes [2,1,3,4,5], and then select the subarray a[1,2] and swap the elements in it, so a becomes [1,2,3,4,5].
*/

/* Time Complexity: O(1) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

int findMinOperations(vector<int>& arr) {
    int n = arr.size();

    // if array is already sorted, 0 moves
    if (is_sorted(arr.begin(), arr.end()))
        return 0;

    // if either the first element, or last element is in correct place
    if (arr[0] == 1 || arr[n - 1] == n)
        return 1;

    // if the first element is largest, and last element is smallest
    if (arr[0] == n && arr[n - 1] == 1)
        return 3;

    return 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << findMinOperations(arr) << '\n';
    }

    return 0;
}
