/* CLRS */

/* Time Complexity: O(N log N) */
/* Space Complexity: O(N) */

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int p, int q, int r) {
    int n1 = q - p + 1;  // length of L
    int n2 = r - q;  // length of R

    // create new arrays of length n+1 to hold sentinels
    vector<int> L(n1 + 1);
    vector<int> R(n2 + 1);

    // copy arr[p..q] to L[0...n1-1]
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];

    // copy arr[q+1..r] to R[0...n2-1]
    for (int j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];

    // add sentinel to the end of both arrays
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    // O(N) steps combining elements from both arrays
    int i = 0;
    int j = 0;
    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
    }
}

void mergeSort(vector<int>& arr, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;  // floor division

        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);

        merge(arr, p, q, r);
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
    mergeSort(arr, 0, arr.size() - 1);

    // print array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << '\n';

    return 0;
}
