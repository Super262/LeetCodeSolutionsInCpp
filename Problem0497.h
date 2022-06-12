//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0497_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0497_H

#include <vector>

using namespace std;

class Solution {
    // 预处理，使概率和面积成正比：把面积为s的矩形看作是数轴上长度为s的线段
    // 随机数：先随机生成前缀和（随机数为前缀和可以保证等概率），二分查找到目标矩形；在目标矩形内随机返回一个点
public:
    Solution(const vector<vector<int>> &rects) {
        this->rects = rects;
        this->n = (int) rects.size();
        prefix.resize(n + 1);   // 线段前缀和
        prefix[0] = 0;
        for (int i = 0; i < n; ++i) {
            auto dx = rects[i][2] - rects[i][0] + 1;  // 不要忘记加1：矩形边界上的点也要被考虑
            auto dy = rects[i][3] - rects[i][1] + 1;
            prefix[i + 1] = prefix[i] + dx * dy;
        }
    }

    vector<int> pick() {
        auto k = (int) (random() % prefix.back() + 1);  // k落在[1,prefix.back()]
        int l = 1;
        auto r = n;  // 二分查找合适的前缀和
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (prefix[mid] >= k) {  // 查找大于或等于k的的最小点
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        auto &t = rects[r - 1];  // 搜索从1开始，索引从0开始
        auto dx = t[2] - t[0] + 1;
        auto dy = t[3] - t[1] + 1;
        return {(int) (random() % dx + t[0]), (int) (random() % dy + t[1])};
    }

private:
    int n;
    vector<vector<int>> rects;
    vector<int> prefix;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0497_H
