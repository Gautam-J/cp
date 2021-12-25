/* CLRS, https://cp-algorithms.com/graph/breadth-first-search.html */
/*
Breadth first search, given adjacency list.
*/

/* Time Complexity: O(V + E) */
/* Space Complexity: O(V + E) */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define trav(i, a) for (auto& i : a)

#ifdef _GLIBCXX_DEBUG
#define debug(x) cerr << "\e[91m"<<"[DEBUG] "<<__func__<<":"<<__LINE__<<" [" << #x << "] = [" << x << "]" << "\e[39m" << '\n';
#else
#define debug(x)
#endif

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';
const double PI = acos(-1);

void addEdge(vector<vi>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void displayAdjacencyList(vector<vi>& adj) {
    cout << nl << "Adjacency List:" << nl;

    int v = sz(adj);
    for (int j = 0; j < v; j++) {
        cout << j << ":";
        trav(v, adj[j])
            cout << " -> " << v;
        cout << nl;
    }
}

void shortestPath(int s, int u, vi& p) {
    // As in CLRS

    if (s == u)
        cout << s << " ";
    else if (p[s] == -100)
        cout << "No path" << nl;
    else {
        shortestPath(s, p[u], p);
        cout << u << " ";
    }
}

void shortestPath2(int s, int u, vector<bool>& visited, vi& p) {
    if (!visited[u])
        cout << nl << "No Path!" << nl;
    else {
        vi path;
        for (int v = u; v != -1; v = p[v])
            path.push_back(v);
        reverse(all(path));

        cout << nl << "Shortest path from " << s << " to " << u  << " using iterative algorithm: " << nl;
        trav(v, path)
            cout << v << " ";
        cout << nl;
    }
}

void BFS(vector<vi>& adj, int s) {
    cout << nl << "BFS:" << nl;

    int n = sz(adj), u;
    vector<bool> visited(n);
    vector<int> d(n), p(n, -100);
    queue<int> q;

    visited[s] = true;
    q.push(s);
    p[s] = -1;

    while (!q.empty()) {
        u = q.front(); q.pop();

        trav(v, adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                d[v] = d[u] + 1;
                p[v] = u;
            }
        }
        cout << u << " ";
    }
    cout << nl;

    int dest = 8;
    cout << nl << "Shortest path from " << s << " to " << dest << " using recursive algorithm:" << nl;
    shortestPath(s, dest, p);

    cout << nl;
    shortestPath2(s, dest, visited, p);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int v = 10;  // number of vertices
    vector<vi> adj(v, vi());

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 5);
    addEdge(adj, 2, 6);
    addEdge(adj, 3, 7);
    addEdge(adj, 5, 8);
    addEdge(adj, 5, 9);

    displayAdjacencyList(adj);

    BFS(adj, 0);

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
