//
// Created by Fengwei Zhang on 9/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0218_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0218_H

#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(const vector<vector<int>> &buildings) {
        vector<pair<int, int>> points;
        points.reserve(buildings.size() * 2);
        for (const auto &b: buildings) {
            points.emplace_back(b[0], -b[2]);  // 起点的高度从大到小排序（提示：利用相反数）
            points.emplace_back(b[1], b[2]);
        }
        sort(points.begin(), points.end());
        multiset<int> heights;  // 红黑树：有序，支持插入和删除
        heights.insert(0);  // 题目要求结果包括x轴上的终点
        vector<vector<int>> result;
        for (const auto &p: points) {
            int x = p.first;
            int h = abs(p.second);
            if (p.second < 0) {  // 是起点
                if (h > *heights.rbegin()) {  // 发现更高的天际线
                    result.push_back({x, h});
                }
                heights.insert(h);
            } else {  // 是终点
                heights.erase(heights.find(h));  // 删除对应的起点的高度
                if (h > *heights.rbegin()) {  // 发现较低的天际线
                    result.push_back({x, *heights.rbegin()});
                }
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0218_H
