/* CLRS, LC - Easy */
/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.



Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23


Constraints:

1 <= nums.length <= 3 * 104
-105 <= nums[i] <= 105
*/

/* The same problem can be done in O(N) time also. */

/* Time Complexity: O(N lg N) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

vector<int> findMaxCrossingSubarray(
        vector<int>& arr, int low, int mid, int high) {

    vector<int> result;
    int maxLeft, maxRight, tempSum;

    int leftSum = -INT_MAX;
    tempSum = 0;
    for (int i = mid; i >= low; i--) {
        tempSum += arr[i];
        if (tempSum > leftSum) {
            leftSum = tempSum;
            maxLeft = i;
        }
    }

    int rightSum = -INT_MAX;
    tempSum = 0;
    for (int j = mid + 1; j <= high; j++) {
        tempSum += arr[j];
        if (tempSum > rightSum) {
            rightSum = tempSum;
            maxRight = j;
        }
    }

    result.push_back(maxLeft);
    result.push_back(maxRight);
    result.push_back(leftSum + rightSum);

    return result;
}

vector<int> findMaxSubarray(vector<int>& arr, int low, int high) {

    // base case, if only one element
    if (low == high) {
        vector<int> result;

        result.push_back(low);
        result.push_back(high);
        result.push_back(arr[low]);

        return result;
    }

    int mid = (low + high) / 2;  // floor division

    vector<int> left = findMaxSubarray(arr, low, mid);
    vector<int> right = findMaxSubarray(arr, mid + 1, high);
    vector<int> cross = findMaxCrossingSubarray(arr, low, mid, high);

    int leftSum = left[2];
    int rightSum = right[2];
    int crossSum = cross[2];

    if (leftSum >= rightSum && leftSum >= crossSum)
        return left;

    if (rightSum >= leftSum && rightSum >= crossSum)
        return right;

    return cross;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    // get user input
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // calculate maximum subarray
    vector<int> result = findMaxSubarray(arr, 0, n - 1);

    int leftIndex = result[0];
    int rightIndex = result[1];
    int sumOfMaxSubarray = result[2];

    auto start = arr.begin() + leftIndex;
    auto end = arr.begin() + leftIndex + rightIndex + 1;

    vector<int> maxSubarray(rightIndex - leftIndex + 1);
    copy(start, end, maxSubarray.begin());

    // print the maxSubarray and its sum
    cout << "Maximum Subarray: ";
    for (int i = 0; i < maxSubarray.size(); i++)
        cout << maxSubarray[i] << ' ';

    cout << '\n' << "Sum: " << sumOfMaxSubarray << '\n';

    return 0;
}
