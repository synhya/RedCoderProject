#include <bits/stdc++.h>
using namespace std;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, _xor = 0, d, f = 1;
    cin >> n;
    while (n--) {
        cin >> d;
        f &= d == 1; // 1 로만 이루어져 있는가..?
        _xor ^= d;
    }
    cout << ((f && !_xor) || (!f && _xor) ? "koosaga" : "clublover");
    // 1로만 이루어져있지 않은경우. 불균형 상태라면 1을 제외한 균형상태로 만들어 줄 수 있다..

    // 1이 몇개인지 세줄게 아니라 1로만 이루어져있는지 확인하는 문제..
    return 0;
}