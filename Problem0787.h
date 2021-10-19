//
// Created by Fengwei Zhang on 10/19/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0787_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0787_H

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Problem0787 {
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        int dist[n + 1];
        int temp[n + 1];
        memset(dist, 0x3f, sizeof dist);
        dist[src] = 0;
        ++k;
        while (k--) {
            memcpy(temp, dist, sizeof dist);
            for (auto &e: flights) {
                dist[e[1]] = min(dist[e[1]], temp[e[0]] + e[2]);
            }
        }
        if (dist[dst] == 0x3f3f3f3f) {
            return -1;
        }
        return dist[dst];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0787_H
