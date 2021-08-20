/* CF - 800 */
/*
A. Insomnia cure
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
«One dragon. Two dragon. Three dragon», — the princess was counting. She had trouble falling asleep, and she got bored of counting lambs when she was nine.

However, just counting dragons was boring as well, so she entertained herself at best she could. Tonight she imagined that all dragons were here to steal her, and she was fighting them off. Every k-th dragon got punched in the face with a frying pan. Every l-th dragon got his tail shut into the balcony door. Every m-th dragon got his paws trampled with sharp heels. Finally, she threatened every n-th dragon to call her mom, and he withdrew in panic.

How many imaginary dragons suffered moral or physical damage tonight, if the princess counted a total of d dragons?

Input
Input data contains integer numbers k, l, m, n and d, each number in a separate line (1 ≤ k, l, m, n ≤ 10, 1 ≤ d ≤ 105).

Output
Output the number of damaged dragons.

Examples
inputCopy
1
2
3
4
12
outputCopy
12
inputCopy
2
3
4
5
24
outputCopy
17
Note
In the first case every first dragon got punched with a frying pan. Some of the dragons suffered from other reasons as well, but the pan alone would be enough.

In the second case dragons 1, 7, 11, 13, 17, 19 and 23 escaped unharmed.
*/

/* Time Complexity: O(n) where n = d */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define trav(i, a) for (auto& i : a)

typedef long long ll;
typedef vector<int> vi;

const char nl = '\n';

int unharmedDragons(int k, int l, int m, int n, int d) {
    if (k == 1 || l == 1 || m == 1 || n == 1)
        return d;

    int res = 0;
    for (int i = 1; i <= d; i++) {
        if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0)
            res++;
    }

    return res;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    cout << unharmedDragons(k, l, m, n, d) << nl;

    return 0;
}
