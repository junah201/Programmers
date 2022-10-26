/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;

struct xy
{
    int x;
    int y;
    bool x_start;
    bool y_start;
    int idx;
};

struct compare
{
    bool operator()(const xy &a, const xy &b)
    {
        if (a.x != b.x)
            return a.x > b.x;
        if (a.y != b.y)
            return a.y > b.y;
        return a.idx > b.idx;
    }
};

//           x,  y,   x start, y start,  point index
priority_queue<xy, vector<xy>, compare> points;

xy points_top()
{
    if (points.empty())
    {
        xy tmp;
        tmp.idx = -1;
        return tmp;
    }

    xy first = points.top();
    points.pop();

    if (!points.empty())
    {
        xy second = points.top();

        if (first.x == second.x && first.y == second.y && first.x_start != second.x_start && first.y_start == second.y_start)
        {
            points.pop();
            return points_top();
        }
    }
    return first;
}

long long solution(vector<vector<int>> rectangles)
{
    long long answer = 0;

    for (int i = 0; i < rectangles.size(); i++)
    {
        int sx = rectangles[i][0];
        int sy = rectangles[i][1];
        int ex = rectangles[i][2];
        int ey = rectangles[i][3];
        // top start
        points.push({sx, sy, true, true, i});
        // bottom start
        points.push({sx, ey, true, false, i});
        // top end
        points.push({ex, sy, false, true, i});
        // bottom end
        points.push({ex, ey, false, false, i});
    }

    while (!points.empty())
    {
        // same_x에 값을 넣기
        vector<xy> same_x;
        same_x.push_back(points_top());

        // 종료 조건
        if (points.empty() || same_x.front().idx == -1)
            break;

        int now_x = same_x.front().x;

        while (!points.empty())
        {
            if (points.top().x != now_x)
                break;
            same_x.push_back(points_top());
        }

        // 가로 dis 미리 구해두기
        int next_x = -1;
        if (!points.empty())
            next_x = points.top().x;

        // 다음 x로 현재 x값 이동 시키기
        if (next_x != -1)
        {
            for (int i = 0; i < same_x.size(); i++)
            {
                xy tmp = same_x[i];
                tmp.x = next_x;
                points.push(tmp);
            }
        }

        // 세로 dis들을 스택을 이용해서 구하기
        stack<xy> s;
        vector<int> dis;

        for (int i = 0; i < same_x.size(); i++)
        {
            xy a = same_x[i];
            if (!s.empty() && s.top().y_start == true && a.y_start == false)
            {
                if (s.size() == 1)
                    dis.push_back(a.y - s.top().y);
                s.pop();
            }
            else
                s.push(a);
        }

        // 구한 dis를 이용해서 넓이 더하기
        for (auto i : dis)
        {
            answer += i * (next_x - now_x);
        }
    }

    return answer;
}

int main()
{
    int N;
    scanf("%d", &N);
    vector<vector<int>> v;
    while (N--)
    {
        vector<int> tmp;
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        tmp.push_back(a);
        tmp.push_back(b);
        tmp.push_back(c);
        tmp.push_back(d);
        v.push_back(tmp);
    }
    printf("%lld", solution(v));
    return 0;
}