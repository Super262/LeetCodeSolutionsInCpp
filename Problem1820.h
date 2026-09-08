//
// Created by Fengwei Zhang on 9/8/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1820_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1820_H

#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Problem1820
{
public:
    /* 用匈牙利算法查找最大二分匹配 */
    int maximumInvitations(const vector<vector<int>>& grid)
    {
        int result = 0;
        int m = (int)grid.size();
        int n =  (int)grid.back().size();
        vector<vector<int>> graph(m + 1);
        int *matched_boy = (int *)calloc(n + 1,
                                         sizeof(int));
        int *visited_girl = (int *)calloc(n + 1,
                                          sizeof(int));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!grid[i][j])
                    continue;
                graph[i + 1].emplace_back(j + 1);
            }
        }

        for (int i = 1, stamp = 0; i <= m; ++i)
        {
            ++stamp;
            if (dfsMatch(i, stamp, graph,
                         matched_boy, visited_girl))
                ++result;
        }

        free(matched_boy);
        free(visited_girl);
        return result;
    }

private:
    bool dfsMatch(int x,
                  int stamp,
                  const vector<vector<int>> &graph,
                  int *matched_boy,
                  int *visited_girl)
    {
        for (int y : graph[x])
        {
            if (visited_girl[y] == stamp)
                continue;
            visited_girl[y] = stamp;
            if (!matched_boy[y] ||
                dfsMatch(matched_boy[y], stamp, graph,
                         matched_boy, visited_girl))
            {
                matched_boy[y] = x;
                return true;
            }
        }
        return false;
    }
};
#endif //LEETCODESOLUTIONSINCPP_PROBLEM1820_H
