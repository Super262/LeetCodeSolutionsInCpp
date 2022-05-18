//
// Created by Fengwei Zhang on 11/16/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0287_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0287_H

#include <vector>

using namespace std;

class Solution {
    // 转化数组为图，图中的边(u, v)：nums[u] = v（数组长度为n+1，数据范围为[1:n]，不会越界）
    // 快慢指针：先找到环，再寻找环的入口（LeetCode 142）
public:
    int findDuplicate(const vector<int> &nums) {
        int a = 0;
        int b = 0;
        while (true) {
            a = nums[a];
            b = nums[nums[b]];
            if (a != b) {
                continue;
            }
            a = 0;
            while (a != b) {
                a = nums[a];
                b = nums[b];
            }
            return a;
        }
        return -1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0287_H
