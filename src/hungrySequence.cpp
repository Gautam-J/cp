/* CF - 1200 */
/*
B. Hungry Sequence
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Iahub and Iahubina went to a date at a luxury restaurant. Everything went fine until paying for the food. Instead of money, the waiter wants Iahub to write a Hungry sequence consisting of n integers.

A sequence a1, a2, ..., an, consisting of n integers, is Hungry if and only if:

Its elements are in increasing order. That is an inequality ai < aj holds for any two indices i, j (i < j).
For any two indices i and j (i < j), aj must not be divisible by ai.
Iahub is in trouble, so he asks you for help. Find a Hungry sequence with n elements.

Input
The input contains a single integer: n (1 ≤ n ≤ 105).

Output
Output a line that contains n space-separated integers a1 a2, ..., an (1 ≤ ai ≤ 107), representing a possible Hungry sequence. Note, that each ai must not be greater than 10000000 (107) and less than 1.

If there are multiple solutions you can output any one.

Examples
inputCopy
3
outputCopy
2 9 15
inputCopy
5
outputCopy
11 14 20 27 31
*/

/* Time Complexity: O(n) or O(n * sqrt(n)) */
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

bool isPrime(int n) {
    if (n <= 1)
        return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

void solve(int n) {
    // 498 ms gets accepted
    // print the first N prime numbers

    int count = 0, i = 2;

    while (count < n) {
        if (isPrime(i)) {
            cout << i << " ";
            count++;
        }
        i++;
    }

    cout << nl;
}

void solve2(int n) {
    // 68 ms

    FOR(i, n) {
        cout << 3 * n + i << " ";
    }
    cout << nl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    solve2(n);

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
