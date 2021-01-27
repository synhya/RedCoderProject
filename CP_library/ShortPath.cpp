#include <bits/stdc++.h>
using namespace std;
/************ USE THIS ***************************/
// vi &d is the distance of each nodes from source node //
void dijkstra(vector<vector<pi>> g, vi &d, int n, int s) {
    vector<bool> vis(n, false);
    d = vi(n, inf);
    d[s] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({s, 0}); // node distance
    while (!pq.empty()) {
        int v = pq.top().first;
        int minValue = -pq.top().second;
        pq.pop();
        vis[v] = true;
        if (d[v] < minValue)
            continue;
        for (auto [to, w] : g[v]) {
            if (vis[to])
                continue;
            int newDist = d[v] + w;
            if (newDist < d[to]) {
                d[to] = newDist;
                pq.push({to, -newDist});
            }
        }
    }
}
/*****************************************************/
// struct version FROM neal.
const int64_t INF64 = int64_t(2e18) + 5;

struct Dijkstra {
    struct edge {
        int node = -1;
        int64_t weight = 0;

        edge() {}
        edge(int _node, int64_t _weight) : node(_node), weight(_weight) {}
    };
    struct state {
        int64_t dist;
        int node;

        state() {}
        state(int64_t _dist, int _node) : dist(_dist), node(_node) {}

        bool operator<(const state &other) const {
            return dist > other.dist; // pq에 활용...!!!!!
        }
    };
    int n;
    vector<vector<edge>> adj;
    vector<int64_t> dist;
    vector<int> parent;

    Dijkstra(int _n = 0) {
        init(_n);
    }
    void init(int _n) {
        n = _n;
        adj.assign(n, {});
    }
    void add_directional_edge(int a, int b, int64_t weight) {
        adj[a].emplace_back(b, weight);
    }

    void add_bidirectional_edge(int a, int b, int64_t weight) {
        add_directional_edge(a, b, weight);
        add_directional_edge(b, a, weight);
    }
    void dijkstra_check(priority_queue<state> &pq, int node, int from, int64_t new_dist) {
        if (new_dist < dist[node]) {
            dist[node] = new_dist;
            parent[node] = from;
            pq.emplace(new_dist, node); //state로 미리 큰거부터정렬됨.!!
        }
    }
    void dijkstra(const vector<int> &source) {
        if (n == 0)
            return;
        dist.assign(n, INF64);
        parent.assign(n, -1); // better than visited vector it can check the route.
        priority_queue<state> pq;

        for (int src : source) // this is starting node (source to sink)
            dijkstra_check(pq, src, -1, 0);

        while (!pq.empty()) {
            state top = pq.top();
            pq.pop();
            if (top.dist > dist[top.node])
                continue;
            for (edge &e : adj[top.node]) {
                dijkstra_check(pq, e.node, top.node, top.dist + e.weight);
            }
        }
    }
};

// example usage
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<array<int, 2>> edges(m);
    Dijkstra dijkstra(n);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        --x, --y;
        edges[i] = {x, y};
        dijkstra.add_bidirectional_edge(x, y, w);
    }
    vector<vector<int64_t>> d(n);
    for (int i = 0; i < n; i++) {
        dijkstra.dijkstra({i});
        d[i] = dijkstra.dist; // i 부터 모든 노드까지의 dist vector.
    }
}