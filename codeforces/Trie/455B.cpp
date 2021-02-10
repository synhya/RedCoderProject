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
const int N = 100 * 1000 + 5; // use for N <= 5 * 10^5
// const int MX = 1e9 + 7; // For convenience, find the answer modulo 10^9+7
// cout << rng();
void Conpairu() {
    int n, k;
    cin >> n >> k;
    vector<bool> canwin(N);
    vector<bool> canlose(N);
    vector<vector<int>> next(N, vector<int>(26, -1));
    int C = 1; // find child
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int cur = 0;
        for (char c : s) {
            int v = c - 'a';
            if (next[cur][v] == -1) {
                next[cur][v] = C++; // child.
            }
            //      aab              ac          bc       input.
            // c[0][0] = 1;       continue;   c[0][1] = 5;
            // c[1][0] = 2;     c[1][2] = 4;  c[5][2] = 6;
            // c[2][1] = 3;
            cur = next[cur][v];
        }
    }
    for (int i = C - 1; i >= 0; i--) { // 6  ~ 0 search every node by level
        bool isLeaf = true;
        rep(v, 26) {
            if (next[i][v] != -1)
                isLeaf = false; // has child info.
        }
        if (isLeaf) {
            canwin[i] = false;
            canlose[i] = true;
        } else {
            canwin[i] = canlose[i] = false;
            rep(v, 26) {
                if (next[i][v] != -1) {
                    if (!canwin[next[i][v]])
                        canwin[i] = true;
                    if (!canlose[next[i][v]])
                        canlose[i] = true;
                }
            }
        }
    }
    if (canwin[0] && canlose[0]) {
        cout << "First\n";
    } else if (canwin[0]) {
        if (k % 2 == 1) {
            cout << "First\n";
        } else {
            cout << "Second\n";
        }
    } else {
        cout << "Second\n";
    }
}
void Another() {
    int nnn, k;
    cin >> nnn >> k;
    vector<vi> a(N, vi(26, 0));
    vi canwin(N);
    vi canlose(N);
    int n = 1;
    for (int i = 0; i < nnn; i++) {
        string s;
        cin >> s;
        int cur = 1;
        for (auto c : s) {
            int p = c - 'a';
            if (a[cur][p] == 0) {
                n++;
                a[cur][p] = n; // next.
            }
            cur = a[cur][p];
        }
    }
    for (int i = n; i >= 1; i--) {
        bool mv = false;
        for (int j = 0; j < 26; j++) {
            if (a[i][j] != 0) {
                mv = true;
                break;
            }
        }
        if (!mv) {
            canwin[i] = false;
            canlose[i] = true;
            continue;
        }
        canwin[i] = false;
        canlose[i] = false;
        for (int j = 0; j < 26; j++) {
            if (a[i][j] != 0) {
                if (!canwin[a[i][j]])
                    canwin[i] = true;
                if (!canlose[a[i][j]])
                    canlose[i] = true;
            }
        }
    }
    if (!canwin[1]) {
        cout << "Second\n";
    } else if (canlose[1]) {
        cout << "First\n";
    } else { // canwin[1] and !canlose[1].
        cout << ((k % 2 == 1) ? "First" : "Second") << endl;
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        Another();
    }
    return 0;
}