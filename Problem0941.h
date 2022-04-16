//
// Created by Fengwei Zhang on 4/16/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0941_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0941_H

#include <vector>

using namespace std;

class Solution {
    // 找到拐点k，判断arr[k:-1]是否为单调递减、arr[0:k-1]是否存在
public:
    bool validMountainArray(const vector<int> &arr) {
        int k = 0;
        while (k + 1 < (int) arr.size() && arr[k + 1] > arr[k]) {  // 严格递增
            ++k;
        }
        if (!k || k + 1 >= (int) arr.size()) {
            return false;
        }
        for (auto i = k + 1; i < (int) arr.size(); ++i) {  // 严格递减
            if (arr[i] >= arr[i - 1]) {
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0941_H
