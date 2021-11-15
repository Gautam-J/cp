/* Practice */
/*
Calculate the power of a number using recursion.
*/

/* Time Complexity: O(p) where p is the power */
/* Space Complexity: O(p) where p is the power */

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

ll getPowerIterative(ll n, ll pow) {
    ll res = 1;
    for (int i = 1; i <= pow; i++) {
        res *= n;
    }

    return res;
}

ll getPower(ll n, ll pow) {
    if (pow == 0)
        return 1;

    if (pow == 1)
        return n;

    return n * getPower(n, pow - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, pow;
    cin >> n >> pow;

    cout << getPower(n, pow) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
