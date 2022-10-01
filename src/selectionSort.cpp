/* CLRS */

/* Time Complexity: O(N^2) for both best and worst case */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr) {
    // uses a greedy approach
    // more efficient than bubble sort
    int min_index;

    for (int i = 0; i < arr.size() - 1; i++) {

        // find the smallest value of the unsorted array A[i + 1...n]
        min_index = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[min_index])
                min_index = j;
        }

        // swap the min_index value with value at index i
        swap(arr[min_index], arr[i]);
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
    selectionSort(arr);

    // print arr
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';

    return 0;
}
