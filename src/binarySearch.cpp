/* CLRS */

/* Time Complexity: O(lg N) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int v, int low, int high) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;  // floor division

    if (v == arr[mid])
        return mid;
    if (v > arr[mid])
        return binarySearch(arr, v, mid + 1, high);
    if (v < arr[mid])
        return binarySearch(arr, v, low, mid - 1);

    return -1; // unneccesary, just to ignore warnings
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, v;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }

    cout << '\n';
    cin >> v;

    cout << binarySearch(arr, v, 0, arr.size() - 1) << "\n";

    return 0;
}
