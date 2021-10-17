/* CC - SnackDown 2021 */
/*
Given an array B of length N, find an array A of length N where 0≤Ai≤109 such that array C where Ci=AimodBi, ∀i∈{1,2,...,N} has maximum number of distinct integers.

In case of multiple answers, print any.

Input Format
First-line will contain T, the number of test cases. Then the test cases follow.
Each test case contains two lines of input.
First-line contains a single integer N.
Second-line contains N space-separated integers B1,B2,…,BN.
Output Format
For each test case, output in a single line N space-separated integers A1,A2,…,AN, the elements of the array A such that array C has the maximum number of distinct elements.

If the output array doesn't follow the constraints or the number of distinct elements in the array C is less than the optimal value, you will receive a wrong answer verdict.

Constraints
1≤T≤105
1≤N≤2⋅105
1≤Bi≤N
0≤Ai≤109
Sum of N over all tests is atmost 106.
Sample Input 1
3
3
2 1 3
2
1 1
6
1 2 3 3 2 1
Sample Output 1
3 1 2
2 3
0 1 2 3 4 5
Explanation
Test Case 1: Array C={3mod2,1mod1,2mod3}={1,0,2}. So the number of unique elements are 3.

Test Case 2: Array C={2mod1,3mod1}={0,0}. So the number of unique elements is 1.

Test Case 3: Array C ={0mod1,1mod2,2mod3,3mod3,4mod2,5mod1} ={0,1,2,0,0,0}. So the number of unique elements are 3.

In all the 3 cases, the number of unique elements can't be increased any further for any choice of the array A.
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
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';
const double PI = acos(-1);

bool cmp(pair<ll, ll>& a, pair<ll, ll>& b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, x;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<pair<ll, ll>> a;

        FOR(i, n) {
            cin >> x;
            a.push_back({ x, i });
        }

        sort(all(a));

        ll k = 0;
        FOR(i, n) {
            if (a[i].first > k) {
                a[i].first = k;
                k++;
            } else if (a[i].first == k) {
                a[i].first = k;
            }
        }

        sort(all(a), cmp);

        FOR(i, n) {
            cout << a[i].first << " ";
        }
        cout << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
