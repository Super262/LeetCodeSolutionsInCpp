//
// Created by Fengwei Zhang on 2/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0717_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0717_H

#include<vector>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(const vector<int> &bits) {
        for (int i = 0; i < bits.size(); ++i) {
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