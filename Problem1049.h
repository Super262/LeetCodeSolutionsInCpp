//
// Created by Fengwei Zhang on 9/9/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1049_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1049_H

#include <vector>
#include <cstring>

using namespace std;

class Problem1049
{
public:
    /*
    ** 将所有石子stones划分为2个集合x、y，
    ** |sum(x) - sum(y)|最小时，x和y碰撞后的剩余最小
    ** 因此sum(x)/sum(y)应尽可能接近sum(stones)/2。
    ** 0/1背包问题：求解背包容量为sum(stones)/2时的最大石子重量。
    */
    int lastStoneWeightII(const vector<int>& stones)
    {
        int total_sum = accumulate(stones.begin(), stones.end(), 0);
        return total_sum - 2 * knapsack_max(stones, total_sum / 2);
    }

private:
    int knapsack_max(const vector<int>& stones, int capacity)
    {
        int *f = (int *)calloc(capacity + 1, sizeof(int));

        for (const int &s : stones)
        {
            for (int i = capacity; i >= s; --i)
                f[i] = max(f[i], f[i - s] + s);
        }

        int result = f[capacity];
        free(f);
        return result;
    }
};
#endif //LEETCODESOLUTIONSINCPP_PROBLEM1049_H
