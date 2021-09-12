/* CF - 1300 */
/*
B. Appleman and Card Game
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Appleman has n cards. Each card has an uppercase letter written on it. Toastman must choose k cards from Appleman's cards. Then Appleman should give Toastman some coins depending on the chosen cards. Formally, for each Toastman's card i you should calculate how much Toastman's cards have the letter equal to letter on ith, then sum up all these quantities, such a number of coins Appleman should give to Toastman.

Given the description of Appleman's cards. What is the maximum number of coins Toastman can get?

Input
The first line contains two integers n and k (1 ≤ k ≤ n ≤ 105). The next line contains n uppercase letters without spaces — the i-th letter describes the i-th card of the Appleman.

Output
Print a single integer – the answer to the problem.

Examples
inputCopy
15 10
DZFDFZDFDDDDDDF
outputCopy
82
inputCopy
6 4
YJSNPI
outputCopy
4
Note
In the first test example Toastman can choose nine cards with letter D and one additional card with any letter. For each card with D he will get 9 coins and for the additional card he will get 1 coin.
*/

/* Time Complexity: O(n) */
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

unordered_map<char, ll> cnt;

bool cmp(char a, char b) {
    return (cnt[a] > cnt[b]);
}

ll solve(string& s, ll k) {
    unordered_set<char> seen;
    trav(i, s) {
        if (cnt.find(i) == cnt.end())
            cnt[i] = 1;
        else
            cnt[i]++;

        seen.insert(i);
    }

    string unique;
    trav(i, seen)
        unique.push_back(i);

    sort(all(unique), cmp);

    ll res = 0, count = 0;
    trav(c, unique) {
        if (count >= k)
            break;

        if (count + cnt[c] <= k) {
            count += cnt[c];
            res += (cnt[c] * cnt[c]);
        }
        else if (count + cnt[c] > k) {
            res += ((k - count) * (k - count));
            break;
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    cout << solve(s, k) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
