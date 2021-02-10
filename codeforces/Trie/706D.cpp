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
// constexpr int inf = 1e9;
// constexpr i64 inf = 1e18;
// const int N = 100 * 1000 + 5;
// const int mod = 1e9 + 7;
#include <bits/stdc++.h>
using namespace std;

struct trie {
    vector<vector<int>> to;
    vector<int> end, pref;
    int sigma;
    char norm;
    trie(int sigma_ = 26, char norm_ = 'a') : sigma(sigma_), norm(norm_) {
        to = {vector<int>(sigma)};
        end = {0}, pref = {0};
    }
    void insert(string s) {
        int cur = 0;
        for (auto c : s) {
            int &nxt = to[cur][c - norm];
            if (!nxt) {          // 필요할때마다 동적으로 증가.
                nxt = to.size(); // child(next) info
                to.push_back(vector<int>(sigma));
                end.push_back(0), pref.push_back(0);
            }
            cur = nxt, pref[cur]++; // for prefix.
            // for a(1)b(2)c(3), a(1)b(2)b(4) .. pref[2] = 2;
        }
        end[cur]++;
    }
    void erase(string s) {
        int cur = 0;
        for (char c : s) {
            int &nxt = to[cur][c - norm];
            cur = nxt, pref[cur]--;
            if (pref[cur] == 0)
                nxt = 0; // empty node cant have child info.
        }
        end[cur]--;
    }
    int find(string s) {
        int cur = 0;
        for (auto c : s) {
            cur = to[cur][c - norm];
            if (cur == 0) // there is no child info.
                return 0;
        }
        return cur;
    }
    int count_pref(string s) {
        return pref[find(s)];
    }
    int query(string s) {
        int cur = 0, ret = 0;
        for (int i = 0; i < s.size(); i++) { // from high bit.
            int c = s[i] - norm;
            if (to[cur][!c] != 0) // can xor
                ret += 1 << (s.size() - 1 - i), cur = to[cur][!c];
            else
                cur = to[cur][c];
        }
        return ret;
    }
};

string to_str(int x) {
    string ret;
    for (int i = 0; i < 31; i++)
        ret += ('0' + !!(x & 1 << (30 - i)));
    return ret; //. 16 = 000...001000
}
void Conpairu() {
    trie t(2, '0'); // sigma and norm
    int q;
    cin >> q;
    t.insert(to_str(0));

    while (q--) {
        char c;
        int a;
        cin >> c >> a;
        if (c == '+')
            t.insert(to_str(a));
        else if (c == '-')
            t.erase(to_str(a));
        else
            cout << t.query(to_str(a)) << endl;
    }
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