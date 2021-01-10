#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    vector<int> n(t);
    vector<int> a(t);
    for (int i = 0; i < t; i++)
    {
        std::cin >> n[i];
        for (int j = 0; j < n[i]; j++)
        {
            std::cin >> a[i];
        }
    }
}