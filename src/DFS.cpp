/* CLRS */
/*
Depth first search, using recursion and stack, given adjacency list.
*/

/* Time Complexity: O(V + E) (Big theta) */
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

int DFSTime = 0;

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

void topologicalSort(vector<vi>& adj, vi& f) {
    cout << nl << "Topological Sort:" << nl;

    int index = -1;
    trav(k, f) {
        auto it = find(all(f), k);
        if (it != f.end()) {
            index = it - f.begin();
            cout << index << " ";
        }
    }
    cout << nl;
}

void DFSVisit(vector<vi>& adj, int u, vector<bool>& visited, vi& d, vi& f) {
    DFSTime++;
    d[u] = DFSTime;

    visited[u] = true;
    cout << u << " ";

    trav(v, adj[u]) {
        if (!visited[v]) {
            DFSVisit(adj, v, visited, d, f);
        }
    }

    DFSTime++;
    f[u] = DFSTime;
}


void DFS(vector<vi>& adj) {
    cout << nl << "DFS:" << nl;

    int n = sz(adj), u;
    vector<bool> visited(n);
    vector<int> d(n), p(n, -100), f(n);

    DFSTime = 0;
    FOR(u, n) {
        if (!visited[u])
            DFSVisit(adj, u, visited, d, f);
    }

    cout << nl;

    topologicalSort(adj, f);
}

void DFSStack(vector<vi>& adj, int s) {
    // same as BFS, just use a stack instead of a queue.
    // this however traverses from right to left.

    cout << nl << "DFS stack:" << nl;

    int n = sz(adj), u;
    vector<bool> visited(n);
    vector<int> d(n), p(n, -100);
    stack<int> q;

    visited[s] = true;
    q.push(s);
    p[s] = -1;

    while (!q.empty()) {
        u = q.top(); q.pop();

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

    DFS(adj);
    DFSStack(adj, 0);

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
