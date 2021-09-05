/* CF - 1000 */
/*
B. Scenes From a Memory
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
During the hypnosis session, Nicholas suddenly remembered a positive integer n, which doesn't contain zeros in decimal notation.

Soon, when he returned home, he got curious: what is the maximum number of digits that can be removed from the number so that the number becomes not prime, that is, either composite or equal to one?

For some numbers doing so is impossible: for example, for number 53 it's impossible to delete some of its digits to obtain a not prime integer. However, for all n in the test cases of this problem, it's guaranteed that it's possible to delete some of their digits to obtain a not prime number.

Note that you cannot remove all the digits from the number.

A prime number is a number that has no divisors except one and itself. A composite is a number that has more than two divisors. 1 is neither a prime nor a composite number.

Input
Each test contains multiple test cases.

The first line contains one positive integer t (1≤t≤103), denoting the number of test cases. Description of the test cases follows.

The first line of each test case contains one positive integer k (1≤k≤50) — the number of digits in the number.

The second line of each test case contains a positive integer n, which doesn't contain zeros in decimal notation (10k−1≤n<10k). It is guaranteed that it is always possible to remove less than k digits to make the number not prime.

It is guaranteed that the sum of k over all test cases does not exceed 104.

Output
For every test case, print two numbers in two lines. In the first line print the number of digits, that you have left in the number. In the second line print the digits left after all delitions.

If there are multiple solutions, print any.

Example
inputCopy
7
3
237
5
44444
3
221
2
35
3
773
1
4
30
626221626221626221626221626221
outputCopy
2
27
1
4
1
1
2
35
2
77
1
4
1
6
Note
In the first test case, you can't delete 2 digits from the number 237, as all the numbers 2, 3, and 7 are prime. However, you can delete 1 digit, obtaining a number 27=33.

In the second test case, you can delete all digits except one, as 4=22 is a composite number.
*/

/* Time Complexity: O(k) */
/* Space Complexity: O(1) or more like O(100) */

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

void solve(int n, string& s, bool prime[]) {

    FOR(i, n) {
        if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8'
                || s[i] == '9') {
            cout << 1 << nl;
            cout << s[i] << nl;
            return;
        }
    }

    FOR(i, n) {
        for (int j = i + 1; j < n; j++) {
            if (!prime[(s[i] - '0') * 10 + (s[j] - '0')]) {
                cout << 2 << nl;
                cout << s[i] << s[j] << nl;
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    bool prime[100];
    for (int i = 2; i < 100; i++) {
        prime[i] = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0)
                prime[i] = false;
        }
    }

    int t, n;
    cin >> t;

    string s;
    while (t--) {
        cin >> n;
        cin >> s;

        solve(n, s, prime);
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
