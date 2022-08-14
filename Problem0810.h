//
// Created by Fengwei Zhang on 3/31/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0810_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0810_H

#include <vector>

using namespace std;

class Problem0810 {
    // 必胜态：存在某种方式转移到必败态；必败态：只能转移到必胜态；设所有数字的异或和为s
    // 通过观察得出：必胜态：s=0或n是偶数；必败态：s!=0且n是奇数
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
