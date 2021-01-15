// https://www.youtube.com/watch?v=pSqmAO-m7Lk

// maintain distance array/ starting node has distance 0
// maintain a PQ of key-value pairs

// in the beginning all dist is set to INF > assume every node unreachable
// PQ of key(index)-value(distance) tells where to visit next
// from ascending order of distance we choose where to visit next
// for example
//      - idx distance pairs in PQ * in starting node 0
//          0, 0 // initial node and its dist
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
int dijkstra(int g, int n, int s) {
    vis =
}