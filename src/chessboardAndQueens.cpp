// CSES

/*
Time limit: 1.00 s Memory limit: 512 MB
Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. However, the reserved squares do not prevent queens from attacking each other.

How many possible ways are there to place the queens?

Input

The input has eight lines, and each of them has eight characters. Each square is either free (.) or reserved (*).

Output

Print one integer: the number of ways you can place the queens.

Example

Input:

........
........
..*.....
........
........
.....**.
...*....
........
Output:

65
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

void backtrack(int r,
               vector<bool>& cols,
               vector<bool>& diag1,
               vector<bool>& diag2,
               const vector<string>& board,
               int& res) {
    if (r == 8) {
        res++;
        return;
    }

    forn(c, 0, 8) {
        if (board[r][c] == '*')
            continue;

        int d1 = r - c + 7;
        int d2 = r + c;
        if (!cols[c] && !diag1[d1] && !diag2[d2]) {
            cols[c] = true;
            diag1[d1] = true;
            diag2[d2] = true;
            backtrack(r + 1, cols, diag1, diag2, board, res);
            cols[c] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }
}

void solve() {
    // Algorithm:
    // ==========
    // Place queens on each possible space and check.
    // Backtrack if not safe.
    //
    // Time and Space complexities are actually constant here since
    // number of queens (8) and board size (8x8) are fixed.
    //
    // Time: O(n!)
    // Space: O(n)

    vector<string> board(8);
    trav(r, board)
        cin >> r;

    vector<bool> cols(8, false);
    vector<bool> diag1(15, false);  // r - c + 7 ranges from 0 to 14
    vector<bool> diag2(15, false);  // r + c ranges from 0 to 14

    int res = 0;
    backtrack(0, cols, diag1, diag2, board, res);
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
