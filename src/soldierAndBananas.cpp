/* CF - 800 */
/*
A. Soldier and Bananas
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A soldier wants to buy w bananas in the shop. He has to pay k dollars for the first banana, 2k dollars for the second one and so on (in other words, he has to pay i·k dollars for the i-th banana).

He has n dollars. How many dollars does he have to borrow from his friend soldier to buy w bananas?

Input
The first line contains three positive integers k, n, w (1  ≤  k, w  ≤  1000, 0 ≤ n ≤ 109), the cost of the first banana, initial number of dollars the soldier has and number of bananas he wants.

Output
Output one integer — the amount of dollars that the soldier must borrow from his friend. If he doesn't have to borrow money, output 0.

Examples
inputCopy
3 17 4
outputCopy
13
*/

/* Time Complexity: O(1) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

int moneyToBorrow(double k, double n, double w) {
    // 1k + 2k + 3k + ... + wk, i.e., sum of arithmatic progression
    double cost = (double)((double)(w / 2.0) * (double)(k + (double)(w * k)));

    if (cost > n)
        return (int)(cost - n);

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double k, n, w;
    cin >> k >> n >> w;
    cout << moneyToBorrow(k, n, w) << "\n";

    return 0;
}
