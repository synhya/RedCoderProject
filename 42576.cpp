#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    unordered_map<string, int> strMap;
    for (auto elem : completion)
    {
        if (strMap.end() == strMap.find(elem)) // if no elem
            strMap.insert(make_pair(elem, 1));
        else
            strMap[elem]++; // same element? > +1
    }

    for (auto elem : participant)
    {
        if (strMap.end() == strMap.find(elem))
        {
            answer = elem; // cant find in completion
            break;
        }
        else
        {
            strMap[elem]--;
            if (strMap[elem] < 0)
            {
                answer = elem; // same name several times
                break;
            }
        }
    }

    return answer;
}