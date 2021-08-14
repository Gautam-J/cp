/* CF - 800 */
/*
A. Word Capitalization
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Capitalization is writing a word with its first letter as a capital letter. Your task is to capitalize the given word.

Note, that during capitalization all the letters except the first one remains unchanged.

Input
A single line contains a non-empty word. This word consists of lowercase and uppercase English letters. The length of the word will not exceed 103.

Output
Output the given word after capitalization.

Examples
inputCopy
ApPLe
outputCopy
ApPLe
inputCopy
konjac
outputCopy
Konjac
*/

/* Time Complexity: O(1) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

void capitalize(string& s) {
    if (islower(s[0]))
        s[0] -= 32;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    capitalize(s);

    cout << s << "\n";

    return 0;
}
