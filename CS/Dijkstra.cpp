// https://www.youtube.com/watch?v=pSqmAO-m7Lk

// maintain distance array/ starting node has distance 0
// maintain a PQ of key-value pairs

// in the beginning all dist is set to INF > assume every node unreachable
// PQ of key(index)-value(distance) tells where to visit next
// from ascending order of distance we choose where to visit next
// for example
//      - idx distance pairs in PQ * in starting node 0
//          0, 0 // initial node and its dist  // pq.push({s, 0});
//          1, 4 // weight of edge (0,1) is 4 (i.e. distance is 4)
//          2, 1 // weight of edge (0,2) is 1
// .> pull out the node that visits every edges of it ( delete 0,0 from PQ )
// .> find the lowest distance from 0 and move toward that idx(node) ( Min PQ )
//
//      - idx distance pairs in PQ * in node 2
//          1, 4 //
//          2, 1 // dist[2] = 1
//          1, 3 // suppose ther is edge(2,1) of weight 2 ( edge.weight )
//            then dist from node 2 to node 1 is dist[2] + edge.weight = 1
//          3, 6 //
// .> best promising (least dist) is node 1 from dist[1] = 3 so move to node 1
// .> and also pull out node 2 since it visited every edge
//      - idx distance pairs in PQ * in node 1
//          1, 4
//          1, 3
//          3, 6
//          3, 4 // edge(1,3) of weight 4
// .> move to node 3 (dist 4) and pull out 1,3
//      - idx distance pairs in PQ * in node 3
//          1, 4  // not pulled out but node 1 already visited >> ignore
//          3, 6
//          3, 4

#include <bits/stdc++.h>
constexpr int INF = 1e9 + 7;
using namespace std;

// g - adjacency list of weighted graph
// n - number of nodes in the graph
// s - starting node (0<= s < n)

// 부연설명.
int dijkstra(vector<vi> g, int n, int s) {
    vector<bool> vis(n, false); // visited default false
    vector<int> dist(n, INF);
    dist[s] = 0; // starting node
    priority_queue<pair<int, int>> pq;
    pq.push({s, 0});
    while (!pq.empty()) {
        int index = pq.top().first;
        int minValue = -pq.top().second; // weight ( pq.push({edge.to, -newDist}); )
        // **** -pq.top().second. edgeWeight를 음수로 변경하면
        // **** maxheap을 minheap으로 변경할수 있다.
        // .> 기본적으로 c++ queue는 poll기능이 없기때문에
        //    ascending 으로 정리되는 큐에서 최소distance부터 가져오기 위해서는
        //  ` -pq.top() , pq.pop() 이 방식으로 최솟값 가져오고
        //  ` pq.push ({..., -newDist}) 이 방식으로 저장하자
        pq.pop(); // from backward
        vis[index] = true;
        if (dist[index] < minValue) // already found better route
            continue;               // dist[1] = 3 and say there is (1,5) in queue then it will skip
        for (auto edge : g[index]) {
            if (vis[edge.to]) // 1번 엣지는 방문한적이 없다. (0 방문하고 2감)
                continue;
            int newDist = dist[index] + edge.cost;
            // {1(from start to edge1), 4(cost)} exists and
            //dist[2] = 1, edge(2,1).cost = 2 appears > newDist = 3;
            if (newDist < dist[edge.to]) {    // update if newDist is shorter ( 3 < 4 )
                dist[edge.to] = newDist;      // (1,3);
                pq.push({edge.to, -newDist}); // 1로가는 비용이 이젠 3이다.
            }
        }
    }
    return dist;
}