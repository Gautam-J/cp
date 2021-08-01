/* CF - 800 */
/*
A. Petya and Strings
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Little Petya loves presents. His mum bought him two strings of the same size for his birthday. The strings consist of uppercase and lowercase Latin letters. Now Petya wants to compare those two strings lexicographically. The letters' case does not matter, that is an uppercase letter is considered equivalent to the corresponding lowercase letter. Help Petya perform the comparison.

Input
Each of the first two lines contains a bought string. The strings' lengths range from 1 to 100 inclusive. It is guaranteed that the strings are of the same length and also consist of uppercase and lowercase Latin letters.

Output
If the first string is less than the second one, print "-1". If the second string is less than the first one, print "1". If the strings are equal, print "0". Note that the letters' case is not taken into consideration when the strings are compared.

Examples
inputCopy
aaaa
aaaA
outputCopy
0
inputCopy
abs
Abz
outputCopy
-1
inputCopy
abcdefg
AbCdEfF
outputCopy
1
*/

/* Time Complexity: O(N) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

int checkLexo(string& s1, string& s2) {
    int c1, c2;

    for (int i = 0; i < s1.length(); i++) {
       c1 = s1[i];
       c2 = s2[i];

       if (isupper(c1))
           c1 += 32;

       if (isupper(c2))
           c2 += 32;

       if (c1 > c2)
           return 1;
       if (c1 < c2)
           return -1;
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    int output = checkLexo(s1, s2);

    cout << output << "\n";

    return 0;
}
