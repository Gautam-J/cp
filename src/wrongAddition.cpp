/* CF - 1200 */
/*
C. Wrong Addition
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Tanya is learning how to add numbers, but so far she is not doing it correctly. She is adding two numbers a and b using the following algorithm:

If one of the numbers is shorter than the other, Tanya adds leading zeros so that the numbers are the same length.
The numbers are processed from right to left (that is, from the least significant digits to the most significant).
In the first step, she adds the last digit of a to the last digit of b and writes their sum in the answer.
At each next step, she performs the same operation on each pair of digits in the same place and writes the result to the left side of the answer.
For example, the numbers a=17236 and b=3465 Tanya adds up as follows:

+17236034651106911
calculates the sum of 6+5=11 and writes 11 in the answer.
calculates the sum of 3+6=9 and writes the result to the left side of the answer to get 911.
calculates the sum of 2+4=6 and writes the result to the left side of the answer to get 6911.
calculates the sum of 7+3=10, and writes the result to the left side of the answer to get 106911.
calculates the sum of 1+0=1 and writes the result to the left side of the answer and get 1106911.
As a result, she gets 1106911.

You are given two positive integers a and s. Find the number b such that by adding a and b as described above, Tanya will get s. Or determine that no suitable b exists.

Input
The first line of input data contains an integer t (1≤t≤104) — the number of test cases.

Each test case consists of a single line containing two positive integers a and s (1≤a<s≤1018) separated by a space.

Output
For each test case print the answer on a separate line.

If the solution exists, print a single positive integer b. The answer must be written without leading zeros. If multiple answers exist, print any of them.

If no suitable number b exists, output -1.

Example
inputCopy
6
17236 1106911
1 5
108 112
12345 1023412
1 11
1 20
outputCopy
3465
4
-1
90007
10
-1
Note
The first test case is explained in the main part of the statement.

In the third test case, we cannot choose b that satisfies the problem statement.

*/

/* Time Complexity: O(s) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
#include <string>
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
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';
const double PI = acos(-1);

void solve(ll a, ll s) {
    vi b;
    int x, y;

    while (s) {
        x = a % 10;
        y = s % 10;

        if (x <= y)
            b.push_back(y - x);
        else {
            s /= 10;
            y += 10 * (s % 10);

            if (x < y && y >= 10 && y <= 19)
                b.push_back(y - x);
            else {
                cout << -1 << nl;
                return;
            }
        }
        a /= 10;
        s /= 10;
    }

    if (a)
        cout << -1 << nl;
    else {
        while (b.back() == 0)
            b.pop_back();

        reverse(all(b));
        trav(i, b)
            cout << i;

        cout << nl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    ll a, s;
    cin >> t;

    while (t--) {
        cin >> a >> s;
        solve(a, s);
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
