//
// Created by Fengwei Zhang on 5/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0356_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0356_H

#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
    // 首先，利用set去除重复点，并保证所有点按照横坐标从小到大、纵坐标从小到大排列
    // 然后，根据纵坐标，对所有点的横坐标分类（构建行）；双指针寻找满足要求的直线
    // 细节：直线坐标要用double类型保存
public:
    bool isReflected(const vector<vector<int>> &points) {
        set<pair<int, int>> unique_points;
        for (const auto &p: points) {
            unique_points.insert({p[0], p[1]});
        }
        unordered_map<int, vector<int>> rows;  // 构建行
        for (const auto &it: unique_points) {
            rows[it.second].emplace_back(it.first);
        }
        double ans;
        bool has_ans = false;
        for (const auto &row: rows) {
            int l = 0;
            auto r = (int) row.second.size() - 1;
            double cur;
            bool has_cur = false;
            while (l <= r) {
                auto mid = row.second[l] + ((double) row.second[r] - row.second[l]) / 2;
                if (!has_cur) {
                    cur = mid;
                    has_cur = true;
                }
                if (cur != mid) {  // 不等，终止
                    return false;
                }
                if (!has_ans) {
                    ans = cur;
                    has_ans = true;
                }
                if (cur != ans) {  // 不等，终止
                    return false;
                }
                ++l;
                --r;
            }
        }
        return has_ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0356_H
