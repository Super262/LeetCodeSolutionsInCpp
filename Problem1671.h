//
// Created by Fengwei Zhang on 9/18/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1671_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1671_H

#include <vector>
#include <algorithm>

using namespace std;

class Problem1671
{
public:
    int minimumMountainRemovals(const vector<int>& nums)
    {
        const int &n = (int) nums.size();
        vector<int> fi(n, -1);
        vector<int> fd(n, -1);
        int answer = 0;

        /* 求以nums[i]为末元素的最长上升子序列的长度 */
        myLIS(nums, fi);

        /* 求以nums[i]为首元素的最长下降子序列的长度 */
        myLDS(nums, fd);

        for (int i = 0; i < n; ++i)
        {
            /* nums[i]不能是最长上升（或下降）子序列中的唯一元素 */
            if (fi[i] > 1 && fd[i] > 1)
                /* 求以nums[i]为分界点的mountain array的最大长度 */
                answer = max(answer, fi[i] + fd[i] - 1);
        }

        return n - answer;
    }

private:
    /* fi[i]：nums[i]为末元素的最长上升子序列的长度 */
    void myLIS(const vector<int>& nums, vector<int> &fi)
    {
        /* 0 <= nums[i] <= 1e9，因此选择-1和1e9+1为边界 */
        const int &n = (int) nums.size();
        vector<int> lisTail(n + 1, 1000000001);

        lisTail[0] = -1;

        for (int i = 0, t, l, r, mid; i < n; ++i)
        {
            t = nums[i];
            l = 0;
            r = i + 1;
            while (l < r)
            {
                mid = l + (r - l + 1) / 2;
                if (lisTail[mid] < t)
                    l = mid;
                else
                    r = mid - 1;
            }

            fi[i] = max(fi[i], l + 1);
            lisTail[l + 1] = min(lisTail[l + 1], t);
        }
    }

    /* fd[i]：nums[i]为首元素的最长下降子序列的长度 */
    void myLDS(const vector<int>& nums, vector<int> &fd)
    {
        /* 0 <= nums[i] <= 1e9，因此选择-1和1e9+1为边界 */
        const int &n = (int) nums.size();
        vector<int> ldsHead(n + 1, 1000000001);

        ldsHead[0] = -1;

        for (int i = n - 1, t, l, r, mid; i >= 0; --i)
        {
            t = nums[i];
            l = 0;
            r = n - i;
            while (l < r)
            {
                mid = l + (r - l + 1) / 2;
                if (ldsHead[mid] < t)
                    l = mid;
                else
                    r = mid - 1;
            }

            fd[i] = max(fd[i], l + 1);
            ldsHead[l + 1] = min(ldsHead[l + 1], t);
        }
    }
};
#endif //LEETCODESOLUTIONSINCPP_PROBLEM1671_H
