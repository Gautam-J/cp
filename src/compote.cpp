/* CF - 800 */
/*
A. Compote
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Nikolay has a lemons, b apples and c pears. He decided to cook a compote. According to the recipe the fruits should be in the ratio 1: 2: 4. It means that for each lemon in the compote should be exactly 2 apples and exactly 4 pears. You can't crumble up, break up or cut these fruits into pieces. These fruits — lemons, apples and pears — should be put in the compote as whole fruits.

Your task is to determine the maximum total number of lemons, apples and pears from which Nikolay can cook the compote. It is possible that Nikolay can't use any fruits, in this case print 0.

Input
The first line contains the positive integer a (1 ≤ a ≤ 1000) — the number of lemons Nikolay has.

The second line contains the positive integer b (1 ≤ b ≤ 1000) — the number of apples Nikolay has.

The third line contains the positive integer c (1 ≤ c ≤ 1000) — the number of pears Nikolay has.

Output
Print the maximum total number of lemons, apples and pears from which Nikolay can cook the compote.

Examples
inputCopy
2
5
7
outputCopy
7
inputCopy
4
7
13
outputCopy
21
inputCopy
2
3
2
outputCopy
0
Note
In the first example Nikolay can use 1 lemon, 2 apples and 4 pears, so the answer is 1 + 2 + 4 = 7.

In the second example Nikolay can use 3 lemons, 6 apples and 12 pears, so the answer is 3 + 6 + 12 = 21.

In the third example Nikolay don't have enough pears to cook any compote, so the answer is 0.
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

int solve(int a, int b, int c) {
    int portions = min({ a, b / 2, c / 4 });
    return portions * 7;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
