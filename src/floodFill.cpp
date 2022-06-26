/* LC - Easy, grind 9 */
/*
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.



Example 1:


Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation: The starting pixel is already colored 0, so no changes are made to the image.


Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n
*/

/* Time Complexity: O(nm) */
/* Space Complexity: O(nm) */

#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

template<typename T> T gcd(T a, T b) { return ( b ? __gcd(a, b) : a); }
template<typename T> T lcm(T a, T b) { return (a * (b / gcd(a, b))); }

#define forn(i, n) for (int i = 0; i < n; ++i)
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

void dfs(vvi& image, int sr, int sc, int m, int n, int color, int startColor) {
    if (image[sr][sc] != startColor)
        return;

    image[sr][sc] = color;

    if (sr - 1 >= 0)
        dfs(image, sr - 1, sc, m, n, color, startColor);
    if (sr + 1 < m)
        dfs(image, sr + 1, sc, m, n, color, startColor);
    if (sc - 1 >= 0)
        dfs(image, sr, sc - 1, m, n, color, startColor);
    if (sc + 1 < n)
        dfs(image, sr, sc + 1, m, n, color, startColor);
}

vvi solve(vvi& image, int sr, int sc, int color) {
    // Algorithm:
    // DFS
    // Check if new color already painted in image[sr][sc]
    // If not, start a DFS with image[sr][sc]
    // Update color of node
    // If neighbor in up,down,left,right has same color as image[sr][sc],
    // call dfs on the neighbor recursively
    //
    // Time: O(nm)
    // Space: O(nm)

    int m = sz(image);
    int n = sz(image[0]);

    if (image[sr][sc] != color)
        dfs(image, sr, sc, m, n, color, image[sr][sc]);

    return image;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vvi image(m, vi(n));
    trav(i, image) {
        trav(j, i)
            cin >> j;
    }

    int sr, sc, color;
    cin >> sr >> sc >> color;

   vvi res =  solve(image, sr, sc, color);
   trav(i, res) {
       trav(j, i)
           cout << j << " ";
       cout << nl;
   }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
