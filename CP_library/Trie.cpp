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
            // for abc, abd .. pref[2] = 2;
        }
        end[cur]++;
    }
    void erase(string s) {
        int cur = 0;
        for (char c : s) {
            int &nxt = to[cur][c - norm];
            cur = nxt, pref[cur]--;
            if (pref[cur] == 0)
                nxt = 0;
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
    /*
    int query(string s) {
        int cur = 0, ret = 0;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - norm;
            if (to[cur][!c] != 0) // can xor
                ret += 1 << (s.size() - 1 - i), cur = to[cur][!c];
            else
                cur = to[cur][c];
        }
        return ret;
    }
    */
};

// to string method..  using ! two times..for onedigiting
string to_str(int x) {
    string ret;
    for (int i = 0; i < 31; i++)
        ret += ('0' + !!(x & 1 << (30 - i)));
    return ret;
}