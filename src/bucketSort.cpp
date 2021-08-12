/* CLRS */

/* Time Complexity: O(N), or more specifically O(n + k) assuming best case for insertion sort */
/* Space Complexity: O(N), more specifically O(nk) */

#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<float>& arr) {
    // modified insertion sort that uses float data type
    float key, i;

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

void bucketSort(vector<float>& arr) {
    int index, n = arr.size();

    // initialize array of n empty buckets
    vector<float> b[n];

    // insert elements into buckets
    for (int i = 0; i < n; i++) {
        index = n * arr[i];  // floor(n * arr[i])
        b[index].push_back(arr[i]);
    }

    // sort individual buckets
    for (int i = 0; i < n; i++) {
        insertionSort(b[i]);
        // or use introsort for O(n lg n)
        // sort(b[i].begin(), b[i].end())
    }

    // concatenate buckets
    index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b[i].size(); j++) {
            arr[index++] = b[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<float> arr(n);

    //  store input from user to array
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // sort array
    bucketSort(arr);

    // print arr
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';

    return 0;
}
