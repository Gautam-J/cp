/* CF - 800 */
/*
A. Array with Odd Sum
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array ??
a
 consisting of ??
n
 integers.

In one move, you can choose two indices 1²??,??²??
1
²
i
,
j
²
n
 such that ??­??
i
­
j
 and set ????:=????
a
i
:=
a
j
. You can perform such moves any number of times (possibly, zero). You can choose different indices in different operations. The operation := is the operation of assignment (i.e. you choose ??
i
 and ??
j
 and replace ????
a
i
 with ????
a
j
).

Your task is to say if it is possible to obtain an array with an odd (not divisible by 2
2
) sum of elements.

You have to answer ??
t
 independent test cases.

Input
The first line of the input contains one integer ??
t
 (1²??²2000
1
²
t
²
2000
) Ñ the number of test cases.

The next 2??
2
t
 lines describe test cases. The first line of the test case contains one integer ??
n
 (1²??²2000
1
²
n
²
2000
) Ñ the number of elements in ??
a
. The second line of the test case contains ??
n
 integers ??1,??2,É,????
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
 (1²????²2000
1
²
a
i
²
2000
), where ????
a
i
 is the ??
i
-th element of ??
a
.

It is guaranteed that the sum of ??
n
 over all test cases does not exceed 2000
2000
 (·??²2000
·
n
²
2000
).

Output
For each test case, print the answer on it Ñ "YES" (without quotes) if it is possible to obtain the array with an odd sum of elements, and "NO" otherwise.

Example
inputCopy
5
2
2 3
4
2 2 8 8
3
3 3 3
4
5 5 5 5
4
1 1 1 1
outputCopy
YES
NO
YES
NO
NO
*/

/* Time Complexity: O(n) */
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
/* const ld PI = acos(-1.0); */

bool solve(vi& a) {
    int sum_ = accumulate(all(a), 0);
    if (sum_ % 2 == 1)
        return true;

    // oddCount, evenCount
    bitset<2> cnt;
    trav(i, a) {
        if (i % 2 == 0)
            cnt.set(0);
        else
            cnt.set(1);

        if (cnt[0] && cnt[1])
            break;
    }

    return (cnt[0] && cnt[1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vi a(n);
        trav(i, a)
            cin >> i;

        cout << (solve(a) ? "YES" : "NO") << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
