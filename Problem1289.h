//
// Created by Fengwei Zhang on 9/12/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1289_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1289_H

#include <vector>
#include <algorithm>

using namespace std;

class Problem1289
{
public:
    /*
    ** f[i][j]：长度为(i + 1)（0<=i<n），末尾元素为grid[i][j]（0<=j<n）的
    ** falling path with non-zero shifts 的元素之和的最小值。
    ** 每次迭代时，选择min(grid[i][0:j))和min(grid[i][j:n))间的较小者，
    ** 因此时间复杂度为O(n^3)。
    ** 优化：预先计算每行的最小值、最小值所在位置和次小值；
    ** 每次迭代时，如果最小值在j，则选择次小值，否则直接选择最小值。
    */
    int minFallingPathSum(const vector<vector<int>>& grid)
    {
        const int &n = (int) grid.size();
        vector<vector<int>> f(n, vector<int>(n));

        for (int j = 0; j < n; ++j)
            f[0][j] = grid[0][j];
        
        for (int i = 1, pre_min1, pre_min1_col, pre_min2; i < n; ++i)
        {
            findSecondMinElement(f[i - 1], pre_min1, pre_min1_col, pre_min2);
            for (int j = 0; j < n; ++j)
            {
                if (pre_min1_col == j)
                    f[i][j] = pre_min2 + grid[i][j];
                else
                    f[i][j] = pre_min1 + grid[i][j];
            }
        }

        return *min_element(f[n - 1].begin(), f[n - 1].end());
    }

private:
    void findSecondMinElement(const vector<int> &arr,
                              int &min1_ele,
                              int &min1_idx,
                              int &min2_ele)
    {
        if (arr.empty())
        {
            min1_idx = -1;
            return;
        }
        
        min1_ele = arr[0];
        min1_idx = 0;
        min2_ele = INT_MAX;

        for (int i = (int)arr.size() - 1; i; --i)
        {
            if (arr[i] < min1_ele)
            {
                min2_ele = min1_ele;
                min1_idx = i;
                min1_ele = arr[i];
            }
            else if (arr[i] < min2_ele)
                min2_ele = arr[i];
        }
    }
};

// class Problem1289
// {
// public:
//     int minFallingPathSum(const vector<vector<int>>& grid)
//     {
//         const int &n = (int) grid.size();
//         vector<vector<int>> f(n, vector<int>(n));
//
//         for (int j = 0; j < n; ++j)
//             f[0][j] = grid[0][j];
//
//         for (int i = 1; i < n; ++i)
//         {
//             for (int j = 0; j < n; ++j)
//             {
//                 if (!j)
//                 {
//                     if (j + 1 < n)
//                         f[i][j] = *min_element(
//                                     f[i - 1].begin() + j + 1,
//                                     f[i - 1].end())
//                                     + grid[i][j];
//                 }
//                 else if (j == n - 1)
//                 {
//                     if (j - 1 >= 0)
//                         f[i][j] = *min_element(
//                                     f[i - 1].begin(),
//                                     f[i - 1].begin() + j)
//                                     + grid[i][j];
//                 }
//                 else
//                     f[i][j] = min(
//                                 *min_element(f[i - 1].begin(), f[i - 1].begin() + j), 
//                                 *min_element(f[i - 1].begin() + j + 1, f[i - 1].end()))
//                                 + grid[i][j];
//             }
//         }
//
//         return *min_element(f[n - 1].begin(), f[n - 1].end());
//     }
// };
#endif //LEETCODESOLUTIONSINCPP_PROBLEM1289_H
