//
// Created by Fengwei Zhang on 3/31/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0810_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0810_H

#include <vector>

using namespace std;

class Solution {
    // 如果所有数字异或和为 0，则显然先手获胜
    // 否则，如果数组长度为偶数，则先手必胜；数组长度为奇数，先手必败
    // 博弈论：https://www.acwing.com/solution/content/24119/
public:
    bool xorGame(const vector<int> &nums) {
        int s = 0;
        for (const auto &x: nums) {
            s ^= x;
        }
        if (!s) {
            return true;
        }
        return nums.size() % 2 == 0;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0810_H
