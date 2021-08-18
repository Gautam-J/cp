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

ll getFib(ll n, map<ll, ll>& hashTable) {

    if (hashTable.find(n) != hashTable.end())
        return hashTable.at(n);

    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    hashTable[n] = getFib(n - 1, hashTable) + getFib(n - 2, hashTable);

    return hashTable.at(n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    map<ll, ll> hashTable;
    cout << getFib(n, hashTable) << '\n';

    return 0;
}
