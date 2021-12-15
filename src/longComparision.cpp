/* CF - 900 */
/*
A. Long Comparison
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Monocarp wrote down two numbers on a whiteboard. Both numbers follow a specific format: a positive integer x with p zeros appended to its end.

Now Monocarp asks you to compare these two numbers. Can you help him?

Input
The first line contains a single integer t (1≤t≤104) — the number of testcases.

The first line of each testcase contains two integers x1 and p1 (1≤x1≤106;0≤p1≤106) — the description of the first number.

The second line of each testcase contains two integers x2 and p2 (1≤x2≤106;0≤p2≤106) — the description of the second number.

Output
For each testcase print the result of the comparison of the given two numbers. If the first number is smaller than the second one, print '<'. If the first number is greater than the second one, print '>'. If they are equal, print '='.

Example
inputCopy
5
2 1
19 0
10 2
100 1
1999 0
2 3
1 0
1 0
99 0
1 2
outputCopy
>
=
<
=
<
Note
The comparisons in the example are: 20>19, 1000=1000, 1999<2000, 1=1, 99<100.
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

void solve(ll x1, ll p1, ll x2, ll p2) {
    // remove the common powers
    ll minimum = min(p1, p2);
    p1 -= minimum;
    p2 -= minimum;

    if (p1 >= 7)
        cout << ">" << nl;
    else if (p2 >= 7)
        cout << "<" << nl;
    else {
        x1 *= pow(10, p1);
        x2 *= pow(10, p2);

        if (x1 > x2)
            cout << ">" << nl;
        else if (x1 < x2)
            cout << "<" << nl;
        else
            cout << "=" << nl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    ll x1, p1, x2, p2;
    while (t--) {
        cin >> x1 >> p1 >> x2 >> p2;
        solve(x1, p1, x2, p2);
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
