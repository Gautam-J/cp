/* CF - 900 */
/*
A. Hexadecimal's theorem
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Recently, a chaotic virus Hexadecimal advanced a new theorem which will shake the Universe. She thinks that each Fibonacci number can be represented as sum of three not necessary different Fibonacci numbers.

Let's remember how Fibonacci numbers can be calculated. F0 = 0, F1 = 1, and all the next numbers are Fi = Fi - 2 + Fi - 1.

So, Fibonacci numbers make a sequence of numbers: 0, 1, 1, 2, 3, 5, 8, 13, ...

If you haven't run away from the PC in fear, you have to help the virus. Your task is to divide given Fibonacci number n by three not necessary different Fibonacci numbers or say that it is impossible.

Input
The input contains of a single integer n (0 ≤ n < 109) — the number that should be represented by the rules described above. It is guaranteed that n is a Fibonacci number.

Output
Output three required numbers: a, b and c. If there is no answer for the test you have to print "I'm too stupid to solve this problem" without the quotes.

If there are multiple answers, print any of them.

Examples
inputCopy
3
outputCopy
1 1 1
inputCopy
13
outputCopy
2 3 8
*/

/* Time Complexity: O(n), and O(1) for optimal solution */
/* Space Complexity: O(n) and O(1) for optimal solution */

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

void sumOfFib2(int n) {
    cout << "0 0 " << n << nl;
}

void sumOfFib(int n) {
    /* Overly complicated solution that actually gets accepted! */

    if (n == 0) {
        cout << "0 0 0 " << nl;
        return;
    }

    if (n == 1) {
        cout << "1 0 0 " << nl;
        return;
    }

    if (n == 2) {
        cout << "1 1 0 " << nl;
        return;
    }

    int fib[1000000 + 1];
    int index;

    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; ;i++) {
        fib[i] = fib[i - 1] + fib[i - 2];

        if (fib[i] == n) {
            index = i;
            break;
        }
    }

    vi a;
    a.push_back(fib[index - 1]);
    a.push_back(fib[index - 3]);
    a.push_back(fib[index - 4]);

    trav(i, a)
        cout << i << " ";
    cout << nl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    sumOfFib2(n);

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
