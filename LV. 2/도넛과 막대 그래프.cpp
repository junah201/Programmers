#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int find(vector<int> &p, vector<int> &edge_cnt, vector<int> &vertice_cnt, int x)
{
    if (x == p[x])
        return x;

    return p[x] = find(p, edge_cnt, vertice_cnt, p[x]);
}

void merge(vector<int> &p, vector<int> &edge_cnt, vector<int> &vertice_cnt, int a, int b)
{
    a = find(p, edge_cnt, vertice_cnt, a);
    b = find(p, edge_cnt, vertice_cnt, b);

    if (a == b)
        return;

    edge_cnt[a] += edge_cnt[b];
    vertice_cnt[a] += vertice_cnt[b];
    p[b] = a;
}

vector<int> solution(vector<vector<int>> edges)
{
    // 정점 개수 구하기
    int N = 0;

    for (auto i : edges)
    {
        N = max(N, i[0]);
        N = max(N, i[1]);
    }

    // 그래프 초기화
    vector<vector<int>> graph(N + 1);
    vector<int> graph_cnt(N + 1, 0);
    vector<int> graph_cnt2(N + 1, 0);

    // 새로 만든 정점 구하기
    int new_vertice, new_vertice_cnt = -1;

    for (auto i : edges)
    {
        graph[i[0]].emplace_back(i[1]);
        graph_cnt[i[0]]++;
        graph_cnt2[i[1]]++;
    }

    for (int i = 1; i <= N; i++)
    {
        if (graph_cnt[i] > new_vertice_cnt && graph_cnt2[i] == 0)
        {
            new_vertice = i;
            new_vertice_cnt = graph_cnt[i];
        }
    }

    // 새로 만든 정점에서 연결된 간선 삭제
    graph[new_vertice].clear();
    graph_cnt[new_vertice] = 0;

    // 유니온 파인드를 위한 P 초기화
    vector<int> p(N + 1, 0), edge_cnt(N + 1, 0), vertice_cnt(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        p[i] = i;
        vertice_cnt[i] = 1;
        edge_cnt[i] = graph[i].size();
    }
    // P 계산
    for (auto i : edges)
    {
        if (i[0] == new_vertice || i[1] == new_vertice)
            continue;
        merge(p, edge_cnt, vertice_cnt, i[0], i[1]);
    }

    // 정답 출력
    vector<int> visited(N + 1, false);

    vector<int> answer(4, 0);
    answer[0] = new_vertice;

    for (int i = 1; i <= N; i++)
    {
        if (i == new_vertice)
            continue;
        int x = find(p, edge_cnt, vertice_cnt, i);
        // printf("i:%lld, x:%lld\n", i, x);

        if (visited[x])
            continue;
        visited[x] = true;
        // printf("x:%lld  i:%lld : e %lld v %lld", x, i, edge_cnt[x], vertice_cnt[x]);
        if (edge_cnt[x] == vertice_cnt[x])
        {
            // printf(" 도넛\n");
            answer[1]++;
        }
        else if (edge_cnt[x] == vertice_cnt[x] - 1)
        {
            // printf(" 막대\n");
            answer[2]++;
        }
        else
        {
            // printf(" 8자\n");
            answer[3]++;
        }
    }

    return answer;
}