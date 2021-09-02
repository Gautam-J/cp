/* CF - 1000 */
/*
A. Little Elephant and Function
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The Little Elephant enjoys recursive functions.

This time he enjoys the sorting function. Let a is a permutation of an integers from 1 to n, inclusive, and ai denotes the i-th element of the permutation. The Little Elephant's recursive function f(x), that sorts the first x permutation's elements, works as follows:

If x = 1, exit the function.
Otherwise, call f(x - 1), and then make swap(ax - 1, ax) (swap the x-th and (x - 1)-th elements of a).
The Little Elephant's teacher believes that this function does not work correctly. But that-be do not get an F, the Little Elephant wants to show the performance of its function. Help him, find a permutation of numbers from 1 to n, such that after performing the Little Elephant's function (that is call f(n)), the permutation will be sorted in ascending order.

Input
A single line contains integer n (1 ≤ n ≤ 1000) — the size of permutation.

Output
In a single line print n distinct integers from 1 to n — the required permutation. Numbers in a line should be separated by spaces.

It is guaranteed that the answer exists.

Examples
inputCopy
1
outputCopy
1
inputCopy
2
outputCopy
2 1
*/

/* Time Complexity: O(n) */
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

void printPermutation(int n) {
    // ans is of the form n, 1, 2, 3, ..., n - 2, n - 1
    cout << n << " ";

    for (int i = 1; i < n; i++)
        cout << i << " ";

    cout << nl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    printPermutation(n);

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
