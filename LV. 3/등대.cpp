#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> light;

int solution(int n, vector<vector<int>> lighthouse)
{
    graph.resize(n + 1);
    light.resize(n + 1, 0);

    for (auto i : lighthouse)
    {
        graph[i[0]].push_back(i[1]);
        graph[i[1]].push_back(i[0]);
    }
    // 끝 쪽에 있는 등대는 무조건 키기
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (graph[i].size() == 1)
        {
            for (auto j : graph[i])
            {
                light[j] = 2;
                // printf("%d\n", j);
                for (auto k : graph[j])
                {
                    light[k] = max(1, light[k]);
                    q.push(k);
                }
            }
        }
    }
    // 기존 켜진 등대에서 2칸 씩 이동하면 최선의 선택을 함
    while (!q.empty())
    {
        int idx = q.front();
        q.pop();
        int cnt = 0;
        for (auto i : graph[idx])
        {
            if (light[i] == 0)
            {
                for (auto j : graph[i])
                {
                    if (light[j] == 0)
                    {
                        light[j] = 2;
                        for (auto k : graph[i])
                        {
                            light[k] = max(1, light[k]);
                            q.push(k);
                        }
                    }
                }
            }
        }
    }
    int answer = 0;
    for (auto i : light)
    {
        printf("%d\n", i);
        if (i == 2)
            answer++;
    }
    return answer;
}