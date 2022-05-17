//
// Created by Fengwei Zhang on 11/15/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0260_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0260_H

#include <vector>

using namespace std;

class Solution {
    // 若a!=b，则a^b至少有1位为1；nums中只有两个只出现一次的数字a、b，因此nums中所有数字依次异或后的结果all_xor=a^b
    // 我们可以在all_xor中找到非零的位置i，根据i=0/1分别生成a/b；时间O(n)，空间O(1)
    // https://www.acwing.com/solution/content/237/
public:
    vector<int> singleNumber(const vector<int> &nums) {
        int all_xor = 0;
        for (const auto &x: nums) {
            all_xor ^= x;
        }
        int k = 0;
        while ((all_xor & 1) == 0) {  // 查找非零位置
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
