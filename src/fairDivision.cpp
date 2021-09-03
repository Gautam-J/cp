/* CF - 800 */
/*
B. Fair Division
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Alice and Bob received n candies from their parents. Each candy weighs either 1 gram or 2 grams. Now they want to divide all candies among themselves fairly so that the total weight of Alice's candies is equal to the total weight of Bob's candies.

Check if they can do that.

Note that candies are not allowed to be cut in half.

Input
The first line contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow.

The first line of each test case contains an integer n (1≤n≤100) — the number of candies that Alice and Bob received.

The next line contains n integers a1,a2,…,an — the weights of the candies. The weight of each candy is either 1 or 2.

It is guaranteed that the sum of n over all test cases does not exceed 105.

Output
For each test case, output on a separate line:

"YES", if all candies can be divided into two sets with the same weight;
"NO" otherwise.
You can output "YES" and "NO" in any case (for example, the strings yEs, yes, Yes and YES will be recognized as positive).

Example
inputCopy
5
2
1 1
2
1 2
4
1 2 1 2
3
2 2 2
3
2 1 2
outputCopy
YES
NO
YES
NO
NO
Note
In the first test case, Alice and Bob can each take one candy, then both will have a total weight of 1.

In the second test case, any division will be unfair.

In the third test case, both Alice and Bob can take two candies, one of weight 1 and one of weight 2.

In the fourth test case, it is impossible to divide three identical candies between two people.

In the fifth test case, any division will also be unfair.
*/

/* Time Complexity: O(n) */
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
const double PI = acos(-1);

bool isFair(vi& a) {
    map<int, int> cnt;
    int n = a.size();
    int sum = 0;

    trav(i, a) {
        sum += i;
        if (cnt.find(i) == cnt.end())
            cnt[i] = 1;
        else
            cnt[i]++;
    }

    if (sum % 2 != 0)
        return false;

    if (cnt[1] >= 2)
        return true;

    if (cnt[1] == 0 && n % 2 == 0)
        return true;

    return false;
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

        cout << (isFair(a) ? "YES" : "NO") << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
