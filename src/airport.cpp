/* CF - 1100 */
/*
B. Airport
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Lolek and Bolek are about to travel abroad by plane. The local airport has a special "Choose Your Plane" offer. The offer's conditions are as follows:

it is up to a passenger to choose a plane to fly on;
if the chosen plane has x (x > 0) empty seats at the given moment, then the ticket for such a plane costs x zlotys (units of Polish currency).
The only ticket office of the airport already has a queue of n passengers in front of it. Lolek and Bolek have not stood in the queue yet, but they are already wondering what is the maximum and the minimum number of zlotys the airport administration can earn if all n passengers buy tickets according to the conditions of this offer?

The passengers buy tickets in turn, the first person in the queue goes first, then goes the second one, and so on up to n-th person.

Input
The first line contains two integers n and m (1 ≤ n, m ≤ 1000) — the number of passengers in the queue and the number of planes in the airport, correspondingly. The next line contains m integers a1, a2, ..., am (1 ≤ ai ≤ 1000) — ai stands for the number of empty seats in the i-th plane before the ticket office starts selling tickets.

The numbers in the lines are separated by a space. It is guaranteed that there are at least n empty seats in total.

Output
Print two integers — the maximum and the minimum number of zlotys that the airport administration can earn, correspondingly.

Examples
inputCopy
4 3
2 1 1
outputCopy
5 5
inputCopy
4 3
2 2 2
outputCopy
7 6
Note
In the first test sample the number of passengers is equal to the number of empty seats, so regardless of the way the planes are chosen, the administration will earn the same sum.

In the second sample the sum is maximized if the 1-st person in the queue buys a ticket to the 1-st plane, the 2-nd person — to the 2-nd plane, the 3-rd person — to the 3-rd plane, the 4-th person — to the 1-st plane. The sum is minimized if the 1-st person in the queue buys a ticket to the 1-st plane, the 2-nd person — to the 1-st plane, the 3-rd person — to the 2-nd plane, the 4-th person — to the 2-nd plane.
*/

/* Time Complexity: O(nm)*/
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

void MinMax(int n, vi a) {
    int m = a.size();
    sort(all(a));

    int minPrice = 0, num = a[0], k = 0;
    FOR(i, n) {
        minPrice += num;
        num -= 1;
        if (num == 0)
            num = a[++k];
    }

    sort(a.rbegin(), a.rend());

    int maxPrice = 0;
    while (n--) {
        maxPrice += a[0];
        a[0]--;
        for (int i = 1; i < m;  i++) {
            if (a[i] <= a[i - 1])
                break;
            swap(a[i], a[i - 1]);
        }
    }

    cout << maxPrice << " " << minPrice << nl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vi a(m);
    trav(i, a)
        cin >> i;

    MinMax(n, a);

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
