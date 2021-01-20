#include <bits/stdc++.h>
using namespace std;
// difference between set, multiset
// Sorted set of Multiple objects of key.
// when just set can have one object for each key.
// as it is set it also uses red black tree(BST)

// when using user define obj > needs to put cmp function first
class Human {
public:
    int age;
    string name; //rhs = right hand side. and lhs.
    bool operator<(const Human &rhs) const { return age < rhs.age; }
    bool operator>(const Human &rhs) const { return age > rhs.age; }
};

int a[2020];
int main() {
    multiset<Human, greater<>> mhuman = {{24, "me"}, {30, "me2"}};
    for (auto &e : mhuman) {
        cout << e.age << " " << e.name << '\n';
    }
    cout << '\n';
    multiset<int> mset = {6, 5, 3, 3, 2, 7, 1, 8, 3};
    mset.insert(10);
    //mset.push(20); no push
    for (auto &e : mset) {
        cout << e << ' '; //1 2 3 3 3 5 6 7 8 10
    }
    cout << '\n';
    multiset<int, greater<int>> mset2 = {6, 5, 3, 3, 2, 7, 1, 8, 3};
    // as sorted array can use cmp function when initializing
    for (auto &e : mset2) {
        cout << e << ' '; //8 7 6 5 3 3 3 2 1
    }
    cout << '\n';
    set<int> set = {6, 5, 3, 3, 2, 7, 1, 8, 3};
    for (auto &e : set) {
        cout << e << ' '; //1 2 3 5 6 7 8
    }
    cout << '\n';

    for (int i = 0; i < 10; i++)
        scanf("%d", a + i);
    multiset<int> S(a, a + 10); //배열이대로 받기도 가능!
    for (auto &e : S) {
        cout << e << endl;
    }

    vector<int> a;
    a.resize(10);
    iota(a.begin(), a.end(), 0);
    multiset<int> s(a.begin(), a.end()); // 벡터등은 iterator사용해서 !
    for (auto e : s) {
        cout << e << " ";
    }
}