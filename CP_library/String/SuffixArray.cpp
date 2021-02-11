#include <bits/stdc++.h>
using namespace std;
#define MN 500000
// for example in 'banana'
// SA[i]  suffix   index
//  5       a        0
//  3      ana       1
//  1     anana      2
//  0     banana     3
//  4       na       4
//  2      nana      5
//
// for memory save. save idx of string like above.

// How to make. use Manber-Myers algorithm
// 같은 알파벳끼리 그룹으로 묶고

vector<int> getSA(string s) {
    int t = 1;
    int n = s.length();
    vector<int> SA(n), g(n + 1), tg(n);
    for (int i = 0; i < n; i++) {
        SA[i] = i;
        g[i] = s[i] - 'a';
    }
    auto cmp = [&](int x, int y) -> bool {
        if (g[x] == g[y]) // same alphabet(same g[])
            return g[x + t] < g[y + t];
        else
            return g[x] < g[y];
    };
    while (t <= n) {
        g[n] = -1;
        sort(SA.begin(), SA.end(), cmp);
        tg[SA[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (cmp(SA[i - 1], SA[i])) // if different alphabet
                tg[SA[i]] = tg[SA[i - 1]] + 1;
            else
                tg[SA[i]] = tg[SA[i - 1]];
        }
        for (int i = 0; i < n; i++)
            g[i] = tg[i];
        t <<= 1; // log n
    }
    return SA;
}
int main() {
    string s;
    cin >> s;
    vector<int> sa = getSA(s);
}