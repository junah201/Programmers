#include <bits/stdc++.h>
using namespace std;

int N, M;

int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
    N = board.size();    // y
    M = board[0].size(); // x

    for (auto cmd : skill)
    {
        int type = cmd[0];
        int x1 = cmd[1];
        int y1 = cmd[2];
        int x2 = cmd[3];
        int y2 = cmd[4];
        int degree = cmd[5];

        if (type == 1)
        {
            for (int x = x1; x <= x2; x++)
            {
                for (int y = y1; y <= y2; y++)
                    board[y][x] += degree;
            }
        }
    }

    int answer = 0;
    return answer;
}