/* CF - 800 */
/*
B. Squares and Cubes
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp likes squares and cubes of positive integers. Here is the beginning of the sequence of numbers he likes: 1, 4, 8, 9, ....

For a given number n, count the number of integers from 1 to n that Polycarp likes. In other words, find the number of such x that x is a square of a positive integer number or a cube of a positive integer number (or both a square and a cube simultaneously).

Input
The first line contains an integer t (1≤t≤20) — the number of test cases.

Then t lines contain the test cases, one per line. Each of the lines contains one integer n (1≤n≤109).

Output
For each test case, print the answer you are looking for — the number of integers from 1 to n that Polycarp likes.
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
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';
const double PI = acos(-1);

int solve(int N) {
    // the number of perfect squares from 1 to N (both inclusive) is floor(sqrt(N)), similarly for cubic root
    int res = (int)sqrt(N) + (int)cbrt(N) - (int)(sqrt(cbrt(N)));
    return res;
}

int solve2(int n) {
    // can be solved using brute force method also
    unordered_set<int> s;

    for (int i = 1; i * i <= n ; i++)
        s.insert(i * i);

    for (int i = 1; i * i * i <= n; i++)
        s.insert(i * i * i);

    return s.size();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        cout << solve(n) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
