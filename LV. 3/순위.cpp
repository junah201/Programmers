#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results)
{
    vector<vector<int>> graph(n + 1);

    for (auto i : results)
    {
        graph[i[0]].push_back(i[1]);
    }

        int answer = 0;
    return answer;
}