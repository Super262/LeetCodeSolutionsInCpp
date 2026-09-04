//
// Created by Fengwei Zhang on 09/04/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM2976_H
#define LEETCODESOLUTIONSINCPP_PROBLEM2976_H

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Problem2976
{
private:
    /* 由于点集很小（26），选择Floyd算法求最短路 */
    void floyd(vector<vector<int>> &dist)
    {
        for (int mid = 0; mid < 26; ++mid)
        {
            for (int i = 0; i < 26; ++i)
            {
                for (int j = 0; j < 26; ++j)
                {
                    if (dist[i][mid] != -1 && dist[mid][j] != -1)
                    {
                        if (dist[i][j] == -1)
                            dist[i][j] = dist[i][mid] + dist[mid][j];
                        else
                            dist[i][j] = min(dist[i][j], dist[i][mid] + dist[mid][j]);
                    }
                }
            }
        }
    }

public:
    long long minimumCost(const string &source,
                          const string &target,
                          const vector<char>& original,
                          const vector<char>& changed,
                          const vector<int>& cost)
    {
        vector<vector<int>> dist(26, vector<int>(26, -1));
        long long answer = 0;
        
        for (int i = 0; i < 26; ++i)
            dist[i][i] = 0;

        for (int i = 0, x, y; i < (int) cost.size(); ++i)
        {
            x = (int)(original[i] - 'a');
            y = (int)(changed[i] - 'a');

            if (dist[x][y] == -1)
                dist[x][y] = cost[i];
            else
                dist[x][y] = min(dist[x][y], cost[i]);
        }

        floyd(dist);
        for (int i = 0, x, y; i < (int) source.length(); ++i)
        {
            if (source[i] == target[i])
                continue;
            
            x = (int)(source[i] - 'a');
            y = (int)(target[i] - 'a');

            if (dist[x][y] == -1)
                return -1;
            
            answer += dist[x][y];
        }

        return answer;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM2976_H
