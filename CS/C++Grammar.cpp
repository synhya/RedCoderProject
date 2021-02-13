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

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.first + a.second > b.second + b.second;
    }
}; // pq같은거 생성시에 compare 은 struct 쓰자.

struct Node {
    Node *c[2];
    int cnt;

    Node() : c{0, 0}, cnt(0) {}
}; // 자기참조 구조체.. linked  list 같은거 만들떄 용이.

int main() {
    //
    int cnt = x >> 3 & 1; // (3+1)번쨰 자리 1,0 가져오기. (3칸 오른쪽이동하니까)
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
    double x = 1;
    cout << fixed << setprecision(6) << x;
    // 소수점 6자리까지.. 1.000000
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

    // char(5) 가 53이라고 하자 char(0)은 48이다..!!!
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

    int r = upper_bound(v.begin(), v.end(), v[i] + k) - v.begin();
    // trick to get the index from iterator directly.. -v.begin();
    // instead we can simply use distance function
    int R = distance((c).begin(), upper_bound(all(c), (x)));

    // when finding min in 3 elements or more (w/o using min_element func)
    // need to use braces .
    int t = min({1, 3, 4}); // min(1,3,4) will occur error

    return cout << "No\n", 0; // returns 0, prints No

    // UNIQUE 함수.// 1 2 2 2 3 3 1 3 2 2 >>> 1 2 3 1 3 2 ... 바로옆의 중복제거.
    // 키의 중복을 허용하지않는 set과는 다른 개념이다!
    unique(v.begin(), v.end());
    int n = unique(a.begin(), a.end()) - a.begin();
    a.resize(n); // unique함수 사용후 재배열시 이렇게함. 1 2 3 1 3 2

    int n = 10;
    vi stak;
    vi a(n);
    if (stak.empty() || a[0] > a[stak.back()]) // no error
        cout << 4 << endl;
    if (a[0] > a[stak.back()])
        cout << 56 << endl; // error

    assert(!v.empty()); // v 가 비어있으면 자동 멈춤! 디버깅용 ( assertion failed )

    function<vector<int>(int)> rec = [&](int i) -> vi {}; // 함수선언방식.
    // auto rec방식으로 선언시에는 재귀함수만들수없음!

    rep(i, h - 1) rep(j, w - 1) {
        if (s[i][j] ^ s[i][j + 1] ^ s[i + 1][j] ^ s[i + 1][j + 1])
            ans++;
    } // grid of '.' and '#'
    // usage of bit operation.. 짝수게 같으면 0. 홀수개같으면 true.

    vi a = {1, 2, 3};
    auto it = find(all(a), 1);
    if (it != a.end()) {
        *it = 100;
    }
    cout << a[0];
    // iter로 값변경가능..

    s.substr(2, 4); // [pos, pos + count)
        // 2에서 3이아니라 2 에서 2+4) 즉 5까지 반환.

    const auto rec = [&](auto &&rec, int v) {};
    //이렇게하면 재귀함수 편하게사용가능.

    int *a; // ok it can be null
    int &b; // it cant be null. define when initialize. > MORE SAFE
    //자바의 타입스크립트처럼 제약사항으로 안정성 UP

    int &&c = 1; // 우측값 참조.. 원래 복사되고 바로 파괴 되는 우측값을.
    // 자주써야하는경우 이렇게 유지시켜준다..
    int b = 1;
    int d = 1; // 1 , 1 둘다 복사, 파괴(임시값) 반복.
    //
    int b = c;
    int d = c; // 복사,파괴안하고 참조값처럼 우측값을 이용한다.
    // >> 퍼포먼스 상승
}
struct test {
    static constexpr int INF = 1e9 + 7;
    // static:객체를 생성하건 생성하지 않건, 메모리 공간에 하나만 할당이 되어서 공유되는 변수
};
