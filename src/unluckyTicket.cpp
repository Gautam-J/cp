/* CF - 1100 */
/*
B. Unlucky Ticket
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Each of you probably has your personal experience of riding public transportation and buying tickets. After a person buys a ticket (which traditionally has an even number of digits), he usually checks whether the ticket is lucky. Let us remind you that a ticket is lucky if the sum of digits in its first half matches the sum of digits in its second half.

But of course, not every ticket can be lucky. Far from it! Moreover, sometimes one look at a ticket can be enough to say right away that the ticket is not lucky. So, let's consider the following unluckiness criterion that can definitely determine an unlucky ticket. We'll say that a ticket is definitely unlucky if each digit from the first half corresponds to some digit from the second half so that each digit from the first half is strictly less than the corresponding digit from the second one or each digit from the first half is strictly more than the corresponding digit from the second one. Each digit should be used exactly once in the comparisons. In other words, there is such bijective correspondence between the digits of the first and the second half of the ticket, that either each digit of the first half turns out strictly less than the corresponding digit of the second half or each digit of the first half turns out strictly more than the corresponding digit from the second half.

For example, ticket 2421 meets the following unluckiness criterion and will not be considered lucky (the sought correspondence is 2 > 1 and 4 > 2), ticket 0135 also meets the criterion (the sought correspondence is 0 < 3 and 1 < 5), and ticket 3754 does not meet the criterion.

You have a ticket in your hands, it contains 2n digits. Your task is to check whether it meets the unluckiness criterion.

Input
The first line contains an integer n (1 ≤ n ≤ 100). The second line contains a string that consists of 2n digits and defines your ticket.

Output
In the first line print "YES" if the ticket meets the unluckiness criterion. Otherwise, print "NO" (without the quotes).

Examples
inputCopy
2
2421
outputCopy
YES
inputCopy
2
0135
outputCopy
YES
inputCopy
2
3754
outputCopy
NO
*/

/* Time Complexity: O(n lg n) where n is the length of first half of the string. */
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

bool solve(string& s) {
    string s1;
    string s2;

    int n = sz(s);
    for (int i = 0; i < (n / 2); i++)
        s1.push_back(s[i]);
    for (int j = (n / 2); j < n; j++)
        s2.push_back(s[j]);

    sort(all(s1));
    sort(all(s2));

    if (s1[0] < s2[0]) {
        for (int i = 1; i < (n / 2); i++) {
            if (s1[i] >= s2[i])
                return false;
        }
    } else if (s1[0] > s2[0]) {
        for (int i = 1; i < (n / 2); i++) {
            if (s1[i] <= s2[i])
                return false;
        }
    } else {
        return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    cout << (solve(s) ? "YES" : "NO") << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
