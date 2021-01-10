#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int w;
    string r;
    std::cin >> w;
    if (w % 2 == 0 && w != 2)
    {
        if ((w - 2) % 2 == 0)
        {
            r = "YES";
        }
    }
    else
    {
        r = "NO";
    }
    std::cout << r;
}