#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, n) for (int i = int(a); i < n; i++)

#define sz(a) int((a).size())
#define x first
#define y second

const int INF = int(1e9);
const int N = 4221;

struct edge
{
    int to, c, f, id;

    edge(int to = 0, int c = 0, int f = 0, int id = -1) : to(to), c(c), f(f), id(id) {}
};

vector<edge> es;
vector<int> g[N];

void add_edge(int fr, int to, int cap, int id)
{ // from, to, capacity, id
    g[fr].push_back(sz(es));
    es.emplace_back(to, cap, 0, id); // edge(to, c, f, id)
    g[to].push_back(sz(es));         // f는 왜 쓰는거지? flow network
    es.emplace_back(fr, 0, 0, id);
}

int pw[N];
int n1, n2, m;

inline bool read()
{
    if (!(cin >> n1 >> n2 >> m))
        return false;

    rep(id, 0, m)
    {
        int u, v;
        assert(cin >> u >> v);
        u--, v--; // to use as index in array pw[]

        pw[u]++; // degrees of each vertex
        pw[n1 + v]++;

        add_edge(u, n1 + v, 1, id); // n1 = u(max)
    }
    return true;
}

void solve()
{
    int cnt = *min_element(pw, pw + n1 + n2); // min(a,b) , max(a,b) , min_element(range)
                                              // cnt = minDegree
    int s = n1 + n2;
    int t = s + 1;
    rep(i, 0, n1) add_edge(s, i, pw[i] - cnt, -1); // id = -1  > erase
}