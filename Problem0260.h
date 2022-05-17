//
// Created by Fengwei Zhang on 11/15/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0260_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0260_H

#include <vector>

using namespace std;

class Solution {
    // 若a!=b，则a^b至少有1位为1；nums中只有两个只出现一次的数字a、b，因此nums中所有数字依次异或后的结果all_xor=a^b
    // 我们可以在all_xor中找到非零的位置i，根据i=0/1分别生成a/b（s1是所有第i位为1的二进制数的异或和，s0同理）；时间O(n)，空间O(1)
    // https://www.acwing.com/solution/content/237/
public:
    vector<int> singleNumber(const vector<int> &nums) {
        int all_xor = 0;
        for (const auto &x: nums) {
            all_xor ^= x;
        }
        int k = 0;
        while ((all_xor & 1) == 0) {
            all_xor >>= 1;
            ++k;
        }
        int s0 = 0;
        int s1 = 0;
        for (const auto &x: nums) {
            if ((x >> k) & 1) {
                s1 ^= x;
            } else {
                s0 ^= x;
            }
        }
        return {s0, s1};
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0260_H
