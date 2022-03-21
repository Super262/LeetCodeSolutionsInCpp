//
// Created by Fengwei Zhang on 11/15/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0260_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0260_H

#include <vector>

using namespace std;

class Solution {
    // https://www.acwing.com/solution/content/237/
public:
    vector<int> singleNumber(const vector<int> &nums) {
        // 时间O(n)，空间O(1)
        int all_xor = 0;
        for (const auto &x: nums) {
            all_xor ^= x;
        }
        int k = 0;
        while ((all_xor & 1) == 0) {
            all_xor >>= 1;
            ++k;
        }
        return {findKthEquals(nums, k, 0), findKthEquals(nums, k, 1)};
    }

private:
    int findKthEquals(const vector<int> &nums, const int &k, const int &val) {
        int result = 0;
        for (const auto &x: nums) {
            if (((x >> k) & 1) == val) {
                result ^= x;
            }
        }
        return result;
    }

};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0260_H
