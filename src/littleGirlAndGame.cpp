/* CF - 1300 */
/*
B. Little Girl and Game
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The Little Girl loves problems on games very much. Here's one of them.

Two players have got a string s, consisting of lowercase English letters. They play a game that is described by the following rules:

The players move in turns; In one move the player can remove an arbitrary letter from string s.
If the player before his turn can reorder the letters in string s so as to get a palindrome, this player wins. A palindrome is a string that reads the same both ways (from left to right, and vice versa). For example, string "abba" is a palindrome and string "abc" isn't.
Determine which player will win, provided that both sides play optimally well — the one who moves first or the one who moves second.

Input
The input contains a single line, containing string s (1 ≤ |s|  ≤  103). String s consists of lowercase English letters.

Output
In a single line print word "First" if the first player wins (provided that both players play optimally well). Otherwise, print word "Second". Print the words without the quotes.

Examples
inputCopy
aba
outputCopy
First
inputCopy
abca
outputCopy
Second
*/

/* Time Complexity: O(n) where n is the length of the string. */
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
typedef vector<int> vi;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';
const double PI = acos(-1);

string solve(string& s) {
    // char -> freq to char
    map<char, int> cnt;
    trav(i, s) {
        if (cnt.find(i) == cnt.end())
            cnt[i] = 1;
        else
            cnt[i]++;
    }

    int oddCount = 0;
    trav(j, cnt) {
        if (j.second % 2 != 0)
            oddCount++;
    }

    if (oddCount == 0 || oddCount == 1)
        return "First";

    if (oddCount % 2 == 0)
        return "Second";

    return "First";

    /* if (n % 2 == 0 && oddCount == 0) */
    /*     return "First"; */

    /* if (n % 2 != 0 && oddCount == 1) */
    /*     return "First"; */

    /* if (n % 2 == 0 && oddCount % 2 == 0) */
    /*     return "Second"; */

    /* if (n % 2 != 0 && oddCount % 2 != 0) */
    /*     return "First"; */

    /* return "NONE"; */
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    cout << solve(s) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
