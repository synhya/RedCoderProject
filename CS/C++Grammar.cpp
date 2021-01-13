#include <bits/stdc++.h>
using namespace std;

constexpr N = 500 * 1000 + 7;
// const > 런타임시 오류. constexpr 컴파일시 오류
int x = 1LL << 5; // 2^5 곱하기. 즉 비트 왼쪽으로 5칸.

int main()
{
    // 1.
    int cnt = x >> 3 & 1; // 3+1번쨰 자리 1,0 가져오기. (3칸 오른쪽이동하니까)
    int exp[10]{};
    for (int i = 0; i < 10; i++)
    {
        exp[i] = 10000 >> i & 1;
    }
    // 2.
    iota(p.begin(), p.end(), 0); // p벡터를 시작점(0)부터 1씩 증가시킨다.. 0,1,2,3,4....
}