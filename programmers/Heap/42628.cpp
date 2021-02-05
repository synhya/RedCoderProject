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
    INT(n);
    vector<string> operations(n);
    rep(i, n) {
        cin >> operations[i];
    }
    ///////////// ///////////// /////////////
    // another answer using multimap. much simple
    vector<int> answer;
    // int n = operations.size();
    multiset<int> pq;
    string sub;
    for (string s : operations) {
        if (s[0] == 'I')
            pq.insert(stoi(s.substr(2, s.size() - 1)));
        else if (s[2] == '1' && !pq.empty())
            pq.erase(--pq.end());
        else if (!pq.empty())
            pq.erase(pq.begin());
    }
    if (pq.empty()) {
        answer[0] = 0, answer[1] = 0;
    } else {
        answer[0] = *--pq.end();
        answer[1] = *pq.begin();
    }

    cout << answer[0] << " " << answer[1] << endl;

    return 0;
}
/* my answer using min,max heap
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;
    int cnt = 0;
    vector<int> minv;
    vector<int> maxv;
    for (int i = 0; i < n; i++) {
        ll num = stoi(operations[i].substr(2, operations[i].size() - 1));
        if (operations[i][0] == 'I') {
            maxpq.push(num);
            minpq.push(num);
            cnt++;
        } else if (operations[i][0] == 'D' && cnt > 0) {
            if (num == 1) {
                maxv.push_back(maxpq.top());
                maxpq.pop();
                cnt--;
            } else if (num == -1) {
                minv.push_back(minpq.top());
                minpq.pop();
                cnt--;
            }
            while (!maxv.empty() && maxv.back() == minpq.top()) {
                maxv.pop_back();
                minpq.pop();
            }
            while (!minv.empty() && minv.back() == maxpq.top()) {
                minv.pop_back();
                maxpq.pop();
            }
        }
    }
    if (cnt) {
        answer.push_back(maxpq.top());
        answer.push_back(minpq.top());
    } else {
        answer.push_back(0);
        answer.push_back(0);
    }
*/