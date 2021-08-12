/* CLRS */

/* For simplicity, we assume d = 10 in the below implementation */

/* Time Complexity: O(d(n + k)) */
/* Space Complexity: O(n + k) since it uses counting sort */

#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& arr, int exp) {
    // modified version of counting sort that uses digits as key
    int digit, i, n = arr.size();

    // initialize vectors as 0
    vector<int> output(n);
    vector<int> count(10);

    // store count of occurences
    for (int i = 0; i < n; i++) {
        digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // count[i] less than or equal to i
    for (int i = 1; i < 10; i++) {
        count[i] = count[i] + count[i - 1];
    }

    // build the output array
    for (int i = n - 1; i >= 0; i--) {
        digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // copy elements from output to input back
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(vector<int>& arr) {
    int k = *max_element(arr.begin(), arr.end());

    // counting sort for every digit
    // exp is 10^i where i is current number
    for (int exp = 1; k / exp > 0; exp *= 10) {
        countingSort(arr, exp);
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
    radixSort(arr);

    // print arr
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';

    return 0;
}
