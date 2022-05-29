
//
// Created by Fengwei Zhang on 5/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0422_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0422_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 判断对角线两侧的字符是否对称相等
public:
    bool validWordSquare(const vector<string> &words) {
        const auto rows = (int) words.size();
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < (int) words[r].size(); ++c) {
                if (c >= rows) {
                    return false;
                }
                if ((int) words[c].size() <= r) {
                    return false;
                }
                if (words[r][c] != words[c][r]) {
                    return false;
                }
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0422_H
