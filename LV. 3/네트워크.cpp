#include <vector>

using namespace std;

int check[202];

void bfs(int idx, int n, vector<vector<int>> computers)
{
    check[idx] = 1;
    for (int i = 0; i < n; i++)
    {
        if (computers[i][idx] == 0 || idx == i || check[i] == 1)
            continue;
        bfs(i, n, computers);
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        if (check[i])
            continue;
        answer++;
        bfs(i, n, computers);
    }

    return answer;
}