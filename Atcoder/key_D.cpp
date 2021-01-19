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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    int k = (1 << n) - 1;
    cout << k << "\n";
    rep2(i,1,k) {
        string s(1 << n,' ');
        rep(j,k+1){
            s[j] = "AB"[__builtin_popcount(j & i) % 2];
        }
        cout << s << '\n';
    }
}