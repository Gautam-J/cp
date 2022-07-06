/* LC - Hard */
/* Time complexity can be reduced to O(n^2) */
/* Time Complexity: O(n!) */
/* Space Complexity: O(n^2) */

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

bool isValid(vector<string>& board, int row, int col) {
    int n = board.size();

    for (int i = row; i >= 0; --i) {
        if (board[i][col] == 'Q')
            return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 'Q')
            return false;
    }

    for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

void dfs(vector<string>& board, vector<vector<string> >& res, int row) {
    int n = board.size();
    if (row == n) {
        res.push_back(board);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isValid(board, row, col)) {
            board[row][col] = 'Q';
            dfs(board, res, row + 1);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    // Algorithm:
    // For every queen, fix row i for queen i
    // For every spot on row, check if a queen can be placed
    // If so, place the queen
    // Recursively go for the next queen
    // If any queen fails, remove the previous queen
    // If all the queens succeed, append board to res
    // Return res
    //
    // Time: O(n!)
    // Space: O(n^2)

    vector<vector<string> > res;

    if (n == 0)
        return res;

    vector<string> board(n, string(n, '.'));
    dfs(board, res, 0);

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<string> > res = solveNQueens(n);

    cout << "Number of solutions: " << res.size() << nl;
    int k = 1;
    trav(i, res) {
        cout << "Solution: " << k++ << nl;
        trav(j, i)
            cout << j << nl;
        cout << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
