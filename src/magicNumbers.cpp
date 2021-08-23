/* CF - 900 */
/*
A. Magic Numbers
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
A magic number is a number formed by concatenation of numbers 1, 14 and 144. We can use each of these numbers any number of times. Therefore 14144, 141414 and 1411 are magic numbers but 1444, 514 and 414 are not.

You're given a number. Determine if it is a magic number or not.

Input
The first line of input contains an integer n, (1 ≤ n ≤ 109). This number doesn't contain leading zeros.

Output
Print "YES" if n is a magic number or print "NO" if it's not.

Examples
inputCopy
114114
outputCopy
YES
inputCopy
1111
outputCopy
YES
inputCopy
441231
outputCopy
NO
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

bool isMagic(string& s) {
    // if starting num is 4
    if (s[0] == '4')
        return false;

    // if s contains any other number other than 1 and 4
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] != '1' && s[i] != '4')
            return false;
    }

    // 1 14 144 do not contain 444
    if (s.find("444") != s.npos)
        return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    cout << (isMagic(s) ? "YES" : "NO") << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
