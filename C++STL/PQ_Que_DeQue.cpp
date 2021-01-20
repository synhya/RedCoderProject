#include <iostream>
#include <queue>
using namespace std;

// deq = DOUBLE ENDED QUEUE can push and pop from front and end
// que = push from end pop from front
// pq = if push sort in asc pop from back

// vector = one array <> deque = linked mutiple array(fixedsize)
int main() {
    queue<int> que;
    priority_queue<int> pq;
    deque<int> deq;
    for (int i = 0; i < 10; i++) {
        que.push(i);
        pq.push(i);
    }

    for (int i = 0; i < 9; i++) {
        cout << que.front() << " \n"[i == 8]; // 0 1 2 3 4 5 6 7 8
        que.pop();                            // deletes from `front`
    }
    for (int i = 0; i < 9; i++) {
        cout << pq.top() << " \n"[i == 8]; // 9 8 7 6 5 4 3 2 1
        pq.pop();                          // deletes from `top`
    }
    que.push(10232);            // 햇갈리지말자 pop만 다르지 push는 같다.
    cout << que.back() << endl; // remember its FIFO but pq(asc default) is not
}