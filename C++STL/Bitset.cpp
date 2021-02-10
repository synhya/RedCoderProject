#include <bits/stdc++.h>
using namespace std;

int main() {
    bitset<30> s(15);      // 10진수 > 2 bit
    cout << s << endl;     // 000000000000000000000000001111
    int n = s.to_ullong(); // 15
    if (s.all())
        cout << "all 1" << endl;
    if (s.any())
        cout << "at least 1" << endl;
    if (s.none())
        cout << "all 0" << endl;

    bool all = !!n; // s.any 같이 쓰던방식
    cout << s.count() << endl;
}