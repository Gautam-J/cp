/* CF - 1300 */
/*
D. Array and Operations
time limit per test2 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
You are given an array a of n integers, and another integer k such that 2k≤n.

You have to perform exactly k operations with this array. In one operation, you have to choose two elements of the array (let them be ai and aj; they can be equal or different, but their positions in the array must not be the same), remove them from the array, and add ⌊aiaj⌋ to your score, where ⌊xy⌋ is the maximum integer not exceeding xy.

Initially, your score is 0. After you perform exactly k operations, you add all the remaining elements of the array to the score.

Calculate the minimum possible score you can get.

Input
The first line of the input contains one integer t (1≤t≤500) — the number of test cases.

Each test case consists of two lines. The first line contains two integers n and k (1≤n≤100; 0≤k≤⌊n2⌋).

The second line contains n integers a1,a2,…,an (1≤ai≤2⋅105).

Output
Print one integer — the minimum possible score you can get.

Example
inputCopy
5
7 3
1 1 1 2 1 3 1
5 1
5 5 5 5 5
4 2
1 3 3 7
2 0
4 2
9 2
1 10 10 1 10 2 7 10 3
outputCopy
2
16
0
6
16
Note
Let's consider the example test.

In the first test case, one way to obtain a score of 2 is the following one:

choose a7=1 and a4=2 for the operation; the score becomes 0+⌊12⌋=0, the array becomes [1,1,1,1,3];
choose a1=1 and a5=3 for the operation; the score becomes 0+⌊13⌋=0, the array becomes [1,1,1];
choose a1=1 and a2=1 for the operation; the score becomes 0+⌊11⌋=1, the array becomes [1];
add the remaining element 1 to the score, so the resulting score is 2.
In the second test case, no matter which operations you choose, the resulting score is 16.

In the third test case, one way to obtain a score of 0 is the following one:

choose a1=1 and a2=3 for the operation; the score becomes 0+⌊13⌋=0, the array becomes [3,7];
choose a1=3 and a2=7 for the operation; the score becomes 0+⌊37⌋=0, the array becomes empty;
the array is empty, so the score doesn't change anymore.
In the fourth test case, no operations can be performed, so the score is the sum of the elements of the array: 4+2=6.
*/

/* Time Complexity: O(n lg n) */
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

ll solve(vi& a, int k) {
    sort(all(a));

    int n = sz(a);
    ll score = 0;

    FOR(i, k)
        score += a[n - 1 - i - k] / a[n - 1 - i];

    FOR(i, n - 2 * k)
            score += a[i];

    return score;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        vi a(n);
        trav(i, a)
            cin >> i;

        cout << solve(a, k) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
