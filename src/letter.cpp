/* CF - 1100 */
/*
B. Letter
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vasya decided to write an anonymous letter cutting the letters out of a newspaper heading. He knows heading s1 and text s2 that he wants to send. Vasya can use every single heading letter no more than once. Vasya doesn't have to cut the spaces out of the heading — he just leaves some blank space to mark them. Help him; find out if he will manage to compose the needed text.

Input
The first line contains a newspaper heading s1. The second line contains the letter text s2. s1 и s2 are non-empty lines consisting of spaces, uppercase and lowercase Latin letters, whose lengths do not exceed 200 symbols. The uppercase and lowercase letters should be differentiated. Vasya does not cut spaces out of the heading.

Output
If Vasya can write the given anonymous letter, print YES, otherwise print NO

Examples
inputCopy
Instead of dogging Your footsteps it disappears but you dont notice anything
where is your dog
outputCopy
NO
inputCopy
Instead of dogging Your footsteps it disappears but you dont notice anything
Your dog is upstears
outputCopy
YES
inputCopy
Instead of dogging your footsteps it disappears but you dont notice anything
Your dog is upstears
outputCopy
NO
inputCopy
abcdefg hijk
k j i h g f e d c b a
outputCopy
YES
*/

/* Time Complexity: O(n + m) where n is the length of s1 and m is the length of s2. */
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

bool solve(string& s1, string& s2) {
    map<char, int> s1cnt;
    map<char, int> s2cnt;

    trav(i, s1) {
        if (i == ' ')
            continue;

        if (s1cnt.find(i) == s1cnt.end())
            s1cnt[i] = 1;
        else
            s1cnt[i]++;
    }

    trav(i, s2) {
        if (i == ' ')
            continue;

        if (s2cnt.find(i) == s2cnt.end())
            s2cnt[i] = 1;
        else
            s2cnt[i]++;
    }

    trav(j, s2cnt) {
        if (j.second > s1cnt[j.first])
            return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    cout << (solve(s1, s2) ? "YES" : "NO") << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
