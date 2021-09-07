/* CF - 1300 */
/*
B. Jeff and Periods
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
One day Jeff got hold of an integer sequence a1, a2, ..., an of length n. The boy immediately decided to analyze the sequence. For that, he needs to find all values of x, for which these conditions hold:

x occurs in sequence a.
Consider all positions of numbers x in the sequence a (such i, that ai = x). These numbers, sorted in the increasing order, must form an arithmetic progression.
Help Jeff, find all x that meet the problem conditions.

Input
The first line contains integer n (1 ≤ n ≤ 105). The next line contains integers a1, a2, ..., an (1 ≤ ai ≤ 105). The numbers are separated by spaces.

Output
In the first line print integer t — the number of valid x. On each of the next t lines print two integers x and px, where x is current suitable value, px is the common difference between numbers in the progression (if x occurs exactly once in the sequence, px must equal 0). Print the pairs in the order of increasing x.

Examples
inputCopy
1
2
outputCopy
1
2 0
inputCopy
8
1 2 1 3 1 2 1 5
outputCopy
4
1 2
2 4
3 0
5 0
Note
In the first test 2 occurs exactly once in the sequence, ergo p2 = 0.
*/

/* Time Complexity: O(n^2) */
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

pair<bool, int> progression(vi& a) {
    pair<bool, int> res = {true, a[1] - a[0]};

    int n = sz(a);

    for (int i = 1; i < n - 1; i++) {
        if (a[i + 1] - a[i] != res.second) {
            res.first = false;
            break;
        }
    }

    return res;
}

void solve(vi& a) {
    // n > indices where n occurs
    map<int, vi> cnt;

    int n = sz(a);
    FOR(i, n) {
        if (cnt.find(a[i]) == cnt.end())
            cnt[a[i]] = vi {i};
        else
            cnt[a[i]].push_back(i);
    }

    // result list of { x, AP difference }
    vector<pair<int, int>> res;

    pair<bool, int> temp;
    trav(k, cnt) {
        if (sz(k.second) == 1)
            res.push_back({k.first, 0});
        else {
            temp = progression(k.second);
            if (temp.first)
                res.push_back({k.first, temp.second});
        }
    }

    cout << sz(res) << nl;
    trav(r, res)
        cout << r.first << " " << r.second << nl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vi a(n);
    trav(i, a)
        cin >> i;

    solve(a);

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
