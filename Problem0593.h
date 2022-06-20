//
// Created by Fengwei Zhang on 1/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0593_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0593_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 正方形条件：四条边相等，对角线相等
    // 暴力法：计算出任意两点间的距离，排序；若最小的6个距离相等，则为正方形
public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4) {
        int dist[6];
        vector<int> *points[4] = {&p1, &p2, &p3, &p4};
        for (int i = 0, k = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                dist[k] = getDist(*points[i], *points[j]);
                ++k;
            }
        }
        sort(dist, dist + 6);
        if (!dist[0]) {  // 说明某2个点重合
            return false;
        }
        return (dist[0] == dist[1] && dist[1] == dist[2] && dist[2] == dist[3]) && (dist[4] == dist[5]);
    }

private:
    int getDist(const vector<int> &a, const vector<int> &b) {
        auto dx = a[0] - b[0];
        auto dy = a[1] - b[1];
        return dx * dx + dy * dy;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0593_H
