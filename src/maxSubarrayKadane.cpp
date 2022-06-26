/* CLRS, LC - Easy, grind 10 */
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

/* The same problem can be done in (N lg N) also. */

/* Time Complexity: O(N) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

vector<int> findMaxSubarray(vector<int>& arr) {
    // Algorithm 1
    // Initialize globalMax to -inf, localMax
    // Iterate through the array
    // localMax = max(localMax + a[i], a[i])
    // globalMax = max(globalMax, localMax)
    // Finally return globalMax
    //
    // Another variant of the same algorithm
    // Initialize globalMax to -inf, localMax
    // Iterate through the array
    // localMax += a[i]
    // globalMax = max(globalMax, localMax)
    // localMax = max(localMax, 0)
    // Finally return globalMax
    //
    // Time: O(n)
    // Space: O(1)

    vector<int> result;
    int bestLeft, bestRight, temp;

    int maxSum = INT_MIN;
    int left = 0;
    int sum = 0;

    for (int i = 0; i < arr.size(); i++) {
       temp = sum + arr[i];

       // sum = max(temp, arr[i])
       if (temp > arr[i]) {
           sum = temp;
       } else {  // after adding A[j], if the sum value decreases, then we start a new subarray
           sum = arr[i];
           left = i;
       }

       // maxSum = max(maxSum, sum)
       if (maxSum < sum) {
           maxSum = sum;
           bestLeft = left;
           bestRight = i;
       }
    }

    result.push_back(bestLeft);
    result.push_back(bestRight);
    result.push_back(maxSum);

    return result;
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
    vector<int> result = findMaxSubarray(arr);

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
