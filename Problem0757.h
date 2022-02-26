//
// Created by Fengwei Zhang on 2/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0757_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0757_H

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
    // 贪心算法：按照右端点排序，短区间在前；从左开始遍历，没有点相交，加入2个点；有1点相交，加入尾结点
public:
    int intersectionSizeTwo(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[1] != b[1]) {
                return a[1] < b[1];
            }
            return a[0] > b[0];  // 短区间在前
        });
        vector<int> q(1, -1);  // 加入-1作为"哨兵"
        int counter = 0;
        for (const auto &r: intervals) {
            if (r[0] > q[counter]) {
                q.emplace_back(r[1] - 1);
                q.emplace_back(r[1]);
                counter += 2;
            } else if (counter > 0 && r[0] > q[counter - 1]) {
                q.emplace_back(r[1]);
                ++counter;
            }
        }
        return counter;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0757_H
