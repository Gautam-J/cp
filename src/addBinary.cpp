/* LC - Easy */
/*
Given two binary strings a and b, return their sum as a binary string.



Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"


Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

/* Time Complexity: O(n) */
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

string processString(string& bigStr, string& smlStr) {
    int lenBig = sz(bigStr), lenSml = sz(smlStr);
    int carry = 0, sum = 0;

    for (int i = lenBig - 1; i >= 0; i--) {
        sum = 0;
        if (lenSml) {
            sum = (smlStr[lenSml - 1] - '0');
            lenSml--;
        }

        sum += (bigStr[i] - '0') + carry;
        carry = sum / 2;
        bigStr[i] = (sum % 2) + '0';
    }

    if (carry)
        return ('1' + bigStr);

    return bigStr;
}

string addBinary(string& a, string& b) {
    if (sz(a) > sz(b))
        return processString(a, b);

    return processString(b, a);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;
    cout << addBinary(a, b) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
