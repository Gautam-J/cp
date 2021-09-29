/* CF - 800 */
/*
A. Balanced Substring
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a string s, consisting of n letters, each letter is either 'a' or 'b'. The letters in the string are numbered from 1 to n.

s[l;r] is a continuous substring of letters from index l to r of the string inclusive.

A string is called balanced if the number of letters 'a' in it is equal to the number of letters 'b'. For example, strings "baba" and "aabbab" are balanced and strings "aaab" and "b" are not.

Find any non-empty balanced substring s[l;r] of string s. Print its l and r (1≤l≤r≤n). If there is no such substring, then print −1 −1.

Input
The first line contains a single integer t (1≤t≤1000) — the number of testcases.

Then the descriptions of t testcases follow.

The first line of the testcase contains a single integer n (1≤n≤50) — the length of the string.

The second line of the testcase contains a string s, consisting of n letters, each letter is either 'a' or 'b'.

Output
For each testcase print two integers. If there exists a non-empty balanced substring s[l;r], then print l r (1≤l≤r≤n). Otherwise, print −1 −1.

Example
inputCopy
4
1
a
6
abbaba
6
abbaba
9
babbabbaa
outputCopy
-1 -1
1 6
3 6
2 5
Note
In the first testcase there are no non-empty balanced subtrings.

In the second and third testcases there are multiple balanced substrings, including the entire string "abbaba" and substring "baba".
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
typedef vector<int> vi;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';
const double PI = acos(-1);

void solve(string& s) {
    map<char, int> cnt;

    trav(i, s) {
        if (cnt.find(i) == cnt.end())
            cnt[i] = 1;
        else
            cnt[i]++;
    }

    if (cnt['a'] == 0 || cnt['b'] == 0) {
        cout << "-1 -1" << nl;
        return;
    }

    int n = sz(s);
    FOR(i, n - 1) {
        if ((s[i] == 'a' && s[i + 1] == 'b') || (s[i] == 'b' && s[i + 1] == 'a')) {
            cout << i + 1 << " " << i + 2 << nl;
            return;
        }
    }

    cout << "-1 -1" << nl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    string s;
    while (t--) {
        cin >> n;
        cin >> s;

        solve(s);
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
