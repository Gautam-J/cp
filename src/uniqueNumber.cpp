/* CF - 900 */
/*
C. Unique Number
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a positive number x. Find the smallest positive integer number that has the sum of digits equal to x and all digits are distinct (unique).

Input
The first line contains a single positive integer t (1≤t≤50) — the number of test cases in the test. Then t test cases follow.

Each test case consists of a single integer number x (1≤x≤50).

Output
Output t answers to the test cases:

if a positive integer number with the sum of digits equal to x and all digits are different exists, print the smallest such number;
otherwise print -1.
Example
inputCopy
4
1
5
15
50
outputCopy
1
5
69
-1
*/

/* Time Complexity: O() */
/* Space Complexity: O() */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef vector<int> vi;

void solve(int x) {
    vi ans;
    int sum = 0, last = 9;

    while (sum < x && last > 0) {
        ans.push_back(min(x - sum, last));
        sum += last;
        last--;
    }

    if (sum < x)
        cout << -1 << '\n';
    else {
        reverse(all(ans));
        FOR(i, ans.size())
            cout << ans[i];
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, x;
    cin >> t;

    while (t--) {
        cin >> x;
        solve(x);
    }

    return 0;
}
