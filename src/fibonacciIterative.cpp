/* Practice */
/*
Given an integer n, print the nth fibinacci number.
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...
*/

/* Time Complexity: O(n) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef vector<int> vi;

ll getFib(ll n) {

    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    ll a = 0;
    ll b = 1;
    ll c = 0;
    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    cout << getFib(n) << '\n';

    return 0;
}
