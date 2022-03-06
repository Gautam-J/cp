
/*
B. Game of Ball Passing
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Daniel is watching a football team playing a game during their training session. They want to improve their passing skills during that session.

The game involves ??
n
 players, making multiple passes towards each other. Unfortunately, since the balls were moving too fast, after the session Daniel is unable to know how many balls were involved during the game. The only thing he knows is the number of passes delivered by each player during all the session.

Find the minimum possible amount of balls that were involved in the game.

Input
There are several test cases in the input data. The first line contains a single integer ??
t
 (1²??²5?104
1
²
t
²
5
?
10
4
) Ñ the number of test cases. This is followed by the test cases description.

The first line of each test case contains one integer ??
n
 (2²??²105
2
²
n
²
10
5
) Ñ the number of players.

The second line of the test case contains a sequence of integers ??1,??2,É,????
a
1
,
a
2
,
É
,
a
n
 (0²????²109
0
²
a
i
²
10
9
), where ????
a
i
 is the number of passes delivered by the ??
i
-th player.

It is guaranteed that the sum of ??
n
 over all test cases doesn't exceed 105
10
5
.

Output
For each test case print a single integer Ñ the answer to the problem.

Example
inputCopy
4
4
2 3 3 2
3
1 5 2
2
0 0
4
1000000000 1000000000 1000000000 1000000000
outputCopy
1
2
0
1
Note
In the first test case, with the only ball, the game can go like this:

2?1?3?4?1?2?3?4?2?3?2
2
?
1
?
3
?
4
?
1
?
2
?
3
?
4
?
2
?
3
?
2
.

In the second test case, there is no possible way to play the game with only one ball. One possible way to play with two balls:

2?1?2?3?2?1
2
?
1
?
2
?
3
?
2
?
1
.

2?3?2?1
2
?
3
?
2
?
1

In the third example, there were no passes, so 0
0
 balls are possible.
*/

/* Time Complexity: O(n lg n) */
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

ll solve(vector<ll>& a) {
    ll n = sz(a);
    ll sum = 0;
    trav(i, a)
        sum += i;

    sort(allit(a));
    sum -= a[n - 1];
    sum++;

    if (a[n - 1] == 0)
        return 0;

    ll ans = a[n - 1] - sum;
    if (ans >= 0)
        return ans + 1;

    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> a(n);
        trav(i, a)
            cin >> i;

        cout << solve(a) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
