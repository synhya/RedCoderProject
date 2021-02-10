#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep2(i, a, b) for (int i = a; i <= b; ++i)
#define rep3(i, a, b) for (int i = a; i >= b; --i)
#define endl '\n'
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
template <class T, class S>
inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S>
inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
template <class T>
using MaxHeap = std::priority_queue<T>;
template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
typedef int64_t ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
constexpr int inf = 1e9;
// constexpr int_64t inf = 1e18;
// const int N = 100 * 1000 + 5;
// const int mod = 1e9 + 7;
#define fi first
#define se second
ll checkAnticlockwise(pi p1, pi p2, pi p3) {
    return (1LL * p3.first * p1.second + p2.first * p3.second + p1.first * p2.second -
            p3.first * p2.second - p2.first * p1.second - p1.first * p3.second);
}
void Conpairu() {
    int n;
    cin >> n;
    vector<pi> p(n);
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }
    sort(all(p), [&](pi a, pi b) {if(a.se != b.se) return a.se < b.se; else return a.fi < b.fi; });
    pi st = p[0];
    function<bool(pi, pi)> comp = [&](pi p1, pi p2) {
        ll a = 1LL * (p1.second - st.second) * (p2.first - st.first);
        ll b = 1LL * (p2.second - st.second) * (p1.first - st.first);
        if (a != b)
            return a < b;
        if (p1.second != p2.second)
            return p1.second < p2.second;
        return p1.first < p2.first;
    };
    sort(p.begin() + 1, p.end(), comp);
    vi stk;
    stk.push_back(0);
    stk.push_back(1);
    int nxt = 2;
    while (nxt < n) { // except start
        while (stk.size() >= 2) {
            int p2 = stk.back();
            stk.pop_back();
            int p1 = stk.back();
            if (checkAnticlockwise(p[p1], p[p2], p[nxt]) > 0) {
                stk.push_back(p2);
                break;
            }
        }
        stk.push_back(nxt);
        nxt++;
    }

    cout << stk.size();
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        Conpairu();
    }
    return 0;
}