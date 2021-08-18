/* CF - */
/*
A. Dislike of Threes
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp doesn't like integers that are divisible by 3 or end with the digit 3 in their decimal representation. Integers that meet both conditions are disliked by Polycarp, too.

Polycarp starts to write out the positive (greater than 0) integers which he likes: 1,2,4,5,7,8,10,11,14,16,…. Output the k-th element of this sequence (the elements are numbered from 1).

Input
The first line contains one integer t (1≤t≤100) — the number of test cases. Then t test cases follow.

Each test case consists of one line containing one integer k (1≤k≤1000).

Output
For each test case, output in a separate line one integer x — the k-th element of the sequence that was written out by Polycarp.

Example
inputCopy
10
1
2
3
4
5
6
7
8
9
1000
outputCopy
1
2
4
5
7
8
10
11
14
1666
*/

/* Time Complexity: O(n) where n = k */
/* Space Complexity: O(n) where n = k */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef vector<int> vi;

int solve(int k) {
    map<int, int> dp;
    int q;

    dp[1] = 1;
    for (int i = 2; i <= k; i++) {

        q = dp[i - 1];
        do
            q++;
        while (q % 3 == 0 || q % 10 == 3);

        dp[i] = q;
    }

    return dp.at(k);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, k;
    cin >> t;

    while (t--) {
        cin >> k;
        cout << solve(k) << "\n";
    }

    return 0;
}
