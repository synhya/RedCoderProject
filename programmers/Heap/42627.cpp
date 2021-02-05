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

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    INT(n);
    vector<vector<int>> jobs(n, vector<int>(2));
    rep(i, n) {
        INT(x, y);
        jobs[i][0] = x;
        jobs[i][1] = y;
    }
    ///////////////////////////////// answer w/o pq.
    // 내 답보다 깔끔
    int answer = 0;
    // int n = jobs.size();
    int start = 0;
    int time = 0;
    sort(jobs.begin(), jobs.end(), [&](vi a, vi b) { return a[1] < b[1]; });
    while (!jobs.empty()) {
        for (int i = 0; i < n; i++) {
            if (jobs[i][0] <= start) {
                start += jobs[i][1];
                time += start - jobs[i][0];
                jobs.erase(jobs.begin() + i);
                break;
            }

            if (i == jobs.size() - 1)
                start++;
        }
    }

    cout << answer << endl;
    return 0;
}
/* my answer using pq.
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    sort(jobs.begin(), jobs.end(), [&](vector<int> a, vector<int> b) { return a[0] > b[0]; });

    //
    ll cur = 0;
    while (!jobs.empty()) {
        int x = jobs.back()[0];
        int y = jobs.back()[1];
        jobs.pop_back();
        answer += y;
        cur = x + y;
        while (!pq.empty() || (!jobs.empty() && jobs.back()[0] < cur)) {
            while (!jobs.empty() && jobs.back()[0] < cur) {
                pq.emplace(jobs.back()[0], jobs.back()[1]);
                jobs.pop_back();
            }
            if (!pq.empty()) {
                pair<int, int> next = pq.top();
                pq.pop();
                cur += next.second;
                answer += cur - next.first;
            }
        }
    }
    answer /= n;
*/