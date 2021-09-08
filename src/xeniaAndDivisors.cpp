/* CF - 1200 */
/*
A. Xenia and Divisors
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Xenia the mathematician has a sequence consisting of n (n is divisible by 3) positive integers, each of them is at most 7. She wants to split the sequence into groups of three so that for each group of three a, b, c the following conditions held:

a < b < c;
a divides b, b divides c.
Naturally, Xenia wants each element of the sequence to belong to exactly one group of three. Thus, if the required partition exists, then it has  groups of three.

Help Xenia, find the required partition or else say that it doesn't exist.

Input
The first line contains integer n (3 ≤ n ≤ 99999) — the number of elements in the sequence. The next line contains n positive integers, each of them is at most 7.

It is guaranteed that n is divisible by 3.

Output
If the required partition exists, print  groups of three. Print each group as values of the elements it contains. You should print values in increasing order. Separate the groups and integers in groups by whitespaces. If there are multiple solutions, you can print any of them.

If there is no solution, print -1.

Examples
inputCopy
6
1 1 1 2 2 2
outputCopy
-1
inputCopy
6
2 2 1 1 4 6
outputCopy
1 2 4
1 2 6
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
typedef vector<int> vi;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';
const double PI = acos(-1);

void solve(vi& a) {
    // only possible combinations
    // 1 2 4
    // 1 2 6
    // 1 3 6
    //
    // thus we can be greedy and check if the above combinations is possible.

    int cnt[8] = { 0 };
    trav(i, a)
        cnt[i]++;

    if (cnt[5] == 0 && cnt[7] == 0 &&
        cnt[2] >= cnt[4] && cnt[1] == cnt[4] + cnt[6] &&
        cnt[2] + cnt[3] == cnt[4] + cnt[6]) {

        FOR(i, cnt[4])
            cout << "1 2 4" << nl;
        cnt[2] -= cnt[4];

        FOR(i, cnt[2])
            cout << "1 2 6" << nl;

        FOR(i, cnt[3])
            cout << "1 3 6" << nl;
    } else {
        cout << "-1" << nl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vi a(n);
    trav(i, a)
        cin >> i;

    solve(a);

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
