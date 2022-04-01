
/*
A. Vasya and Coins
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vasya decided to go to the grocery store. He found in his wallet ??
a
 coins of 1
1
 burle and ??
b
 coins of 2
2
 burles. He does not yet know the total cost of all goods, so help him find out ??
s
 (??>0
s
>
0
): the minimum positive integer amount of money he cannot pay without change or pay at all using only his coins.

For example, if ??=1
a
=
1
 and ??=1
b
=
1
 (he has one 1
1
-burle coin and one 2
2
-burle coin), then:

he can pay 1
1
 burle without change, paying with one 1
1
-burle coin,
he can pay 2
2
 burle without change, paying with one 2
2
-burle coin,
he can pay 3
3
 burle without change by paying with one 1
1
-burle coin and one 2
2
-burle coin,
he cannot pay 4
4
 burle without change (moreover, he cannot pay this amount at all).
So for ??=1
a
=
1
 and ??=1
b
=
1
 the answer is ??=4
s
=
4
.

Input
The first line of the input contains an integer ??
t
 (1²??²104
1
²
t
²
10
4
) Ñ the number of test cases in the test.

The description of each test case consists of one line containing two integers ????
a
i
 and ????
b
i
 (0²????,????²108
0
²
a
i
,
b
i
²
10
8
) Ñ the number of 1
1
-burle coins and 2
2
-burles coins Vasya has respectively.

Output
For each test case, on a separate line print one integer ??
s
 (??>0
s
>
0
): the minimum positive integer amount of money that Vasya cannot pay without change or pay at all.

Example
inputCopy
5
1 1
4 0
0 2
0 0
2314 2374
outputCopy
4
5
1
1
7063
Note
The first test case of the example is clarified into the main part of the statement.
In the second test case, Vasya has only 1
1
 burle coins, and he can collect either any amount from 1
1
 to 4
4
, but 5
5
 can't.
In the second test case, Vasya has only 2
2
 burle coins, and he cannot pay 1
1
 burle without change.
In the fourth test case you don't have any coins, and he can't even pay 1
1
 burle.
*/

/* Time Complexity: O(1) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

template<typename T> T gcd(T a, T b) { return ( b ? __gcd(a, b) : a); }
template<typename T> T lcm(T a, T b) { return (a * (b / gcd(a, b))); }

#define forn(i, n) for (int i = 0; i < n; i++)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; i++)
#define trav(i, a) for (auto& i : a)
#define allit(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
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
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< pi > vpi;

// mt19937_64 for 64 bit random numbers
mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());

const char nl = '\n';
/* const ld PI = acos(-1.0); */

int solve(int a, int b) {
    if (a == 0 && b == 0)
        return 1;

    if (a == 0)
        return 1;

    if (b == 0)
        return a + 1;

    return a + (2*b) + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << solve(a, b) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
