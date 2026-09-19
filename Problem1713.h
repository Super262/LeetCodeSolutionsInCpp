//
// Created by Fengwei Zhang on 9/19/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1713_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1713_H

#include <cstring>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Problem1713
{
public:
    /*
    ** 转化为最长上升子序列问题
    ** 最长上升子序列中的每个元素是target数组的索引下标
    ** 目标是在arr中找到一个如上所述的最长上升子序列
    ** 若它的长度是l，结果是target.size() - l
    */
    int minOperations(const vector<int> &target,
                      const vector<int> &arr)
    {
        unordered_map<int, int> num2TargetIdx;
        const int &m = (int) target.size();

        num2TargetIdx.reserve(m);
        for (int i = 0; i < m; ++i)
            num2TargetIdx[target[i]] = i;

        return m - myLIS(arr, num2TargetIdx);
    }

private:
    int myLIS(const vector<int> &arr,
              const unordered_map<int, int> &num2TargetIdx)
    {
        const int &n = (int) arr.size();
        const int &m = (int) num2TargetIdx.size();
        int *lisTail = (int *)malloc(sizeof(int) * (m + 1));
        int answer = 0;

        memset(lisTail, 0x3f, sizeof(int) * (m + 1));

        for (int i = 0, pivot, l, r, mid; i < n; ++i)
        {
            unordered_map<int, int>::const_iterator it =
                num2TargetIdx.find(arr[i]);

            if (it == num2TargetIdx.end())
                continue;

            pivot = it->second;
            l = 0;
            r = i + 1;

            while (l < r)
            {
                mid = l + (r - l + 1) / 2;

                if (lisTail[mid] >= pivot)
                    r = mid - 1;
                else
                    l = mid;
            }

            if (lisTail[l + 1] > pivot)
                lisTail[l + 1] = pivot;

            if (l + 1 > answer)
                answer = l + 1;
        }

        free(lisTail);
        return answer;
    }
};
#endif //LEETCODESOLUTIONSINCPP_PROBLEM1713_H
