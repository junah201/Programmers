#include <bits/stdc++.h>
using namespace std;

int N, ans = -1;
int visited[200002];
vector<vector<int>> graph;

void dfs(int idx, int cnt)
{
    ans = max(ans, cnt);
    for (auto next : graph[idx])
    {
        if (visited[next] == 0)
        {
            visited[next]++;
            dfs(next, cnt + 1);
            visited[next]--;
        }
        else if (visited[next] == 1)
        {
            visited[next]++;
            dfs(next, cnt);
            visited[next]--;
        }
    }
}

int solution(vector<vector<int>> t)
{
    N = t.size();
    graph.resize(N + 1);
    for (auto i : t)
    {
        graph[i[0]].push_back(i[1]);
        graph[i[1]].push_back(i[0]);
    }

    for (int i = 0; i < N; i++)
    {
        memset(visited, 0, N + 1);
        visited[i] = 1;
        dfs(i, 1);
    }
    return ans;
}