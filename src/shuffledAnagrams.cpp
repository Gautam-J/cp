/* KickStart - 2021 E */
/*
Let S be a string containing only letters of the English alphabet. An anagram of S is any string that contains exactly the same letters as S (with the same number of occurrences for each letter), but in a different order. For example, the word kick has anagrams such as kcik and ckki.

Now, let S[i] be the i-th letter in S. We say that an anagram of S, A, is shuffled if and only if for all i, S[i]≠A[i]. So, for instance, kcik is not a shuffled anagram of kick as the first and fourth letters of both of them are the same. However, ckki would be considered a shuffled anagram of kick, as would ikkc.

Given an arbitrary string S, your task is to output any one shuffled anagram of S, or else print IMPOSSIBLE if this cannot be done.

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of one line, a string of English letters.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is a shuffled anagram of the string for that test case, or IMPOSSIBLE if no shuffled anagram exists for that string.

Limits
Memory limit: 1 GB.
1≤T≤100.
All input letters are lowercase English letters.

Test Set 1
Time limit: 20 seconds.
1≤ the length of S ≤8.

Test Set 2
Time limit: 40 seconds.
1≤ the length of S ≤104.

Sample
Sample Input
save_alt
content_copy
2
start
jjj
Sample Output
save_alt
content_copy
Case #1: tarts
Case #2: IMPOSSIBLE
In test case #1, tarts is a shuffled anagram of start as none of the letters in each position of both strings match the other. Another possible solution is trsta (though you only need to provide one solution). However, in test case #2, there is no way of anagramming jjj to form a shuffled anagram, so IMPOSSIBLE is printed instead.
*/

/* Time Complexity: O(n) where n is the length of the given string. */
/* Space Complexity: O(1) */

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define trav(i, a) for (auto& i : a)

#ifdef _GLIBCXX_DEBUG
#define debug(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; cerr << x; cerr << "\e[39m" << '\n';
#else
#define debug(x...)
#endif

typedef long long ll;
typedef vector<int> vi;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';

string getAnag(string& s) {
    int cnt[26];
    FOR(i, 26)
        cnt[i] = 0;
    trav(a, s)
        cnt[a - 'a']++;

    vector<pair<int, int>> ord;
    FOR(i, 26) {
        if (cnt[i] * 2 > sz(s))
            return "IMPOSSIBLE";

        ord.push_back({cnt[i], i});
    }

    sort(all(ord));
    reverse(all(ord));

    string res;
    FOR(i, sz(s))
        res += ' ';

    int p;
    FOR(i, 26) {
        FOR(j, sz(s)) {
            if (s[j] - 'a' != ord[i].second)
                continue;

            FOR(k, 26) {
                p = ord[(i + 1 + k) % 26].second;
                if (cnt[p]) {
                    cnt[p]--;
                    res[j] = 'a' + p;
                    break;
                }
            }
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    string s;
    FOR(t, T) {
        cin >> s;
        cout << "Case #" << t + 1 << ": " << getAnag(s) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
