//
// Created by Fengwei Zhang on 11/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0167_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0167_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(const vector<int> &numbers, const int &target) {
        vector<int> ans = {1, 2};
        int i = 0;
        auto j = (int) numbers.size() - 1;
        while (i < j) {
            if (numbers[i] + numbers[j] == target) {
                ans[0] = i + 1;
                ans[1] = j + 1;
                return ans;
            } else if (numbers[i] + numbers[j] > target) {
                --j;
            } else {
                ++i;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0167_H
