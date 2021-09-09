/* CF - 1200 */
/*
A. Two Bags of Potatoes
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Valera had two bags of potatoes, the first of these bags contains x (x ≥ 1) potatoes, and the second — y (y ≥ 1) potatoes. Valera — very scattered boy, so the first bag of potatoes (it contains x potatoes) Valera lost. Valera remembers that the total amount of potatoes (x + y) in the two bags, firstly, was not gerater than n, and, secondly, was divisible by k.

Help Valera to determine how many potatoes could be in the first bag. Print all such possible numbers in ascending order.

Input
The first line of input contains three integers y, k, n (1 ≤ y, k, n ≤ 109;   ≤ 105).

Output
Print the list of whitespace-separated integers — all possible values of x in ascending order. You should print each possible value of x exactly once.

If there are no such values of x print a single integer -1.

Examples
inputCopy
10 1 10
outputCopy
-1
inputCopy
10 6 40
outputCopy
2 8 14 20 26
*/

/* Time Complexity: O(n) ?? */
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

void solve(int y, int k, int n) {
    int x = k - y % k;
    int top = n - y;

    if (x > top) {
        cout << -1 << nl;
        return;
    }

    cout << x << " ";
    x += k;
    while (x <= top) {
        cout << x << " ";
        x += k;
    }
    cout << nl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int y, k, n;
    cin >> y >> k >> n;

    solve(y, k, n);

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
