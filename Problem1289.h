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
    int minFallingPathSum(const vector<vector<int>>& grid)
    {
        const int &n = (int) grid.size();
        vector<vector<int>> f(n, vector<int>(n));

        for (int j = 0; j < n; ++j)
            f[0][j] = grid[0][j];
        
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!j)
                {
                    if (j + 1 < n)
                        f[i][j] = *min_element(
                                    f[i - 1].begin() + j + 1,
                                    f[i - 1].end())
                                    + grid[i][j];
                }
                else if (j == n - 1)
                {
                    if (j - 1 >= 0)
                        f[i][j] = *min_element(
                                    f[i - 1].begin(),
                                    f[i - 1].begin() + j)
                                    + grid[i][j];
                }
                else
                    f[i][j] = min(
                                *min_element(f[i - 1].begin(), f[i - 1].begin() + j), 
                                *min_element(f[i - 1].begin() + j + 1, f[i - 1].end()))
                                + grid[i][j];
            }
        }

        return *min_element(f[n - 1].begin(), f[n - 1].end());
    }
};
#endif //LEETCODESOLUTIONSINCPP_PROBLEM1289_H
