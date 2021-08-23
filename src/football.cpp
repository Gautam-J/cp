/* CF - 1000 */
/*
A. Football
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
One day Vasya decided to have a look at the results of Berland 1910 Football Championship’s finals. Unfortunately he didn't find the overall score of the match; however, he got hold of a profound description of the match's process. On the whole there are n lines in that description each of which described one goal. Every goal was marked with the name of the team that had scored it. Help Vasya, learn the name of the team that won the finals. It is guaranteed that the match did not end in a tie.

Input
The first line contains an integer n (1 ≤ n ≤ 100) — the number of lines in the description. Then follow n lines — for each goal the names of the teams that scored it. The names are non-empty lines consisting of uppercase Latin letters whose lengths do not exceed 10 symbols. It is guaranteed that the match did not end in a tie and the description contains no more than two different teams.

Output
Print the name of the winning team. We remind you that in football the team that scores more goals is considered the winner.

Examples
inputCopy
1
ABC
outputCopy
ABC
inputCopy
5
A
ABA
ABA
A
A
outputCopy
A
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

string whoWon(vector<string>& a) {
    pair<string, int> t1 = {a[0], -1};
    pair<string, int> t2;

    for (int i = 1; i < (int)a.size(); i++) {
        if (a[i] != t1.first) {
            t2.first = a[i];
            t2.second = -1;
            break;
        }
    }

    trav(i, a) {
        if (i == t1.first)
            t1.second++;
        else
            t2.second++;
    }

    if (t2.second > t1.second)
        return t2.first;

    return t1.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> a(n);
    trav(i, a)
        cin >> i;

    cout << whoWon(a) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
