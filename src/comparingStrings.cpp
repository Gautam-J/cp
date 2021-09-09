/* CF - 1100 */
/*
A. Comparing Strings
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Some dwarves that are finishing the StUDY (State University for Dwarven Youngsters) Bachelor courses, have been told "no genome, no degree". That means that all dwarves should write a thesis on genome. Dwarven genome is far from simple. It is represented by a string that consists of lowercase Latin letters.

Dwarf Misha has already chosen the subject for his thesis: determining by two dwarven genomes, whether they belong to the same race. Two dwarves belong to the same race if we can swap two characters in the first dwarf's genome and get the second dwarf's genome as a result. Help Dwarf Misha and find out whether two gnomes belong to the same race or not.

Input
The first line contains the first dwarf's genome: a non-empty string, consisting of lowercase Latin letters.

The second line contains the second dwarf's genome: a non-empty string, consisting of lowercase Latin letters.

The number of letters in each genome doesn't exceed 105. It is guaranteed that the strings that correspond to the genomes are different. The given genomes may have different length.

Output
Print "YES", if the dwarves belong to the same race. Otherwise, print "NO".

Examples
inputCopy
ab
ba
outputCopy
YES
inputCopy
aa
ab
outputCopy
NO
Note
First example: you can simply swap two letters in string "ab". So we get "ba".
Second example: we can't change string "aa" into string "ab", because "aa" does not contain letter "b".
*/

/* Time Complexity: O(n) where n is the length of the string. */
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
    int n = sz(s1);
    int m = sz(s2);

    if (n != m)
        return false;

    map<char, int> cnts1;
    map<char, int> cnts2;

    trav(i, s1) {
        if (cnts1.find(i) == cnts1.end())
            cnts1[i] = 1;
        else
            cnts1[i]++;
    }

    trav(i, s2) {
        if (cnts2.find(i) == cnts2.end())
            cnts2[i] = 1;
        else
            cnts2[i]++;
    }

    trav(i, cnts1) {
        if (i.second != cnts2[i.first])
            return false;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i])
            cnt++;
    }

    return (cnt == 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    cout << (solve(s1, s2) ? "YES" : "NO") << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
