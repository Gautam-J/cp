/* CF - 800 */
/*
A. A Variety of Operations
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output

William has two numbers a and b initially both equal to zero. William mastered performing three different operations with them quickly. Before performing each operation some positive integer k is picked, which is then used to perform one of the following operations: (note, that for each operation you can choose a new positive integer k)

add number k to both a and b, or
add number k to a and subtract k from b, or
add number k to b and subtract k from a.
Note that after performing operations, numbers a and b may become negative as well.

William wants to find out the minimal number of operations he would have to perform to make a equal to his favorite number c and b equal to his second favorite number d.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). Description of the test cases follows.

The only line of each test case contains two integers c and d (0≤c,d≤109), which are William's favorite numbers and which he wants a and b to be transformed into.

Output
For each test case output a single number, which is the minimal number of operations which William would have to perform to make a equal to c and b equal to d, or −1 if it is impossible to achieve this using the described operations.

Example
inputCopy
6
1 2
3 5
5 3
6 6
8 0
0 0
outputCopy
-1
2
2
1
2
0
Note
Let us demonstrate one of the suboptimal ways of getting a pair (3,5):

Using an operation of the first type with k=1, the current pair would be equal to (1,1).
Using an operation of the third type with k=8, the current pair would be equal to (−7,9).
Using an operation of the second type with k=7, the current pair would be equal to (0,2).
Using an operation of the first type with k=3, the current pair would be equal to (3,5).
*/

/* Time Complexity: O(1) */
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

int solve(int c, int d) {
    if (abs(c - d) % 2 != 0)
        return -1;

    if (c == d) {
        if (c == 0)
            return 0;
        return 1;
    }

    return 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, c, d;
    cin >> t;

    while (t--) {
        cin >> c >> d;
        cout << solve(c, d) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
