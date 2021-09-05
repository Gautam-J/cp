/* CF - 1300 */
/*
B. Pashmak and Flowers
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Pashmak decided to give Parmida a pair of flowers from the garden. There are n flowers in the garden and the i-th of them has a beauty number bi. Parmida is a very strange girl so she doesn't want to have the two most beautiful flowers necessarily. She wants to have those pairs of flowers that their beauty difference is maximal possible!

Your task is to write a program which calculates two things:

The maximum beauty difference of flowers that Pashmak can give to Parmida.
The number of ways that Pashmak can pick the flowers. Two ways are considered different if and only if there is at least one flower that is chosen in the first way and not chosen in the second way.
Input
The first line of the input contains n (2 ≤ n ≤ 2·105). In the next line there are n space-separated integers b1, b2, ..., bn (1 ≤ bi ≤ 109).

Output
The only line of output should contain two integers. The maximum beauty difference and the number of ways this may happen, respectively.

Examples
inputCopy
2
1 2
outputCopy
1 1
inputCopy
3
1 4 5
outputCopy
4 1
inputCopy
5
3 1 2 3 1
outputCopy
2 4
Note
In the third sample the maximum beauty difference is 2 and there are 4 ways to do this:

choosing the first and the second flowers;
choosing the first and the fifth flowers;
choosing the fourth and the second flowers;
choosing the fourth and the fifth flowers.
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

vector<ll> solve(vector<ll>& a) {
    ll n = a.size();

    bool flag = true;
    FOR(i, n) {
        if (a[i] != a[0])
            flag = false;
    }

    if (flag)
        return vector<ll> {0, (n * (n - 1) / 2)};

    ll ma = *max_element(all(a));
    ll mi = *min_element(all(a));

    ll cntMa = 0, cntMi = 0;

    trav(i, a) {
        if (i == ma)
            cntMa++;
        if (i == mi)
            cntMi++;
    }

    return vector<ll> {ma - mi, cntMa * cntMi};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector<ll> a(n);
    trav(i, a)
        cin >> i;

    vector<ll> res = solve(a);
    trav(j, res)
        cout << j << " ";
    cout << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
