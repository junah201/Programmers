#include <vector>

using namespace std;

int answer = 0;
// 1 : 괄호 열기
// 0 : 괄호 닫기

void dfs(int idx, int s[50], int n, int open, int close)
{
    if (idx == n)
    {
        if (open == close)
            answer++;
        return;
    }
    if (idx == 0)
    {
        s[idx] = 1;
        dfs(idx + 1, s, n, open + 1, close);
        return;
    }

    if (close < open)
    {
        s[idx] = 0;
        dfs(idx + 1, s, n, open, close + 1);
    }

    if (open < n / 2)
    {
        s[idx] = 1;
        dfs(idx + 1, s, n, open + 1, close);
    }
}

int solution(int n)
{
    int s[50];
    dfs(0, s, n * 2, 0, 0);

    return answer;
}