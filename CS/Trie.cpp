// 정수형이 아닌 문자열의 검색에 걸리는ㅅ시간은
// 트리에서 o(s.lenght() * log n) 이 걸린다.
// 이를 o(m.length()) 로 바꾸기 위한구조.
// 여기서 m은 찾고자하는 문자열이다.

// 핵심은 max.length * 26개 노드를 가진,
// 각각의 부모가 26개 자식을 가진 트리

// 구현.
#include <bits/stdc++.h>
using namespace std;
int N = maxString.length(); // N is max length of element of string array * numberof input string.
vector<vector<int>> next(N, vector<int>(26, -1));
// 모든 상위트리노드가 26개 알파벳 child갖는다고 가정.
int C = 1; // find child
for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int cur = 0;
    for (char c : s) {
        int v = c - 'a';
        if (next[cur][v] == -1) {
            next[cur][v] = C++; // child info.
        }
        //      aab              ac          bc       input.
        // c[0][0] = 1;       continue;   c[0][1] = 5;
        // c[1][0] = 2;     c[1][2] = 4;  c[5][2] = 6;
        // c[2][1] = 3;
        cur = next[cur][v];
    }
}
// IsLeaf Method
for (int i = C - 1; i >= 0; i--) {
    bool isLeaf = true;
    for (int v = 0; v < 26; v++) {
        if (next[i][v] != -1)
            // 모든 노드 순회시에 초기값인지만 확인하면된다.!
            isLeaf = false; // no child
    }
    if (isLeaf) {
        // do sth.
    }
}
//