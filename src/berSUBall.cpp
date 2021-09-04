/* CF - 1200 */
/*
B. BerSU Ball
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
The Berland State University is hosting a ballroom dance in celebration of its 100500-th anniversary! n boys and m girls are already busy rehearsing waltz, minuet, polonaise and quadrille moves.

We know that several boy&girl pairs are going to be invited to the ball. However, the partners' dancing skill in each pair must differ by at most one.

For each boy, we know his dancing skills. Similarly, for each girl we know her dancing skills. Write a code that can determine the largest possible number of pairs that can be formed from n boys and m girls.

Input
The first line contains an integer n (1 ≤ n ≤ 100) — the number of boys. The second line contains sequence a1, a2, ..., an (1 ≤ ai ≤ 100), where ai is the i-th boy's dancing skill.

Similarly, the third line contains an integer m (1 ≤ m ≤ 100) — the number of girls. The fourth line contains sequence b1, b2, ..., bm (1 ≤ bj ≤ 100), where bj is the j-th girl's dancing skill.

Output
Print a single number — the required maximum possible number of pairs.

Examples
inputCopy
4
1 4 6 2
5
5 1 5 7 9
outputCopy
3
inputCopy
4
1 2 3 4
4
10 11 12 13
outputCopy
0
inputCopy
5
1 1 1 1 1
3
1 2 3
outputCopy
2
*/

/* Time Complexity: O(nm) */
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

int maxPairs(vi& b, vi& g) {
    int n = b.size();
    int m = g.size();
    int res = 0;

    sort(all(b));
    sort(all(g));

    for (int i = 0; i < n; i++) {
        for (int j =0; j < m; j++) {
            if (abs(b[i] - g[j]) <= 1) {
                g.erase(g.begin() + j);
                m--;
                res++;
                break;
            }
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;

    vi b(n);
    trav(i, b)
        cin >> i;

    cin >> m;

    vi g(m);
    trav(i, g)
        cin >> i;

    cout << maxPairs(b, g) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
