/* CF - 1100 */
/*
A. Kitahara Haruki's Gift
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Kitahara Haruki has bought n apples for Touma Kazusa and Ogiso Setsuna. Now he wants to divide all the apples between the friends.

Each apple weights 100 grams or 200 grams. Of course Kitahara Haruki doesn't want to offend any of his friend. Therefore the total weight of the apples given to Touma Kazusa must be equal to the total weight of the apples given to Ogiso Setsuna.

But unfortunately Kitahara Haruki doesn't have a knife right now, so he cannot split any apple into some parts. Please, tell him: is it possible to divide all the apples in a fair way between his friends?

Input
The first line contains an integer n (1 ≤ n ≤ 100) — the number of apples. The second line contains n integers w1, w2, ..., wn (wi = 100 or wi = 200), where wi is the weight of the i-th apple.

Output
In a single line print "YES" (without the quotes) if it is possible to divide all the apples between his friends. Otherwise print "NO" (without the quotes).

Examples
inputCopy
3
100 200 100
outputCopy
YES
inputCopy
4
100 100 100 200
outputCopy
NO
Note
In the first test sample Kitahara Haruki can give the first and the last apple to Ogiso Setsuna and the middle apple to Touma Kazusa.
*/

/* Time Complexity: O(n) */
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

bool solve(vi& a) {
    int n = sz(a);

    if (n == 1)
        return false;

    map<int, int> cnt;
    cnt[100] = 0;
    cnt[200] = 0;

    trav(i, a)
        cnt[i]++;

    int sum = 100 * cnt[100] + 200 * cnt[200];
    if (sum % 200 != 0)
        return false;

    int half = sum / 2;
    bool res = false;

    for (int i = 0; i <= cnt[200]; i++) {
        if (200 * i <= half && half - 200 * i <= cnt[100] * 100)
            res = true;
    }

    return res;
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
