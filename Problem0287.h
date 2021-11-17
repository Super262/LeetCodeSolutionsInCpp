//
// Created by Fengwei Zhang on 11/16/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0287_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0287_H

#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(const vector<int> &nums) {
        // 图中的边(u, v)：nums[u] = v
        // 快慢指针：因为只有1个数字重复，因此目标就是找到环的入口
        int a = 0;
        int b = 0;
        while (true) {
            a = nums[a];
            b = nums[nums[b]];
            if (a == b) {
                a = 0;
                while (a != b) {
                    a = nums[a];
                    b = nums[b];
                }
                return a;
            }
        }
        return -1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0287_H
