bool checkAnticlockwise(pi p1, pi p2, pi p3) {
    return (1LL * p3.first * p1.second + p2.first * p3.second + p1.first * p2.second >
            1LL * p3.first * p2.second + p2.first * p1.second + p1.first * p3.second);
}
// 반시계면 추가. 아니면 p2를 뺀다.

pi st = {inf, inf}; // 시작노드기준 기울기.
bool comp(pi p1, pi p2) {
    ll a = 1LL * (p1.second - st.second) * (p2.first - st.first);
    ll b = 1LL * (p2.second - st.second) * (p1.first - st.first);
    if (a != b)
        return a < b;
    if (p1.first != p2.first)
        return p1.first < p2.first;
    return p1.second < p2.second;
}
// 기울기순으로 정렬할때 나누기를 쓰면 안된다.. 이렇게 풀어서 쓰자.

// example.
sort(p.begin() + 1, p.end(), comp);
vi stk;
stk.push_back(0);
stk.push_back(1);
int nxt = 2;
while (nxt < n) { // except start
    while (stk.size() >= 2) {
        // 사이즈가 2가 될떄까지 돌아가면서
        // 재확인 해야함을 잊지말자!!!
        int p2 = stk.back();
        stk.pop_back();
        int p1 = stk.back();
        if (checkAnticlockwise(p[p1], p[p2], p[nxt]) > 0) {
            stk.push_back(p2);
            break;
        }
    }
    stk.push_back(nxt);
    nxt++;
}