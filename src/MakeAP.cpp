/* CF - 900 */
/*
B. Make AP
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp has 3 positive integers a, b and c. He can perform the following operation exactly once.

Choose a positive integer m and multiply exactly one of the integers a, b or c by m.
Can Polycarp make it so that after performing the operation, the sequence of three numbers a, b, c (in this order) forms an arithmetic progression? Note that you cannot change the order of a, b and c.

Formally, a sequence x1,x2,…,xn is called an arithmetic progression (AP) if there exists a number d (called "common difference") such that xi+1=xi+d for all i from 1 to n−1. In this problem, n=3.

For example, the following sequences are AP: [5,10,15], [3,2,1], [1,1,1], and [13,10,7]. The following sequences are not AP: [1,2,4], [0,1,0] and [1,3,2].

You need to answer t independent test cases.

Input
The first line contains the number t (1≤t≤104) — the number of test cases.

Each of the following t lines contains 3 integers a, b, c (1≤a,b,c≤108).

Output
For each test case print "YES" (without quotes) if Polycarp can choose a positive integer m and multiply exactly one of the integers a, b or c by m to make [a,b,c] be an arithmetic progression. Print "NO" (without quotes) otherwise.

You can print YES and NO in any (upper or lower) case (for example, the strings yEs, yes, Yes and YES will be recognized as a positive answer).

Example
inputCopy
11
10 5 30
30 5 10
1 2 3
1 6 3
2 6 3
1 1 1
1 1 2
1 1 3
1 100000000 1
2 1 1
1 2 2
outputCopy
YES
YES
YES
YES
NO
YES
NO
YES
YES
NO
YES
Note
In the first and second test cases, you can choose the number m=4 and multiply the second number (b=5) by 4.

In the first test case the resulting sequence will be [10,20,30]. This is an AP with a difference d=10.

In the second test case the resulting sequence will be [30,20,10]. This is an AP with a difference d=−10.

In the third test case, you can choose m=1 and multiply any number by 1. The resulting sequence will be [1,2,3]. This is an AP with a difference d=1.

In the fourth test case, you can choose m=9 and multiply the first number (a=1) by 9. The resulting sequence will be [9,6,3]. This is an AP with a difference d=−3.

In the fifth test case, it is impossible to make an AP.


*/

/* Time Complexity: O(1) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

void dbg_out() { cerr << endl; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

template<typename T> T gcd(T a, T b) { return ( b ? __gcd(a, b) : a); }
template<typename T> T lcm(T a, T b) { return (a * (b / gcd(a, b))); }

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define trav(i, a) for (auto& i : a)
#define pb push_back
#define SHUF(v) shuffle(all(v), mt_rand)
#define umap unordered_map
#define uset unordered_set
#define imax INT_MAX
#define imin INT_MIN

#ifdef _GLIBCXX_DEBUG
#define debug(...) cerr << "[DEBUG]: [" << #__VA_ARGS__ << "]:", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< pi > vpi;

// mt19937_64 for 64 bit random numbers
mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());

const char nl = '\n';
const double PI = acos(-1);

bool solve(int a, int b, int c) {

    int na = (2 * b) - c;
    if (na >= a && na % a == 0 && na != 0)
        return true;

    int nb = (a + c) / 2;
    if (nb >= b && (a + c) % 2 == 0 && nb % b == 0 && nb != 0)
        return true;

    int nc = (2 * b) - a;
    if (nc >= c && nc % c == 0 && nc != 0)
        return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, a, b, c;
    cin >> t;

    while (t--) {
        cin >> a >> b >> c;
        cout << (solve(a, b, c) ? "YES" : "NO") << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
