/* CF - 1100 */
/*
A. IQ Test
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
In the city of Ultima Thule job applicants are often offered an IQ test.

The test is as follows: the person gets a piece of squared paper with a 4 × 4 square painted on it. Some of the square's cells are painted black and others are painted white. Your task is to repaint at most one cell the other color so that the picture has a 2 × 2 square, completely consisting of cells of the same color. If the initial picture already has such a square, the person should just say so and the test will be completed.

Your task is to write a program that determines whether it is possible to pass the test. You cannot pass the test if either repainting any cell or no action doesn't result in a 2 × 2 square, consisting of cells of the same color.

Input
Four lines contain four characters each: the j-th character of the i-th line equals "." if the cell in the i-th row and the j-th column of the square is painted white, and "#", if the cell is black.

Output
Print "YES" (without the quotes), if the test can be passed and "NO" (without the quotes) otherwise.

Examples
inputCopy
####
.#..
####
....
outputCopy
YES
inputCopy
####
....
####
....
outputCopy
NO

Note
In the first test sample it is enough to repaint the first cell in the second row. After such repainting the required 2 × 2 square is on the intersection of the 1-st and 2-nd row with the 1-st and 2-nd column.
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

bool solve(vector<string>& a) {
    int bCount = 0, wCount = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            bCount = 0;
            wCount = 0;
            for (int k = i; k < i + 2; k++) {
                for (int l = j; l < j + 2; l++) {
                    if (a[k][l] == '.')
                        bCount++;
                    else
                        wCount++;
                }
            }

            if (bCount == 1 && wCount == 3)
                return true;
            if (bCount == 3 && wCount == 1)
                return true;
            if (bCount == 4 || wCount == 4)
                return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<string> a(4);
    trav(i, a) {
        cin >> i;
    }

    cout << (solve(a) ? "YES" : "NO") << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
