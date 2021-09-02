/* CF - 1000 */
/*
B. Present from Lena
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vasya's birthday is approaching and Lena decided to sew a patterned handkerchief to him as a present. Lena chose digits from 0 to n as the pattern. The digits will form a rhombus. The largest digit n should be located in the centre. The digits should decrease as they approach the edges. For example, for n = 5 the handkerchief pattern should look like that:


          0
        0 1 0
      0 1 2 1 0
    0 1 2 3 2 1 0
  0 1 2 3 4 3 2 1 0
0 1 2 3 4 5 4 3 2 1 0
  0 1 2 3 4 3 2 1 0
    0 1 2 3 2 1 0
      0 1 2 1 0
        0 1 0
          0
Your task is to determine the way the handkerchief will look like by the given n.

Input
The first line contains the single integer n (2 ≤ n ≤ 9).

Output
Print a picture for the given n. You should strictly observe the number of spaces before the first digit on each line. Every two adjacent digits in the same line should be separated by exactly one space. There should be no spaces after the last digit at the end of each line.

Examples
inputCopy
2
outputCopy
    0
  0 1 0
0 1 2 1 0
  0 1 0
    0
inputCopy
3
outputCopy
      0
    0 1 0
  0 1 2 1 0
0 1 2 3 2 1 0
  0 1 2 1 0
    0 1 0
      0
*/

/* Time Complexity: O(n^2) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define trav(i, a) for (auto& i : a)
#define debug(x) cout << "[DEBUG] " << #x << "=" << x << '\n'

typedef long long ll;
typedef vector<int> vi;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';
const double PI = acos(-1);

void printPattern(int n) {
    int nSpaces;

    // upper half
    for (int r = 0; r <= n; r++) {
        nSpaces = n - r;

        for (int s = 0; s < nSpaces; s++)
            cout << " " << " ";
        if (r == 0)
            cout << r;
        else {
            for (int c = 0; c <= r; c++)
                cout << c << " ";
        }
        for (int k = r - 1; k >= 1; k--)
            cout << k << " ";

        if (r != 0)
            cout << "0";

        cout << nl;
    }

    // lower half
    for (int r = n - 1; r >= 0; r--) {
        nSpaces = abs(r - n);

        for (int s = 0; s < nSpaces; s++)
            cout << " " << " ";
        if (r == 0)
            cout << r;
        else {
            for (int c = 0; c <= r; c++)
                cout << c << " ";
        }
        for (int k = r - 1; k >= 1; k--)
            cout << k << " ";

        if (r != 0)
            cout << "0";

        cout << nl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    printPattern(n);

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
