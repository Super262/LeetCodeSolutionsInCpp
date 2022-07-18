//
// Created by Fengwei Zhang on 2/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0735_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0735_H

#include <vector>

using namespace std;

class Problem0735 {
    // 贪心：对每个陨石x，若x>0，直接保存x；若x<0，从尾部遍历当前答案，除去较小的反向陨石和相等的反向陨石
public:
    vector<int> asteroidCollision(const vector<int> &asteroids) {
        vector<int> ans;
        for (const auto &x: asteroids) {
            if (x > 0) {
                ans.emplace_back(x);
                continue;
            }
            while (!ans.empty() && ans.back() > 0 && ans.back() < -x) {
                ans.pop_back();
            }
            if (!ans.empty() && ans.back() == -x) {
                ans.pop_back();
            } else if (ans.empty() || ans.back() < 0) {
                ans.emplace_back(x);
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0735_H
