// CSES

/*
Time limit: 1.00 s
Memory limit: 512 MB

Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).
Input
The only input line has a string of length n consisting of characters A–Z.
Output
Print a palindrome consisting of the characters of the original string. You may print any valid solution. If there are no solutions, print "NO SOLUTION".
Constraints

1 \le n \le 10^6

Example
Input:
AAAACACBA

Output:
AACABACAA
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
    // Palindrome can be contructed only if frequency of all char is even,
    // except max 1 char, i.e. if total number of frequency is odd.
    //
    // Calculate frequencies of each char.
    // Check if odd, store char along with odd frequency.
    // Divide frequecies of all other char by 2.
    // Construct first half of palindrome using new freq.
    // Add middle char with its frequency.
    // Reverse first half and append at end.
    //
    // Time: O(n)
    // Space: O(1)

    string s;
    cin >> s;

    bitset<26> cnt;
    trav(c, s)
        cnt.flip(c - 'A');

    if (cnt.count() > 1) {
        cout << "NO SOLUTION" << nl;
        return;
    }

    umap<char, int> freq;
    trav(c, s) {
        if (freq.find(c) == freq.end())
            freq[c] = 1;
        else
            freq[c]++;
    }

    char middle_element;
    bool has_odd = false;
    trav(p, freq) {
        if (p.second & 1) {  // alternatively, also check if has_odd = true, then NO SOLUTION
            has_odd = true;
            middle_element = p.first;
            break;
        }
    }

    trav(p, freq) {
        freq[p.first] = p.second / 2;
    }

    // string first_half;
    // trav(p, freq) {
    //     forn(i, 0, p.second)
    //         first_half.pb(p.first);
    // }
    //
    // string second_half = first_half;
    // reverse(allit(second_half));
    //
    // cout << first_half;
    // if (has_odd)
    //     cout << middle_element;
    // cout << second_half << nl;

    string res;
    trav(p, freq) {
        forn(i, 0, p.second)
            res.pb(p.first);
    }

    int first_half_size = sz(res);

    if (has_odd) {
        res.pb(middle_element);
    }

    forn(i, 0, first_half_size) {
        res.pb(res.at(first_half_size - i - 1));
    }

    cout << res << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while(t--)
        solve();

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
