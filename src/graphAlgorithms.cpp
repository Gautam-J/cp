/* CLRS */
/*
Implementation of different graph algorithms using OOP.
Input is given as an adjacency list.

Sample Input

10 13
0 3 1
0 1 3
3 2 6
1 2 1
2 9 8
2 8 2
1 7 6
7 6 2
1 6 1
1 4 5
6 4 9
4 5 0
4 7 3
1
0
5

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

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
typedef vector<vi> vvi;
typedef vector<pi> vpi;

// mt19937_64 for 64 bit random numbers
mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());

const char nl = '\n';
const double PI = acos(-1);

struct Edge {
    int src, dest, w = 1;
};

class Graph {
private:
    bool directed = false, ranBFS = false, ranDFS = false;
    int nVertices, timeDFS = 0;
    vector<vpi> adjL;

    vector<bool> visitedBFS, visitedDFS;
    vector<int> distBFS, parBFS, discoverDFS, finishDFS, parDFS;

    list<int> topologicalOrder;

    void addEdge(Edge e) {
        this->adjL[e.src].emplace_back(e.dest, e.w);

        if (!this->directed)
            this->adjL[e.dest].emplace_back(e.src, e.w);
    }

    void shortestPathBFSUtil(int s, int d) {
        if (s == d)
            cout << s << " ";
        else if (this->parBFS[d] == imin) {
            cout << "No path from " << s << " to " << d << " exists." << nl;
        } else {
            shortestPathBFSUtil(s, this->parBFS[d]);
            cout << d << " ";
        }
    }

    void DFSVisit(int u) {
        this->timeDFS++;
        this->discoverDFS[u] = this->timeDFS;
        this->visitedDFS[u] = true;

        // to output as soon as the node is visited, but not yet explored
        /* cout << u << " "; */

        int v;
        trav(p, this->adjL[u]) {
            v = p.first;

            if (!visitedDFS[v]) {
                parDFS[v] = u;
                DFSVisit(v);
            }
        }

        this->timeDFS++;
        finishDFS[u] = this->timeDFS;
        this->topologicalOrder.push_front(u);

        cout << u << " ";
    }

public:

    Graph(vector<Edge>& edges, int nv, bool dir = false) {
        this->nVertices = nv;
        this->directed = dir;

        adjL.resize(this->nVertices);
        trav(i, edges)
            this->addEdge(i);
    }

    void displayAdjacencyList() {
        cout << nl << "Adjacency List:" << nl;

        FOR(j, nVertices) {
            cout << j << ":";

            trav(v, this->adjL[j])
                cout << " -> " << v.first << "(" << v.second << ")";

            cout << nl;
        }
    }

    void BFS(int s) {
        cout << nl << "BFS starting from " << s << ":" << nl;
        this->ranBFS = true;

        this->visitedBFS.resize(this->nVertices, false);
        this->distBFS.resize(this->nVertices, imax);
        this->parBFS.resize(this->nVertices, imin);

        this->visitedBFS[s] = true;
        this->distBFS[s] = 0;

        queue<int> q;
        q.push(s);

        int u, v;
        while (!q.empty()) {
            u = q.front(); q.pop();

            trav(p, this->adjL[u]) {
                v = p.first;

                if (!this->visitedBFS[v]) {
                    this->visitedBFS[v] = true;
                    this->distBFS[v] = this->distBFS[u] + 1;
                    this->parBFS[v] = u;
                    q.push(v);
                }
            }
            cout << u << " ";
        }
        cout << nl;
    }

    void shortestPathBFS(int s, int d) {
        if (!this->ranBFS) {
            cout << "\nRun BFS to calculate parents of each vertex." << nl;
        } else {
            cout << "\nShortest path (minimum edges) from " << s << " to " << d << ":" << nl;
            shortestPathBFSUtil(s, d);
            cout << nl;
        }
    }

    void DFS() {
        cout << nl << "DFS:" << nl;
        this->ranDFS = true;

        this->visitedDFS.resize(this->nVertices, false);
        this->parDFS.resize(this->nVertices, imin);
        this->discoverDFS.resize(this->nVertices, 0);
        this->finishDFS.resize(this->nVertices, 0);
        this->timeDFS = 0;

        FOR(u, this->nVertices) {
            if (!visitedDFS[u])
                DFSVisit(u);
        }
        cout << nl;
    }

    void topologicalSort() {
        if (!ranDFS) {
            cout << "\nRun DFS to compute finishing times for each vertex." << nl;
            return;
        }

        cout << nl << "Topological Sort:" << nl;

        trav(i, this->topologicalOrder)
            cout << i << " ";
        cout << nl;
    }

    void kruskal() {};
    void prim() {};
    void bellmanFord() {};
    void dagShortest() {};  // uses topological sorting
    void dijkstra() {};
    void floydWarshall() {};
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int nVertices, nEdges, srcForBFS, shortestPathBFSDest, dir;
    cin >> nVertices >> nEdges;

    vector<Edge> edges(nEdges);
    trav(i, edges) {
        cin >> i.src >> i.dest >> i.w;
    }

    cin >> dir;
    Graph G(edges, nVertices, dir);
    G.displayAdjacencyList();

    cin >> srcForBFS;
    G.BFS(srcForBFS);

    cin >> shortestPathBFSDest;
    G.shortestPathBFS(srcForBFS, shortestPathBFSDest);

    G.DFS();
    G.topologicalSort();

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
