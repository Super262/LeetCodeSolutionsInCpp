//
// Created by Fengwei Zhang on 2/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0611_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0611_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 经典算法，必须掌握：双指针
    // 避免重复：将所有数排序
public:
    int triangleNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int a = 2; a < (int) nums.size(); ++a) {  // 第1条边
            for (int b = a - 1, c = 0; c < b; --b) {  // 第2、3条边
                while (c < b && nums[c] + nums[b] <= nums[a]) {  // 保证 b + c >= a 成立
                    ++c;
                }
                res += b - c;
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0611_H
