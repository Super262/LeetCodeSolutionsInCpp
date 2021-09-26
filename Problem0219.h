//
// Created by Fengwei Zhang on 9/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0219_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0219_H

#include <unordered_map>

using namespace std;

class Problem0219 {
private:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        // 利用哈希表保存数字最近出现位置
        unordered_map<int, unsigned long long> lastIdx;
        for (unsigned long long i = 0; i < nums.size(); ++i) {
            if (lastIdx.count(nums[i]) && i - lastIdx[nums[i]] <= k) {
                return true;
            }
            lastIdx[nums[i]] = i;
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0219_H
