#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using namespace std;
template <class T>
T POW(T x, int n) {
    T res = 1;
    for (; n; n >>= 1, x *= x)
        if (n & 1)
            res *= x;
    return res;
}

// constexpr int inf = 1e9;
// constexpr i64 inf = 1e18;
// const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int H, W, K;
    cin >> H >> W >> K;
    vector<vector<char>> sq(H + 1, vector<char>(W + 1));
    vector<vector<vector<int>>> dp(H + 1, vector<vector<int>>(W + 1, vector<int>(0)));
    rep(i, K) {
        int h, w;
        char x;
        cin >> h >> w >> x;
        sq[h][w] = x;
    } // dp[h][w][k]

    
    int ans = 0;
    rep(i, dp[H][W].k.size()) {
        ans += dp[H][W].d
    }
}

return 0;
}