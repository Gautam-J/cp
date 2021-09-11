/* CF - 1300 */
/*
B. Easy Number Challenge
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Let's denote d(n) as the number of divisors of a positive integer n. You are given three integers a, b and c. Your task is to calculate the following sum:


Find the sum modulo 1073741824 (230).

Input
The first line contains three space-separated integers a, b and c (1 ≤ a, b, c ≤ 100).

Output
Print a single integer — the required sum modulo 1073741824 (230).

Examples
inputCopy
2 2 2
outputCopy
20
inputCopy
5 6 7
outputCopy
1520
Note
For the first example.

d(1·1·1) = d(1) = 1;
d(1·1·2) = d(2) = 2;
d(1·2·1) = d(2) = 2;
d(1·2·2) = d(4) = 3;
d(2·1·1) = d(2) = 2;
d(2·1·2) = d(4) = 3;
d(2·2·1) = d(4) = 3;
d(2·2·2) = d(8) = 4.
So the result is 1 + 2 + 2 + 3 + 2 + 3 + 3 + 4 = 20.
*/

/* Time Complexity: O(n * sqrt(n)) where n = a * b * c. Can be done in O(n * n^{1/3})*/
/* Space Complexity: O(n) where n = a * b * c. */

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

int countDivisors(int n) {
    // this takes O(sqrt(n)) time.
    // We can use sieve of eratosthenes for O(n^{1/3})

    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i == i)
                cnt++;
            else
                cnt += 2;
        }
    }

    return cnt;
}

int solve(ll a, ll b, ll c) {
    int res = 0;
    unordered_map<int, int> dp;

    int temp;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= c; k++) {
                temp = i * j * k;
                if (dp.find(temp) == dp.end())
                    dp[temp] = countDivisors(temp);

                res += dp[temp];
            }
        }
    }

    res %= 1073741824;  // 2^30

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    cout << solve(a, b, c) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
