/* CF - 1200 */
/*
A. Pythagorean Theorem II
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
In mathematics, the Pythagorean theorem — is a relation in Euclidean geometry among the three sides of a right-angled triangle. In terms of areas, it states:

In any right-angled triangle, the area of the square whose side is the hypotenuse (the side opposite the right angle) is equal to the sum of the areas of the squares whose sides are the two legs (the two sides that meet at a right angle).

The theorem can be written as an equation relating the lengths of the sides a, b and c, often called the Pythagorean equation:

a2 + b2 = c2
where c represents the length of the hypotenuse, and a and b represent the lengths of the other two sides.


Given n, your task is to count how many right-angled triangles with side-lengths a, b and c that satisfied an inequality 1 ≤ a ≤ b ≤ c ≤ n.

Input
The only line contains one integer n (1 ≤ n ≤ 104) as we mentioned above.

Output
Print a single integer — the answer to the problem.

Examples
inputCopy
5
outputCopy
1
inputCopy
74
outputCopy
35
*/

/* Time Complexity: O(n^2) */
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

int solve(int n) {
    int sq[n + 1];
    for (int i = 0; i <= n; i++)
        sq[i] = i * i;

    int k, res = 0;
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            k = sqrt(sq[i] + sq[j]);
			if (k <= n && sq[i] + sq[j] == sq[k])
				res++;
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cout << solve(n) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
