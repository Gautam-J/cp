/* CLRS */

/* Time Complexity: O(n), more specifically O(n + k) */
/* Space Complexity: O(n), more specifically O(n + k) */

#include <bits/stdc++.h>
using namespace std;

vector<int> countingSort(vector<int>& arr) {
    int element, n = arr.size();

    // find the max element of input array
    int k =  *max_element(arr.begin(), arr.end());

    // initialize vectors to 0
    vector<int> sortedArr(n);
    vector<int> count(k + 1);

    // let count[i] be number of elements equal to i
    for (int j = 0; j < n; j++) {
        element = arr[j];
        count[element]++;
    }

    // let count[i] be number of elements less than or equal to i
    // like a running sum
    for (int i = 1; i < count.size(); i++) {
        count[i] = count[i] + count[i - 1];
    }

    // place elements from input array into output array
    for (int j = n - 1; j >= 0; j--) {
        element = arr[j];

        // place element in its position based on the number of elements
        // less than or equal to the element
        sortedArr[count[element] - 1] = element;
        count[element]--;
    }

    return sortedArr;
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
    vector<int> sortedArr = countingSort(arr);

    // print arr
    for (int i = 0; i < n; i++) {
        cout << sortedArr[i] << " ";
    }
    cout << '\n';

    return 0;
}
