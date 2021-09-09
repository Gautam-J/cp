/* CF - 1100 */
/*
A. Yaroslav and Permutations
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Yaroslav has an array that consists of n integers. In one second Yaroslav can swap two neighboring array elements. Now Yaroslav is wondering if he can obtain an array where any two neighboring elements would be distinct in a finite time.

Help Yaroslav.

Input
The first line contains integer n (1 ≤ n ≤ 100) — the number of elements in the array. The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 1000) — the array elements.

Output
In the single line print "YES" (without the quotes) if Yaroslav can obtain the array he needs, and "NO" (without the quotes) otherwise.

Examples
inputCopy
1
1
outputCopy
YES
inputCopy
3
1 1 2
outputCopy
YES
inputCopy
4
7 7 7 7
outputCopy
NO
Note
In the first sample the initial array fits well.

In the second sample Yaroslav can get array: 1, 2, 1. He can swap the last and the second last elements to obtain it.

In the third sample Yarosav can't get the array he needs.
*/

/* Time Complexity: O(n) */
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

bool solve(vi& a) {

    unordered_map<int, int> cnt;
    trav(i, a) {
        if (cnt.find(i) == cnt.end())
            cnt[i] = 1;
        else
            cnt[i]++;
    }

    // the count of each unique number C must be C <= (n + 1) / 2
    int n = sz(a);
    trav(j, cnt) {
        if (j.second > (n + 1) / 2)
            return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vi a(n);
    trav(i, a)
        cin >> i;

    cout << (solve(a) ? "YES" : "NO") << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
