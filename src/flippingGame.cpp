/* CF - 1200 */
/*
A. Flipping Game
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Iahub got bored, so he invented a game to be played on paper.

He writes n integers a1, a2, ..., an. Each of those integers can be either 0 or 1. He's allowed to do exactly one move: he chooses two indices i and j (1 ≤ i ≤ j ≤ n) and flips all values ak for which their positions are in range [i, j] (that is i ≤ k ≤ j). Flip the value of x means to apply operation x = 1 - x.

The goal of the game is that after exactly one move to obtain the maximum number of ones. Write a program to solve the little game of Iahub.

Input
The first line of the input contains an integer n (1 ≤ n ≤ 100). In the second line of the input there are n integers: a1, a2, ..., an. It is guaranteed that each of those n values is either 0 or 1.

Output
Print an integer — the maximal number of 1s that can be obtained after exactly one move.

Examples
inputCopy
5
1 0 0 1 0
outputCopy
4
inputCopy
4
1 0 0 1
outputCopy
4
Note
In the first case, flip the segment from 2 to 5 (i = 2, j = 5). That flip changes the sequence, it becomes: [1 1 1 0 1]. So, it contains four ones. There is no way to make the whole sequence equal to [1 1 1 1 1].

In the second case, flipping only the second and the third element (i = 2, j = 3) will turn all numbers into 1.
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

int solve(vi& a) {
    // Use kadane's algorithm on a custom built array b.

    vi b;
    trav(i, a) {
        if (i == 0)
            b.push_back(1);
        else
            b.push_back(-1);
    }

    int bestLeft = 0, bestRight = 0, temp;
    int maxSum = INT_MIN;
    int left = 0;
    int sum = 0;
    int n = sz(b);

    FOR(i, n) {
       temp = sum + b[i];

       // sum = max(temp, b[i])
       if (temp > b[i]) {
           sum = temp;
       } else {  // after adding A[j], if the sum value decreases, then we start a new subbay
           sum = b[i];
           left = i;
       }

       // maxSum = max(maxSum, sum)
       if (maxSum < sum) {
           maxSum = sum;
           bestLeft = left;
           bestRight = i;
       }
    }

    for (int j = bestLeft; j <= bestRight; j++) {
        a[j] = 1 - a[j];
    }

    int res = 0;
    trav(i, a) {
        if (i == 1)
            res++;
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

    cout << solve(a) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
