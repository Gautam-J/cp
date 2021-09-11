/* CF - 1100 */
/*
A. Rank List
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Another programming contest is over. You got hold of the contest's final results table. The table has the following data. For each team we are shown two numbers: the number of problems and the total penalty time. However, for no team we are shown its final place.

You know the rules of comparing the results of two given teams very well. Let's say that team a solved pa problems with total penalty time ta and team b solved pb problems with total penalty time tb. Team a gets a higher place than team b in the end, if it either solved more problems on the contest, or solved the same number of problems but in less total time. In other words, team a gets a higher place than team b in the final results' table if either pa > pb, or pa = pb and ta < tb.

It is considered that the teams that solve the same number of problems with the same penalty time share all corresponding places. More formally, let's say there is a group of x teams that solved the same number of problems with the same penalty time. Let's also say that y teams performed better than the teams from this group. In this case all teams from the group share places y + 1, y + 2, ..., y + x. The teams that performed worse than the teams from this group, get their places in the results table starting from the y + x + 1-th place.

Your task is to count what number of teams from the given list shared the k-th place.

Input
The first line contains two integers n and k (1 ≤ k ≤ n ≤ 50). Then n lines contain the description of the teams: the i-th line contains two integers pi and ti (1 ≤ pi, ti ≤ 50) — the number of solved problems and the total penalty time of the i-th team, correspondingly. All numbers in the lines are separated by spaces.

Output
In the only line print the sought number of teams that got the k-th place in the final results' table.

Examples
inputCopy
7 2
4 10
4 10
4 10
3 20
2 1
2 1
1 10
outputCopy
3
inputCopy
5 4
3 1
3 1
5 3
3 1
3 1
outputCopy
4
Note
The final results' table for the first sample is:

1-3 places — 4 solved problems, the penalty time equals 10
4 place — 3 solved problems, the penalty time equals 20
5-6 places — 2 solved problems, the penalty time equals 1
7 place — 1 solved problem, the penalty time equals 10
The table shows that the second place is shared by the teams that solved 4 problems with penalty time 10. There are 3 such teams.

The final table for the second sample is:

1 place — 5 solved problems, the penalty time equals 3
2-5 places — 3 solved problems, the penalty time equals 1
The table shows that the fourth place is shared by the teams that solved 3 problems with penalty time 1. There are 4 such teams.
*/

/* Time Complexity: O(n lg n) */
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

bool customCmp(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first)
        return true;

    if (a.first == b.first)
        return (a.second < b.second);

    return false;
}

int solve(vector<pair<int, int>>& a, int k) {
    map<pair<int, int>, int> place;

    trav(i, a) {
        if (place.find(i) == place.end())
            place[i] = 1;
        else
            place[i]++;
    }

    sort(all(a), customCmp);

    return place[a[k - 1]];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> a(n);
    trav(i, a) {
        cin >> i.first >> i.second;
    }

    cout << solve(a, k) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
