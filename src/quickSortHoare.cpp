/* CLRS */

/* The worst case scenario however is O(n^2) */

/* Time Complexity: O(n lg n) is the average case running time */
/* Space Complexity: O(1) since we are doing it inplace */

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do
            j--;
        while (arr[j] > pivot);  // arr[j] < pivot for desc

        do
            i++;
        while (arr[i] < pivot);  // arr[i] > pivot for desc

        if (i >= j)
            return j;  // q

        swap(arr[i], arr[j]);
    }
}

void quickSort(vector<int>& arr, int low, int high) {

    if (low < high) {
        int q = partition(arr, low, high);
        quickSort(arr, low, q);
        quickSort(arr, q + 1, high);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);

    //  store input from user to array
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // sort array
    quickSort(arr, 0, arr.size() - 1);

    // print arr
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';

    return 0;
}
