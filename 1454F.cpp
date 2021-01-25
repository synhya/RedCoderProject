#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
#define rep3(i, a, b) for (ll i = a; i >= b; --i)
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
void IN(Head &head, Tail &... tail) {
    scan(head);
    IN(tail...);
}
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
typedef long long int ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
// constexpr int inf = 1e9;
// constexpr i64 inf = 1e18;
// const int N = 500 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7

bool found;
void shift(multiset<int> &l, multiset<int> &r, int val) {
    l.erase(l.find(val));
    r.insert(val);
}

void check(const multiset<int> &lf, const multiset<int> &mid, const multiset<int> &rg) {
    if (found || lf.empty() || mid.empty() || rg.empty()) {
        return;
    }
    if (*lf.rbegin() == *mid.begin() && *mid.begin() == *rg.rbegin()) {
        found = true;
        cout << "YES\n";
        cout << lf.size() << " " << mid.size() << " " << rg.size() << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        }
    return 0;
}
/* tutorial answer
        INT(n);
        VEC(int, a, n);
        found = false;
        multiset<int> lf, mid(all(a)), rg;
        int r = n - 1;

        rep(l, n - 2) {
            shift(mid, lf, a[l]);
            while (r - 1 >= l && a[r] <= *lf.rbegin()) {
                shift(mid, rg, a[r]);
                --r;
            }
            while (r - 1 < l) { // l을 밀다가 mid가 empty된 경우.
                shift(rg, mid, a[r + 1]);
                ++r;
            }

            check(lf, mid, rg);
            // 1 3 2 4 3 3 1 이 경우 i가 1일때는 1 3 / 2 4 / 3 3 1
            // i=2일때 1 3 2 / 4 / 3 3 1 >> 아래에서 1 3 2 / 4 3 / 3 1 로 확인가능
            if (rg.empty())
                continue;

            shift(rg, mid, a[r + 1]);
            check(lf, mid, rg);
            shift(mid, rg, a[r + 1]);
            // 1 3 4 3 3 1 이 경우 rg는 3 3 1 까지 땡길꺼고 lf는 1 3 일꺼니까
            // 4 에서 3을 하나 가져오고.. 이게 3보다 작으면 ( 1 3 4 2 3 1)
            // 성립이 안되고 3과 같으면 성립하는거다.
            // 하나만 가져오면 알수 있으므로(3인지 3보다작은지) 하나만 땡겨본다.
            // 만약에 1 3 2 4 3 3 1의 경우. i가 3까지가야 결과 알수 있을것.
        }
        if (!found) {
            cout << "NO\n";
        }
*/