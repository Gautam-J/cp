/* CF - 1100 */
/*
A. Cinema Line
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The new "Die Hard" movie has just been released! There are n people at the cinema box office standing in a huge line. Each of them has a single 100, 50 or 25 ruble bill. A "Die Hard" ticket costs 25 rubles. Can the booking clerk sell a ticket to each person and give the change if he initially has no money and sells the tickets strictly in the order people follow in the line?

Input
The first line contains integer n (1 ≤ n ≤ 105) — the number of people in the line. The next line contains n integers, each of them equals 25, 50 or 100 — the values of the bills the people have. The numbers are given in the order from the beginning of the line (at the box office) to the end of the line.

Output
Print "YES" (without the quotes) if the booking clerk can sell a ticket to each person and give the change. Otherwise print "NO".

Examples
inputCopy
4
25 25 50 50
outputCopy
YES
inputCopy
2
25 100
outputCopy
NO
inputCopy
4
50 50 25 25
outputCopy
NO
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
    int c25 = 0, c50 = 0;

    trav(i, a) {
        if (i == 25) {
            c25++;
        } else if (i == 50) {  // should give 25 back
            c50++;

            if (c25 >= 1)
                c25--;
            else
                return false;
        } else if (i == 100) {  // should give 75 back
            if (c50 >= 1 && c25 >= 1) {
                c25--;
                c50--;
            } else if (c25 >= 3)
                c25 -= 3;
            else
                return false;
        }
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
