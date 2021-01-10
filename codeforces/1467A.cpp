#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    vector<unsigned long long> answer(t);

    vector<unsigned long long> n(t);

    for (int i = 0; i < t; i++)
    {
        std::cin >> n[i];
    }

    int k;
    bool reverse;
    for (int i = 0; i < t; i++)
    {
        k = 0;
        reverse = false;
        for (; n[i] > 0; n[i]--)
        {
            if (k > 9)
            {
                k = 1;
                if (!reverse)
                {
                    reverse = true;
                }
                else
                {
                    reverse = false;
                }
            }

            if (!reverse)
            {
                answer[i] += pow(10, n[i] - 1) * (9 - k);
            }
            else
            {
                answer[i] += pow(10, n[i] - 1) * (k);
            }
            k++;
        }
    }

    for (int i = 0; i < t; i++)
    {
        std::cout << answer[i] << "\n";
    }
}