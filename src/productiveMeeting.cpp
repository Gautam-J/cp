/* CF - 1400 */
/*
D. Productive Meeting
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
An important meeting is to be held and there are exactly n people invited. At any moment, any two people can step back and talk in private. The same two people can talk several (as many as they want) times per meeting.

Each person has limited sociability. The sociability of the i-th person is a non-negative integer ai. This means that after exactly ai talks this person leaves the meeting (and does not talk to anyone else anymore). If ai=0, the i-th person leaves the meeting immediately after it starts.

A meeting is considered most productive if the maximum possible number of talks took place during it.

You are given an array of sociability a, determine which people should talk to each other so that the total number of talks is as large as possible.

Input
The first line contains an integer t (1≤t≤1000) — the number of test cases.

The next 2t lines contain descriptions of the test cases.

The first line of each test case description contains an integer n (2≤n≤2⋅105) —the number of people in the meeting. The second line consists of n space-separated integers a1,a2,…,an (0≤ai≤2⋅105) — the sociability parameters of all people.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105. It is also guaranteed that the sum of all ai (over all test cases and all i) does not exceed 2⋅105.

Output
Print t answers to all test cases.

On the first line of each answer print the number k — the maximum number of talks possible in a meeting.

On each of the next k lines print two integers i and j (1≤i,j≤n and i≠j) — the numbers of people who will have another talk.

If there are several possible answers, you may print any of them.

Example
inputCopy
8
2
2 3
3
1 2 3
4
1 2 3 4
3
0 0 2
2
6 2
3
0 0 2
5
8 2 0 1 1
5
0 1 0 0 6
outputCopy
2
1 2
1 2
3
1 3
2 3
2 3
5
1 3
2 4
2 4
3 4
3 4
0
2
1 2
1 2
0
4
1 2
1 5
1 4
1 2
1
5 2
*/

/* Time Complexity: O(n log n) */
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
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';
const double PI = acos(-1);

void solve(vi& a) {
    // greedy
    priority_queue<pi> pq;
    int n = sz(a);

    for (int i = 0; i < n; i++) {
        if (a[i] > 0)
            pq.push({a[i], i});
    }

    vector<pi> res;
    int a1, v1, a2, v2;
    while (pq.size() >= 2) {
        a1 = pq.top().first;
        v1 = pq.top().second;
        pq.pop();

        a2 = pq.top().first;
        v2 = pq.top().second;
        pq.pop();

        res.push_back({v1 + 1, v2 + 1});

        if (a1 > 1)
            pq.push({a1 - 1, v1});
        if (a2 > 1)
            pq.push({a2 - 1, v2});
    }

    int k = sz(res);
    cout << k << nl;
    trav(i, res)
        cout << i.first << " " << i.second << nl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vi a(n);
        trav(i, a)
            cin >> i;

        solve(a);
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
