/* Practice */
/*
Given an integer n, print the nth fibinacci number.
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...
*/

/* Time Complexity: O(n) */
/* Space Complexity: O(n) */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef vector<int> vi;

ll getFib(ll n) {
    map<ll, ll> hashTable;

    hashTable[1] = 0;
    hashTable[2] = 1;

    for (int i = 3; i <= n; i++)
        hashTable[i] = hashTable[i - 1] + hashTable[i - 2];

    return hashTable.at(n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    cout << getFib(n) << '\n';

    return 0;
}
