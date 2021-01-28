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
constexpr int inf = 1e9;
// constexpr i64 inf = 1e18;
// const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7
vi t_parent;
vi t_ord;
void tree_getorder(const vector<vi> &e, int root) {
    int n = e.size();
    t_parent.assign(n, -1);
    t_ord.clear();

    vi stk;
    stk.push_back(root);
    while (!stk.empty()) {
        int i = stk.back();
        stk.pop_back();
        t_ord.push_back(i); // 0 2 5 ,,
        for (int c : e[i]) {
            if (t_parent[c] == -1 && c != root)
                stk.push_back(c);
            else
                t_parent[i] = c; // e[] = {0,2},{2,0} >> stk.push(2) >> parent[2] = 0;
                                 // e[] {2,5} >> stk.push(5) >> {5,2} >> parent[5] = 2; ..
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    INT(n);
    vector<vi> e(n);
    rep(i, n - 1) { //tree
        INT(x, y);
        --x, --y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    tree_getorder(e, 0);
    vector<bool> isleaf(n);
    rep(i, n)
        isleaf[i] = e[i].size() == 1;
    vi subtleafs(n);
    rep(i, n)
        subtleafs[i] = isleaf[i];
    for (auto it = t_ord.end() - 1; it >= t_ord.begin(); it--) {
        int p = t_parent[*it];
        subtleafs[p] += subtleafs[*it];
    }
    function<vector<int>(int)> rec = [&](int i) -> vi {
        int im = isleaf[i] ? 1 : 0; // root is not leaf in 2nd case
        vi dp, ndp;
        ndp.assign((im + 1) * 2, inf);
        ndp[0 * 2 + 0] = 0;
        ndp[(isleaf[i] ? 1 : 0) * 2 + 1] = 0;
        int n = im;
        for (auto j = e[i].begin(); j != e[i].end(); j++) {
            if (*j != t_parent[i]) { // t_parent[0] == -1;
                dp.swap(ndp);
                int m = subtleafs[*j];
                vi v = rec(*j);
                assert(v.size() == (m + 1) * 2);
                ndp.assign((n + m + 1) * 2, inf);
                rep2(a, 0, n) rep2(b, 0, m) rep(x, 2) rep(y, 2) {
                    chmin(ndp[(a + b) * 2 + x], dp[a * 2 + x] + v[b * 2 + y] + (x != y));
                } // x and y for color 0 and 1 so + (x != y) is for different parties.
                // a,b for cnt. how many colored leafs.
                n += m;
            }
        }
        return ndp;
    };
    vi ansv = rec(0);
    int a = subtleafs[0] / 2;
    int ans = min(ansv[a * 2 + 0], ansv[a * 2 + 1]);
    cout << ans << endl;

    return 0;
}