/* CLRS LC - Easy grind 8 */

/* Time Complexity: O(lg N) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int v, int low, int high) {
    if (low > high)
        return -1;

    /* int mid = (low + high) / 2;  // floor division */

    // to prevent overflow, use the below formula
    int mid = low + (high - low) / 2;  // floor division

    if (v == arr[mid])
        return mid;
    if (v > arr[mid])
        return binarySearch(arr, v, mid + 1, high);
    if (v < arr[mid])
        return binarySearch(arr, v, low, mid - 1);

    return -1; // unneccesary, just to ignore warnings, or make the v == arr[mid] case as default
}

int binarySearchIterative(vector<int>& arr, int v, int low, int high) {
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (arr[mid] == v)
            return mid;

        if (arr[mid] > v)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, v;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < (int)arr.size(); i++) {
        cin >> arr[i];
    }

    cout << '\n';
    cin >> v;

    cout << binarySearch(arr, v, 0, arr.size() - 1) << "\n";
    cout << binarySearchIterative(arr, v, 0, arr.size() - 1) << "\n";

    return 0;
}
