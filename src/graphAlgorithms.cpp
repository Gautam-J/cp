/* CLRS */
/*
Implementation of different graph algorithms using OOP.
Input is given as an adjacency list.

Sample Input
DAG that works for all algos implemented here.

7 9
0 1 1
0 2 2
1 3 4
1 4 5
4 6 10
3 6 9
5 4 9
5 6 11
2 5 7
1
0
4

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
typedef pair< int, int > pi;
typedef vector< int > vi;
typedef vector <vi > vvi;
typedef vector< pi > vpi;

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
    vvi adjM;

    vector<bool> visitedBFS, visitedDFS;
    vi distBFS, parBFS, discoverDFS, finishDFS, parDFS, root, distBF, parBF, distDAG, parDAG, distDIJ, parDIJ;
    vector<vvi> distFW;

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

    int parent(int a) {
        while (this->root[a] != a) {
            this->root[a] = this->root[this->root[a]];
            a = this->root[a];
        }
        return a;
    }

    void unionFind(int a, int b) {
        int parA = this->parent(a);
        int parB = this->parent(b);
        this->root[parA] = this->root[parB];
    }

    void initializeSingleSource(vi& dist, vi& par, int s) {
        dist.resize(this->nVertices, imax);
        par.resize(this->nVertices, imin);
        dist[s] = 0;
    }

    void relax(vi& dist, vi& par, int src, int dest, int w) {
        if (dist[src] != imax && dist[dest] > dist[src] + w) {
            dist[dest] = dist[src] + w;
            par[dest] = src;
        }
    }

    bool bellmanFordUtil(vector<Edge>& edges, int s) {
        // returns TRUE if NO negative weight cycle

        initializeSingleSource(this->distBF, this->parBF, s);
        FOR(i, this->nVertices - 1) {
            trav(e, edges) {
                relax(this->distBF, this->parBF, e.src, e.dest, e.w);
            }
        }

        trav(e, edges) {
            if (this->distBF[e.src] != imax && this->distBF[e.dest] > this->distBF[e.src] + e.w)
                return false;
        }
        return true;
    };

    void printPathParent(vi& par, int i) {
        if (par[i] == imin)
            return;
        printPathParent(par, par[i]);
        cout << i << " ";
    }

    void constructAdjacencyMatrix() {
        this->adjM.resize(this->nVertices);
        trav(v, this->adjM)
            v.resize(this->nVertices, imax);

        FOR(i, this->nVertices) {
            FOR(j, this->nVertices) {
                if (i == j)
                    this->adjM[i][j] = 0;
            }
        }

        FOR(u, this->nVertices) {
            trav(e, this->adjL[u]) {
                this->adjM[u][e.first] = e.second;
            }
        }
    }

public:

    Graph(vector<Edge>& edges, int nv, bool dir = false) {
        this->nVertices = nv;
        this->directed = dir;

        adjL.resize(this->nVertices);
        trav(i, edges)
            this->addEdge(i);

        constructAdjacencyMatrix();
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

    void displayAdjacencyMatrix() {
        cout << nl << "Adjacency Matrix:" << nl;

        FOR(i, this->nVertices) {
            FOR(j, this->nVertices) {
                if (this->adjM[i][j] == imax)
                    cout << "F" << "   ";
                else
                    cout << this->adjM[i][j] << "   ";
            }
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
        cout << "Warning! Topological sort can only be done on a directed acyclic graph (DAG)!\n";

        trav(i, this->topologicalOrder)
            cout << i << " ";
        cout << nl;
    }

    void kruskal(vector<Edge>& edges) {
        cout << nl << "Kruskal's Algorithm:" << nl;
        cout << "Warning! Kruskal's algorithm works only for undirected graphs!\n";
        int mstWeight = 0;
        int nEdges = sz(edges);
        int s, d, w;

        this->root.resize(1e6-1);
        iota(all(this->root), 0);

        sort(all(edges), [](Edge a, Edge b) { return a.w < b.w; });

        FOR(i, nEdges) {
            s = edges[i].src; d = edges[i].dest; w = edges[i].w;

            if (this->parent(s) != this->parent(d)) {
                cout << s << " -> " << d << " weight " << w << nl;

                mstWeight += w;
                this->unionFind(s, d);
            }
        }
        cout << "Weight of minimum spanning tree (Kruskal): " << mstWeight << nl;
    };

    void prim(int src) {
        cout << nl << "Prim's Algorithm:" << nl;
        cout << "Warning! Prim's algorithm works only for undirected graphs!\n";

        priority_queue<pi, vpi, greater<pi> > pq;
        int u, v, w, mstWeight = 0;

        vi key(this->nVertices, imax);
        vi parent(this->nVertices, -1);
        vector<bool> inMST(this->nVertices, false);

        pq.push(make_pair(0, src));
        key[src] = 0;

        while (!pq.empty()) {
            u = pq.top().second; pq.pop();

            if (inMST[u])
                continue;

            inMST[u] = true;
            trav(x, this->adjL[u]) {
                v = x.first;
                w = x.second;

                if (inMST[v] == false && key[v] > w) {
                    key[v] = w;
                    pq.push(make_pair(key[v], v));
                    parent[v] = u;
                }
            }
        }

        int tsrc, tdest, weight = 0;
        for (int i = 1; i < this->nVertices; i++) {
            tsrc = parent[i];
            tdest = i;

            trav(e, adjL[tsrc]) {
                if (e.first == tdest) {
                    weight = e.second;
                    break;
                }
            }

            mstWeight += weight;
            cout << tsrc << " -> " << tdest << " weight " << weight << nl;  // << it->second << nl;
        }
        cout << "Weight of minimum spanning tree (Prim): " << mstWeight << nl;
    };

    void bellmanFord(vector<Edge>& edges, int s) {
        cout << nl << "Bellman Ford Algorithm:" << nl;
        cout << "Warning! BellmanFord algorithm works only for directed graphs!\n";
        bool hasNegativeCycle = !bellmanFordUtil(edges, s);

        if (hasNegativeCycle) {
            cout << "Given graph has negative cycle." << nl;
        } else {
            FOR(i, this->nVertices) {
                cout << "Destination: " << i << " Path: " << s << " ";
                printPathParent(this->parBF, i);
                cout << " Minimum Distance: " << this->distBF[i] << nl;
            }
        }
    }

    void dagShortest(int s) {
        cout << nl << "DAG Shortest Path:" << nl;
        cout << "Warning! DAG shortest path algorithm works only for directed acyclic graphs!\n";

        if (!ranDFS) {
            cout << "Run DFS to compute the topological sort order." << nl;
        } else {
            initializeSingleSource(this->distDAG, this->parDAG, s);

            trav(u, this->topologicalOrder) {
                trav(p, this->adjL[u]) {
                    relax(this->distDAG, this->parDAG, u, p.first, p.second);
                }
            }
            FOR(i, nVertices) {
                cout << "Destination: " << i << " Path: " << s << " ";
                printPathParent(this->parDAG, i);
                cout << " Minimum Distance: " << this->distDAG[i] << nl;
            }
        }
    };

    void dijkstra(int s) {
        cout << nl << "Dijkstra's algorithm:" << nl;
        cout << "Warning! Dijkstra's algorithm works only for directed graphs with nonnegative weights!\n";

        int u, v, w;
        priority_queue<pi, vpi, greater<pi> > pq;

        this->distDIJ.resize(this->nVertices, imax);
        this->parDIJ.resize(this->nVertices, imin);

        pq.push(make_pair(0, s));
        this->distDIJ[s] = 0;

        while (!pq.empty()) {
            u = pq.top().second; pq.pop();

            trav(x, this->adjL[u]) {
                v = x.first;
                w = x.second;

                if (this->distDIJ[v] > this->distDIJ[u] + w) {
                    this->distDIJ[v] = this->distDIJ[u] + w;
                    pq.push(make_pair(this->distDIJ[v], v));
                    this->parDIJ[v] = u;
                }
            }
        }

        FOR(i, this->nVertices) {
            cout << "Destination: " << i << " Path: " << s << " ";
            printPathParent(this->parDIJ, i);
            cout << " Minimum Distance: " << this->distDIJ[i] << nl;
        }
    };

    void floydWarshall() {
        cout << nl << "Floyd Warshall Algorithm" << nl;
        cout << "Warning! Floyd Warshall algorithm works only for directed graphs with no negative-weight cycles!\n";

        this->distFW.resize(this->nVertices + 1);
        trav(u, this->distFW) {
            u.resize(this->nVertices);
            trav(v, u) {
                v.resize(this->nVertices, imax);
            }
        }

        this->distFW[0].assign(all(this->adjM));

        for (int k = 1; k <= this->nVertices; k++) {
            FOR(i, this->nVertices) {
                FOR(j, this->nVertices) {

                    if (this->distFW[k - 1][i][j] >
                        (this->distFW[k - 1][i][k - 1] + this->distFW[k - 1][k - 1][j]) &&
                        (this->distFW[k - 1][k - 1][j] != imax) &&
                        (this->distFW[k - 1][i][k - 1] != imax)) {
                        this->distFW[k][i][j] = this->distFW[k - 1][i][k - 1] + this->distFW[k - 1][k - 1][j];
                    } else {
                        this->distFW[k][i][j] = this->distFW[k - 1][i][j];
                    }

                }
            }
        }

        cout << "All pairs Shortest distance" << nl;
        FOR(i, this->nVertices) {
            FOR(j, this->nVertices) {
                if (this->distFW[this->nVertices][i][j] == imax)
                    cout << "F" << "   ";
                else
                    cout << this->distFW[this->nVertices][i][j] << "   ";
            }
            cout << nl;
        }

    };
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int nVertices, nEdges, srcForTraversal, shortestPathBFSDest, dir;
    cin >> nVertices >> nEdges;

    vector<Edge> edges(nEdges);
    trav(i, edges) {
        cin >> i.src >> i.dest >> i.w;
    }

    cin >> dir;
    Graph G(edges, nVertices, dir);
    G.displayAdjacencyList();
    G.displayAdjacencyMatrix();

    cin >> srcForTraversal;
    G.BFS(srcForTraversal);

    cin >> shortestPathBFSDest;
    G.shortestPathBFS(srcForTraversal, shortestPathBFSDest);

    G.DFS();
    G.topologicalSort();

    G.kruskal(edges);
    G.prim(srcForTraversal);

    G.bellmanFord(edges, srcForTraversal);
    G.dagShortest(srcForTraversal);
    G.dijkstra(srcForTraversal);

    G.floydWarshall();

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
