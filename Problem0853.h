//
// Created by Fengwei Zhang on 4/6/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0853_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0853_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 排序；从终点向起点依次枚举每辆车，讨论它是否会追赶上后面的车
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed) {
        const auto n = (int) position.size();
        int id[n];  // 技巧：id标示索引
        for (int i = 0; i < n; ++i) {
            id[i] = i;
        }
        sort(id, id + n, [&](const int &a, const int &b) {
            return position[a] < position[b];
        });
        auto ans = n;
        const auto ZERO = 1e-8;
        double prev = 0;  // 后面的车到达终点的时间耗费
        for (auto i = n - 1; i >= 0; --i) {
            auto t = (target - position[id[i]]) / (double) speed[id[i]];
            if (t - prev < ZERO) {  // 当前车比后面的车速度快
                --ans;  // 发生碰撞
            } else {
                prev = t;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0853_H
