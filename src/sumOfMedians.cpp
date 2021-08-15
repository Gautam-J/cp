/* CF - 900 */
/*
B. Sum of Medians
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A median of an array of integers of length n is the number standing on the ⌈n2⌉ (rounding up) position in the non-decreasing ordering of its elements. Positions are numbered starting with 1. For example, a median of the array [2,6,4,1,3,5] is equal to 3. There exist some other definitions of the median, but in this problem, we will use the described one.

Given two integers n and k and non-decreasing array of nk integers. Divide all numbers into k arrays of size n, such that each number belongs to exactly one array.

You want the sum of medians of all k arrays to be the maximum possible. Find this maximum possible sum.

Input
The first line contains a single integer t (1≤t≤100) — the number of test cases. The next 2t lines contain descriptions of test cases.

The first line of the description of each test case contains two integers n, k (1≤n,k≤1000).

The second line of the description of each test case contains nk integers a1,a2,…,ank (0≤ai≤109) — given array. It is guaranteed that the array is non-decreasing: a1≤a2≤…≤ank.

It is guaranteed that the sum of nk for all test cases does not exceed 2⋅105.

Output
For each test case print a single integer — the maximum possible sum of medians of all k arrays.

Example
inputCopy
6
2 4
0 24 34 58 62 64 69 78
2 2
27 61 81 91
4 3
2 4 16 18 21 27 36 53 82 91 92 95
3 4
3 11 12 22 33 35 38 67 69 71 94 99
2 1
11 41
3 3
1 1 1 1 1 1 1 1 1
outputCopy
165
108
145
234
11
3
Note
The examples of possible divisions into arrays for all test cases of the first test:

Test case 1: [0,24],[34,58],[62,64],[69,78]. The medians are 0,34,62,69. Their sum is 165.

Test case 2: [27,61],[81,91]. The medians are 27,81. Their sum is 108.

Test case 3: [2,91,92,95],[4,36,53,82],[16,18,21,27]. The medians are 91,36,18. Their sum is 145.

Test case 4: [3,33,35],[11,94,99],[12,38,67],[22,69,71]. The medians are 33,94,38,69. Their sum is 234.

Test case 5: [11,41]. The median is 11. The sum of the only median is 11.

Test case 6: [1,1,1],[1,1,1],[1,1,1]. The medians are 1,1,1. Their sum is 3.
*/

/* Time Complexity: O(k) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef vector<int> vi;

ll maxSum(vector<ll>& arr, ll n, ll k) {
    ll sumOfMedians = 0;
    ll x = (n + 1) / 2 - 1;
    x = n - x;
    ll z = k * n + 1;

    while (k--) {
        z -= x;
        if (z <= 0)
            break;
        sumOfMedians += arr[z];
    }

    return sumOfMedians;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    ll n, k;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        vector<ll> arr((n * k) + 1);
        for (int i = 1; i <= n * k; i++)
            cin >> arr[i];

        cout << maxSum(arr, n, k) << '\n';
    }

    return 0;
}
