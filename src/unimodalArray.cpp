/* CF - 1000 */
/*
A. Unimodal Array
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Array of integers is unimodal, if:

it is strictly increasing in the beginning;
after that it is constant;
after that it is strictly decreasing.
The first block (increasing) and the last block (decreasing) may be absent. It is allowed that both of this blocks are absent.

For example, the following three arrays are unimodal: [5,?7,?11,?11,?2,?1], [4,?4,?2], [7], but the following three are not unimodal: [5,?5,?6,?6,?1], [1,?2,?1,?2], [4,?5,?5,?6].

Write a program that checks if an array is unimodal.

Input
The first line contains integer n (1?²?n?²?100) Ñ the number of elements in the array.

The second line contains n integers a1,?a2,?...,?an (1?²?ai?²?1?000) Ñ the elements of the array.

Output
Print "YES" if the given array is unimodal. Otherwise, print "NO".

You can output each letter in any case (upper or lower).

Examples
inputCopy
6
1 5 5 5 4 2
outputCopy
YES
inputCopy
5
10 20 30 20 10
outputCopy
YES
inputCopy
4
1 2 1 2
outputCopy
NO
inputCopy
7
3 3 3 3 3 3 3
outputCopy
YES
Note
In the first example the array is unimodal, because it is strictly increasing in the beginning (from position 1 to position 2, inclusively), that it is constant (from position 2 to position 4, inclusively) and then it is strictly decreasing (from position 4 to position 6, inclusively).
*/

/* Time Complexity: O() */
/* Space Complexity: O() */

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

bool isUnimodal(vi& a) {
    int i = 1;
    int n = sz(a);

    while (i < n && a[i - 1] < a[i])
        i++;
    while (i < n && a[i - 1] == a[i])
        i++;
    while (i < n && a[i - 1] > a[i])
        i++;

    return i == n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);

    trav(i, a)
        cin >> i;

    cout << (isUnimodal(a) ? "YES" : "NO") << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
