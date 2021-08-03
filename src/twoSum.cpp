/* CLRS, LC - Easy */
/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
*/

/* Using hashmaps, we can solve it in O(N) time. */

/* Time Complexity: O(N lg N) */
/* Space Complexity: O(N) */

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& arr, int x) {
    vector<int> result;

    // sort the given array O(n lg n)
    sort(arr.begin(), arr.end());

    // use binary search to check if elements add upto x O(n lg n)
    int low = 0;
    int high = arr.size() - 1;
    while (low < high) {

        if (arr[low] + arr[high] == x) {
            result.push_back(low);
            result.push_back(high);
            return result;
        }

        if (arr[low] + arr[high] > x)
            high--;
        else
            low++;
    }

    // not necessary
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n;

    // get user input
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> x;

    // get indices
    vector<int> result = twoSum(arr, x);

    // output
    for (auto x : result) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}
