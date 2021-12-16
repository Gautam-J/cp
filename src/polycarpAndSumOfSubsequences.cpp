/* CF - 800 */
/*
A. Polycarp and Sums of Subsequences
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp had an array a of 3 positive integers. He wrote out the sums of all non-empty subsequences of this array, sorted them in non-decreasing order, and got an array b of 7 integers.

For example, if a={1,4,3}, then Polycarp wrote out 1, 4, 3, 1+4=5, 1+3=4, 4+3=7, 1+4+3=8. After sorting, he got an array b={1,3,4,4,5,7,8}.
Unfortunately, Polycarp lost the array a. He only has the array b left. Help him to restore the array a.

Input
The first line contains one integer t (1≤t≤5000) — the number of test cases.

Each test case consists of one line which contains 7 integers b1,b2,…,b7 (1≤bi≤109; bi≤bi+1).

Additional constraint on the input: there exists at least one array a which yields this array b as described in the statement.

Output
For each test case, print 3 integers — a1, a2 and a3. If there can be several answers, print any of them.

Example
inputCopy
5
1 3 4 4 5 7 8
1 2 3 4 5 6 7
300000000 300000000 300000000 600000000 600000000 600000000 900000000
1 1 2 999999998 999999999 999999999 1000000000
1 2 2 3 3 4 5
outputCopy
1 4 3
4 1 2
300000000 300000000 300000000
999999998 1 1
1 2 2
Note
The subsequence of the array a is a sequence that can be obtained from a by removing zero or more of its elements.

Two subsequences are considered different if index sets of elements included in them are different. That is, the values of the elements don't matter in the comparison of subsequences. In particular, any array of length 3 has exactly 7 different non-empty subsequences.
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
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';
const double PI = acos(-1);

void solve2(vi& a) {
    cout << a[0] << " " << a[1] << " " << a[6] - a[0] - a[1] << nl;
}

void solve(vi& a) {
    // accepted O(n) solution
    int n = sz(a);
    int low = 1, high = n - 2, sum;

    while (low <= high) {
        sum = a[low] + a[high];

        if (sum == a[n - 1] - a[0]) {
            cout << a[0] << " " << a[low] << " " << a[high] << nl;
            return;
        }

        if (sum < a[n - 1] - a[0])
            low++;
        else
            high--;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        vi a(7);
        trav(i, a)
            cin >> i;

        solve(a);
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
