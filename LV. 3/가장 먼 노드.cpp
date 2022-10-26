#include <vector>
#include <queue>
#include <stdio.h>
using namespace std;

vector<int> dist;
vector<vector<int>> graph;
int max_dis;

void bfs()
{
    queue<pair<int, int>> q;
    q.push({1, 0});
    dist[1] = 0;

    while (!q.empty())
    {
        auto [idx, dis] = q.front();
        q.pop();

        for (const auto &next : graph[idx])
        {
            if (dist[next] > dis + 1)
            {
                dist[next] = min(dist[next], dis + 1);
                q.push({next, dist[next]});
                max_dis = max(max_dis, dist[next]);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge)
{
    graph.resize(n + 1);
    dist.resize(n + 1, 987654321);
    for (auto i : edge)
    {
        graph[i[0]].push_back(i[1]);
        graph[i[1]].push_back(i[0]);
    }

    bfs();
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == max_dis)
            ans++;
    }
    return ans;
}