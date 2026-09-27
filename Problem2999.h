//
// Created by Fengwei Zhang on 9/25/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM2999_H
#define LEETCODESOLUTIONSINCPP_PROBLEM2999_H

#include <string>
#include <algorithm>

using namespace std;

class Problem2999
{
public:
    long long numberOfPowerfulInt(long long start,
                                  long long finish,
                                  int limit,
                                  const string &s)
    {
#define PROBLEM2999_NUM_MAX_LENGTH (15)

        /* 预计算 (limit + 1) 的整数次幂 */
        size_t limitPower[PROBLEM2999_NUM_MAX_LENGTH + 1];

        limitPower[0] = 1;
        for (int i = 1; i <= PROBLEM2999_NUM_MAX_LENGTH; ++i)
            limitPower[i] = limitPower[i - 1] * (limit + 1);

        return (long long)(myCalculator(finish, (size_t)limit, limitPower, s) -
                           myCalculator(start - 1, (size_t)limit, limitPower, s));

#undef PROBLEM2999_NUM_MAX_LENGTH
    }

private:
    /* 统计[0:num]内powerful integer的个数 */
    size_t myCalculator(size_t num,
                        size_t limit,
                        const size_t *limitPower,
                        const string &s)
    {
        const string &numStr = to_string(num);

        /* 若num小于s，直接返回0 */
        if (numStr.length() < s.length())
            return 0;

        /* 若num等于s，直接返回1 */
        if (numStr.length() == s.length())
            return numStr >= s ? 1 : 0;
        
        size_t answer = 0;
        int prefixLength = (int)(numStr.length() - s.length());

        /*
        ** 枚举所有长度为（numStr.length() - s.length()）的
        ** 各位不大于limit的，且各位不大于num中对应位的整数
        */
        for (int i = 0; i < prefixLength; ++i)
        {
            int x = (int)(numStr[i] - '0');
            int remaining = prefixLength - i - 1;

            if (x > limit)
            {
                answer += limitPower[remaining + 1];
                return answer;
            }
            else
                answer += x * limitPower[remaining];
        }

        if (numStr.compare(prefixLength, s.length(), s) >= 0)
            ++answer;

        return answer;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM2999_H
