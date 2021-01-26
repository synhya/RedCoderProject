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
void IN(Head &head, Tail &...tail) {
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

// 3가지 풀이법이 있다.
// 1. Multiset을 이용한 최소값 최대값유지.
// 2. SegTree(RMQ)를 이용한 방법. 1번과유사함. 최솟값 계속 query한다.
// 3. suffix , prefix sum을 이용한 방법. (제일 빠르다.)

int main() { // jiangly using suffix and preffix max
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        INT(n);
        VEC(int, a, n);
        vi pre(n + 1), suf(n + 1);
        rep(i, n) pre[i + 1] = max(pre[i], a[i]);
        rep3(i, n - 1, 0) suf[i] = max(suf[i + 1], a[i]);
        // ~!!! suf[n-1] 은 n-1까지 max. pre[n-1] 은 n-2까지의 max!
        int X = -1, Y = -1, Z = -1;
        vi stk;
        rep2(r, 1, n - 1) {
            while (!stk.empty() && a[r - 1] <= a[stk.back()])
                stk.pop_back();
            //a[r-1] 보다 작은값은 항상 포함하여 유지
            stk.push_back(r - 1);
            int x = suf[r];
            int L = lower_bound(all(pre), x) - pre.begin();
            int R = min<int>(r, upper_bound(all(pre), x) - pre.begin());
            auto it = lower_bound(all(stk), x, [&](int i, int x) { return a[i] < x; });
            // a[i] < x 라고 해서 햇갈리지말자. lowerbound함수는 *it = i 를 반환하되
            // a[i] 의 값은 x와 같거나 그보다 큰 바로다음 값이다(lowerbound특성);
            if (it == stk.end() || a[*it] != x)
                continue;
            // a[*it] > x 또는 x보다 크거나 같은값이 아예없는경우
            if (it != stk.begin())
                L = max(L, *prev(it) + 1); // +1은 a[0]부터 시작하니까.
            // 그 전 최솟 값은 L이 포함해야..> 6 4 8 7 6 6 과 4 6 8 7 6 6 비교.
            cout << r << ": " << L << " vs "
                 << R << " " << *it + 1 << endl;
            R = min(R, *it + 1); // r이 9, 10일때 2가 L에도 있고 R에도 있는 경우를 막기위함.
            // 1 2 3 3 3 4 4 3 4 2 1
            if (L >= R)
                continue;
            X = L;
            Y = r - L;
            Z = n - r;
        }
        if (X == -1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << X << " " << Y << " " << Z << "\n";
        }
    }
    return 0;
}
/* tutorial answer (O(NlogN)) . N for iterating log N for multiset sorting
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
/* answer using RMQ(similar to the multiset answer)
int a[200005], suf[200005];
SegTree seg(18);

        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            seg.update(i, a[i]);
        seg.update(n + 1, inf);

        suf[n + 1] = -inf;
        for (int i = n; i >= 1; i--) {
            suf[i] = max(suf[i + 1], a[i]);
        }

        int pre = 0;
        for (int i = 1; i <= n - 2; ++i) {
            pre = max(pre, a[i]);
            int ub = n - i, lb = 1, mid;
            while (ub - lb > 1) {
                mid = (ub + lb) / 2;
                if (seg.query(i + 1, i + mid) >= pre)
                    lb = mid;
                else
                    ub = mid; // pre보다 큰건 최대한 당긴다.
            }
            if (seg.query(i + 1, i + lb) != pre)
                continue;
            if (seg.query(i + 1, i + lb) == suf[i + lb + 1] && suf[i + lb + 1] == pre) {
                cout << "YES" << endl;
                cout << i << " " << lb << " " << n - (i + lb) << endl;
                goto end;
            }
            if (lb >= 2) {
                --lb; // 최대한 당겼기때문에 하나만 줘본다.(pre보다 크거나 같을것.)
                if (seg.query(i + 1, i + lb) == suf[i + lb + 1] && suf[i + lb + 1] == pre) {
                    cout << "YES" << endl;
                    cout << i << " " << lb << " " << n - (i + lb) << endl;
                    goto end;
                }
            }
        }
        cout << "NO" << endl;
    end:;
*/