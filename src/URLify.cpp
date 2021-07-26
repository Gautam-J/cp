/* Method to replace all spaces in a string with '%20' */
/* Assuming the string has enough spaces at the end to hold chars */

/* We make a 2 pass approach. In the first pass, we count number of spaces */
/* In the second pass, we replace space with %20 */

/* Time Complexity: O(N) */
/* Space Complexity: O(N) */

#include <bits/stdc++.h>
using namespace std;

string replaceSpaces(string str, int trueLength) {
    int spaceCount = 0, index, i = 0;

    for (i = 0; i < trueLength; i++) {
        if (str[i] == ' ')
            spaceCount++;
    }

    index = trueLength + spaceCount * 2;
    if (trueLength < str.length())
        str[trueLength] = '\0';

    for(i = trueLength - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[index - 1] = '0';
            str[index - 2] = '2';
            str[index - 3] = '%';
            index -= 3;
        } else {
            str[index - 1] = str[i];
            index--;
        }
    }

    return str;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int trueLength;

    getline(cin, str);
    cin >> trueLength;

    str = replaceSpaces(str, trueLength);
    cout << str << "\n";

    return 0;
}
