// Flow Network. >> 976F in codeforce
// Mice and owl problem implementation
// https://www.youtube.com/watch?v=ar6x7dHfGHA&list=PLDV1Zeh2NRsDj3NzHbbFIC58etjZhiGcG&index=4

// Bipartite graph. > verticies can be split in to two independent graphs
// - a graph is bipartite if there is no cycle with an odd lenght.
// - in case of *MATCHING* one to another (mice to holes) it is bipartite graph

// label the mice nodes [0.M) and label the hole nodes [M, M+H)
// each edge from mice nodes to hole nodes have 1 capacity (for each mouse)
// then finally connect source node to mice nodes and sink node to hole nodes
// .> now it is max-flow problem from source to sink (with each edge of cap 1)

// to do this we use cuts.
// A cut(S,T) of a flow net G(V,E) is a partition V such that s∈S , t∈T
// flows can't exceed capacity of any cuts.. therefore Min-cut equals Max-flow

// There are various ways to find max flow. most powerful one is Dinic's Algorithm
// > Dinic's Algorithm. polynomial (run time doest depend on Capacity values)
//      uses BFS for leveling graph(shortest edges required to reach the node = level)
//      then use DFS.. to measure the DEPTH we use the level graph (h[v] == h[u] + 1)

struct Flow {
    static constexpr int INF = 1e9;
    int n;
    struct Edge {
        int to, cap;
        Edge(int to, int cap) : to(to), cap(cap) {}
    };
    vector<Edge> e;
    vector<vector<int>> g;
    vector<int> cur, h;
    Flow(int n) : n(n), g(n) {}
    bool bfs(int s, int t) { // source sink
        h.assign(n, -1);
        queue<int> que;
        h[s] = 0; // h[9] = 0
        que.push(s);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int i : g[u]) { //gets edge index from u
                auto [v, c] = e[i];
                if (c > 0 && h[v] == -1) { // from 7 to 3. h[3] already 1 so pass
                    h[v] = h[u] + 1;       // h[1] = h[9] + 1  ( from u to v)
                    if (v == t)            // reached sink
                        return true;
                    que.push(v); // 1 3 5 7 8 (from node 9) ,
                }                // 0 2 (from 3, 5) > 0 to 10 == t > return
            }                    // h[0], h[2] with 2 , h[10] with 3 (h[0] + 1)
        }                        // this h array forms level graph. used in dfs
        return false;
    }
    int dfs(int u, int t, int f) { //ans += dfs(s, t, INF); f is flow here.
        if (u == t)                // reached sink
            return f;
        int r = f;
        for (int &i = cur[u]; i < int(g[u].size()); ++i) {
            int j = g[u][i]; // g[9][0] = 2.. j = edge number //cur.assign(n, 0);
            auto [v, c] = e[j];
            if (c > 0 && h[v] == h[u] + 1) {  // on the next level graph
                int a = dfs(v, t, min(r, c)); // do recursive until reach sink
                // dfs(9,10,INF) > (1,10,3) (3,10,5) (5,10,7) (7,10,9) (8,10,1)
                //           return   0     (0,10,5) (2,10,7)    0         0
                //           return      (10,10,2) 2 (10,10,7) 7
                e[j].cap -= a;     // e[j]=(10, 2-2) > (0, INF-2) > e[j] =(3,5-2)  update this path with flow
                e[j ^ 1].cap += a; // update the residual graph.
                r -= a;            // in (0,10,5) r = 5 - 2(a) and returned f-r (5-3);
                if (r == 0)        // in (3,10,5) r = 5 - 2(5-3) and returned 2(5-3)
                    return f;      // Same way in (5,10,7) returns 7
            }                      // in (9,10,INF) r = INF - 2 - 7 and returned 9(INF - INF + 9);
        }                          // eventually every DFS is done returning 9 as value
        return f - r;              // (1,10,3) return 0;
    }

    void addEdge(int u, int v, int c) { // g[0][0] = 0, g[10][0] = 1. (residual)
        g[u].push_back(e.size());       // g[9][0] = 2 , e[2] = 1,3  // 9 to 1 (cap 3)
        e.emplace_back(v, c);           // for (int i : g[u]) > gets edge index from u
        g[v].push_back(e.size());       // so e.size() for index..
        e.emplace_back(u, 0);
        // e[j ^ 1].cap += a; e[j].cap -= a; this is for this!!
    }
    int maxFlow(int s, int t) {
        int ans = 0;
        while (bfs(s, t)) { // first return with 2 to sink
            cur.assign(n, 0);
            ans += dfs(s, t, INF); // add 9 as return
        }
        return ans;
    }
};
