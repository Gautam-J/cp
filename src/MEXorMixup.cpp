/* CF - */
/*
B. MEXor Mixup
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Alice gave Bob two integers a and b (a>0 and b≥0). Being a curious boy, Bob wrote down an array of non-negative integers with MEX value of all elements equal to a and XOR value of all elements equal to b.

What is the shortest possible length of the array Bob wrote?

Recall that the MEX (Minimum EXcluded) of an array is the minimum non-negative integer that does not belong to the array and the XOR of an array is the bitwise XOR of all the elements of the array.

Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤5⋅104) — the number of test cases. The description of the test cases follows.

The only line of each test case contains two integers a and b (1≤a≤3⋅105; 0≤b≤3⋅105) — the MEX and XOR of the array, respectively.

Output
For each test case, output one (positive) integer — the length of the shortest array with MEX a and XOR b. We can show that such an array always exists.

Example
inputCopy
5
1 1
2 1
2 0
1 10000
2 10000
outputCopy
3
2
3
2
3
Note
In the first test case, one of the shortest arrays with MEX 1 and XOR 1 is [0,2020,2021].

In the second test case, one of the shortest arrays with MEX 2 and XOR 1 is [0,1].

It can be shown that these arrays are the shortest arrays possible.
*/

/* Time Complexity: O(1) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define trav(i, a) for (auto& i : a)

#ifdef _GLIBCXX_DEBUG
#define debug(x) cerr << "\e[91m"<<"[DEBUG] "<<__func__<<":"<<__LINE__<<" [" << #x << "] = [" << x << "]" << "\e[39m" << '\n';
#else
#define debug(x)
#endif

typedef long long ll;
typedef vector<int> vi;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';
const double PI = acos(-1);

int solve(int a, int b) {
    int x;

    // calculating XOR of array [0, 1, 2, ... n - 1]
    if (a % 4 == 1)
        x = a - 1;
    else if (a % 4 == 2)
        x = 1;
    else if (a % 4 == 3)
        x = a;
    else
        x = 0;

    if (b == x)
        return a;
    if ((x ^ b) == a)
        return a + 2;

    return a + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, a, b;
    cin >> t;

    while (t--) {
        cin >> a >> b;
        cout << solve(a, b) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
