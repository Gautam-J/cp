/* Exercise */
/*
Tower of Hanoi using recursion.
*/

/* Time Complexity: O(2^n) */
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
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';
const double PI = acos(-1);

void towerOfHanoi(int n, char source, char destination, char aux) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << " pole" << nl;
        return;
    }

    towerOfHanoi(n - 1, source, aux, destination);
    cout << "Move disk " << n << " from " << source << " to " << destination << " pole" << nl;
    towerOfHanoi(n - 1, aux, destination, source);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    towerOfHanoi(n, 'A', 'C', 'B');

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
