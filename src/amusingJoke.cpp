/* CF - 800 */
/*
A. Amusing Joke
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
So, the New Year holidays are over. Santa Claus and his colleagues can take a rest and have guests at last. When two "New Year and Christmas Men" meet, thear assistants cut out of cardboard the letters from the guest's name and the host's name in honor of this event. Then the hung the letters above the main entrance. One night, when everyone went to bed, someone took all the letters of our characters' names. Then he may have shuffled the letters and put them in one pile in front of the door.

The next morning it was impossible to find the culprit who had made the disorder. But everybody wondered whether it is possible to restore the names of the host and his guests from the letters lying at the door? That is, we need to verify that there are no extra letters, and that nobody will need to cut more letters.

Help the "New Year and Christmas Men" and their friends to cope with this problem. You are given both inscriptions that hung over the front door the previous night, and a pile of letters that were found at the front door next morning.

Input
The input file consists of three lines: the first line contains the guest's name, the second line contains the name of the residence host and the third line contains letters in a pile that were found at the door in the morning. All lines are not empty and contain only uppercase Latin letters. The length of each line does not exceed 100.

Output
Print "YES" without the quotes, if the letters in the pile could be permuted to make the names of the "New Year and Christmas Men". Otherwise, print "NO" without the quotes.

Examples
inputCopy
SANTACLAUS
DEDMOROZ
SANTAMOROZDEDCLAUS
outputCopy
YES
inputCopy
PAPAINOEL
JOULUPUKKI
JOULNAPAOILELUPUKKI
outputCopy
NO
inputCopy
BABBONATALE
FATHERCHRISTMAS
BABCHRISTMASBONATALLEFATHER
outputCopy
NO
Note
In the first sample the letters written in the last line can be used to write the names and there won't be any extra letters left.

In the second sample letter "P" is missing from the pile and there's an extra letter "L".

In the third sample there's an extra letter "L".
*/

/* Time Complexity: O(n) where n is the length of the strings */
/* Space Complexity: O(1) because there are only 26 chars */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define trav(i, a) for (auto& i : a)

typedef long long ll;
typedef vector<int> vi;

const char nl = '\n';

bool isValid(string& s1, string& s2, string& s3) {
    if (s3.size() != (s1.size() + s2.size()))
        return false;

    map<char, int> hash;
    trav(c, s1) {
        if (hash.find(c) == hash.end())
            hash[c] = 1;
        else
            hash[c]++;
    }

    trav(c, s2) {
        if (hash.find(c) == hash.end())
            hash[c] = 1;
        else
            hash[c]++;
    }

    map<char, int> pile;
    trav(c, s3) {
        if (pile.find(c) == pile.end())
            pile[c] = 1;
        else
            pile[c]++;
    }

    char k;
    int v;
    trav(c, pile) {
        k = c.first;
        v = c.second;

        if (hash[k] != v)
            return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    cout << (isValid(s1, s2, s3) ? "YES" : "NO") << nl;

    return 0;
}
