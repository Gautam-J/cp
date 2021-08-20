/* CF - 900 */
/*
A. Lights Out
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Lenny is playing a game on a 3 × 3 grid of lights. In the beginning of the game all lights are switched on. Pressing any of the lights will toggle it and all side-adjacent lights. The goal of the game is to switch all the lights off. We consider the toggling as follows: if the light was switched on then it will be switched off, if it was switched off then it will be switched on.

Lenny has spent some time playing with the grid and by now he has pressed each light a certain number of times. Given the number of times each light is pressed, you have to print the current state of each light.

Input
The input consists of three rows. Each row contains three integers each between 0 to 100 inclusive. The j-th number in the i-th row is the number of times the j-th light of the i-th row of the grid is pressed.

Output
Print three lines, each containing three characters. The j-th character of the i-th line is "1" if and only if the corresponding light is switched on, otherwise it's "0".

Examples
inputCopy
1 0 0
0 0 0
0 0 1
outputCopy
001
010
100
inputCopy
1 0 1
8 8 8
2 0 3
outputCopy
010
011
100
*/

/* Time Complexity: O(1) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define trav(a, x) for (auto& a : x)

typedef long long ll;
typedef vector<int> vi;

const char nl = '\n';

void printLights(int grid[3][3]) {
    int states[3][3];
    int num;

    // initally the lights are switched on
    FOR(i, 3) {
        FOR(j, 3)
            states[i][j] = 1;
    }

    FOR(i, 3) {
        FOR(j, 3) {
            num = grid[i][j];
            if (num % 2 == 0)
                continue;
            else {
                // flip light 1 and 0 using XOR
                states[i][j] ^= 1;

                // flip left light
                if (j > 0)
                    states[i][j - 1] ^= 1;
                // flip up light
                if (i > 0)
                    states[i - 1][j] ^= 1;
                // flip down light
                if (i < 2)
                    states[i + 1][j] ^= 1;
                // flip right light
                if (j < 2)
                    states[i][j + 1] ^= 1;
            }
        }
    }

    FOR(i, 3) {
        FOR(j, 3) {
            cout << states[i][j];
        }
        cout << nl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int grid[3][3];
    FOR(i, 3) {
        FOR(j, 3)
            cin >> grid[i][j];
    }

    printLights(grid);

    return 0;
}
