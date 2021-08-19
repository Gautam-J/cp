/* LC - Easy */
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


Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/

/* Time Complexity: O(n) */
/* Space Complexity: O(n) */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define trav(a, x) for (auto& a : x)

typedef long long ll;
typedef vector<int> vi;

const char nl = '\n';

/* 3 2 4 | 6 */

vi getIndices(vi& nums, int target) {
    vi res;

    int diff, n = nums.size();
    map<int, int> dp; // map i to index of i

    // what number must be added to nums[i] to get target
    /* dp[nums[i]] = target - i */

    for (int i = 0; i < n; i++) {
        diff = target - nums[i];

        if (dp.find(diff) != dp.end()) {
            res.push_back(dp[diff]);
            res.push_back(i);
            return res;
        }

        dp[nums[i]] = i;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, target;
    cin >> n;

    vi a(n);
    trav(i, a)
        cin >> i;
    cin >> target;

    vi res = getIndices(a, target);
    cout << res[0] << " " << res[1] << nl;

    return 0;
}
