/* CF - 900 */
/*
A. Is it rated - 2
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Interaction
This is an interactive problem. You need to read participants' queries from standard input and print your responses to standard output. You don't know the number of queries upfront, so you'll need to process them as you get them; you'll know you're done once you reach the end of the file.

In each query, you will be asked the question, written in one line. You have to answer it correctly, patiently and without any display of emotions. Your response is case-insensitive.

Please make sure to use the stream flushing operation after each response in order not to leave part of your output in some buffer.

Example
inputCopy
Is it rated?
Is it rated?
Is it rated?
outputCopy
NO
NO
NO
*/

/* Time Complexity: O(n) however n is not given before hand */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while (getline(cin, s))
        cout << "NO" << endl;

    return 0;
}
