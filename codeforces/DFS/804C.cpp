#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep2(i, a, b) for (int i = a; i <= b; ++i)
#define rep3(i, a, b) for (int i = a; i >= b; --i)
#define endl '\n'
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
void YES(bool t = 1) { cout << YESNO[t] << endl; }
void Yes(bool t = 1) { cout << YesNo[t] << endl; }
void yes(bool t = 1) { cout << yesno[t] << endl; }

template <class T, class S>
inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S>
inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
#define INT(...)     \
    int __VA_ARGS__; \
    IN(__VA_ARGS__)
#define LL(...)     \
    ll __VA_ARGS__; \
    IN(__VA_ARGS__)
#define VEC(type, name, size) \
    vector<type> name(size);  \
    IN(name)
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define VV(type, name, h, w)                       \
    vector<vector<type>> name(h, vector<type>(w)); \
    IN(name)
int scan() { return getchar(); }
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T, class S>
void scan(pair<T, S> &p) { scan(p.first), scan(p.second); }
template <class T>
void scan(vector<T> &);
template <class T>
void scan(vector<T> &a) {
    for (auto &i : a)
        scan(i);
}
template <class T>
void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail>
void IN(Head &head, Tail &...tail) {
    scan(head);
    IN(tail...);
}
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
// constexpr int inf = 1e9;
// constexpr i64 inf = 1e18;
const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7

int n, m;
int color[N];
set<int> S;
vi vertex[N], e[N];
void colorpicker(int c) {
    for (auto x : vertex[c]) { //vertex의 icecream들
        if (color[x])
            S.erase(color[x]);
    }
    for (auto x : vertex[c]) {
        if (!color[x]) {
            color[x] = *S.begin(); // 1
            S.erase(color[x]);
        }
    }
    for (auto x : vertex[c]) {
        S.insert(color[x]);
    }
}
void dfs(int a, int pa) { // 0, -1
    colorpicker(a);
    for (auto x : e[a]) {
        if (x == pa)
            continue;
        dfs(x, a);
    }
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n >> m;
    rep2(i, 1, m) S.insert(i);
    int maxv = 0;
    rep(i, n) {
        int Q;
        cin >> Q;
        rep(i, Q) {
            int t;
            cin >> t;
            --t;
            vertex[i].push_back(t);
        }
    }
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(0, -1);
    rep(i, m) {
        if (color[i] == 0) // 엣지가 없는 경우.. 독립노드.
            color[i] = 1;
        maxv = max(maxv, color[i]);
    }
    cout << maxv << endl;
    rep(i, m) {
        cout << color[i] << " ";
    }
    return 0;
}
