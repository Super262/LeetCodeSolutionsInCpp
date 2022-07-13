//
// Created by Fengwei Zhang on 2/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0717_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0717_H

#include<vector>

using namespace std;

class Solution {
    // 遇到"0"，判断当前是不是最后位；遇到"1"，直接后移2位
public:
    bool isOneBitCharacter(const vector<int> &bits) {
        for (int i = 0; i < (int) bits.size(); ++i) {
            if (!bits[i] && i == (int) (bits.size() - 1)) {  // 最后位为0
                return true;
            }
            if (bits[i]) {  // 开头为1，跳过2位
                ++i;
            }
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0717_H
