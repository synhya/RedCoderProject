#include <bits/stdc++.h>
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
typedef long long int ll;
typedef pair<int, int> pi;
#define MOD 998244353
#define SIZE 5005

char mp[SIZE][SIZE];
ll dp[SIZE][SIZE];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    rep(i, n) rep(j, m) mp[i][j] = '.';
    rep(i, k) {
        int h, w;
        char c;
        cin >> h >> w >> c;
        h--, w--;
        mp[h][w] = c;
    }
    ll iv = 2;
    while (iv % 3 != 0)
        iv += MOD; // iv * pow(3,h*w-k) % MOD = pow(3,h*w-k -1) * 2
    iv /= 3;       // iv * pow(3,h*w-k) = pow(3,h*w-k -1) * 2 * MOD + pow(3,h*w-k -1) * 2
    rep(i, n) {    // iv * iv * iv * pow(3,h*w-k) % MOD = pow(3,h*w-k -3) * 2 * 2 * 2
        rep(j, m) {
            if (mp[i][j] != 'R' && i + 1 < n) {
                dp[i + 1][j] += dp[i][j] * (mp[i][j] == '.' ? iv : 1);
                dp[i + 1][j] %= MOD;
            }
            if (mp[i][j] != 'D' && j + 1 < m) {
                dp[i][j + 1] += dp[i][j] * (mp[i][j] == '.' ? iv : 1);
                dp[i][j + 1] %= MOD;
            }
        }
    }
    ll ret = dp[n - 1][m - 1];
    rep(i, n * m - k) ret = ret * 3LL % MOD;
    cout << ret << "\n";
    return 0;
}