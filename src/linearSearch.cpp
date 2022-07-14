/* CLRS */

/* Time complexity is O(N / 2) for average case, thus O(N) */

/* Time Complexity: O(N)  for both average and worst case*/
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>& arr, int v) {

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == v)
            return i;
    }

    return -1;
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

    cin >> v;

    cout << linearSearch(arr, v) << "\n";

    return 0;
}
