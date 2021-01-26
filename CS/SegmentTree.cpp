// if need to check minimum or sum in range for several times .
// we use segment tree.. it stores minimum values in tree so works like dp
// 1454F

#include <bits/stdc++.h>
using namespace std;
#define inf 1e9 + 7
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
int a[200005], mx[200005];
SegTree seg(18);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    seg.init();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            seg.update(i, a[i]);
        seg.update(n + 1, inf);

        suf[n + 1] = -inf;
        for (int i = n; i >= 1; i--) {
            suf[i] = max(suf[i + 1], a[i]);
        }

        int pre = 0;
        for (int i = 1; i <= n - 2; ++i) {
            pre = max(pre, a[i]);
            int ub = n - i, lb = 1, mid;
            while (ub - lb > 1) {
                mid = (ub + lb) / 2;
                if (seg.query(i + 1, i + mid) >= pre)
                    lb = mid;
                else
                    ub = mid; // pre보다 큰건 최대한 당긴다.
            }
            if (seg.query(i + 1, i + lb) != pre)
                continue;
            if (seg.query(i + 1, i + lb) == suf[i + lb + 1] && mx[i + lb + 1] == pre) {
                cout << "YES" << endl;
                cout << i << " " << lb << " " << n - (i + lb) << endl;
                goto end;
            }
            if (lb >= 2) {
                --lb; // 최대한 당겼기때문에 하나만 줘본다.(pre보다 크거나 같을것.)
                if (seg.query(i + 1, i + lb) == suf[i + lb + 1] && mx[i + lb + 1] == pre) {
                    cout << "YES" << endl;
                    cout << i << " " << lb << " " << n - (i + lb) << endl;
                    goto end;
                }
            }
        }
        cout << "NO" << endl;
    end:;
    }
}