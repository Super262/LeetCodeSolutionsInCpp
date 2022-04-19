//
// Created by Fengwei Zhang on 4/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0982_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0982_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 采用类似3Sum的做法，根据数据范围得出时间复杂度为(2^16 * 1000)级别
    // 与x做AND操作结果为0的数：[0, (1<<M) - 1 - x]，通过消除最后的"1"来遍历这个列表（背诵这段代码）
public:
    int countTriplets(const vector<int> &nums) {
        const int M = 1 << 16;
        int counter[M];
        memset(counter, 0, sizeof counter);
        for (const int &a: nums) {
            for (const auto &b: nums) {
                ++counter[a & b];
            }
        }
        int ans = 0;
        for (const auto &x: nums) {
            const auto full = M - 1 - x;
            for (auto y = full; y > 0; y = (y - 1) & full) {  //遍历与x做AND操作结果为0的数
                ans += counter[y];
            }
            ans += counter[0];  // 0和任何数进行AND，结果都是0，别忘记它！
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0982_H
