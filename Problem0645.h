//
// Created by Fengwei Zhang on 2/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0645_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0645_H

#include <vector>

using namespace std;

class Solution {
    // 经典算法，必须掌握：翻转nums[k]符号位后，若nums[x]符号为正，则x出现0次或2次
public:
    vector<int> findErrorNums(vector<int> &nums) {
        vector<int> res(2, 0);
        for (auto &x: nums) {
            auto k = abs(x);
            nums[k - 1] *= -1;
            if (nums[k - 1] > 0) {  // 发现第1个正数
                res[0] = k;
            }
        }
        for (int i = 0; i < (int) nums.size(); ++i) {
            if (nums[i] > 0 && i + 1 != res[0]) {  // 发现第2个正数
                res[1] = i + 1;
                break;
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0645_H
