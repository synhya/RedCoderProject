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
template <class T>
vector<T> divisor(T x) {
    vector<T> ans;
    for (T i = 1; i * i <= x; i++)
        if (x % i == 0) {
            ans.pb(i);
            if (i * i != x)
                ans.pb(x / i);
        }
    return ans;
}
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())
// constexpr int inf = 1e9;
// constexpr i64 inf = 1e18;
// const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    INT(N);
    vector<vector<string>> tickets(N, vector<string>(2)); //ICN
    rep(i, N) {
        cin >> tickets[i][0] >> tickets[i][1];
    }
    /////////////////////////////////////////
    // VISITED 의 재발견.  노드가 아니라 엣지에 적용사례!!
    vector<string> answer;
    int n = tickets.size();
    vector<int> visited(n);
    sort(tickets.begin(), tickets.end(), [&](vector<string> a, vector<string> b) { return a[1] < b[1]; });
    function<void(string)> dfs = [&](string from) -> void {
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                if (tickets[i][0] == from) {
                    visited[i] = 1; // visited for tickets!!
                    // answer.push_back(tickets[i][1]);
                    // 가다가 막힐수 있으므로 여기 넣으면 안된다~!
                    dfs(tickets[i][1]);
                    answer.push_back(tickets[i][1]);
                }
            }
        }
        return;
    };

    dfs("ICN");
    answer.push_back("ICN");
    reverse(answer.begin(), answer.end());

    for (int i = 0; i < n + 1; i++)
        cout << answer[i] << " \n"[i == n];
    return 0;
}
/* my answer. spaghetti like.
    map<string, int> port;
    for (int i = 0; i < n; i += 1) {
        port.insert({tickets[i][0], 0});
        port.insert({tickets[i][1], 0});
    }
    int idx = 0;
    int start_v = 0;
    vector<string> p;
    for (auto &[x, y] : port) { // & 잊지말자!
        y += idx;
        idx++;
        p.push_back(x);
        if (x == "ICN")
            start_v = y;
    }
    // cout << start_v;
    int m = port.size();
    vector<vector<int>> e(m);
    for (int i = 0; i < n; i++) {
        int x = port[tickets[i][0]];
        int y = port[tickets[i][1]];
        e[x].push_back(y); // one way
    }
    vector<int> res;
    vector<int> comres;
    function<void(int, int, vector<vector<int>>, vector<int>)> dfs;
    dfs = [&](int u, int prev_u, vector<vector<int>> edge, vector<int> result) -> void {
        if (prev_u != -1) {
            edge[prev_u].erase(find(edge[prev_u].begin(), edge[prev_u].end(), u));
        } // 맨 처음 놓는건 self-node 방지.
        result.push_back(u);
        if (edge[u].empty()) {
            cout << result.size() << endl;
            if (result.size() == n + 1) {
                // compare with prev result.
                if (comres.empty()) {
                    comres = result;
                } else {
                    for (int i = 0; i < n + 1; i++) {
                        if (result[i] != comres[i]) {
                            if (result[i] < comres[i])
                                comres = result;
                            break;
                        }
                    }
                }
            }
            return;
        }
        for (auto v : edge[u]) {
            //cout << p[u] << " : " << p[v] << endl;
            dfs(v, u, edge, result);
        }
    };
    //cout << p[e[start_v][0]];
    dfs(start_v, -1, e, res);
    for (int i = 0; i < n + 1; i++) {
        answer.push_back(p[comres[i]]);
    }
    for (int i = 0; i < n + 1; i++)
        cout << answer[i] << " \n"[i == n];
*/