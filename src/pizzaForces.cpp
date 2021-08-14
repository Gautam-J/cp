/* CF - 900 */
/*
A. PizzaForces
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
PizzaForces is Petya's favorite pizzeria. PizzaForces makes and sells pizzas of three sizes: small pizzas consist of 6 slices, medium ones consist of 8 slices, and large pizzas consist of 10 slices each. Baking them takes 15, 20 and 25 minutes, respectively.

Petya's birthday is today, and n of his friends will come, so he decided to make an order from his favorite pizzeria. Petya wants to order so much pizza that each of his friends gets at least one slice of pizza. The cooking time of the order is the total baking time of all the pizzas in the order.

Your task is to determine the minimum number of minutes that is needed to make pizzas containing at least n slices in total. For example:

if 12 friends come to Petya's birthday, he has to order pizzas containing at least 12 slices in total. He can order two small pizzas, containing exactly 12 slices, and the time to bake them is 30 minutes;
if 15 friends come to Petya's birthday, he has to order pizzas containing at least 15 slices in total. He can order a small pizza and a large pizza, containing 16 slices, and the time to bake them is 40 minutes;
if 300 friends come to Petya's birthday, he has to order pizzas containing at least 300 slices in total. He can order 15 small pizzas, 10 medium pizzas and 13 large pizzas, in total they contain 15⋅6+10⋅8+13⋅10=300 slices, and the total time to bake them is 15⋅15+10⋅20+13⋅25=750 minutes;
if only one friend comes to Petya's birthday, he can order a small pizza, and the time to bake it is 15 minutes.
Input
The first line contains a single integer t (1≤t≤104) — the number of testcases.

Each testcase consists of a single line that contains a single integer n (1≤n≤1016) — the number of Petya's friends.

Output
For each testcase, print one integer — the minimum number of minutes that is needed to bake pizzas containing at least n slices in total.

Example
inputCopy
6
12
15
300
1
9999999999999999
3
outputCopy
30
40
750
15
25000000000000000
15
*/

/* Time Complexity: O(1) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

long long minMinutes(long long n) {

    if (n <= 6)
        return 15;

    // each slice takes 2.5 mins, only even slices can be baked
    if (n % 2 != 0)
        n++;

    return (n) / 2 * 5;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    long long n;

    cin >> t;
    while (t--) {
        cin >> n;
        cout << minMinutes(n) << "\n";
    }

    return 0;
}
