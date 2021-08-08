/* CF - 800 */
/*
A. Stones on the Table
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
There are n stones on the table in a row, each of them can be red, green or blue. Count the minimum number of stones to take from the table so that any two neighboring stones had different colors. Stones in a row are considered neighboring if there are no other stones between them.

Input
The first line contains integer n (1 ≤ n ≤ 50) — the number of stones on the table.

The next line contains string s, which represents the colors of the stones. We'll consider the stones in the row numbered from 1 to n from left to right. Then the i-th character s equals "R", if the i-th stone is red, "G", if it's green and "B", if it's blue.

Output
Print a single integer — the answer to the problem.

Examples
inputCopy
3
RRG
outputCopy
1
inputCopy
5
RRRRR
outputCopy
4
inputCopy
4
BRBG
outputCopy
0
*/

/* Time Complexity: O(n) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

int getNumberOfStones(vector<char>& arr) {
    int count = 0;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i - 1] == arr[i])
            count++;
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<char> arr(n);
    for (int i = 0; i < arr.size(); i++)
        cin >> arr[i];

    cout << getNumberOfStones(arr) << '\n';

    return 0;
}
