/* CF - 1000 */
/*
A. Chat room
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vasya has recently learned to type and log on to the Internet. He immediately entered a chat room and decided to say hello to everybody. Vasya typed the word s. It is considered that Vasya managed to say hello if several letters can be deleted from the typed word so that it resulted in the word "hello". For example, if Vasya types the word "ahhellllloou", it will be considered that he said hello, and if he types "hlelo", it will be considered that Vasya got misunderstood and he didn't manage to say hello. Determine whether Vasya managed to say hello by the given word s.

Input
The first and only line contains the word s, which Vasya typed. This word consisits of small Latin letters, its length is no less that 1 and no more than 100 letters.

Output
If Vasya managed to say hello, print "YES", otherwise print "NO".

Examples
inputCopy
ahhellllloou
outputCopy
YES
inputCopy
hlelo
outputCopy
NO
*/

/* Time Complexity: O(n) where n is the length of the string */
/* Space Complexity: O(1) */

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

bool isHello(string& s) {

    int startIndex;
    string newS;
    if (s.find('h') != s.npos) {
        startIndex = s.find('h');
        newS = s.substr(startIndex);
    } else {
        return false;
    }

    if (newS.find('e') != newS.npos) {
        startIndex = newS.find('e');
        newS = newS.substr(startIndex);
    } else {
        return false;
    }

    if (newS.find('l') != newS.npos) {
        startIndex = newS.find('l');
        newS = newS.substr(startIndex);
    } else {
        return false;
    }

    int lCount = 0;
    trav(c, newS) {
        if (c == 'l')
            lCount++;
    }

    if (lCount < 2)
        return false;

    if (newS.find('o') != newS.npos) {
        startIndex = newS.find('o');
        newS = newS.substr(startIndex);
    } else {
        return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    cout << (isHello(s) ? "YES" : "NO") << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
