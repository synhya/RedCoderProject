#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size());
    stack<int> s;
    int size = prices.size();
    for (int i = 0; i < size; i++)
    {
        while (!s.empty() && prices[s.top()] > prices[i])
        {                                  // prices = [ 1, 2, 3, 1, 9]인 경우
            answer[s.top()] = i - s.top(); // answer[2] = 3 - 2; pop 2   > 1
            s.pop();                       // answer[1] = 3 - 1; pop 1   > 0
        }                                  // prices[0] 은 price[3] 보다 작지않으므로 통과
        s.push(i);                         // 감소하는 값 찾을때까지 계속 push 이경우 s = [ 0, 3 ,4]
    }
    while (!s.empty())
    {
        answer[s.top()] = size - s.top() - 1; // 끝까지 간경우에만 1 빼니까..
        s.pop();
    }
    return answer;
}