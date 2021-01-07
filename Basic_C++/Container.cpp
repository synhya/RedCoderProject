#include <iostream>
#include <array>
#include <vector>
using namespace std;
//Array
// Syntax: std::array<T, N> array;  (input parameters)
// for example cin >> N ;  and use it as length

// Assign by value ( Doesnt send pointer! )
// myarray.at() has exception while myarray[] will return garbage value

//Vector
// Syntax: std::vector<T> vector;
// Also known as Dynamic array or array list . Array ans List useage
// >> array for faster access, literally just fetches data
// size fixed > array , dynamic size > list
// vector added fast and dynamic features both in same container

// vector.push_back(10); adds 10 to array but when there is no capacity
// vector DOUBLES size of the array already created and
// start to point the new array
// Double sizing would go like 3 > 6 > 12 > 24..

//
int main()
{
    // Declare
    std::array<int, 5> myarray;
    // Initialization
    myarray = {1, 2, 3};
    std::array<int, 5> myarray2{1, 2, 3}; // uniform initailization

    vector<int> Vec = {100, 2, 3, 4};
    vector<int> VecCopy = Vec;
    VecCopy.pop_back();
    cout << Vec.back() << endl;
    cout << VecCopy.back() << endl;
    // vector is also Assigned by value
}