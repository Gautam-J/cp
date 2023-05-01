/* CF - 800 */
/*
A. Maximum Increase
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given array consisting of n integers. Your task is to find the maximum length of an increasing subarray of the given array.

A subarray is the sequence of consecutive elements of the array. Subarray is called increasing if each element of this subarray strictly greater than previous.

Input
The first line contains single positive integer n (1?²?n?²?105) Ñ the number of integers.

The second line contains n positive integers a1,?a2,?...,?an (1?²?ai?²?109).

Output
Print the maximum length of an increasing subarray of the given array.

Examples
inputCopy
5
1 7 2 11 15
outputCopy
3
inputCopy
6
100 100 100 100 100 100
outputCopy
1
inputCopy
3
1 2 3
outputCopy
3
*/

// We can also solve in constant space using a greedy approach.

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

// int solve(vi& a) {
//     int n = sz(a);
//     int dp[n];
//
//     dp[0] = 1;
//     for (int i = 1; i < n; i++) {
//         if (a[i] > a[i - 1]) {
//             dp[i] = dp[i - 1] + 1;
//         } else {
//             dp[i] = 1;
//         }
//     }
//     return *max_element(dp, dp + n);
// }

int solve(vi& a) {
    int n = sz(a);
    int ans = 1, curr = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            curr++;
        } else {
            curr = 1;
        }
        ans = max(ans, curr);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    trav(i, a)
        cin >> i;

    cout << solve(a) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
