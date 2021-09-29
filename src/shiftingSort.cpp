
/*
B. Shifting Sort
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The new generation external memory contains an array of integers a[1…n]=[a1,a2,…,an].

This type of memory does not support changing the value of an arbitrary element. Instead, it allows you to cut out any segment of the given array, cyclically shift (rotate) it by any offset and insert it back into the same place.

Technically, each cyclic shift consists of two consecutive actions:

You may select arbitrary indices l and r (1≤l<r≤n) as the boundaries of the segment.
Then you replace the segment a[l…r] with it's cyclic shift to the left by an arbitrary offset d. The concept of a cyclic shift can be also explained by following relations: the sequence [1,4,1,3] is a cyclic shift of the sequence [3,1,4,1] to the left by the offset 1 and the sequence [4,1,3,1] is a cyclic shift of the sequence [3,1,4,1] to the left by the offset 2.
For example, if a=[1,3,2,8,5], then choosing l=2, r=4 and d=2 yields a segment a[2…4]=[3,2,8]. This segment is then shifted by the offset d=2 to the left, and you get a segment [8,3,2] which then takes the place of of the original elements of the segment. In the end you get a=[1,8,3,2,5].

Sort the given array a using no more than n cyclic shifts of any of its segments. Note that you don't need to minimize the number of cyclic shifts. Any method that requires n or less cyclic shifts will be accepted.

Input
The first line contains an integer t (1≤t≤1000) — the number of test cases.

The next 2t lines contain the descriptions of the test cases.

The first line of each test case description contains an integer n (2≤n≤50) — the length of the array. The second line consists of space-separated elements of the array ai (−109≤ai≤109). Elements of array a may repeat and don't have to be unique.

Output
Print t answers to all input test cases.

The first line of the answer of each test case should contain an integer k (0≤k≤n) — the number of actions to sort the array. The next k lines should contain descriptions of the actions formatted as "l r d" (without quotes) where l and r (1≤l<r≤n) are the boundaries of the segment being shifted, while d (1≤d≤r−l) is the offset value. Please remember that only the cyclic shifts to the left are considered so the chosen segment will be shifted by the offset d to the to the left.

Note that you are not required to find the minimum number of cyclic shifts needed for sorting. Any sorting method where the number of shifts does not exceed n will be accepted.

If the given array a is already sorted, one of the possible answers is k=0 and an empty sequence of cyclic shifts.

If there are several possible answers, you may print any of them.

Example
inputCopy
4
2
2 1
3
1 2 1
4
2 4 1 3
5
2 5 1 4 3
outputCopy
1
1 2 1
1
1 3 2
3
2 4 1
2 3 1
1 3 2
4
2 4 2
1 5 3
1 2 1
1 3 1
Note
Explanation of the fourth data set in the example:

The segment a[2…4] is selected and is shifted to the left by 2: [2,5,1,4,3]⟶[2,4,5,1,3]
The segment a[1…5] is then selected and is shifted to the left by 3: [2,4,5,1,3]⟶[1,3,2,4,5]
After that the segment a[1…2] is selected and is shifted to the left by 1: [1,3,2,4,5]⟶[3,1,2,4,5]
And in the end the segment a[1…3] is selected and is shifted to the left by 1: [3,1,2,4,5]⟶[1,2,3,4,5]
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
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';
const double PI = acos(-1);

void leftShift(vi& a, int l, int r) {
    int temp = a[l];
    for (int i = l; i < r; i++)
        a[i] = a[i + 1];
    a[r] = temp;
}

void solve(vi& a) {
    int maxElement, l, r;
    int c = 0;
    int n = sz(a);
    vector<pair<int, int>> res;

    while (!is_sorted(all(a))) {
        l = -1;
        r = -1;
        maxElement = INT_MIN;

        for (int i = 0; i < n - c; i++) {
            if (a[i] > maxElement) {
                maxElement = a[i];
                l = i;
                r = n - 1 - c;
            }
        }

        leftShift(a, l, r);
        c++;
        if (l != r)
            res.push_back({l + 1, r + 1});
    }

    cout << res.size() << nl;
    trav(p, res)
        cout << p.first << " " << p.second << " " << 1 << nl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;

        vi a(n);
        trav(i, a)
            cin >> i;

        solve(a);
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
