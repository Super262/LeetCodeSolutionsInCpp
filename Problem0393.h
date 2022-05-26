//
// Created by Fengwei Zhang on 11/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0393_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0393_H

#include <vector>

using namespace std;

class Solution {
    // 获取每个起点数字的高位，统计"1"的个数
    // 细节：注意判定无效情况（起点高位有1个"1"，或超过4个"1"）
public:
    bool validUtf8(const vector<int> &data) {
        for (int i = 0; i < (int) data.size(); ++i) {
            if (bitAt(data[i], 0) == 0) {  // 1-byte character
                continue;
            }
            int k = 0;
            while (bitAt(data[i], k) && k <= 4) {
                ++k;
            }
            if (k > 4 || k == 1 || i + k - 1 >= (int) data.size()) {  // 不要忘记这个判断
                return false;
            }
            for (int j = i + 1; j <= i + k - 1; ++j) {
                if (bitAt(data[j], 0) != 1 || bitAt(data[j], 1) != 0) {
                    return false;
                }
            }
            i += k - 1;
        }
        return true;
    }

private:
    int bitAt(int x, int k) {  // 获取第k位（从高位开始）
        return (x >> (7 - k)) & 1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0393_H
