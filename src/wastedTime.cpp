/* CF - 900 */
/*
A. Wasted Time
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Mr. Scrooge, a very busy man, decided to count the time he wastes on all sorts of useless stuff to evaluate the lost profit. He has already counted the time he wastes sleeping and eating. And now Mr. Scrooge wants to count the time he has wasted signing papers.

Mr. Scrooge's signature can be represented as a polyline A1A2... An. Scrooge signs like that: first it places a pen at the point A1, then draws a segment from point A1 to point A2, then he draws a segment from point A2 to point A3 and so on to point An, where he stops signing and takes the pen off the paper. At that the resulting line can intersect with itself and partially repeat itself but Scrooge pays no attention to it and never changes his signing style. As Scrooge makes the signature, he never takes the pen off the paper and his writing speed is constant Ñ 50 millimeters per second.

Scrooge signed exactly k papers throughout his life and all those signatures look the same.

Find the total time Scrooge wasted signing the papers.

Input
The first line contains two integers n and k (2?²?n?²?100, 1?²?k?²?1000). Each of the following n lines contains the coordinates of the polyline's endpoints. The i-th one contains coordinates of the point Ai Ñ integers xi and yi, separated by a space.

All points Ai are different. The absolute value of all coordinates does not exceed 20. The coordinates are measured in millimeters.

Output
Print one real number Ñ the total time Scrooges wastes on signing the papers in seconds. The absolute or relative error should not exceed 10?-?6.

Examples
inputCopy
2 1
0 0
10 0
outputCopy
0.200000000
inputCopy
5 10
3 1
-5 6
-2 -1
3 2
10 0
outputCopy
6.032163204
inputCopy
6 10
5 0
4 0
6 0
3 0
7 0
2 0
outputCopy
3.000000000
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

long double solve(vpi& a, int k) {
    long double distance = 0.0, temp, x1, x2, y1, y2;
    int n = sz(a);

    for (int i = 1; i < n; i++) {
        x1 = a[i - 1].first;
        x2 = a[i].first;
        y1 = a[i - 1].second;
        y2 = a[i].second;
        temp = sqrt(pow((x2 - x1), 2.0L) + pow((y2 - y1), 2.0L));
        distance += temp;
        /* debug(i, temp, distance); */
    }

    // d = s * t
    long double res = (distance * k) / 50.0;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vpi a(n);
    trav(i, a) {
        cin >> i.first >> i.second;
    }

    cout << fixed << setprecision(6) << solve(a, k) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
