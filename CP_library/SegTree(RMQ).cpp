#include <bits/stdc++.h>
using namespace std;
/////////////// RANGE MINIMUM QUEUE ///////////////////
#define inf 1e9 + 7;
struct SegTree {
    int size;
    vector<int> seg;

    SegTree() {}
    SegTree(int size) {
        this->size = size;
        seg.resize(1 << (size + 1));
    }
    void init() {
        for (int i = 0; i < (1 << (size + 1)); i++)
            seg[i] = inf;
    }
    void update(int i, int val) {
        i += (1 << size);
        seg[i] = val;
        while (i > 1) {
            i /= 2;
            seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
        }
    }
    int query(int a, int b, int k, int l, int r) {
        if (b < l || r < a)
            return inf;
        if (a <= l && r <= b) // 1<= l && r <= 5
            return seg[k];
        int lval = query(a, b, k * 2, l, (l + r) / 2);
        int rval = query(a, b, k * 2 + 1, (l + r) / 2 + 1, r);
        return min(lval, rval);
    }
    int query(int a, int b) {
        if (a > b)
            return inf;
        return query(a, b, 1, 0, (1 << size) - 1);
    }
};