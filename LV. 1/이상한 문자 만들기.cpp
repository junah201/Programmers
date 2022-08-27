#include <string>
#include <vector>

using namespace std;

bool is_english(int i)
{
    if (i >= 65 && i <= 90)
        return true;
    if (i >= 97 && i <= 122)
        return true;
    return false;
}

string solution(string s)
{
    string answer = "";
    int idx = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (!is_english(s[i]))
        {
            answer += s[i];
            idx = 0;
        }
        else if (idx % 2 == 0)
        {
            if (s[i] >= 97)
                answer += s[i] - 32;
            else
                answer += s[i];
            idx++;
        }
        else
        {
            if (s[i] >= 97)
                answer += s[i];
            else
                answer += s[i] + 32;
            idx++;
        }
    }
    return answer;
}