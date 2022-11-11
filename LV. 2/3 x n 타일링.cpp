long long DP[5002];

long long f(int idx)
{
    if (idx % 2 == 1)
        return 0;
    if (idx == 0)
        return 1;
    else if (idx == 2)
        return 3;
    else if (idx == 4)
        return 11;
    else if (DP[idx] == 0)
    {
        DP[idx] = 3 * f(idx - 2);
        DP[idx] %= 1000000007;
        for (int i = idx; i >= 4; i -= 2)
        {
            DP[idx] += 2 * f(idx - i);
            DP[idx] %= 1000000007;
        }
    }
    return DP[idx];
}

int solution(int n)
{
    return (int)f(n);
}