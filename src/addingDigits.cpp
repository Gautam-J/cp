/* CF - 1400 */
/*
A. Adding Digits
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vasya has got two number: a and b. However, Vasya finds number a too short. So he decided to repeat the operation of lengthening number a n times.

One operation of lengthening a number means adding exactly one digit to the number (in the decimal notation) to the right provided that the resulting number is divisible by Vasya's number b. If it is impossible to obtain the number which is divisible by b, then the lengthening operation cannot be performed.

Your task is to help Vasya and print the number he can get after applying the lengthening operation to number a n times.

Input
The first line contains three integers: a, b, n (1 ≤ a, b, n ≤ 105).

Output
In a single line print the integer without leading zeros, which Vasya can get when he applies the lengthening operations to number a n times. If no such number exists, then print number -1. If there are multiple possible answers, print any of them.

Examples
inputCopy
5 4 5
outputCopy
524848
inputCopy
12 11 1
outputCopy
121
inputCopy
260 150 10
outputCopy
-1
*/

/* Time Complexity: O(n) */
/* Space Complexity: O(n) */

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

string solve(ll a, ll b, ll n) {
    ll res = a;
    ll temp;
    bool done = false;

    for (int i = 0; i <= 9; i++) {
        temp = res * 10 + i;
        if (temp % b == 0) {
            res = temp;
            done = true;
            break;
        }
    }

    if (!done)
        return "-1";

    string s = to_string(res);

    FOR(i, n - 1) {
        s += '0';
    }

    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, n;
    cin >> a >> b >> n;

    cout << solve(a, b, n) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
