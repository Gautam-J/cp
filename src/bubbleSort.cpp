/* CLRS */

/* Time Complexity: O(N^2) worst and best case can be O(n) */
/* Space Complexity: O(1) since we are doing it inplace */

#include <bits/stdc++.h>
#include <set>
using namespace std;

void bubbleSortImproved(vector<int>& arr) {
    // stops after one full pass of the array if already sorted.
    // that is, best case time Complexity becomes O(n), instead of O(n^2)

    for (int i = 0; i < arr.size() - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swapped = true;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (!swapped)
            return;
    }
}

void bubbleSort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = arr.size() - 1; j > i; j--) {
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
        }
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
    /* bubbleSort(arr); */
    bubbleSortImproved(arr);

    // print arr
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';

    return 0;
}
