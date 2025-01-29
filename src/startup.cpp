// CF - 800

/*
B. Startup
time limit per test2 seconds
memory limit per test256 megabytes
Arseniy came up with another business plan — to sell soda from a vending machine! For this, he purchased a machine with 𝑛 shelves, as well as 𝑘 bottles, where the 𝑖-th bottle is characterized by the brand index 𝑏𝑖 and the cost 𝑐𝑖.

You can place any number of bottles on each shelf, but all bottles on the same shelf must be of the same brand.

Arseniy knows that all the bottles he puts on the shelves of the machine will be sold. Therefore, he asked you to calculate the maximum amount he can earn.

Input
The first line contains one integer 𝑡 (1≤𝑡≤104) — the number of test cases.

The first line of each test case contains two integers 𝑛 and 𝑘 (1≤𝑛,𝑘≤2⋅105), where 𝑛 is the number of shelves in the machine, and 𝑘 is the number of bottles available to Arseniy.

The next 𝑘 lines contain two integers 𝑏𝑖 and 𝑐𝑖 (1≤𝑏𝑖≤𝑘,1≤𝑐𝑖≤1000) — the brand and cost of the 𝑖-th bottle.

It is also guaranteed that the sum of 𝑛 across all test cases does not exceed 2⋅105 and that the sum of 𝑘 across all test cases also does not exceed 2⋅105.

Output
For each test case, output one integer — the maximum amount that Arseniy can earn.

Example
inputCopy
4
3 3
2 6
2 7
1 15
1 3
2 6
2 7
1 15
6 2
1 7
2 5
190000 1
1 1000
outputCopy
28
15
12
1000
Note
In the first test case, Arseniy has 3 shelves in the vending machine. He can place, for example, two bottles of the brand 2 on the first shelf and a bottle of the brand 1 on the second shelf. Then the total cost of the bottles would be 6+7+15=28.

In the second test case, he has only one shelf. It is not difficult to show that the optimal option is to place a bottle of the brand 1 on it. Then the total cost will be 15.

In the third test case, he has as many as 6 shelves, so he can place all available bottles with a total cost of 7+5=12.
*/

#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

template<typename T> T gcd(T a, T b) { return ( b ? __gcd(a, b) : a); }
template<typename T> T lcm(T a, T b) { return (a * (b / gcd(a, b))); }

#define forn(i, l, r) for (int i = (int)l; i < (int)r; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define trav(i, a) for (auto& i : a)
#define allit(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define shuf(v) shuffle(allit(v), rng)
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

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const char nl = '\n';
// const ll MOD = 1e9+7;
// const ld PI = acos(-1.0);

void solve() {
    // Algorithm:
    // ==========
    // Calculate sum of cost of each bottle per brand.
    // Push total sum per brand into a max heap.
    // Iterate n times from maxheap and keep adding to res.
    //
    // Time: O(k log k)
    // Space: O(k)

    int n, k;
    cin >> n >> k;
    vpi bc(k);
    trav(i, bc) cin >> i.first >> i.second;

    vi bs(k + 1);
    trav(i, bc)
        bs[i.first] += i.second;

    priority_queue<int> q;
    trav(i, bs)
        q.push(i);

    int res = 0;
    while(!q.empty() && n--) {
        res += q.top();
        q.pop();
    }
    cout << res << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--)
        solve();

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
