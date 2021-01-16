#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
// constexpr int inf = 1e9;
constexpr i64 inf = 1e18;
// const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7

//minimum weight  >> shortest path >> dijkstra
using namespace std;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> e(n); //edge
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w); // add edge and weight with pair
    }
    vector<i64> dis(4 * n, inf); // 비트계산 응용! 뒷자리 00 고정.
    priority_queue<pair<i64, int>> h;
    dis[0] = 0;
    h.emplace(0, 0); // h.push(pair<int, int>(0,0));
    while (!h.empty()) {
        i64 d = -h.top().first; // edge cost from lowest (use '-' !!)
        int x = h.top().second; // pointing node
        h.pop();
        if (d > dis[x]) {
            continue;
        }
        int u = x / 4;     // bit operation
        int p = x / 2 % 2; // p and q for min and max respectively
        int q = x % 2;
        for (auto [v, w] : e[u]) { // for edge u to v (endpoint ) and w
            int y = v * 4 + p * 2 + q;
            if (dis[y] > dis[x] + w) {
                dis[y] = dis[x] + w;
                h.emplace(-dis[y], y);
            }
            if (p == 0 && dis[y + 2] > dis[x]) {
                dis[y + 2] = dis[x];
                h.emplace(-dis[y + 2], y + 2);
            }
            if (q == 0 && dis[y + 1] > dis[x] + 2 * w) {
                dis[y + 1] = dis[x] + 2 * w;
                h.emplace(-dis[y + 1], y + 1);
            }
            // x 가 4의 배수면 dis[x] , dis[x+1], dis[x+2] 업데이트
            // x 가 2의 배수면 dis[x] , dis[x+1] 업데이트
        }
    }
    for (int i = 1; i < n; i++) {
        cout << min(dis[i * 4], dis[i * 4 + 3]) << " \n"[i == n - 1];
    } // dis[i*4]와 비교하는 이유는 min == max인 경우 고려.
    // .> (dis[x] + 0 * w) + ( dis[x] + 2 * w)
}