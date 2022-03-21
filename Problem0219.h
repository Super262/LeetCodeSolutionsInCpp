//
// Created by Fengwei Zhang on 9/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0219_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0219_H

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(const vector<int> &nums, int k) {
        // 利用哈希表保存数字最近出现位置
        unordered_map<int, int> last_idx;
        for (int i = 0; i < (int) nums.size(); ++i) {
            if (last_idx.count(nums[i]) && i - last_idx[nums[i]] <= k) {
                return true;
            }
            last_idx[nums[i]] = i;
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0219_H
