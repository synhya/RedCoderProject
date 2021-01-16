#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
// constexpr int inf = 1e9;
// const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7

// ***************************************************************** //
// ins[j] == "+" 사용시 ins[j] 는 포인터고 "+"는 char이라면서 오류 뜬다.

// best answer
struct Data {
    int mx;
    int mn;
    int add;
    Data(int mx = 0, int mn = 0, int add = 0) : mx(mx), mn(mn), add(add) {}
};
Data operator+(const Data &a, const Data &b) {
    return Data(std::max(a.mx, a.add + b.mx), std::min(a.mn, a.add + b.mn), a.add + b.add);
} // 현재 add 그리고 최대 최소로 나눠서 풀이..

// m 번의 반복동안 기존에 저장한 데이터를 불러오는게 포인트.
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::string s;
        std::cin >> s;
        std::vector<Data> a(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '+') {
                a[i] = Data(1, 0, 1);
            } else {
                a[i] = Data(0, -1, -1);
            }
        }
        std::vector<Data> pre(n + 1), suf(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + a[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = a[i] + suf[i + 1]; // when i = n-1 suf[i+1] = suf[n] 하지만 초기화값 0
        }
        while (m--) {
            int l, r;
            std::cin >> l >> r;
            l--;
            auto v = pre[l] + suf[r];
            std::cout << v.mx - v.mn + 1 << "\n";
        }
    }
    return 0;
}

/*  My answer . time limit . Needs DP
void solve() {
    INT(n, m);
    STR(ins);
    int res = 0;
    set<int> ans = {0};
    vi l(m), r(m);
    rep(i, m) {
        cin >> l[i] >> r[i];
    }

    rep(i, m) {
        rep(j, n) {
            if (((j + 1) >= l[i]) && ((j + 1) <= r[i])) {
                continue;
            }

            if (ins[j] == '+')
                ++res;
            if (ins[j] == '-')
                --res;
            ans.insert(res);
        }
        cout << sz(ans) << endl;
        ans.clear();
        res = 0;
        ans.insert(res);
    }
}

*/