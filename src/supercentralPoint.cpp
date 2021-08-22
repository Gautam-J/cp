/* CF - 1000 */
/*
A. Supercentral Point
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
One day Vasya painted a Cartesian coordinate system on a piece of paper and marked some set of points (x1, y1), (x2, y2), ..., (xn, yn). Let's define neighbors for some fixed point from the given set (x, y):

point (x', y') is (x, y)'s right neighbor, if x' > x and y' = y
point (x', y') is (x, y)'s left neighbor, if x' < x and y' = y
point (x', y') is (x, y)'s lower neighbor, if x' = x and y' < y
point (x', y') is (x, y)'s upper neighbor, if x' = x and y' > y
We'll consider point (x, y) from the given set supercentral, if it has at least one upper, at least one lower, at least one left and at least one right neighbor among this set's points.

Vasya marked quite many points on the paper. Analyzing the picture manually is rather a challenge, so Vasya asked you to help him. Your task is to find the number of supercentral points in the given set.

Input
The first input line contains the only integer n (1 ≤ n ≤ 200) — the number of points in the given set. Next n lines contain the coordinates of the points written as "x y" (without the quotes) (|x|, |y| ≤ 1000), all coordinates are integers. The numbers in the line are separated by exactly one space. It is guaranteed that all points are different.

Output
Print the only number — the number of supercentral points of the given set.

Examples
inputCopy
8
1 1
4 2
3 1
1 2
0 2
0 1
1 0
1 3
outputCopy
2
inputCopy
5
0 0
0 1
1 0
0 -1
-1 0
outputCopy
1
Note
In the first sample the supercentral points are only points (1, 1) and (1, 2).

In the second sample there is one supercental point — point (0, 0).

*/

/* Time Complexity: O(n^2) */
/* Space Complexity: O(1) */

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

int superPoints(vector<pair<int, int>>& pnt) {
    int n = pnt.size();
    int res = 0;

    bool upper, lower, left, right;
    for (int i = 0; i < n; i++) {
        upper = false, lower = false, right = false, left = false;

        for (int j = 0; j < n; j++) {
            if (pnt[i] == pnt[j])
                continue;

            // check upper and lower
            if (pnt[j].second > pnt[i].second && pnt[j].first == pnt[i].first)
                upper = true;
            else if (pnt[j].second < pnt[i].second && pnt[j].first == pnt[i].first)
                lower = true;

            // check right and left
            if (pnt[j].first > pnt[i].first && pnt[j].second == pnt[i].second)
                right = true;
            else if (pnt[j].first < pnt[i].first && pnt[j].second == pnt[i].second)
                left = true;
        }

        if (upper && lower && right && left)
            res++;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> pnt(n);
    trav(i, pnt)
        cin >> i.first >> i.second;

    cout << superPoints(pnt) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
