
/*
C. Paint the Array
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array a consisting of n positive integers. You have to choose a positive integer d and paint all elements into two colors. All elements which are divisible by d will be painted red, and all other elements will be painted blue.

The coloring is called beautiful if there are no pairs of adjacent elements with the same color in the array. Your task is to find any value of d which yields a beautiful coloring, or report that it is impossible.

Input
The first line contains a single integer t (1≤t≤1000) — the number of testcases.

The first line of each testcase contains one integer n (2≤n≤100) — the number of elements of the array.

The second line of each testcase contains n integers a1,a2,…,an (1≤ai≤1018).

Output
For each testcase print a single integer. If there is no such value of d that yields a beautiful coloring, print 0. Otherwise, print any suitable value of d (1≤d≤1018).

Example
inputCopy
5
5
1 2 3 4 5
3
10 5 15
3
100 10 200
10
9 8 2 6 6 2 8 6 5 4
2
1 3
outputCopy
2
0
100
0
3

*/

/* Time Complexity: O(n) */
/* Space Complexity: O(1) */

#include <algorithm>
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

ll solve(vector<ll>& a) {
    vector<ll> g(a.begin(), a.begin() + 2);

    int n = sz(a);
    FOR(i, n)
        g[i % 2] = __gcd(g[i % 2], a[i]);

    vector<bool> good(2, true);
    FOR(i, n)
        good[i % 2] = good[i % 2] && (a[i] % g[(i % 2) ^ 1] > 0);

    ll ans = 0;
    FOR(i, 2) {
        if (good[i])
            ans = max(ans, g[i ^ 1]);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<ll> a(n);
        trav(i, a)
            cin >> i;

        cout << solve(a) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
