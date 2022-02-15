/* CF - 1000 */
/*
A. Amr and Music
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Amr is a young coder who likes music a lot. He always wanted to learn how to play music but he was busy coding so he got an idea.

Amr has n instruments, it takes ai days to learn i-th instrument. Being busy, Amr dedicated k days to learn how to play the maximum possible number of instruments.

Amr asked for your help to distribute his free days between instruments so that he can achieve his goal.

Input
The first line contains two numbers n, k (1?²?n?²?100, 0?²?k?²?10?000), the number of instruments and number of days respectively.

The second line contains n integers ai (1?²?ai?²?100), representing number of days required to learn the i-th instrument.

Output
In the first line output one integer m representing the maximum number of instruments Amr can learn.

In the second line output m space-separated integers: the indices of instruments to be learnt. You may output indices in any order.

if there are multiple optimal solutions output any. It is not necessary to use all days for studying.

Examples
inputCopy
4 10
4 3 1 2
outputCopy
4
1 2 3 4
inputCopy
5 6
4 3 1 1 2
outputCopy
3
1 3 4
inputCopy
1 3
4
outputCopy
0
Note
In the first test Amr can learn all 4 instruments.

In the second test other possible solutions are: {2,?3,?5} or {3,?4,?5}.

In the third test Amr doesn't have enough time to learn the only presented instrument.
*/

// Similar to time scheduling problem where m events happen
// Max possible number of events that can occur within a specific time

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
#define all(a) a.begin(), a.end()
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
const ld PI = acos(-1.0);

void solve(vpi& a, int k) {
    sort(all(a));

    int n = sz(a);
    vi res;
    forn(i, n) {
        if (a[i].first > k)
            break;

        res.pb(a[i].second);
        k -= a[i].first;
    }

    cout << sz(res) << nl;
    trav(j, res)
        cout << j << " ";
    cout << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vpi a(n);
    forn(i, n) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    solve(a, k);

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
