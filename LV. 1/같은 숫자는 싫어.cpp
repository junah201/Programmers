#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int last_number = 999;

    for (auto i : arr)
    {
        if (i != last_number)
        {
            last_number = i;
            answer.push_back(i);
        }
    }

    return answer;
}