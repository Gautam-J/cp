/* CF - 900 */
/*
B. Prime Square
time limit per test1.5 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Sasha likes investigating different math objects, for example, magic squares. But Sasha understands that magic squares have already been studied by hundreds of people, so he sees no sense of studying them further. Instead, he invented his own type of square — a prime square.

A square of size n×n is called prime if the following three conditions are held simultaneously:

all numbers on the square are non-negative integers not exceeding 105;
there are no prime numbers in the square;
sums of integers in each row and each column are prime numbers.
Sasha has an integer n. He asks you to find any prime square of size n×n. Sasha is absolutely sure such squares exist, so just help him!

Input
The first line contains a single integer t (1≤t≤10) — the number of test cases.

Each of the next t lines contains a single integer n (2≤n≤100) — the required size of a square.

Output
For each test case print n lines, each containing n integers — the prime square you built. If there are multiple answers, print any.

Example
inputCopy
2
4
2
outputCopy
4 6 8 1
4 9 9 9
4 10 10 65
1 4 4 4
1 1
1 1
*/

/* Time Complexity: O(n) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef vector<int> vi;

void printSquare(int n) {
    vector<vi> a(n, vi (n, 0));

    // set diagonal elements as 1
    FOR(i, n) {
        a[i][i] = 1;
        a[i][n - i - 1] = 1;
    }

    if (n % 2) {
        a[n / 2 - 1][n / 2] = 1;
        a[n / 2][n / 2 + 1] = 1;
    }

    FOR(i, n) {
        FOR(j, n) {
            cout << a[i][j];
            if (j < n - 1)
                cout << " ";
            else
                cout << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        printSquare(n);
    }

    return 0;
}
