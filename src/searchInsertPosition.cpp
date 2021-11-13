/* LC - Easy */
/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
Example 4:

Input: nums = [1,3,5,6], target = 0
Output: 0
Example 5:

Input: nums = [1], target = 0
Output: 0


Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
*/

/* Time Complexity: O(log n) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define trav(i, a) for (auto& i : a)

#ifdef _GLIBCXX_DEBUG
#define debug(x) cerr << "\e[91m"<<"[DEBUG] "<<__func__<<":"<<__LINE__<<" [" << #x << "] = [" << x << "]" << "\e[39m" << '\n';
#else
#define debug(x)
#endif

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';
const double PI = acos(-1);

int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    int high = n - 1, low = 0, insert = 0, mid;

    while (high >= low) {
        mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;

        if (nums[mid] > target) {
            high = mid - 1;
        } else if (nums[mid] < target) {
            low = mid + 1;
            insert = mid + 1;
        }
    }

    return insert;
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

    cout << searchInsert(a, target) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
