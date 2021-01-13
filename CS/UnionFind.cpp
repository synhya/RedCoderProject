// UnionFind in otherwords DSU(disjoint set union)

// https://www.youtube.com/watch?v=ibjEGG7ylHk
// Unify magnets in to groups, each group have distinct colors
// groups can merge(union) together. Finally all magnets belong to One group

// Kruskal's Minimum Spanning Tree
// https://www.youtube.com/watch?v=JZBQLXgSGfs
// - Sort edges by asc edge weight (edges have weight. not nodes)
// - iterate edges with their linked nodes
//    - Check edge's both nodes ( DO FIND OPERATION )
// * procedure for Kruskal
//  1. if both nodes are not unified > make new group
//  2. if only one node unified > include the node not unifed to already exisiting group
//  3. if both nodes are unified?
//     3-1. if both nodes are part of SAME GROUP
//      - if the edge it self gets in to the node's group
//      - it will create a CYCLE so we IGNORE for the edge (iter++;)
//     3-2. if both nodes are part of DIFFERENT GROUP
//      - merge two different groups to ONE GROUP

// https://www.youtube.com/watch?v=0jNmHPfA_yE
// compare ROOT nodes of each union operation nodes are pointing to
// keep merging groups(nodes) of smaller components to larger one
//    by merging means group's root node pointing the other group's rootnode
// >>> PROBLEM
//   with union operation.. on nodes we need to find it's
//   root node every single time operation done.. which is unefficient
//   so we use Union Find Path Compression

// Union Find Path Compression
// https://www.youtube.com/watch?v=VHRhJWacxis
// by following path of a single node to root node
// for every nodes which belongs to the path
// DIRECTLY link to the root node
// which will save time going to root node in UNION operation
// - for example A > B > C > D(root) to A > D, B > D, C > D

#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
    // total number of elements
    int size;
    // to track the sizes of components( number of elements in component )
    vector<int> sz;
    // id[i] points to PARENT of i-th element.
    vector<int> id;
    // total number of components
    int numComponents;

    UnionFind(int _size) : size(_size), numComponents(_size)
    {
        if (size <= 0)
            throw invalid_argument("size should be positive");
        // this->size = numComponents = size;
        sz.resize(size);
        id.resize(size);

        for (int i = 0; i < size; i++)
        {
            id[i] = i; // link to it self(selfroot) > if id[i] == i then root node
            sz[i] = 1; // it will increase by Union
        }
    };
    // Find root of component 'p'
    int find(int p)
    {
        // Find the root of the component
        int root = p;
        while (root != id[root])
            root = id[root]; // loop until finding root

        // ***** PATH Compression *****
        // this is what makes UnionFind a(n) (amortized constant time complexity)
        while (p != root) // root = id[root]
        {
            int next = id[p];
            id[p] = root;
            p = next;
        }

        return root;
    }

    // return if elements(nodes) are on same componenet
    bool connected(int p, int q)
    {
        return find(p) == find(q);
    }
    int componentSize(int p)
    {
        return sz[find(p)];
    }
    int size()
    {
        return size;
    }
    int components()
    {
        return numComponents;
    }
    // Unify the components containing elements 'p' and 'q'
    void unify(int p, int q)
    {
        int root1 = find(p);
        int root2 = find(q);

        // if in same group IGNORE
        if (root1 == root2)
            return;

        if (sz[root1] < sz[root2])
        {
            sz[root2] += sz[root1];
            id[root1] = root2;
        }
        else
        {
            sz[root1] += sz[root2];
            id[root2] = root1;
        }
        numComponents--; // Unify > groups -1
    }
};

int main()
{
}