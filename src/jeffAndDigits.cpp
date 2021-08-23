/* CF - 1000 */
/*
A. Jeff and Digits
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Jeff's got n cards, each card contains either digit 0, or digit 5. Jeff can choose several cards and put them in a line so that he gets some number. What is the largest possible number divisible by 90 Jeff can make from the cards he's got?

Jeff must make the number without leading zero. At that, we assume that number 0 doesn't contain any leading zeroes. Jeff doesn't have to use all the cards.

Input
The first line contains integer n (1 ≤ n ≤ 103). The next line contains n integers a1, a2, ..., an (ai = 0 or ai = 5). Number ai represents the digit that is written on the i-th card.

Output
In a single line print the answer to the problem — the maximum number, divisible by 90. If you can't make any divisible by 90 number from the cards, print -1.

Examples
inputCopy
4
5 0 5 0
outputCopy
0
inputCopy
11
5 5 5 5 5 5 5 5 0 5 5
outputCopy
5555555550
Note
In the first test you can make only one number that is a multiple of 90 — 0.

In the second test you can make number 5555555550, it is a multiple of 90.
*/

/* Time Complexity: O(n) */
/* Space Complexity: O(n) */

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

void maxNum(vi& a) {
    // digit -> frequency of the digit
    map<int, int> cnt;

    trav(i, a) {
        if (cnt.find(i) == cnt.end())
            cnt[i] = 1;
        else
            cnt[i]++;
    }

    if (cnt[0] < 1) {
        cout << -1 << nl;
        return;
    }

    bool flag1 = false;
    while (cnt[5] > -1) {
        if ((cnt[5] * 5) % 9 == 0) {
            FOR(i, cnt[5]) {
                flag1 = true;
                cout << 5;
            }
            if (flag1) {
                FOR(i, cnt[0])
                    cout << 0;
            } else {
                cout << 0;
            }
            break;
        } else {
            cnt[5]--;
        }
    }

    cout << nl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vi a(n);
    trav(i, a)
        cin >> i;

    maxNum(a);

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
