/* CF - 800 */
/*
A. Translation
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The translation from the Berland language into the Birland language is not an easy task. Those languages are very similar: a berlandish word differs from a birlandish word with the same meaning a little: it is spelled (and pronounced) reversely. For example, a Berlandish word code corresponds to a Birlandish word edoc. However, it's easy to make a mistake during the «translation». Vasya translated word s from Berlandish into Birlandish as t. Help him: find out if he translated the word correctly.

Input
The first line contains word s, the second line contains word t. The words consist of lowercase Latin letters. The input data do not consist unnecessary spaces. The words are not empty and their lengths do not exceed 100 symbols.

Output
If the word t is a word s, written reversely, print YES, otherwise print NO.

Examples
inputCopy
code
edoc
outputCopy
YES
inputCopy
abb
aba
outputCopy
NO
inputCopy
code
code
outputCopy
NO
*/

/* Time Complexity: O(n) where n is the length of the string */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

void checkTranslation(string& str1, string& str2) {
    bool isReverse = true;
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] != str2[str2.size() - 1 - i])
            isReverse = false;
    }

    if (isReverse)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str1, str2;
    cin >> str1 >> str2;

    checkTranslation(str1, str2);

    return 0;
}
