#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    stack<bool> stk;

    int len = s.length();

    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(')
        {
            stk.push(1);
        }
        else
        {
            if (stk.empty())
                return false;
            stk.pop();
        }
    }
    if (!stk.empty())
        return false;
    return true;
}