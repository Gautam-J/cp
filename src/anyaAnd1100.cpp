// CF - 1100

/*
C. Anya and 1100
time limit per test3 seconds
memory limit per test256 megabytes
While rummaging through things in a distant drawer, Anya found a beautiful string 𝑠 consisting only of zeros and ones.

Now she wants to make it even more beautiful by performing 𝑞 operations on it.

Each operation is described by two integers 𝑖 (1≤𝑖≤|𝑠|) and 𝑣 (𝑣∈{0,1}) and means that the 𝑖-th character of the string is assigned the value 𝑣 (that is, the assignment 𝑠𝑖=𝑣 is performed).

But Anya loves the number 1100, so after each query, she asks you to tell her whether the substring "1100" is present in her string (i.e. there exist such 1≤𝑖≤|𝑠|−3 that 𝑠𝑖𝑠𝑖+1𝑠𝑖+2𝑠𝑖+3=𝟷𝟷𝟶𝟶).

Input
The first line contains one integer 𝑡 (1≤𝑡≤104) — the number of test cases.

The first line of the test case contains the string 𝑠 (1≤|𝑠|≤2⋅105), consisting only of the characters "0" and "1". Here |𝑠| denotes the length of the string 𝑠.

The next line contains an integer 𝑞 (1≤𝑞≤2⋅105) — the number of queries.

The following 𝑞 lines contain two integers 𝑖 (1≤𝑖≤|𝑠|) and 𝑣 (𝑣∈{0,1}), describing the query.

It is guaranteed that the sum of |𝑠| across all test cases does not exceed 2⋅105. It is also guaranteed that the sum of 𝑞 across all test cases does not exceed 2⋅105.

Output
For each query, output "YES", if "1100" is present in Anya's string; otherwise, output "NO".

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
inputCopy
4
100
4
1 1
2 0
2 0
3 1
1100000
3
6 1
7 1
4 1
111010
4
1 1
5 0
4 1
5 0
0100
4
3 1
1 1
2 0
2 1
outputCopy
NO
NO
NO
NO
YES
YES
NO
NO
YES
YES
YES
NO
NO
NO
NO
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

void solve1() {
    // Algorithm:
    // ==========
    // Brute force search will not work.
    // Instead of checking if substr occurs in the entire string, check only
    // fraction of the string.
    //
    // Time: O(q)
    // Space: O(n) where n is the length of the string

    string s;
    cin >> s;
    int q;
    cin >> q;

    uset<int> occ;

    int n = s.size();
    forn(i, 0, n - 3) {
        if (s[i] == '1' && s[i+1] == '1' && s[i+2] == '0' && s[i+3] == '0')
            occ.insert(i);
    }

    int i, pos, s_min, s_max;
    char v;
    forn(r, 0, q) {
        cin >> i >> v;

        pos = i - 1;
        s[pos] = v;

        s_min = max(0, pos - 3);
        s_max = min(pos, n - 4);

        fore(j, s_min, s_max) {
            if (s[j] == '1' && s[j+1] == '1' && s[j+2] == '0' && s[j+3] == '0')
                occ.insert(j);
            else
                occ.erase(j);
        }
        cout << (occ.empty() ? "NO" : "YES") << '\n';
    }
}

bool check_1100(ll i, string& buf) {
    if (i < 0) return false;
    if (i >= sz(buf) - 3) return false;
    return buf[i] == '1' && buf[i + 1] == '1' && buf[i + 2] == '0' && buf[i + 3] == '0';
}

void solve() {
    // Algorithm:
    // ==========
    // Brute force search will not work.
    // Instead of checking if substr occurs in the entire string, check only
    // fraction of the string.
    //
    // More optimized for space.
    //
    // Time: O(n + q) where n is the length of the string
    // Space: O(1)

    string s;
    cin >> s;
    int q;
    cin >> q;

    ll count = 0;
    ll n = sz(s);
    forn(i, 0, n)
        if (check_1100(i, s)) count++;

    int i, v;
    bool before, after;
    while (q--) {
        cin >> i >> v;
        i--;  // 0 index
        if (s[i] != '0' + v) {
            before = check_1100(i-3, s) || check_1100(i-2, s) || check_1100(i-1, s) || check_1100(i, s);
		    s[i] = '0' + v;
		    after = check_1100(i-3, s) || check_1100(i-2, s) || check_1100(i-1, s) || check_1100(i, s);
		    count += after - before;
        }
        cout << (count ? "YES" : "NO") << nl;
    }
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
