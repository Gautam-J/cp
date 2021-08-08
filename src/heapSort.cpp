/* CLRS */

/* Time Complexity: O(n lg n) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int>& arr, int index, int heapSize) {
    // + 1 because of zero based indexing
    int l = 2 * index + 1;
    int r = 2 * index + 2;

    int largest = index;
    if (l < heapSize && arr[l] > arr[index])
        largest = l;
    if (r < heapSize && arr[r] > arr[largest])
        largest = r;

    if (largest != index) {
        swap(arr[index], arr[largest]);
        maxHeapify(arr, largest, heapSize);
    }
}

void buildMaxHeap(vector<int>& arr) {
    int n = arr.size();  // floor division

    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, i, n);

    // print max heap
    cout << "Max Heap:" << '\n';
    for (auto x : arr)
        cout << x << " ";
    cout << '\n';
}

void heapSort(vector<int>& arr) {
    int heapSize = arr.size();
    buildMaxHeap(arr);

    for (int i = arr.size() - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, 0, i);
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
    heapSort(arr);

    // print arr
    cout << "Sorted array:" << '\n';
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';

    return 0;
}
