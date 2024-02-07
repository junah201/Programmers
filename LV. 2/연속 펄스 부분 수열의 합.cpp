#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> sequence)
{
    vector<long long> sequence_m(sequence.size());
    vector<long long> sequence_p(sequence.size());
    vector<long long> sum_m(sequence.size());
    vector<long long> sum_p(sequence.size());

    long long ans = -9223372036854775807ll;

    for (size_t i = 0; i < sequence.size(); i++)
    {
        if (i % 2 == 0)
        {
            sequence_m[i] = -sequence[i];
            sequence_p[i] = sequence[i];
        }
        else
        {
            sequence_m[i] = sequence[i];
            sequence_p[i] = -sequence[i];
        }

        ans = max({ans, sequence_m[i], sequence_p[i]});
    }

    sum_m[0] = sequence_m[0];
    sum_p[0] = sequence_p[0];

    for (size_t i = 1; i < sequence.size(); i++)
    {
        if (sum_m[i - 1] >= 0)
            sum_m[i] = sum_m[i - 1];
        sum_m[i] += sequence_m[i];

        if (sum_p[i - 1] >= 0)
            sum_p[i] = sum_p[i - 1];
        sum_p[i] += sequence_p[i];

        ans = max({ans, sum_m[i], sum_p[i]});
    }

    return ans;
}