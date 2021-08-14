/* CF - 900 */
/*
B. Napoleon Cake
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
This week Arkady wanted to cook some pancakes (to follow ancient traditions) and make a problem about that. But then he remembered that one can't make a problem about stacking pancakes without working at a specific IT company, so he decided to bake the Napoleon cake instead.

To bake a Napoleon cake, one has to bake n dry layers first, and then put them on each other in one stack, adding some cream. Arkady started with an empty plate, and performed the following steps n times:

place a new cake layer on the top of the stack;
after the i-th layer is placed, pour ai units of cream on top of the stack.
When x units of cream are poured on the top of the stack, top x layers of the cake get drenched in the cream. If there are less than x layers, all layers get drenched and the rest of the cream is wasted. If x=0, no layer gets drenched.

The picture represents the first test case of the example.
Help Arkady determine which layers of the cake eventually get drenched when the process is over, and which don't.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤20000). Description of the test cases follows.

The first line of each test case contains a single integer n (1≤n≤2⋅105) — the number of layers in the cake.

The second line of each test case contains n integers a1,a2,…,an (0≤ai≤n) — the amount of cream poured on the cake after adding each layer.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, print a single line with n integers. The i-th of the integers should be equal to 1 if the i-th layer from the bottom gets drenched, and 0 otherwise.

Example
inputCopy
3
6
0 3 0 0 1 3
10
0 0 0 1 0 5 0 0 0 2
3
0 0 0
outputCopy
1 1 0 1 1 1
0 1 1 1 1 1 0 0 1 1
0 0 0
*/

/* Time Complexity: O(n) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

/* void getDrenchedArray(vector<int>& arr) { */
/*     // brute force method - O(n^2) */
/*     // Time limit exceeds */
/*     int x, n = arr.size(); */
/*     vector<int> darr(n); */

/*     for (int i = 1; i <= n; i++) { */
/*         x = arr[i - 1]; */

/*         if (x > i) { */
/*             for (int j = 0; j < i; j++) */
/*                 darr[j] = 1; */
/*         } else { */
/*             for (int j = i - 1; j >= (i - x); j--) */
/*                 darr[j] = 1; */
/*         } */
/*     } */

/*     for (auto s : darr) */
/*         cout << s << ' '; */
/*     cout << '\n'; */
/* } */

void getDrenchedArray(vector<int>& arr) {
    int n = arr.size();
    vector<int> darr;

    int c = arr[n - 1];
    for (int i = n - 1; i >= 0; i--) {

        // c = max(c, arr[i])
        if (arr[i] >= c)
            c = arr[i];

        if (c > 0 && c >= arr[i]) {
            darr.push_back(1);
            c--;
        } else
            darr.push_back(0);
    }

    reverse(darr.begin(), darr.end());

    for (auto s : darr)
        cout << s << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >>arr[i];

        getDrenchedArray(arr);
    }

    return 0;
}
