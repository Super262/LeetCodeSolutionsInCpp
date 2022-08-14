//
// Created by Fengwei Zhang on 4/1/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0822_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0822_H

#include <vector>
#include <unordered_set>

using namespace std;

class Problem0822 {
    // 脑筋急转弯：若对于某个数字x，存在i使得fronts[i] = backs[i]，x不合法
    // 先找出所有不合法的数字，再遍历，找到最小的good integer
public:
    int flipgame(const vector<int> &fronts, const vector<int> &backs) {
        unordered_set<int> invalid_nums;
        for (int i = 0; i < (int) fronts.size(); ++i) {
            if (fronts[i] != backs[i]) {
                continue;
            }
            invalid_nums.insert(fronts[i]);
        }
        int ans = INT_MAX;
        for (const auto &x: fronts) {
            if (invalid_nums.count(x)) {
                continue;
            }
            ans = min(ans, x);
        }
        for (const auto &x: backs) {
            if (invalid_nums.count(x)) {
                continue;
            }
            ans = min(ans, x);
        }
        if (ans == INT_MAX) {
            return 0;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0822_H
