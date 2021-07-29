/* CLRS */

/* Determine if there exists two elements in S such that they add upto x */

/* Time Complexity: O(N lg N) */
/* Space Complexity: O(N) */

#include <bits/stdc++.h>
using namespace std;

bool twoSum(vector<int>& arr, int x) {
    // sort the given array O(n lg n)
    sort(arr.begin(), arr.end());

    // use binary search to check if elements add upto x O(n lg n)
    int low = 0;
    int high = arr.size() - 1;
    while (low < high) {
        if (arr[low] + arr[high] == x)
            return true;

        if (arr[low] + arr[high] > x)
            high--;
        else
            low++;
    }

    return false;
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

    cout << twoSum(arr, x) << "\n";

    return 0;
}
