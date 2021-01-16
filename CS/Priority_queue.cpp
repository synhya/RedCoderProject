// https://www.youtube.com/watch?v=JSqznrzWGvc&t=77s

// provides Constant time lookup of the
//          *Largest or Smallest* element. O(1)
//     because it will always stay on root node

// By default vector container used inside.
// implemented using  make_heap, push_heap, pop_heap functions.

// Heap is a binary tree based on sorting nodes
//  > so for insertion uses O(log n)

#include <bits/stdc++.h>

using namespace std;

template <typename T>
void print_queue(T &q) {
    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << "\n";
}

int main() {
    priority_queue<int> q;
    for (int elm : {1, 2, 613, 435, 141, 325, 32, 125}) {
        q.push(elm);
    }
    print_queue(q);

    priority_queue<int, vector<int>, greater<int>> q2;
    // using vector as container and descending order
    for (int elm : {124, 636, 342, 153, 4, 324, 72}) {
        q2.push(elm);
    }
    // printed in ascending as it is pop()ed
    print_queue(q2);

    // pair같은 경우 cmp할때 활용가능
    auto cmp = [](int left, int right) { return (left) < (right); };
    priority_queue<int, vector<int>, decltype(cmp)> q3(cmp);
}
