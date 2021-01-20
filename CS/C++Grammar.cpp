#include <bits/stdc++.h>
using namespace std;

constexpr N = 500 * 1000 + 7;
// const > 런타임시 오류. constexpr 컴파일시 오류
int x = 1LL << 5; // 2^5 곱하기. 즉 비트 왼쪽으로 5칸.

ll test[10][10]; // 메인함수 바깥에서 생성하면 0으로 자동 초기화

class Human {
public:
    int age;
    string name; //rhs = right hand side. and lhs.
    bool operator<(const Human &rhs) const { return age < rhs.age; }
    bool operator>(const Human &rhs) const { return age > rhs.age; }
}; // bool 연산자 정의시 const 두번 꼭 쓰자..

int main() {
    //
    int cnt = x >> 3 & 1; // 3+1번쨰 자리 1,0 가져오기. (3칸 오른쪽이동하니까)
    int exp[10]{};
    for (int i = 0; i < 10; i++) {
        exp[i] = 10000 >> i & 1;
    }
    //
    iota(p.begin(), p.end(), 0); // p벡터를 시작점(0)부터 1씩 증가시킨다.. 0,1,2,3,4....
    //
    string test = "test";
    cout << t[0] << endl;
    cout << &t[0] << endl; // 문자열 그대로 반환
    //
    string ins = "test+";
    int j = 5;
    if (ins[j] == '+') {
    } // fine
    if (ins[j] == "+") {
    } // error
    //
    std::cout << std::fixed << std::setprecision(10) << L << "\n";
    // setprecision(10) 소수점 10까지 ,, fixed 정수형이여도..
    // ex) L = 14 >>> 14.0000000000
    //
    struct edge {
        int u, v, w;
    } e[M];
    bool operator<(const edge &a, const edge &b) {
        return a.w < b.w;
    } // 연산자 오버로딩.

    priority_queue<pair<int, int>> h;
    h.emplace(0, 0);
    h.push(pair<int, int>(0, 0));
    // pair같은경우 emplace가 더 깔끔하다.
    // vector > emplace_back, deque > emplace_front

    for (int i = 0; i < 10; i++) {
        cout << i << " \n"[i == n - 1];
    } // 마지막에서만 newline 그때까진 space 우아한표현

    int u = x / 4;     // bit operation
    int p = x / 2 % 2; // p and q for min and max respectively
    int q = x % 2;
    // 비트연산자를 이용해 if x = 1101(2)
    // > u = 11(2)  p = 0(2)   q = 1(2) ; from 1473E
    x = u * 4 + p * 2 + q;

    //j 와 i의 and값에 들어있는 1의 갯수를 반환한다.
    s[j] = "AB"[__builtin_popcount(j & i) % 2];

    cout << ('5' - '0') << endl; // 계산 가능하다.. 5반환.
    cout << ('0' - '0') << endl; // char끼리 계산해서 int반환해준다.
    string t += '0' + 1;         // 이런식으로 char로 변환도 가능하다.

    vector<int> used((1 << 5));     // 100000
    used[((1 << 5) - 1) ^ cur] = 1; // 11111 (letters of 5) ^ cur

    int lg = __lg(n) + 1; // 로그함수.

    for (int i = 10; i--;) {
        cout << i << " ";
    } // 가운데 넣으면 계산하고시작하겠지.
      // > 9 8 7 6 5 4 3 2 1 0
}
struct test {
    static constexpr int INF = 1e9 + 7;
    // static:객체를 생성하건 생성하지 않건, 메모리 공간에 하나만 할당이 되어서 공유되는 변수
};
