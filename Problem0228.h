//
// Created by Fengwei Zhang on 9/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0228_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0228_H

#include <vector>
#include <string>

using namespace std;

class Problem0228 {
private:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> result;
        for (int i = 0; i < nums.size(); ++i) {
            int j = i + 1;
            while (j < nums.size() && nums[j] == nums[j - 1] + 1) {
                ++j;
            }
            if (j == i + 1) {  // 区间只有1个数字
                result.emplace_back(to_string(nums[j - 1]));
            } else {
                result.emplace_back(to_string(nums[i]) + "->" + to_string(nums[j - 1]));
            }
            i = j - 1;
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0228_H
