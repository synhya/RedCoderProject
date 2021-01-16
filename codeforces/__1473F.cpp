#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using namespace std;
// constexpr int inf = 1e9;
// constexpr i64 inf = 1e18;
// const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7

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
        }// eventually every DFS is done returning 9 as value
        return f - r; // (1,10,3) return 0;
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
constexpr int inf = 1e9;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) { // a1 .. an <= 100
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) { // -10^5 ~ 10^5
        cin >> b[i];
    }
    vector<int> last(101, -1); //
    Flow g(n + 2);             // n = s , n + 1 = t
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] > 0) {
            ans += b[i];
            g.addEdge(n, i, b[i]);
            // from n(Source) to i add directed graph with cap c;
            // also add residual of cap 0
        } else {
            g.addEdge(i, n + 1, -b[i]);
        }
        for (int j = 1; j <= a[i]; j++) {         // when i = 3 for j <= 4(a3)
            if (a[i] % j == 0 && last[j] != -1) { // 4 % 1,2,4 == 0
                g.addEdge(i, last[j], inf);       // last[1,2] == -1, last[4] = 0
            }                                     // . > add (3, 0, inf);
        }                                         // ...when i = 7, add(7, 3, inf);
        last[a[i]] = i;                           // i = 0 > last[4(a0)] = 0
    }                                             // i = 3 > last[4(a3)] = 3 update
    ans -= g.maxFlow(n, n + 1);
    cout << ans << "\n";
    return 0; // why cap of inf? > to keep two nodes in same partition in cut!
}
//// 양수 b[i]가 s에서 시작하는 용량이고.. 최대유량을 구해서 빼준다..
// 두 bipartite 파트를 연결하는 에지의 용량이 무한대이므로 모든노드가 연결되어있다면
// t에 연결된 음수b[i] 만큼의 용량을(s용량보다 작다면) 보내줄수있을 것이다.
// 결국 최대유량을 구하는 문제이므로 dinic사용한다.