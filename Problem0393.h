//
// Created by Fengwei Zhang on 11/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0393_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0393_H

#include <vector>

using namespace std;

class Solution {
public:
    bool validUtf8(const vector<int> &data) {
        for (int i = 0; i < (int) data.size(); ++i) {
            if (getBit(data[i], 0) == 0) {  // 1-byte character
                continue;
            }
            int k = 0;
            while (getBit(data[i], k) && k <= 4) {
                ++k;
            }
            if (k > 4 || k == 1 || i + k - 1 >= (int) data.size()) {  // 不要忘记这个判断
                return false;
            }
            for (int j = i + 1; j <= i + k - 1; ++j) {
                if (getBit(data[j], 0) != 1 || getBit(data[j], 1) != 0) {
                    return false;
                }
            }
            i += k - 1;
        }
        return true;
    }

private:
    int getBit(int x, int k) {
        return (x >> (7 - k)) & 1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0393_H
