/* CF - 1200 */
/*
A. Cards with Numbers
time limit per test1 second
memory limit per test256 megabytes
inputinput.txt
outputoutput.txt
Petya has got 2n cards, each card contains some integer. The numbers on the cards can be the same. Let's index all cards by consecutive integers from 1 to 2n. We'll denote the number that is written on a card with number i, as ai. In order to play one entertaining game with his friends, Petya needs to split the cards into pairs so that each pair had equal numbers on the cards. Help Petya do that.

Input
The first line contains integer n (1 ≤ n ≤ 3·105). The second line contains the sequence of 2n positive integers a1, a2, ..., a2n (1 ≤ ai ≤ 5000) — the numbers that are written on the cards. The numbers on the line are separated by single spaces.

Output
If it is impossible to divide the cards into pairs so that cards in each pair had the same numbers, print on a single line integer -1. But if the required partition exists, then print n pairs of integers, a pair per line — the indices of the cards that form the pairs.

Separate the numbers on the lines by spaces. You can print the pairs and the numbers in the pairs in any order. If there are multiple solutions, print any of them.

Examples
inputCopy
3
20 30 10 30 20 10
outputCopy
4 2
1 5
6 3
inputCopy
1
1 2
outputCopy
-1
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

void solve(vi& a) {
    vi index[5001];

    int n = sz(a);
    for (int i = 1; i <= n; i++)
        index[a[i - 1]].push_back(i);

    bool isAllEven = true;
    for (int i = 1; i <= 5000; i++) {
        if (sz(index[i]) % 2 != 0) {
            isAllEven = false;
            break;
        }
    }

    if (!isAllEven) {
        cout << -1 << nl;
        return;
    }

    for (int i = 1; i <= 5000; i++) {
        for (int j = 0; j < sz(index[i]); j += 2)
            cout << index[i][j] << " " << index[i][j + 1] << nl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vi a(2 * n);
    trav(i, a)
        cin >> i;

    solve(a);

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
