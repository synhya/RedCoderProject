#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using namespace std;

// constexpr int inf = 1e9;
// constexpr i64 inf = 1e18;
// const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> h(n), w(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i] >> w[i];
            if (h[i] > w[i])
                swap(h[i], w[i]);
        }
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(), [&](int i, int j) {
            return h[i] < h[j];
        }); // 데이터 유지하고 인덱스만
        int u = -1;
        vector<int> ans(n, -1);
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && h[p[i]] == h[p[j]]) {
                j++; // 다른 높이가 나올 때까지.
            }
            for (int k = i; k < j; k++) { // k = 0; k < 2
                if (u != -1 && w[u] < w[p[k]]) { //h가 다르고 u가 더 작으므로
                    ans[p[k]] = u;
                }
            }
            for (int k = i; k < j; k++) { // 같은 높이 중에서
                if (u == -1 || (w[u] > w[p[k]])) {
                    u = p[k]; // width 더 작은 거 반환, u = 0;
                }
            }
            i = j; // 같은거 정렬 끝나고 다음 인덱스 ( 0 > 2 )
        }
        for ( int i = 0; i < n; i++) {
            cout << ans[i] + (ans[i] >= 0) << " \n"[i== n-1];
        }
    }
    return 0;
}