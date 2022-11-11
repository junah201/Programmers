int N, is_print, cnt, idx;
int map[15][15];

int check(int x, int y)
{
    int temp_x, temp_y;
    // ↓
    temp_y = 0;
    while (temp_y < N)
    {
        if (map[temp_y][x] == 1)
            return 0;
        temp_y++;
    }
    // →
    temp_x = 0;
    while (temp_x < N)
    {
        if (map[y][temp_x] == 1)
            return 0;
        temp_x++;
    }
    // ↘
    temp_x = x;
    temp_y = y;
    while (temp_x < N && temp_y < N)
    {
        if (map[temp_y][temp_x] == 1)
            return 0;
        temp_x++;
        temp_y++;
    }
    // ↖
    temp_x = x;
    temp_y = y;
    while (temp_x >= 0 && temp_y >= 0)
    {
        if (map[temp_y][temp_x] == 1)
            return 0;
        temp_x--;
        temp_y--;
    }
    //↙
    temp_x = x;
    temp_y = y;
    while (temp_x >= 0 && temp_y < N)
    {
        if (map[temp_y][temp_x] == 1)
            return 0;
        temp_x--;
        temp_y++;
    }
    //↗
    temp_x = x;
    temp_y = y;
    while (temp_x < N && temp_y >= 0)
    {
        if (map[temp_y][temp_x] == 1)
            return 0;
        temp_x++;
        temp_y--;
    }
    return 1;
}

int placed(int y)
{
    for (int x = 0; x < N; x++)
    {
        if (map[y][x] == 1)
            return 1;
    }
    return 0;
}

int f(int x, int y, int stack)
{
    if (stack == N)
    {
        cnt++;
        return 0;
    }
    if (x >= N)
    {
        if (placed(y))
            f(0, y + 1, stack);
        return 0;
    }
    if (y >= N)
        return 0;
    if (check(x, y))
    {
        map[y][x] = 1;
        f(0, y + 1, stack + 1);
        map[y][x] = 0;
    }
    f(x + 1, y, stack);
    return 0;
}

int solution(int n)
{
    N = n;
    f(0, 0, 0);
    return cnt;
}
