/* CF - 1000 */
/*
A. k-String
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
A string is called a k-string if it can be represented as k concatenated copies of some string. For example, the string "aabaabaabaab" is at the same time a 1-string, a 2-string and a 4-string, but it is not a 3-string, a 5-string, or a 6-string and so on. Obviously any string is a 1-string.

You are given a string s, consisting of lowercase English letters and a positive integer k. Your task is to reorder the letters in the string s in such a way that the resulting string is a k-string.

Input
The first input line contains integer k (1 ≤ k ≤ 1000). The second line contains s, all characters in s are lowercase English letters. The string length s satisfies the inequality 1 ≤ |s| ≤ 1000, where |s| is the length of string s.

Output
Rearrange the letters in string s in such a way that the result is a k-string. Print the result on a single output line. If there are multiple solutions, print any of them.

If the solution doesn't exist, print "-1" (without quotes).

Examples
inputCopy
2
aazz
outputCopy
azaz
inputCopy
3
abcabcabz
outputCopy
-1
*/

/* Time Complexity: O(n log n) where n is the length of the string. */
/* Space Complexity: O(1) since we will be storing a max of 26 pairs. */

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

void getKString(string& s, int k) {

    // char -> frequency of char;
    map<char, int> cnt;
    trav(i, s) {
        if (cnt.find(i) == cnt.end())
            cnt[i] = 1;
        else
            cnt[i]++;
    }

    int tempCount;
    for (auto& j : cnt) {
        tempCount = j.second;
        if (tempCount % k != 0) {
            cout << "-1" << nl;
            return;
        }
    }

    sort(all(s));
    FOR(i, k) {
        for(int l = 0; l < (int)s.size(); l += k){
            cout << s[l];
        }
    }

    cout << nl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k;
    string s;
    cin >> k;
    cin >> s;

    getKString(s, k);

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
