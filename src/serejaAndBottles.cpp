/* CF - 1400 */
/*
A. Sereja and Bottles
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Sereja and his friends went to a picnic. The guys had n soda bottles just for it. Sereja forgot the bottle opener as usual, so the guys had to come up with another way to open bottles.

Sereja knows that the i-th bottle is from brand ai, besides, you can use it to open other bottles of brand bi. You can use one bottle to open multiple other bottles. Sereja can open bottle with opened bottle or closed bottle.

Knowing this, Sereja wants to find out the number of bottles they've got that they won't be able to open in any way. Help him and find this number.

Input
The first line contains integer n (1 ≤ n ≤ 100) — the number of bottles. The next n lines contain the bottles' description. The i-th line contains two integers ai, bi (1 ≤ ai, bi ≤ 1000) — the description of the i-th bottle.

Output
In a single line print a single integer — the answer to the problem.

Examples
inputCopy
4
1 1
2 2
3 3
4 4
outputCopy
4
inputCopy
4
1 2
2 3
3 4
4 1
outputCopy
0
*/

/* Time Complexity: O(n^2) */
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

int solve(vector<pair<int, int>>& a) {
    // for each bottle, check if you can open it with another bottle.

    int n = sz(a);
    bool seen[n];
    memset(seen, false, sizeof(seen));

    FOR(i, n) {
        FOR(j, n) {
            if (i != j && a[j].second == a[i].first)
                seen[i] = true;
        }
    }

    int res = 0;
    FOR(k, n) {
        if (!seen[k])
            res++;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    trav(i, a)
        cin >> i.first >> i.second;

    cout << solve(a) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
