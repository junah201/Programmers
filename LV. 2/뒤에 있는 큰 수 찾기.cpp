#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    stack<int> s;
    vector<int> answer(numbers.size(), -1);

    printf("%d %d\n", numbers.size(), 0);

    for (int i = numbers.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= numbers[i])
            s.pop();
        if (s.empty())
            answer[i] = -1;
        else
            answer[i] = s.top();
        s.emplace(numbers[i]);
    }

    return answer;
}

int main()
{
    auto i = solution({2, 3, 3, 5});
    for (int j : i)
    {
        printf("%d ", j);
    }
    return 0;
}