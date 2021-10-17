/* CC - SnackDown 2021 */
/*
Chef buys a lottery ticket that has a  digit code associated with it. He thinks that digit  is his lucky digit and brings him good luck. Chef will win some amount in the lottery if at least one of the digits of the lottery ticket is .

Given three digits , , and  of the lottery ticket, tell whether Chef wins something or not?

Input Format
First line will contain , the number of test cases. Then the test cases follow.
Each test case contains a single line of input, three space separated integers .
Output Format
For each testcase, output in a single line answer "YES" if Chef wins a positive amount with the lottery and "NO" if not.

You may print each character of the string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints


Sample Input 1
3
0 0 0
7 8 9
2 7 7
Sample Output 1
NO
YES
YES
Explanation
Test Case : Since no digit is equal to , Chef fails to win any amount in the lottery.

Test Case : Since the first digit is equal to , Chef will win some amount in the lottery.

Test Case : Since the second and third digit is equal to , Chef will win some amount in the lottery.
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

bool solve(int a, int b, int c) {
    return (a == 7 || b == 7 || c == 7);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, a, b, c;
    cin >> t;

    while (t--) {
        cin >> a >> b >> c;
        cout << (solve(a, b, c) ? "YES" : "NO") << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
