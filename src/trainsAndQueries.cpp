// CF
/* Time Complexity: O(n + k) */
/* Space Complexity: O(k) */

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Algorithm:
    // For each station, track the index of its first occurence
    // and last occurence using a hash map.
    // Then, for each pair s, d
    //     check if either stations are in the map
    //     if not, NO
    //     else, check if first occurence of s is less than or equal to
    //     the last occurence of d, if so YES, otherwise no
    //
    // Time: O(n + k)
    // Space: O(n)

    int n, k;
    cin >> n >> k;

    map<int, pair<int, int> > m;
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        if (m.find(u) == m.end())
            m[u] = { i, i };
        else
            m[u].second = i;
    }

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        if (m.find(a) == m.end() ||
                m.find(b) == m.end() ||
                m[a].first > m[b].second)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
