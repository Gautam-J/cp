/* CF - 1300 */
/*
B. Sort the Array
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Being a programmer, you like arrays a lot. For your birthday, your friends have given you an array a consisting of n distinct integers.

Unfortunately, the size of a is too small. You want a bigger array! Your friends agree to give you a bigger array, but only if you are able to answer the following question correctly: is it possible to sort the array a (in increasing order) by reversing exactly one segment of a? See definitions of segment and reversing in the notes.

Input
The first line of the input contains an integer n (1 ≤ n ≤ 105) — the size of array a.

The second line contains n distinct space-separated integers: a[1], a[2], ..., a[n] (1 ≤ a[i] ≤ 109).

Output
Print "yes" or "no" (without quotes), depending on the answer.

If your answer is "yes", then also print two space-separated integers denoting start and end (start must not be greater than end) indices of the segment to be reversed. If there are multiple ways of selecting these indices, print any of them.

Examples
inputCopy
3
3 2 1
outputCopy
yes
1 3
inputCopy
4
2 1 3 4
outputCopy
yes
1 2
inputCopy
4
3 1 2 4
outputCopy
no
inputCopy
2
1 2
outputCopy
yes
1 1
Note
Sample 1. You can reverse the entire array to get [1, 2, 3], which is sorted.

Sample 3. No segment can be reversed such that the array will be sorted.

Definitions

A segment [l, r] of array a is the sequence a[l], a[l + 1], ..., a[r].

If you have an array a of size n and you reverse its segment [l, r], the array will become:

a[1], a[2], ..., a[l - 2], a[l - 1], a[r], a[r - 1], ..., a[l + 1], a[l], a[r + 1], a[r + 2], ..., a[n - 1], a[n].
*/

/* Time Complexity: O(n log n) */
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

void solve(vi& a) {
    if (is_sorted(all(a))) {
        cout << "yes" << nl;
        cout << "1 1" << nl;
        return;
    }

    int n = sz(a);
    int start = 0, end = n - 1;

    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] < a[i]) {
            start = i;
            break;
        }
    }

    for (int j = start; j < n - 1; j++) {
        if (a[j + 1] > a[j]) {
            end = j;
            break;
        }
    }

    reverse(a.begin() + start, a.begin() + end + 1);

    if (is_sorted(all(a))) {
        cout << "yes" << nl;
        cout << start + 1 << " " << end + 1 << nl;
    } else {
        cout << "no" << nl;
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vi a(n);
    trav(i, a)
        cin >> i;

    solve(a);

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
