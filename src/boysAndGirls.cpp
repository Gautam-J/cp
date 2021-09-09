/* CF - 1100 */
/*
A. Boys and Girls
time limit per test1 second
memory limit per test256 megabytes
inputinput.txt
outputoutput.txt
There are n boys and m girls studying in the class. They should stand in a line so that boys and girls alternated there as much as possible. Let's assume that positions in the line are indexed from left to right by numbers from 1 to n + m. Then the number of integers i (1 ≤ i < n + m) such that positions with indexes i and i + 1 contain children of different genders (position i has a girl and position i + 1 has a boy or vice versa) must be as large as possible.

Help the children and tell them how to form the line.

Input
The single line of the input contains two integers n and m (1 ≤ n, m ≤ 100), separated by a space.

Output
Print a line of n + m characters. Print on the i-th position of the line character "B", if the i-th position of your arrangement should have a boy and "G", if it should have a girl.

Of course, the number of characters "B" should equal n and the number of characters "G" should equal m. If there are multiple optimal solutions, print any of them.

Examples
inputCopy
3 3
outputCopy
GBGBGB
inputCopy
4 2
outputCopy
BGBGBB
Note
In the first sample another possible answer is BGBGBG.

In the second sample answer BBGBGB is also optimal.

*/

/* Time Complexity: O(max(n, m)) */
/* Space Complexity: O(n + m) */

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

string solve(int n, int m) {
    if (n >= m) {
        string res(n + m, 'B');
        for (int i = 1; i < 2 * m; i += 2)
            res[i] = 'G';

        return res;
    }

    string res(n + m, 'G');
    for (int i = 1; i < 2 * n; i += 2)
        res[i] = 'B';

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    cout << solve(n, m) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
