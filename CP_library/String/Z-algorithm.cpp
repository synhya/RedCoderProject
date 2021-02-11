#include <bits/stdc++.h>
using namespace std;
// confusing ; check https://www.youtube.com/watch?v=CpZh4eF8QBw

// Z(k) == the max length` of substring
//      that starts from idx k` which is
//      prefix of the main string.

// main idea is DP, reuse of Z array (PATTERN MATCHING)

//      a a b x a a b c d e
// Z(k) 0 1 0 0 2 1
// for example) Z(4) = 2 so.
// S.substr(4,2) = a a is max string
// that starts in k(4) and is
// prefix of a a b x a a b c d e. !

int main() {
    string s;
    int n = s.size();
    int L = 0, R = 0;
    vector<int> Z(n);
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R - L] == s[R])
                R++;
            Z[i] = R - L;         //    a b c x a b c x w c a b c x a b c x a b f
            R--;                  // Z  0 0 0 0 4 0 0 0 0 0 8 0 0 0 6 0 0 0 2 0 0
                                  // R  - 0 1 2 7 7 7 7 7 8 1717171719191919191919
        } else {                  // L  0 1 2 3 4 4 4 4 8 9 1010101014141414181819
            int k = i - L;        // k            1 2 3       1 2 3   1 2 3   1
            if (Z[k] < R - i + 1) //  Z[k](4) + i(14) > R(17). and Z[k](4) + i(18) > R(19)
                Z[i] = Z[k];      // the copying process
            else {
                L = i; // 18 !<= 17 >> find new pattern from R(17)
                while (R < n && s[R - L] == s[R])
                    R++;
                Z[i] = R - L; //
                R--;
            }
        }
    }

    //Application
    int maxz = 0, res = 0;
    for (int i = 1; i < n; i++) {
        if (Z[i] == n - i && maxz >= n - i) {
            res = n - i;
            break;
        }
        maxz = max(maxz, Z[i]);
    }
}