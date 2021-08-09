/* CLRS */

/* Best case run time complexity: O(N) */

/* Time Complexity: O(N^2) */
/* Space Complexity: O(1) since we are doing it inplace */

#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr) {
    int key, i;

    for (int j = 1; j < arr.size(); j++) {
        // select element from array, to be placed in the sorted subarray
        key = arr[j];

        // switch / move elements within the sorted subarray
        i = j - 1;
        while (i >= 0 && arr[i] > key) {  // arr[i] < key for desc
            arr[i + 1] = arr[i];
            i--;
        }

        // insert key into sorted subarray A[0...j - 1]
        arr[i + 1] = key;
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
    insertionSort(arr);

    // print arr
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';

    return 0;
}
